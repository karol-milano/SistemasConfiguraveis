@@ -119,7 +119,7 @@ static void
 escaped_output (FILE *out, char const *string)
 {
   char const *p;
-  fputs ("[[", out);
+  fprintf (out, "[[");
 
   for (p = quotearg_style (c_quoting_style, string); *p; p++)
     switch (*p)
@@ -131,7 +131,7 @@ escaped_output (FILE *out, char const *string)
       default: fputc (*p, out); break;
       }
 
-  fputs ("]]", out);
+  fprintf (out, "]]");
 }
 
 
@@ -302,7 +302,8 @@ user_actions_output (FILE *out)
 	fprintf (out, "]b4_syncline(%d, ",
 		 rules[r].action_location.start.line);
 	escaped_output (out, rules[r].action_location.start.file);
-	fprintf (out, ")[\n    %s\n    break;\n\n",
+	fprintf (out, ")[\n");
+	fprintf (out, "    %s\n    break;\n\n",
 		 rules[r].action);
       }
   fputs ("]])\n\n", out);
