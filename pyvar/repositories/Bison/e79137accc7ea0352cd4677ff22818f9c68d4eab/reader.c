@@ -283,11 +283,12 @@ reader (void)
   startval = NULL;  /* start symbol not specified yet. */
 
 #if 0
-  translations = 0;  /* initially assume token number translation not needed.  */
+  /* initially assume token number translation not needed.  */
+  translations = 0;
 #endif
-  /* Nowadays translations is always set to 1,
-     since we give `error' a user-token-number
-     to satisfy the Posix demand for YYERRCODE==256.  */
+  /* Nowadays translations is always set to 1, since we give `error' a
+     user-token-number to satisfy the Posix demand for YYERRCODE==256.
+     */
   translations = 1;
 
   nsyms = 1;
@@ -295,7 +296,7 @@ reader (void)
   nrules = 0;
   nitems = 0;
   rline_allocated = 10;
-  rline = NEW2(rline_allocated, short);
+  rline = NEW2 (rline_allocated, short);
 
   typed = 0;
   lastprec = 0;
@@ -308,50 +309,56 @@ reader (void)
 
   grammar = NULL;
 
-  init_lex();
+  init_lex ();
   lineno = 1;
 
-  /* initialize the symbol table.  */
-  tabinit();
-  /* construct the error token */
-  errtoken = getsym("error");
+  /* Initialize the symbol table.  */
+  tabinit ();
+  /* Construct the error token */
+  errtoken = getsym ("error");
   errtoken->class = STOKEN;
-  errtoken->user_token_number = 256; /* Value specified by posix.  */
-  /* construct a token that represents all undefined literal tokens. */
-  /* it is always token number 2.  */
-  undeftoken = getsym("$undefined.");
+  errtoken->user_token_number = 256; /* Value specified by POSIX.  */
+  /* Construct a token that represents all undefined literal tokens.
+     It is always token number 2.  */
+  undeftoken = getsym ("$undefined.");
   undeftoken->class = STOKEN;
   undeftoken->user_token_number = 2;
-  /* Read the declaration section.  Copy %{ ... %} groups to ftable and fdefines file.
-     Also notice any %token, %left, etc. found there.  */
-  if (noparserflag)
-    fprintf(ftable, "\n/*  Bison-generated parse tables, made from %s\n",
-		infile);
-  else
-    fprintf(ftable, "\n/*  A Bison parser, made from %s\n", infile);
-  fprintf(ftable, "    by %s  */\n\n", VERSION_STRING);
-  fprintf(ftable, "#define YYBISON 1  /* Identify Bison output.  */\n\n");
-  read_declarations();
-  /* start writing the guard and action files, if they are needed.  */
-  output_headers();
-  /* read in the grammar, build grammar in list form.  write out guards and actions.  */
-  readgram();
-  /* Now we know whether we need the line-number stack.
-     If we do, write its type into the .tab.h file.  */
+
+  /* Read the declaration section.  Copy %{ ... %} groups to FTABLE
+     and FDEFINES file.  Also notice any %token, %left, etc. found
+     there.  */
+  putc ('\n', ftable);
+  fprintf (ftable, "\
+/* %s, made from %s\n\
+   by GNU bison %s.  */\n\
+\n",
+	   noparserflag ? "Bison-generated parse tables" : "A Bison parser",
+	   infile,
+	   VERSION);
+
+  fputs ("#define YYBISON 1  /* Identify Bison output.  */\n\n", ftable);
+  read_declarations ();
+  /* Start writing the guard and action files, if they are needed.  */
+  output_headers ();
+  /* Read in the grammar, build grammar in list form.  Write out
+     guards and actions.  */
+  readgram ();
+  /* Now we know whether we need the line-number stack.  If we do,
+     write its type into the .tab.h file.  */
   if (fdefines)
-    reader_output_yylsp(fdefines);
-  /* write closing delimiters for actions and guards.  */
-  output_trailers();
+    reader_output_yylsp (fdefines);
+  /* Write closing delimiters for actions and guards.  */
+  output_trailers ();
   if (yylsp_needed)
-    fprintf(ftable, "#define YYLSP_NEEDED\n\n");
-  /* assign the symbols their symbol numbers.
-     Write #defines for the token symbols into fdefines if requested.  */
-  packsymbols();
-  /* convert the grammar into the format described in gram.h.  */
-  packgram();
-  /* free the symbol table data structure
-     since symbols are now all referred to by symbol number.  */
-  free_symtab();
+    fprintf ("#define YYLSP_NEEDED\n\n", ftable);
+  /* Assign the symbols their symbol numbers.  Write #defines for the
+     token symbols into FDEFINES if requested.  */
+  packsymbols ();
+  /* Convert the grammar into the format described in gram.h.  */
+  packgram ();
+  /* Free the symbol table data structure since symbols are now all
+     referred to by symbol number.  */
+  free_symtab ();
 }
 
 void
