@@ -67,9 +67,6 @@ static int gensym_count;
 
 static bucket *errtoken;
 static bucket *undeftoken;
-
-/* Nonzero if any action or guard uses the @n construct.  */
-static int yylsp_needed;
 
 
 /*===================\
@@ -256,7 +253,7 @@ copy_at (FILE *fin, FILE *fout, int stack_offset)
   if (c == '$')
     {
       fprintf (fout, "yyloc");
-      yylsp_needed = 1;
+      locations_flag = 1;
     }
   else if (isdigit (c) || c == '-')
     {
@@ -266,7 +263,7 @@ copy_at (FILE *fin, FILE *fout, int stack_offset)
       n = read_signed_integer (fin);
 
       fprintf (fout, "yylsp[%d]", n - stack_offset);
-      yylsp_needed = 1;
+      locations_flag = 1;
     }
   else
     complain (_("@%s is invalid"), printable_version (c));
@@ -284,7 +281,7 @@ copy_definition (void)
   /* -1 while reading a character if prev char was %. */
   int after_percent;
 
-  if (!nolinesflag)
+  if (!no_lines_flag)
     fprintf (fattrs, "#line %d \"%s\"\n", lineno, infile);
 
   after_percent = 0;
@@ -631,7 +628,7 @@ parse_union_decl (void)
 
   typed = 1;
 
-  if (!nolinesflag)
+  if (!no_lines_flag)
     fprintf (fattrs, "\n#line %d \"%s\"\n", lineno, infile);
   else
     fprintf (fattrs, "\n");
@@ -919,7 +916,7 @@ copy_action (symbol_list * rule, int stack_offset)
     stack_offset = 0;
 
   fprintf (faction, "\ncase %d:\n", nrules);
-  if (!nolinesflag)
+  if (!no_lines_flag)
     fprintf (faction, "#line %d \"%s\"\n", lineno, infile);
   putc ('{', faction);
 
@@ -1058,7 +1055,7 @@ copy_guard (symbol_list * rule, int stack_offset)
     stack_offset = 0;
 
   fprintf (fguard, "\ncase %d:\n", nrules);
-  if (!nolinesflag)
+  if (!no_lines_flag)
     fprintf (fguard, "#line %d \"%s\"\n", lineno, infile);
   putc ('{', fguard);
 
@@ -1303,7 +1300,7 @@ readgram (void)
     {
       if (t == IDENTIFIER || t == BAR)
 	{
-	  int actionflag = 0;
+	  int action_flag = 0;
 	  int rulelength = 0;	/* number of symbols in rhs of this rule so far  */
 	  int xactions = 0;	/* JF for error checking */
 	  bucket *first_rhs = 0;
@@ -1399,7 +1396,7 @@ readgram (void)
 	      /* If we just passed an action, that action was in the middle
 	         of a rule, so make a dummy rule to reduce it to a
 	         non-terminal.  */
-	      if (actionflag)
+	      if (action_flag)
 		{
 		  bucket *sdummy;
 
@@ -1433,7 +1430,7 @@ readgram (void)
 		  p1->next = p;
 		  p1 = p;
 
-		  actionflag = 0;
+		  action_flag = 0;
 		}
 
 	      if (t == IDENTIFIER)
@@ -1447,7 +1444,7 @@ readgram (void)
 	      else		/* handle an action.  */
 		{
 		  copy_action (crule, rulelength);
-		  actionflag = 1;
+		  action_flag = 1;
 		  xactions++;	/* JF */
 		}
 	      rulelength++;
@@ -1478,10 +1475,10 @@ readgram (void)
 	  else if (t == LEFT_CURLY)
 	    {
 	      /* This case never occurs -wjh */
-	      if (actionflag)
+	      if (action_flag)
 		complain (_("two actions at end of one rule"));
 	      copy_action (crule, rulelength);
-	      actionflag = 1;
+	      action_flag = 1;
 	      xactions++;	/* -wjh */
 	      t = lex ();
 	    }
@@ -1622,7 +1619,7 @@ output_token_defines (FILE *file)
 	continue;
 
       fprintf (file, "#define\t%s\t%d\n", symbol,
-	       ((translations && !rawtoknumflag)
+	       ((translations && !raw_flag)
 		? bp->user_token_number : bp->value));
       if (semantic_parser)
 	fprintf (file, "#define\tT%s\t%d\n", symbol, bp->value);
@@ -1750,7 +1747,7 @@ packsymbols (void)
 
   error_token_number = errtoken->value;
 
-  if (!noparserflag)
+  if (!no_parser_flag)
     output_token_defines (ftable);
 
   if (startval->class == unknown_sym)
@@ -1760,7 +1757,7 @@ packsymbols (void)
 
   start_symbol = startval->value;
 
-  if (definesflag)
+  if (defines_flag)
     {
       output_token_defines (fdefines);
 
@@ -1892,7 +1889,6 @@ reader (void)
 
   semantic_parser = 0;
   pure_parser = 0;
-  yylsp_needed = 0;
 
   grammar = NULL;
 
@@ -1918,7 +1914,7 @@ reader (void)
   fprintf (ftable, "\
 /* %s, made from %s\n\
    by GNU bison %s.  */\n\
-\n", noparserflag ? "Bison-generated parse tables" : "A Bison parser", infile, VERSION);
+\n", no_parser_flag ? "Bison-generated parse tables" : "A Bison parser", infile, VERSION);
 
   fputs ("#define YYBISON 1  /* Identify Bison output.  */\n\n", ftable);
   read_declarations ();
@@ -1933,7 +1929,7 @@ reader (void)
     reader_output_yylsp (fdefines);
   /* Write closing delimiters for actions and guards.  */
   output_trailers ();
-  if (yylsp_needed)
+  if (locations_flag)
     fputs ("#define YYLSP_NEEDED\n\n", ftable);
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
@@ -1949,26 +1945,22 @@ reader (void)
 void
 reader_output_yylsp (FILE *f)
 {
-  if (yylsp_needed)
+  if (locations_flag)
     fputs ("\
 \n\
 #ifndef YYLTYPE\n\
-typedef\n\
-  struct yyltype\n\
-\
-    {\n\
-      int timestamp;\n\
-      int first_line;\n\
-      int first_column;\
+typedef struct yyltype\n\
+{\n\
+  int timestamp;\n\
+  int first_line;\n\
+  int first_column;\
 \n\
-      int last_line;\n\
-      int last_column;\n\
-      char *text;\n\
-   }\n\
-\
-  yyltype;\n\
+  int last_line;\n\
+  int last_column;\n\
+  char *text;\n\
+} yyltype;\n\
 \n\
-#define YYLTYPE yyltype\n\
+# define YYLTYPE yyltype\n\
 #endif\n\
 \n",
 	   f);
