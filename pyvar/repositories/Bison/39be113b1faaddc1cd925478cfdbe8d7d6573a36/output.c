@@ -107,10 +107,8 @@ GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_state_number_table, state_number)
 `----------------------------------------------------------------*/
 
 static void
-quoted_output (FILE *out, char const *cp)
+output_escaped (FILE *out, const char *cp)
 {
-  fprintf (out, "[[");
-
   for (; *cp; cp++)
     switch (*cp)
       {
@@ -120,7 +118,13 @@ quoted_output (FILE *out, char const *cp)
       case ']': fputs ("@}",  out); break;
       default:  fputc (*cp,   out); break;
       }
+}
 
+static void
+output_quoted (FILE *out, char const *cp)
+{
+  fprintf (out, "[[");
+  output_escaped (out, cp);
   fprintf (out, "]]");
 }
 
@@ -132,7 +136,7 @@ quoted_output (FILE *out, char const *cp)
 static void
 string_output (FILE *out, char const *string)
 {
-  quoted_output (out, quotearg_style (c_quoting_style, string));
+  output_quoted (out, quotearg_style (c_quoting_style, string));
 }
 
 
@@ -474,6 +478,21 @@ symbol_numbers_output (FILE *out)
 | Output the user reduction actions to OUT.  |
 `-------------------------------------------*/
 
+static void
+rule_output (const rule *r, FILE *out)
+{
+  output_escaped (out, r->lhs->symbol->tag);
+  fputc (':', out);
+  if (0 <= *r->rhs)
+    for (item_number *rhsp = r->rhs; 0 <= *rhsp; ++rhsp)
+      {
+        fputc (' ', out);
+        output_escaped (out, symbols[*rhsp]->tag);
+      }
+  else
+    fputs (" %empty", out);
+}
+
 static void
 user_actions_output (FILE *out)
 {
@@ -492,9 +511,11 @@ user_actions_output (FILE *out)
             string_output (out, rules[r].action_loc.start.file);
             fprintf (out, ")dnl\n");
           }
-        fprintf (out, "[%*s%s]])\n\n",
+        fprintf (out, "[%*s%s]],\n[[",
                  rules[r].action_loc.start.column - 1, "",
                  rules[r].action);
+        rule_output (&rules[r], out);
+        fprintf (out, "]])\n\n");
       }
   fputs ("])\n\n", out);
 }
