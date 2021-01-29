@@ -321,12 +321,15 @@ symbol_precedence_set (symbol *sym, int prec, assoc a, location loc)
 {
   if (a != undef_assoc)
     {
-      if (sym->prec != 0)
+      if (sym->prec)
         symbol_redeclaration (sym, assoc_to_string (a), sym->prec_location,
                               loc);
-      sym->prec = prec;
-      sym->assoc = a;
-      sym->prec_location = loc;
+      else
+        {
+          sym->prec = prec;
+          sym->assoc = a;
+          sym->prec_location = loc;
+        }
     }
 
   /* Only terminals have a precedence. */
@@ -1153,14 +1156,14 @@ print_precedence_warnings (void)
           && !prec_nodes[i]->succ)
         {
           if (is_assoc_useless (s))
-            complain (&s->location, Wprecedence,
+            complain (&s->prec_location, Wprecedence,
                       _("useless precedence and associativity for %s"), s->tag);
           else if (s->assoc == precedence_assoc)
-            complain (&s->location, Wprecedence,
+            complain (&s->prec_location, Wprecedence,
                       _("useless precedence for %s"), s->tag);
         }
       else if (is_assoc_useless (s))
-        complain (&s->location, Wprecedence,
+        complain (&s->prec_location, Wprecedence,
                   _("useless associativity for %s, use %%precedence"), s->tag);
     }
   free (used_assoc);
