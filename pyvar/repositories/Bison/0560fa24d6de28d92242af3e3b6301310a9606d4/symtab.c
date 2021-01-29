@@ -400,15 +400,15 @@ symbol_check_defined (symbol *sym)
         {
         case used:
           complain_at (sym->location, Wother,
-                   _("symbol %s is used, but is not defined as a token"
-                     " and has no rules"),
-                   sym->tag);
+                       _("symbol %s is used, but is not defined as a token"
+                         " and has no rules"),
+                       sym->tag);
           break;
         case undeclared:
         case needed:
           complain_at (sym->location, complaint,
-                    _("symbol %s is used, but is not defined as a token"
-                      " and has no rules"),
+                       _("symbol %s is used, but is not defined as a token"
+                         " and has no rules"),
                     sym->tag);
           break;
         case declared:
@@ -450,8 +450,8 @@ semantic_type_check_defined (semantic_type *sem_type)
         if (sem_type->props[i].kind != CODE_PROPS_NONE
             && ! sem_type->props[i].is_used)
           complain_at (sem_type->location, Wother,
-                   _("useless %s for type <%s>"),
-                   code_props_type_string (i), sem_type->tag);
+                       _("useless %s for type <%s>"),
+                       code_props_type_string (i), sem_type->tag);
     }
   else
     complain_at (sem_type->location, Wother,
