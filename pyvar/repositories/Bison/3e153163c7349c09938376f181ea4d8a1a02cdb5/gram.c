@@ -105,11 +105,10 @@ rule_rhs_print (rule *r, FILE *out)
       item_number *rp;
       for (rp = r->rhs; *rp >= 0; rp++)
         fprintf (out, " %s", symbols[*rp]->tag);
-      fputc ('\n', out);
     }
   else
     {
-      fprintf (out, " /* %s */\n", _("empty"));
+      fprintf (out, " /* %s */", _("empty"));
     }
 }
 
@@ -133,7 +132,7 @@ rule_rhs_print_xml (rule *r, FILE *out, int level)
     }
 }
 
-void
+static void
 rule_print (rule *r, FILE *out)
 {
   fprintf (out, "%s:", r->lhs->tag);
@@ -189,6 +188,7 @@ grammar_rules_partial_print (FILE *out, const char *title,
       first = false;
       rule_lhs_print (&rules[r], previous_lhs, out);
       rule_rhs_print (&rules[r], out);
+      fprintf (out, "\n");
       previous_lhs = rules[r].lhs;
     }
   if (!first)
@@ -296,6 +296,7 @@ grammar_dump (FILE *out, const char *title)
       {
         fprintf (out, "%-5d  ", r);
         rule_print (&rules[r], out);
+        fprintf (out, "\n");
       }
   }
   fprintf (out, "\n\n");
@@ -313,9 +314,10 @@ grammar_rules_useless_report (const char *message)
           {
             complain_at (rules[r].location, w, "%s: ", message);
             rule_print (&rules[r], stderr);
+            fprintf (stderr, "\n");
             fflush (stderr);
           }
-      }
+    }
 }
 
 void
