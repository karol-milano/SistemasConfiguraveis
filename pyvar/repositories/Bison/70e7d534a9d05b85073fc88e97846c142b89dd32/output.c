@@ -1071,66 +1071,6 @@ prepare (void)
   muscle_insert ("skeleton", skeleton);
 }
 
-/*-------------------------.
-| Output the header file.  |
-`-------------------------*/
-
-static void
-header_output (void)
-{
-  FILE *out = xfopen (spec_defines_file, "w");
-  char *macro_name = compute_header_macro ();
-
-  fprintf (out, "#ifndef %s\n", macro_name);
-  fprintf (out, "# define %s\n\n", macro_name);
-
-  token_definitions_output (out);
-  fprintf (out, "\
-#ifndef YYSTYPE\n\
-typedef %s
-yystype;\n\
-# define YYSTYPE yystype\n\
-#endif\n",
-		    muscle_find ("stype"));
-
-  if (!pure_parser)
-    fprintf (out, "\nextern YYSTYPE %slval;\n",
-	     spec_name_prefix ? spec_name_prefix : "yy");
-
-  if (locations_flag)
-    {
-      fputs ("\n\n", out);
-      fprintf (out, "\
-#ifndef YYLTYPE\n\
-typedef struct yyltype\n\
-{\n\
-  int first_line;\n\
-  int first_column;\n\
-  int last_line;\n\
-  int last_column;\n\
-} yyltype;\n\
-# define YYLTYPE yyltype\n\
-#endif\n");
-      if (!pure_parser)
-	fprintf (out, "\nextern YYLTYPE %slloc;\n",
-		 spec_name_prefix ? spec_name_prefix : "yy");
-    }
-
-  if (semantic_parser)
-    {
-      int i;
-
-      for (i = ntokens; i < nsyms; i++)
-	/* don't make these for dummy nonterminals made by gensym.  */
-	if (*symbols[i]->tag != '@')
-	  fprintf (out, "# define NT%s\t%d\n", symbols[i]->tag, i);
-    }
-
-  fprintf (out, "\n#endif /* not %s */\n", macro_name);
-  free (macro_name);
-  xfclose (out);
-}
-
 
 /*----------------------------------------------------------.
 | Output the parsing tables and the parser code to ftable.  |
@@ -1155,11 +1095,6 @@ output (void)
   /* Process the selected skeleton file.  */
   output_skeleton ();
 
-  /* Output the header if needed. */
-
-  if (0)
-    header_output ();
-
   free (rules + 1);
   obstack_free (&muscle_obstack, NULL);
   obstack_free (&format_obstack, NULL);
