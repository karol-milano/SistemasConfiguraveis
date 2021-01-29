@@ -107,6 +107,30 @@ GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_item_number_table, item_number_t)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_state_number_table, state_number_t)
 
 
+/*----------------------------------------------------------------------.
+| Print to OUT a representation of FILENAME escaped both for C and M4.  |
+`----------------------------------------------------------------------*/
+
+static void
+escaped_file_name_output (FILE *out, char const *filename)
+{
+  char const *p;
+  fprintf (out, "[[");
+
+  for (p = quotearg_style (c_quoting_style, filename); *p; p++)
+    switch (*p)
+      {
+      case '$': fputs ("$][", out); break;
+      case '@': fputs ("@@",  out); break;
+      case '[': fputs ("@{",  out); break;
+      case ']': fputs ("@}",  out); break;
+      default: fputc (*p, out); break;
+      }
+
+  fprintf (out, "]]");
+}
+
+
 /*------------------------------------------------------------------.
 | Prepare the muscles related to the symbols: translate, tname, and |
 | toknum.                                                           |
@@ -146,14 +170,7 @@ prepare_symbols (void)
 	    j = 2;
 	  }
 
-	for (; *cp; cp++)
-	  switch (*cp)
-	    {
-	    case '[': obstack_sgrow (&format_obstack, "@<:@"); break;
-	    case ']': obstack_sgrow (&format_obstack, "@:>@"); break;
-	    default: obstack_1grow (&format_obstack, *cp); break;
-	    }
-
+	MUSCLE_OBSTACK_SGROW (&format_obstack, cp);
 	obstack_sgrow (&format_obstack, ", ");
 	j += strsize;
       }
@@ -276,10 +293,10 @@ user_actions_output (FILE *out)
       {
 	fprintf (out, "  case %d:\n", r + 1);
 
-	fprintf (out, "]b4_syncline([[%d]], [[%s]])[\n",
-		 rules[r].action_location.first_line,
-		 quotearg_style (escape_quoting_style,
-				 rules[r].action_location.file));
+	fprintf (out, "]b4_syncline([[%d]], ",
+		 rules[r].action_location.first_line);
+	escaped_file_name_output (out, rules[r].action_location.file);
+	fprintf (out, ")[\n");
 	fprintf (out, "    %s\n    break;\n\n",
 		 rules[r].action);
       }
@@ -378,10 +395,10 @@ symbol_destructors_output (FILE *out)
 	/* Filename, lineno,
 	   Symbol-name, Symbol-number,
 	   destructor, typename. */
-	fprintf (out, "%s[[[%s]], [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
-		 first ? "" : ",\n",
-		 quotearg_style (escape_quoting_style,
-				 symbol->destructor_location.file),
+	fprintf (out, "%s[",
+		 first ? "" : ",\n");
+	escaped_file_name_output (out, symbol->destructor_location.file);
+	fprintf (out, ", [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
 		 symbol->destructor_location.first_line,
 		 symbol->tag,
 		 symbol->number,
@@ -413,10 +430,10 @@ symbol_printers_output (FILE *out)
 	/* Filename, lineno,
 	   Symbol-name, Symbol-number,
 	   printer, typename. */
-	fprintf (out, "%s[[[%s]], [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
-		 first ? "" : ",\n",
-		 quotearg_style (escape_quoting_style,
-				 symbol->printer_location.file),
+	fprintf (out, "%s[",
+		 first ? "" : ",\n");
+	escaped_file_name_output (out, symbol->printer_location.file);
+	fprintf (out, ", [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
 		 symbol->printer_location.first_line,
 		 symbol->tag,
 		 symbol->number,
@@ -577,10 +594,6 @@ prepare (void)
   /* FIXME: This is wrong: the muscles should decide whether they hold
      a copy or not, but the situation is too obscure currently.  */
   MUSCLE_INSERT_STRING ("prefix", spec_name_prefix ? spec_name_prefix : "yy");
-  MUSCLE_INSERT_STRING ("output_infix", output_infix ? output_infix : "");
-  MUSCLE_INSERT_STRING ("output_prefix", short_base_name);
-  MUSCLE_INSERT_STRING ("output_parser_name", parser_file_name);
-  MUSCLE_INSERT_STRING ("output_header_name", spec_defines_file);
 
   /* User Code.  */
   obstack_1grow (&pre_prologue_obstack, 0);
@@ -598,7 +611,7 @@ prepare (void)
     }
 
   /* Parse the skeleton file and output the needed parsers.  */
-  MUSCLE_INSERT_STRING ("skeleton", skeleton);
+  MUSCLE_INSERT_C_STRING ("skeleton", skeleton);
 }
 
 
