@@ -567,6 +567,54 @@ guards_output (FILE *out, size_t *line)
 }
 
 
+/*---------------------------------------.
+| Output the tokens definition to OOUT.  |
+`---------------------------------------*/
+
+static void
+token_definitions_output (FILE *out, size_t *line)
+{
+  int i;
+  for (i = 0; i < ntokens; ++i)
+    {
+      bucket *symbol = symbols[i];
+      int number = symbol->user_token_number;
+
+      if (number == SALIAS)
+	continue;
+      /* Skip error token.  */
+      if (symbol->value == error_token_number)
+	continue;
+      if (symbol->tag[0] == '\'')
+	continue;               /* skip literal character */
+      if (symbol->tag[0] == '\"')
+	{
+	  /* use literal string only if given a symbol with an alias */
+	  if (symbol->alias)
+	    symbol = symbol->alias;
+	  else
+	    continue;
+	}
+
+      /* Don't #define nonliteral tokens whose names contain periods
+	 or '$' (as does the default value of the EOF token).  */
+      if (strchr (symbol->tag, '.') || strchr (symbol->tag, '$'))
+	continue;
+
+      fprintf (out, "# define %s\t%d\n",
+	       symbol->tag, number);
+      ++*line;
+      if (semantic_parser)
+	{
+	  /* FIXME: This is probably wrong, and should be just as
+	     above. --akim.  */
+	  fprintf (out, "# define T%s\t%d\n", symbol->tag, symbol->value);
+	  ++*line;
+	}
+    }
+}
+
+
 static void
 save_column (int symbol, int default_state)
 {
@@ -963,6 +1011,8 @@ output_parser (const char *skel_filename, FILE *out)
 	    guards_output (out, &output_line);
 	  else if (!strcmp (muscle_key, "line"))
 	    fprintf (out, "%d", output_line);
+	  else if (!strcmp (muscle_key, "tokendef"))
+	    token_definitions_output (out, &output_line);
 	  else if (!strcmp (muscle_key, "skeleton-line"))
 	    fprintf (out, "%d", skeleton_line);
 	  else if (muscle_value)
@@ -1059,13 +1109,14 @@ prepare (void)
 static void
 header_output (void)
 {
+  size_t dummy_line;
   FILE *out = xfopen (spec_defines_file, "w");
   char *macro_name = compute_header_macro ();
 
   fprintf (out, "#ifndef %s\n", macro_name);
   fprintf (out, "# define %s\n\n", macro_name);
 
-  fputs (muscle_find ("tokendef"), out);
+  token_definitions_output (out, &dummy_line);
   fprintf (out, "\
 #ifndef YYSTYPE\n\
 typedef %s
