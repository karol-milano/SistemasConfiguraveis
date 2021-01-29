@@ -106,8 +106,11 @@ print_core (FILE *out, state *s)
       for (sp = rules[r].rhs; sp < sp1; sp++)
         fprintf (out, " %s", symbols[*sp]->tag);
       fputs (" .", out);
-      for (/* Nothing */; *sp >= 0; ++sp)
-        fprintf (out, " %s", symbols[*sp]->tag);
+      if (0 <= *rules[r].rhs)
+        for (/* Nothing */; 0 <= *sp; ++sp)
+          fprintf (out, " %s", symbols[*sp]->tag);
+      else
+        fprintf (out, " %%empty");
 
       /* Display the lookahead tokens?  */
       if (report_flag & report_lookahead_tokens
