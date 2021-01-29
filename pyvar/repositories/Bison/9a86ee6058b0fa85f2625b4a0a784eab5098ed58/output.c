@@ -110,29 +110,39 @@ GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_item_number_table, item_number)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_state_number_table, state_number)
 
 
-/*--------------------------------------------------------------------.
-| Print to OUT a representation of STRING escaped both for C and M4.  |
-`--------------------------------------------------------------------*/
+/*----------------------------------------------------------------.
+| Print to OUT a representation of CP quoted and escaped for M4.  |
+`----------------------------------------------------------------*/
 
 static void
-escaped_output (FILE *out, char const *string)
+quoted_output (FILE *out, char const *cp)
 {
-  char const *p;
   fprintf (out, "[[");
 
-  for (p = quotearg_style (c_quoting_style, string); *p; p++)
-    switch (*p)
+  for (; *cp; cp++)
+    switch (*cp)
       {
       case '$': fputs ("$][", out); break;
       case '@': fputs ("@@",  out); break;
       case '[': fputs ("@{",  out); break;
       case ']': fputs ("@}",  out); break;
-      default: fputc (*p, out); break;
+      default:  fputc (*cp,   out); break;
       }
 
   fprintf (out, "]]");
 }
 
+/*----------------------------------------------------------------.
+| Print to OUT a representation of STRING quoted and escaped both |
+| for C and M4.                                                   |
+`----------------------------------------------------------------*/
+
+static void
+string_output (FILE *out, char const *string)
+{
+  quoted_output (out, quotearg_style (c_quoting_style, string));
+}
+
 
 /*------------------------------------------------------------------.
 | Prepare the muscles related to the symbols: translate, tname, and |
@@ -299,7 +309,7 @@ user_actions_output (FILE *out)
       {
 	fprintf (out, "b4_case(%d, [b4_syncline(%d, ", r + 1,
 		 rules[r].action_location.start.line);
-	escaped_output (out, rules[r].action_location.start.file);
+	string_output (out, rules[r].action_location.start.file);
 	fprintf (out, ")\n[    %s]])\n\n", rules[r].action);
       }
   fputs ("])\n\n", out);
@@ -405,12 +415,15 @@ symbol_code_props_output (FILE *out, char const *what,
              code, optional typename.  */
           fprintf (out, "%s[", sep);
           sep = ",\n";
-          escaped_output (out, loc.start.file);
+          string_output (out, loc.start.file);
           fprintf (out, ", %d, ", loc.start.line);
-          escaped_output (out, sym->tag);
+          quoted_output (out, sym->tag);
           fprintf (out, ", %d, [[%s]]", sym->number, code);
           if (sym->type_name)
-            fprintf (out, ", [[%s]]", sym->type_name);
+            {
+              fputs (", ", out);
+              quoted_output (out, sym->type_name);
+            }
           fputc (']', out);
         }
     }
