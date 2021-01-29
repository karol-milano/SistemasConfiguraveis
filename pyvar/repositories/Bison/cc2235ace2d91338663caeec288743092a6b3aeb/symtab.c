@@ -1057,29 +1057,6 @@ register_precedence (graphid first, graphid snd)
 }
 
 
-/*--------------------------------------------------.
-| Print a warning for unused precedence relations.  |
-`--------------------------------------------------*/
-
-void
-print_precedence_warnings (void)
-{
-  int i;
-  if (!prec_nodes)
-    init_prec_nodes ();
-  for (i = 0; i < nsyms; ++i)
-    {
-      symbol *s = symbols[i];
-      if (s
-          && s->prec != 0
-          && !prec_nodes[i]->pred
-          && !prec_nodes[i]->succ
-          && s->assoc == precedence_assoc)
-        complain (&s->location, Wother,
-                  _("useless precedence for %s"), s->tag);
-    }
-}
-
 /*---------------------------------------.
 | Initialize association tracking table. |
 `---------------------------------------*/
@@ -1119,21 +1096,35 @@ register_assoc (graphid i, graphid j)
   used_assoc[j] = true;
 }
 
-/*------------------------------------------------------.
-| Print a warning for each unused symbol associativity. |
-`------------------------------------------------------*/
+/*--------------------------------------------------.
+| Print a warning for unused precedence relations.  |
+`--------------------------------------------------*/
 
 void
-print_assoc_warnings (void)
+print_precedence_warnings (void)
 {
-  graphid i;
+  int i;
+  if (!prec_nodes)
+    init_prec_nodes ();
   if (!used_assoc)
     init_assoc ();
   for (i = 0; i < nsyms; ++i)
     {
       symbol *s = symbols[i];
-      if (is_assoc_useless (s))
-        complain (&s->location, Wother,
-                  _("useless associativity for %s"), s->tag);
+      if (s
+          && s->prec != 0
+          && !prec_nodes[i]->pred
+          && !prec_nodes[i]->succ)
+        {
+          if (is_assoc_useless (s))
+            complain (&s->location, Wprecedence,
+                      _("useless precedence and associativity for %s"), s->tag);
+          else if (s->assoc == precedence_assoc)
+            complain (&s->location, Wprecedence,
+                      _("useless precedence for %s"), s->tag);
+        }
+      else if (is_assoc_useless (s))
+        complain (&s->location, Wprecedence,
+                  _("useless associativity for %s, use %%precedence"), s->tag);
     }
 }
