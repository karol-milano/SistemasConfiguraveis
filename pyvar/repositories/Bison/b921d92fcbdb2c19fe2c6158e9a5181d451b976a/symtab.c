@@ -85,7 +85,7 @@ symbol_new (uniqstr tag, location loc)
 
   res->alias = NULL;
   res->class = unknown_sym;
-  res->declared = false;
+  res->status = needed;
 
   if (nsyms == SYMBOL_NUMBER_MAXIMUM)
     fatal (_("too many symbols in input grammar (limit is %d)"),
@@ -361,7 +361,7 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
   if (sym->class != unknown_sym && sym->class != class)
     {
       complain_at (loc, _("symbol %s redefined"), sym->tag);
-      sym->declared = false;
+      sym->status = needed;
     }
 
   if (class == nterm_sym && sym->class != nterm_sym)
@@ -373,9 +373,9 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
 
   if (declaring)
     {
-      if (sym->declared)
+      if (sym->status == declared)
         warn_at (loc, _("symbol %s redeclared"), sym->tag);
-      sym->declared = true;
+      sym->status = declared;
     }
 }
 
@@ -421,10 +421,19 @@ symbol_check_defined (symbol *sym)
 {
   if (sym->class == unknown_sym)
     {
-      complain_at
-        (sym->location,
-         _("symbol %s is used, but is not defined as a token and has no rules"),
-         sym->tag);
+      if (sym->status == needed)
+        complain_at
+          (sym->location,
+           _("symbol %s is used, but is not defined as a token and has no"
+             " rules"),
+           sym->tag);
+      else
+        warn_at
+          (sym->location,
+           _("symbol %s is used, but is not defined as a token and has no"
+             " rules"),
+           sym->tag);
+
       sym->class = nterm_sym;
       sym->number = nvars++;
     }
