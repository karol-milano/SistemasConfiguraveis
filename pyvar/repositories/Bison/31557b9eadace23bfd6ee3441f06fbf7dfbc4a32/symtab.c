@@ -383,26 +383,12 @@ symbol_check_defined (symbol *sym)
 {
   if (sym->class == unknown_sym)
     {
-      switch (sym->status)
-        {
-        case used:
-          complain_at (sym->location, Wother,
-                       _("symbol %s is used, but is not defined as a token"
-                         " and has no rules"),
-                       sym->tag);
-          break;
-        case undeclared:
-        case needed:
-          complain_at (sym->location, complaint,
-                       _("symbol %s is used, but is not defined as a token"
-                         " and has no rules"),
-                       sym->tag);
-          break;
-        case declared:
-          /* If declared, then sym->class != unknown_sym. */
-          assert (0);
-        }
-
+      assert (sym->status != declared);
+      complain_at (sym->location,
+                   sym->status == needed ? complaint : Wother,
+                   _("symbol %s is used, but is not defined as a token"
+                     " and has no rules"),
+                   sym->tag);
       sym->class = nterm_sym;
       sym->number = nvars++;
     }
