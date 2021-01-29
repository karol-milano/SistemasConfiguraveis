@@ -125,13 +125,6 @@ rule_rhs_print_xml (rule const *r, FILE *out, int level)
     }
 }
 
-static void
-rule_print (rule const *r, FILE *out)
-{
-  fprintf (out, "%s:", r->lhs->tag);
-  rule_rhs_print (r, out);
-}
-
 void
 ritem_print (FILE *out)
 {
@@ -289,8 +282,8 @@ grammar_dump (FILE *out, const char *title)
     rule_number r;
     for (r = 0; r < nrules + nuseless_productions; r++)
       {
-        fprintf (out, "%-5d  ", r);
-        rule_print (&rules[r], out);
+        fprintf (out, "%-5d  %s:", r, rules[r].lhs->tag);
+        rule_rhs_print (&rules[r], out);
         fprintf (out, "\n");
       }
   }
@@ -300,24 +293,10 @@ grammar_dump (FILE *out, const char *title)
 void
 grammar_rules_useless_report (const char *message)
 {
-  warnings w = Wother;
-  if (warnings_flag & w)
-    {
-      rule_number r;
-      for (r = 0; r < nrules ; ++r)
-        if (!rules[r].useful)
-          {
-            if (feature_flag & feature_caret)
-              complain (&rules[r].location, w, "%s", message);
-            else
-              {
-                complain (&rules[r].location, w | silent, "%s: ", message);
-                rule_print (&rules[r], stderr);
-                warnings_print_categories (w);
-                fprintf (stderr, "\n");
-              }
-          }
-    }
+  rule_number r;
+  for (r = 0; r < nrules ; ++r)
+    if (!rules[r].useful)
+      complain (&rules[r].location, Wother, "%s", message);
 }
 
 void
