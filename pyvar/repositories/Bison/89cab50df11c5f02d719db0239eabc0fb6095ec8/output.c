@@ -203,7 +203,7 @@ output_headers (void)
   if (semantic_parser)
     fprintf (fguard, GUARDSTR, attrsfile);
 
-  if (noparserflag)
+  if (no_parser_flag)
     return;
 
   fprintf (faction, (semantic_parser ? ACTSTR : ACTSTR_SIMPLE), attrsfile);
@@ -238,7 +238,7 @@ output_trailers (void)
 
   fprintf (faction, "\n");
 
-  if (noparserflag)
+  if (no_parser_flag)
     return;
 
   if (semantic_parser)
@@ -300,8 +300,8 @@ output_gram (void)
 
   /* With the ordinary parser,
      yyprhs and yyrhs are needed only for yydebug. */
-  /* With the noparser option, all tables are generated */
-  if (!semantic_parser && !noparserflag)
+  /* With the no_parser option, all tables are generated */
+  if (!semantic_parser && !no_parser_flag)
     fprintf (ftable, "\n#if YYDEBUG != 0\n");
 
   output_short_table (ftable, "yyprhs", rrhs,
@@ -332,7 +332,7 @@ output_gram (void)
 
   fprintf (ftable, "\n};\n");
 
-  if (!semantic_parser && !noparserflag)
+  if (!semantic_parser && !no_parser_flag)
     fprintf (ftable, "\n#endif\n");
 }
 
@@ -361,7 +361,7 @@ output_rule_data (void)
 
   fputs ("#endif\n\n", ftable);
 
-  if (toknumflag || noparserflag)
+  if (token_table_flag || no_parser_flag)
     {
       fprintf (ftable, "#define YYNTOKENS %d\n", ntokens);
       fprintf (ftable, "#define YYNNTS %d\n", nvars);
@@ -370,7 +370,7 @@ output_rule_data (void)
       fprintf (ftable, "#define YYMAXUTOK %d\n\n", max_user_token_number);
     }
 
-  if (!toknumflag && !noparserflag)
+  if (!token_table_flag && !no_parser_flag)
     fprintf (ftable, "\n#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)\n\n");
 
   /* Output the table of symbol names.  */
@@ -436,11 +436,11 @@ output_rule_data (void)
   /* add a NULL entry to list of tokens */
   fprintf (ftable, ", NULL\n};\n");
 
-  if (!toknumflag && !noparserflag)
+  if (!token_table_flag && !no_parser_flag)
     fprintf (ftable, "#endif\n\n");
 
   /* Output YYTOKNUM. */
-  if (toknumflag)
+  if (token_table_flag)
     {
       output_short_table (ftable, "yytoknum", user_toknums,
 			  0, 1, ntokens + 1);
@@ -1195,7 +1195,7 @@ output_parser (void)
 
       /* See if the line starts with `#line.
          If so, set write_line to 0.  */
-      if (nolinesflag)
+      if (no_lines_flag)
 	if (c == '#')
 	  {
 	    c = getc (fpars);
@@ -1254,7 +1254,7 @@ output_program (void)
 {
   int c;
 
-  if (!nolinesflag)
+  if (!no_lines_flag)
     fprintf (ftable, "#line %d \"%s\"\n", lineno, infile);
 
   c = getc (finput);
@@ -1298,7 +1298,7 @@ output (void)
 	putc (c, ftable);
     }
   reader_output_yylsp (ftable);
-  if (debugflag)
+  if (debug_flag)
     fputs ("\
 #ifndef YYDEBUG\n\
 # define YYDEBUG 1\n\
@@ -1309,7 +1309,7 @@ output (void)
   if (semantic_parser)
     fprintf (ftable, "#include \"%s\"\n", attrsfile);
 
-  if (!noparserflag)
+  if (!no_parser_flag)
     fprintf (ftable, "#include <stdio.h>\n\n");
 
   /* Make "const" do nothing if not in ANSI C.  */
@@ -1333,7 +1333,7 @@ output (void)
     output_stos ();
   output_rule_data ();
   output_actions ();
-  if (!noparserflag)
+  if (!no_parser_flag)
     output_parser ();
   output_program ();
 }
