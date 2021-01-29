@@ -176,9 +176,7 @@ prepare_symbols (void)
 	obstack_1grow (&format_obstack, ',');
 	j += width;
       }
-    /* Add a NULL entry to list of tokens (well, 0, as NULL might not be
-       defined).  */
-    obstack_sgrow (&format_obstack, " 0");
+    obstack_sgrow (&format_obstack, " ]b4_null[");
 
     /* Finish table and store. */
     obstack_1grow (&format_obstack, 0);
@@ -290,20 +288,16 @@ user_actions_output (FILE *out)
 {
   rule_number r;
 
-  fputs ("m4_define([b4_actions], \n[[", out);
+  fputs ("m4_define([b4_actions], \n[", out);
   for (r = 0; r < nrules; ++r)
     if (rules[r].action)
       {
-	fprintf (out, "  case %d:\n", r + 1);
-
-	fprintf (out, "]b4_syncline(%d, ",
+	fprintf (out, "b4_case(%d, [b4_syncline(%d, ", r + 1,
 		 rules[r].action_location.start.line);
 	escaped_output (out, rules[r].action_location.start.file);
-	fprintf (out, ")[\n");
-	fprintf (out, "    %s\n    break;\n\n",
-		 rules[r].action);
+	fprintf (out, ")\n[    %s]])\n\n", rules[r].action);
       }
-  fputs ("]])\n\n", out);
+  fputs ("])\n\n", out);
 }
 
 /*--------------------------------------.
