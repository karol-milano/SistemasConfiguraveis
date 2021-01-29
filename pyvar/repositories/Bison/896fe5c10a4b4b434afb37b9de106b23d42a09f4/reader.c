@@ -219,7 +219,8 @@ copy_string (FILE *fin, FILE *fout, struct obstack *oout, int match)
 `----------------------------------------------------------------*/
 
 static inline void
-copy_comment2 (FILE *fin, FILE *out1, FILE *out2, struct obstack *oout)
+copy_comment2 (FILE *fin, FILE *out1,
+	       struct obstack *oout2, struct obstack *oout)
 {
   int cplus_comment;
   int ended;
@@ -228,10 +229,10 @@ copy_comment2 (FILE *fin, FILE *out1, FILE *out2, struct obstack *oout)
   /* We read a `/', output it. */
   if (out1)
     putc ('/', out1);
-  if (out2)
-    putc ('/', out2);
   if (oout)
     obstack_1grow (oout, '/');
+  if (oout2)
+    obstack_1grow (oout2, '/');
 
   switch ((c = getc (fin)))
     {
@@ -248,10 +249,10 @@ copy_comment2 (FILE *fin, FILE *out1, FILE *out2, struct obstack *oout)
 
   if (out1)
     putc (c, out1);
-  if (out2)
-    putc (c, out2);
   if (oout)
     obstack_1grow (oout, c);
+  if (oout2)
+    obstack_1grow (oout2, c);
   c = getc (fin);
 
   ended = 0;
@@ -263,10 +264,10 @@ copy_comment2 (FILE *fin, FILE *out1, FILE *out2, struct obstack *oout)
 	    {
 	      if (out1)
 		putc (c, out1);
-	      if (out2)
-		putc (c, out2);
 	      if (oout)
 		obstack_1grow (oout, c);
+	      if (oout2)
+		obstack_1grow (oout2, c);
 	      c = getc (fin);
 	    }
 
@@ -274,10 +275,10 @@ copy_comment2 (FILE *fin, FILE *out1, FILE *out2, struct obstack *oout)
 	    {
 	      if (out1)
 		putc (c, out1);
-	      if (out2)
-		putc (c, out2);
 	      if (oout)
 		obstack_1grow (oout, c);
+	      if (oout2)
+		obstack_1grow (oout2, c);
 	      ended = 1;
 	    }
 	}
@@ -286,10 +287,10 @@ copy_comment2 (FILE *fin, FILE *out1, FILE *out2, struct obstack *oout)
 	  lineno++;
 	  if (out1)
 	    putc (c, out1);
-	  if (out2)
-	    putc (c, out2);
 	  if (oout)
 	    obstack_1grow (oout, c);
+	  if (oout2)
+	    obstack_1grow (oout2, c);
 	  if (cplus_comment)
 	    ended = 1;
 	  else
@@ -301,10 +302,10 @@ copy_comment2 (FILE *fin, FILE *out1, FILE *out2, struct obstack *oout)
 	{
 	  if (out1)
 	    putc (c, out1);
-	  if (out2)
-	    putc (c, out2);
 	  if (oout)
 	    obstack_1grow (oout, c);
+	  if (oout2)
+	    obstack_1grow (oout2, c);
 	  c = getc (fin);
 	}
     }
@@ -783,16 +784,16 @@ parse_union_decl (void)
     obstack_1grow (&attrs_obstack, '\n');
 
   obstack_grow_literal_string (&attrs_obstack, "typedef union");
-  if (fdefines)
-    fprintf (fdefines, "typedef union");
+  if (defines_flag)
+    obstack_grow_literal_string (&defines_obstack, "typedef union");
 
   c = getc (finput);
 
   while (c != EOF)
     {
       obstack_1grow (&attrs_obstack, c);
-      if (fdefines)
-	putc (c, fdefines);
+      if (defines_flag)
+	obstack_grow_literal_string (&defines_obstack, c);
 
       switch (c)
 	{
@@ -801,7 +802,7 @@ parse_union_decl (void)
 	  break;
 
 	case '/':
-	  copy_comment2 (finput, 0, fdefines, &attrs_obstack);
+	  copy_comment2 (finput, 0, &defines_obstack, &attrs_obstack);
 	  break;
 
 	case '{':
@@ -815,8 +816,8 @@ parse_union_decl (void)
 	  if (count <= 0)
 	    {
 	      obstack_grow_literal_string (&attrs_obstack, " YYSTYPE;\n");
-	      if (fdefines)
-		fprintf (fdefines, " YYSTYPE;\n");
+	      if (defines_flag)
+		obstack_grow_literal_string (&defines_obstack, " YYSTYPE;\n");
 	      /* JF don't choke on trailing semi */
 	      c = skip_white_space ();
 	      if (c != ';')
@@ -1595,8 +1596,11 @@ readgram (void)
          Most programs should declare their own type anyway.  */
       obstack_grow_literal_string (&attrs_obstack,
 			    "#ifndef YYSTYPE\n#define YYSTYPE int\n#endif\n");
-      if (fdefines)
-	fprintf (fdefines, "#ifndef YYSTYPE\n#define YYSTYPE int\n#endif\n");
+      if (defines_flag)
+	obstack_grow_literal_string (&defines_obstack, "\
+#ifndef YYSTYPE\n\
+# define YYSTYPE int\n\
+#endif\n");
     }
 
   /* Report any undefined symbols and consider them nonterminals.  */
@@ -1620,7 +1624,7 @@ readgram (void)
 `--------------------------------------------------------------*/
 
 static void
-output_token_defines (FILE *file)
+output_token_defines (struct obstack *oout)
 {
   bucket *bp;
   char *cp, *symbol;
@@ -1653,14 +1657,15 @@ output_token_defines (FILE *file)
       if (c != '\0')
 	continue;
 
-      fprintf (file, "#define\t%s\t%d\n", symbol,
-	       ((translations && !raw_flag)
-		? bp->user_token_number : bp->value));
+      obstack_fgrow2 (oout, "#define\t%s\t%d\n",
+		      symbol,
+		      ((translations && !raw_flag)
+		       ? bp->user_token_number : bp->value));
       if (semantic_parser)
-	fprintf (file, "#define\tT%s\t%d\n", symbol, bp->value);
+	obstack_fgrow2 (oout, "#define\tT%s\t%d\n", symbol, bp->value);
     }
 
-  putc ('\n', file);
+  obstack_1grow (oout, '\n');
 }
 
 
@@ -1783,7 +1788,7 @@ packsymbols (void)
   error_token_number = errtoken->value;
 
   if (!no_parser_flag)
-    output_token_defines (ftable);
+    output_token_defines (&table_obstack);
 
   if (startval->class == unknown_sym)
     fatal (_("the start symbol %s is undefined"), startval->tag);
@@ -1794,15 +1799,16 @@ packsymbols (void)
 
   if (defines_flag)
     {
-      output_token_defines (fdefines);
+      output_token_defines (&defines_obstack);
 
       if (!pure_parser)
 	{
 	  if (spec_name_prefix)
-	    fprintf (fdefines, "\nextern YYSTYPE %slval;\n",
-		     spec_name_prefix);
+	    obstack_fgrow1 (&defines_obstack, "\nextern YYSTYPE %slval;\n",
+			    spec_name_prefix);
 	  else
-	    fprintf (fdefines, "\nextern YYSTYPE yylval;\n");
+	    obstack_grow_literal_string (&defines_obstack,
+					 "\nextern YYSTYPE yylval;\n");
 	}
 
       if (semantic_parser)
@@ -1810,7 +1816,8 @@ packsymbols (void)
 	  {
 	    /* don't make these for dummy nonterminals made by gensym.  */
 	    if (*tags[i] != '@')
-	      fprintf (fdefines, "#define\tNT%s\t%d\n", tags[i], i);
+	       obstack_fgrow2 (&defines_obstack,
+			       "#define\tNT%s\t%d\n", tags[i], i);
 	  }
 #if 0
       /* `fdefines' is now a temporary file, so we need to copy its
@@ -1942,16 +1949,19 @@ reader (void)
   undeftoken->class = token_sym;
   undeftoken->user_token_number = 2;
 
-  /* Read the declaration section.  Copy %{ ... %} groups to FTABLE
-     and FDEFINES file.  Also notice any %token, %left, etc. found
-     there.  */
-  putc ('\n', ftable);
-  fprintf (ftable, "\
+  /* Read the declaration section.  Copy %{ ... %} groups to
+     TABLE_OBSTACK and FDEFINES file.  Also notice any %token, %left,
+     etc. found there.  */
+  obstack_1grow (&table_obstack, '\n');
+  obstack_fgrow3 (&table_obstack, "\
 /* %s, made from %s\n\
    by GNU bison %s.  */\n\
-\n", no_parser_flag ? "Bison-generated parse tables" : "A Bison parser", infile, VERSION);
+\n",
+		  no_parser_flag ? "Bison-generated parse tables" : "A Bison parser",
+		  infile, VERSION);
 
-  fputs ("#define YYBISON 1  /* Identify Bison output.  */\n\n", ftable);
+  obstack_grow_literal_string (&table_obstack,
+		       "#define YYBISON 1  /* Identify Bison output.  */\n\n");
   read_declarations ();
   /* Start writing the guard and action files, if they are needed.  */
   output_headers ();
@@ -1960,12 +1970,12 @@ reader (void)
   readgram ();
   /* Now we know whether we need the line-number stack.  If we do,
      write its type into the .tab.h file.  */
-  if (fdefines)
-    reader_output_yylsp (fdefines);
+  if (defines_flag)
+    reader_output_yylsp (&defines_obstack);
   /* Write closing delimiters for actions and guards.  */
   output_trailers ();
   if (locations_flag)
-    fputs ("#define YYLSP_NEEDED\n\n", ftable);
+    obstack_grow_literal_string (&table_obstack, "#define YYLSP_NEEDED\n\n");
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
   packsymbols ();
@@ -1978,10 +1988,10 @@ reader (void)
 
 
 void
-reader_output_yylsp (FILE *f)
+reader_output_yylsp (struct obstack *oout)
 {
   if (locations_flag)
-    fputs ("\
+    obstack_grow_literal_string (oout, "\
 \n\
 #ifndef YYLTYPE\n\
 typedef struct yyltype\n\
@@ -1997,6 +2007,5 @@ typedef struct yyltype\n\
 \n\
 # define YYLTYPE yyltype\n\
 #endif\n\
-\n",
-	   f);
+\n");
 }
