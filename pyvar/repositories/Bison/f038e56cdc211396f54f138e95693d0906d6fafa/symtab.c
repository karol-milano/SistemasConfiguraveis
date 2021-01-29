@@ -1057,6 +1057,42 @@ register_precedence (graphid first, graphid snd)
 }
 
 
+/*---------------------------------------.
+| Deep clear a linked / adjacency list). |
+`---------------------------------------*/
+
+static void
+linkedlist_free (symgraphlink *node)
+{
+  if (node)
+    {
+      while (node->next)
+        {
+          symgraphlink *tmp = node->next;
+          free (node);
+          node = tmp;
+        }
+      free (node);
+    }
+}
+
+/*----------------------------------------------.
+| Clear and destroy association tracking table. |
+`----------------------------------------------*/
+
+static void
+assoc_free (void)
+{
+  int i;
+  for (i = 0; i < nsyms; ++i)
+    {
+      linkedlist_free (prec_nodes[i]->pred);
+      linkedlist_free (prec_nodes[i]->succ);
+      free (prec_nodes[i]);
+    }
+  free (prec_nodes);
+}
+
 /*---------------------------------------.
 | Initialize association tracking table. |
 `---------------------------------------*/
@@ -1127,4 +1163,6 @@ print_precedence_warnings (void)
         complain (&s->location, Wprecedence,
                   _("useless associativity for %s, use %%precedence"), s->tag);
     }
+  free (used_assoc);
+  assoc_free ();
 }
