@@ -249,7 +249,7 @@ prepare_tokens (void)
 	   SYMBOL_TAG_GET uses slot 0.  */
 	const char *cp =
 	  quotearg_n_style (1, c_quoting_style,
-			    symbol_tag_get (symbols[i]));
+			    symbols[i]->tag);
 	/* Width of the next token, including the two quotes, the coma
 	   and the space.  */
 	int strsize = strlen (cp) + 2;
@@ -745,7 +745,7 @@ symbol_destructors_output (FILE *out)
 	fprintf (out, "%s[[[%s]], [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
 		 first ? "" : ",\n",
 		 infile, symbol->destructor_location.first_line,
-		 symbol_tag_get (symbol),
+		 symbol->tag,
 		 symbol->number,
 		 symbol->destructor,
 		 symbol->type_name);
@@ -778,7 +778,7 @@ symbol_printers_output (FILE *out)
 	fprintf (out, "%s[[[%s]], [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
 		 first ? "" : ",\n",
 		 infile, symbol->printer_location.first_line,
-		 symbol_tag_get (symbol),
+		 symbol->tag,
 		 symbol->number,
 		 symbol->printer,
 		 symbol->type_name);
@@ -1196,9 +1196,9 @@ m4_invoke (const char *definitions)
   if (!skel_in)
     error (EXIT_FAILURE, errno, "cannot run m4");
   skel_lex ();
-
 }
 
+
 /*---------------------------.
 | Call the skeleton parser.  |
 `---------------------------*/
