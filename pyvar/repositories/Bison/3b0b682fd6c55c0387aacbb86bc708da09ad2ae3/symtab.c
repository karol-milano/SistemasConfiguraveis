@@ -85,7 +85,7 @@ symbol_new (uniqstr tag, location loc)
 
   res->alias = NULL;
   res->class = unknown_sym;
-  res->status = needed;
+  res->status = undeclared;
 
   if (nsyms == SYMBOL_NUMBER_MAXIMUM)
     fatal (_("too many symbols in input grammar (limit is %d)"),
@@ -358,10 +358,12 @@ symbol_precedence_set (symbol *sym, int prec, assoc a, location loc)
 void
 symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
 {
+  bool warned = false;
   if (sym->class != unknown_sym && sym->class != class)
     {
       complain_at (loc, _("symbol %s redefined"), sym->tag);
-      sym->status = needed;
+      // Don't report both "redefined" and "redeclared".
+      warned = true;
     }
 
   if (class == nterm_sym && sym->class != nterm_sym)
@@ -373,7 +375,7 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
 
   if (declaring)
     {
-      if (sym->status == declared)
+      if (sym->status == declared && !warned)
         warn_at (loc, _("symbol %s redeclared"), sym->tag);
       sym->status = declared;
     }
@@ -421,18 +423,25 @@ symbol_check_defined (symbol *sym)
 {
   if (sym->class == unknown_sym)
     {
-      if (sym->status == needed)
-        complain_at
-          (sym->location,
-           _("symbol %s is used, but is not defined as a token and has no"
-             " rules"),
-           sym->tag);
-      else
-        warn_at
-          (sym->location,
-           _("symbol %s is used, but is not defined as a token and has no"
-             " rules"),
-           sym->tag);
+      switch (sym->status)
+        {
+        case used:
+          warn_at (sym->location,
+                   _("symbol %s is used, but is not defined as a token"
+                     " and has no rules"),
+                   sym->tag);
+          break;
+        case undeclared:
+        case needed:
+          complain_at (sym->location,
+                       _("symbol %s is used, but is not defined as a token"
+                         " and has no rules"),
+                       sym->tag);
+          break;
+        case declared:
+          /* If declared, then sym->class != unknown_sym. */
+          assert (0);
+        }
 
       sym->class = nterm_sym;
       sym->number = nvars++;
