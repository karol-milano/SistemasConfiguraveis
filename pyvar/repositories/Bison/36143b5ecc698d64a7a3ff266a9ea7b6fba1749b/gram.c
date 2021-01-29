@@ -55,14 +55,17 @@ item_print (item_number *item, rule const *previous_rule, FILE *out)
   rule const *r = item_rule (item);
   rule_lhs_print (r, previous_rule ? previous_rule->lhs : NULL, out);
 
-  for (item_number *sp = r->rhs; sp < item; sp++)
-    fprintf (out, " %s", symbols[*sp]->tag);
-  fprintf (out, " %s", dot);
   if (0 <= *r->rhs)
-    for (item_number *sp = item; 0 <= *sp; ++sp)
-      fprintf (out, " %s", symbols[*sp]->tag);
+    {
+      // Non-empty rhs.
+      for (item_number *sp = r->rhs; sp < item; sp++)
+        fprintf (out, " %s", symbols[*sp]->tag);
+      fprintf (out, " %s", dot);
+      for (item_number *sp = item; 0 <= *sp; ++sp)
+        fprintf (out, " %s", symbols[*sp]->tag);
+    }
   else
-    fprintf (out, " %%empty");
+    fprintf (out, " %s %s", empty, dot);
 }
 
 
@@ -122,7 +125,7 @@ rule_rhs_print (rule const *r, FILE *out)
     for (item_number *rhsp = r->rhs; 0 <= *rhsp; ++rhsp)
       fprintf (out, " %s", symbols[*rhsp]->tag);
   else
-    fputs (" %empty", out);
+    fprintf (out, " %s", empty);
 }
 
 static void
