@@ -132,37 +132,40 @@ extern char *consistent;
 extern short *goto_map;
 extern short *from_state;
 extern short *to_state;
-
-void output_token_translations();
-void output_gram();
-void output_stos();
-void output_rule_data();
-void output_defines();
-void output_actions();
-void token_actions();
-void save_row();
-void goto_actions();
-void save_column();
-void sort_actions();
-void pack_table();
-void output_base();
-void output_table();
-void output_check();
-void output_parser();
-void output_program();
-void free_itemset();
-void free_shifts();
-void free_reductions();
-void free_itemsets();
-int action_row();
-int default_goto();
-int matching_state();
-int pack_vector();
-
-extern void berror();
-extern void fatals();
-extern char *int_to_string();
-extern void reader_output_yylsp();
+extern int lineno;
+
+void output_headers PARAMS((void));
+void output_trailers PARAMS((void));
+void output PARAMS((void));
+void output_token_translations PARAMS((void));
+void output_gram PARAMS((void));
+void output_stos PARAMS((void));
+void output_rule_data PARAMS((void));
+void output_defines PARAMS((void));
+void output_actions PARAMS((void));
+void token_actions PARAMS((void));
+void save_row PARAMS((int));
+void goto_actions PARAMS((void));
+void save_column PARAMS((int, int));
+void sort_actions PARAMS((void));
+void pack_table PARAMS((void));
+void output_base PARAMS((void));
+void output_table PARAMS((void));
+void output_check PARAMS((void));
+void output_parser PARAMS((void));
+void output_program PARAMS((void));
+void free_shifts PARAMS((void));
+void free_reductions PARAMS((void));
+void free_itemsets PARAMS((void));
+int action_row PARAMS((int));
+int default_goto PARAMS((int));
+int matching_state PARAMS((int));
+int pack_vector PARAMS((int));
+
+extern void berror PARAMS((char *));
+extern void fatals PARAMS((char *, char *));
+extern char *int_to_string PARAMS((int));
+extern void reader_output_yylsp PARAMS((FILE *));
 
 static int nvectors;
 static int nentries;
@@ -197,7 +200,7 @@ register YYLTYPE *yylsp;\n{\n  switch (n)\n{"
 
 
 void
-output_headers()
+output_headers (void)
 {
   if (semantic_parser)
     fprintf(fguard, GUARDSTR, attrsfile);
@@ -226,7 +229,7 @@ output_headers()
 
 
 void
-output_trailers()
+output_trailers (void)
 {
   if (semantic_parser)
       fprintf(fguard, "\n    }\n}\n");
@@ -243,7 +246,7 @@ output_trailers()
 
 
 void
-output()
+output (void)
 {
   int c;
 
@@ -286,7 +289,7 @@ output()
 
 
 void
-output_token_translations()
+output_token_translations (void)
 {
   register int i, j;
 /*   register short *sp; JF unused */
@@ -330,7 +333,7 @@ output_token_translations()
 
 
 void
-output_gram()
+output_gram (void)
 {
   register int i;
   register int j;
@@ -395,7 +398,7 @@ output_gram()
 
 
 void
-output_stos()
+output_stos (void)
 {
   register int i;
   register int j;
@@ -425,7 +428,7 @@ output_stos()
 
 
 void
-output_rule_data()
+output_rule_data (void)
 {
   register int i;
   register int j;
@@ -600,7 +603,7 @@ output_rule_data()
 
 
 void
-output_defines()
+output_defines (void)
 {
   fprintf(ftable, "\n\n#define\tYYFINAL\t\t%d\n", final_state);
   fprintf(ftable, "#define\tYYFLAG\t\t%d\n", MINSHORT);
@@ -612,7 +615,7 @@ output_defines()
 /* compute and output yydefact, yydefgoto, yypact, yypgoto, yytable and yycheck.  */
 
 void
-output_actions()
+output_actions (void)
 {
   nvectors = nstates + nvars;
 
@@ -649,7 +652,7 @@ output_actions()
    is saved for putting into yytable later.  */
 
 void
-token_actions()
+token_actions (void)
 {
   register int i;
   register int j;
@@ -699,8 +702,7 @@ token_actions()
    a token gets to handle it.  */
 
 int
-action_row(state)
-int state;
+action_row (int state)
 {
   register int i;
   register int j;
@@ -863,8 +865,7 @@ int state;
 
 
 void
-save_row(state)
-int state;
+save_row (int state)
 {
   register int i;
   register int count;
@@ -908,7 +909,7 @@ int state;
    is saved for putting into yytable later.  */
 
 void
-goto_actions()
+goto_actions (void)
 {
   register int i;
   register int j;
@@ -947,8 +948,7 @@ goto_actions()
 
 
 int
-default_goto(symbol)
-int symbol;
+default_goto (int symbol)
 {
   register int i;
   register int m;
@@ -985,9 +985,7 @@ int symbol;
 
 
 void
-save_column(symbol, default_state)
-int symbol;
-int default_state;
+save_column (int symbol, int default_state)
 {
   register int i;
   register int m;
@@ -1035,7 +1033,7 @@ int default_state;
    the actions and gotos information into yytable. */
 
 void
-sort_actions()
+sort_actions (void)
 {
   register int i;
   register int j;
@@ -1071,7 +1069,7 @@ sort_actions()
 
 
 void
-pack_table()
+pack_table (void)
 {
   register int i;
   register int place;
@@ -1120,8 +1118,7 @@ pack_table()
 
 
 int
-matching_state(vector)
-int vector;
+matching_state (int vector)
 {
   register int i;
   register int j;
@@ -1161,8 +1158,7 @@ int vector;
 
 
 int
-pack_vector(vector)
-int vector;
+pack_vector (int vector)
 {
   register int i;
   register int j;
@@ -1231,7 +1227,7 @@ int vector;
    and the vectors whose elements index the portion starts */
 
 void
-output_base()
+output_base (void)
 {
   register int i;
   register int j;
@@ -1282,7 +1278,7 @@ output_base()
 
 
 void
-output_table()
+output_table (void)
 {
   register int i;
   register int j;
@@ -1314,7 +1310,7 @@ output_table()
 
 
 void
-output_check()
+output_check (void)
 {
   register int i;
   register int j;
@@ -1348,7 +1344,7 @@ output_check()
 /* copy the parser code into the ftable file at the end.  */
 
 void
-output_parser()
+output_parser (void)
 {
   register int c;
 #ifdef DONTDEF
@@ -1407,7 +1403,7 @@ output_parser()
 
       /* now write out the line... */
       for (; c != '\n' && c != EOF; c = getc(fpars))
-	if (write_line)
+	if (write_line) {
 	  if (c == '$')
 	    {
 	      /* `$' in the parser file indicates where to put the actions.
@@ -1418,6 +1414,7 @@ output_parser()
 	    }
 	  else
 	    putc(c, ftable);
+	}
       if (c == EOF)
 	break;
       putc(c, ftable);
@@ -1425,10 +1422,9 @@ output_parser()
 }
 
 void
-output_program()
+output_program (void)
 {
   register int c;
-  extern int lineno;
 
   if (!nolinesflag)
     fprintf(ftable, "#line %d \"%s\"\n", lineno, infile);
@@ -1443,7 +1439,7 @@ output_program()
 
 
 void
-free_itemsets()
+free_itemsets (void)
 {
   register core *cp,*cptmp;
 
@@ -1457,7 +1453,7 @@ free_itemsets()
 
 
 void
-free_shifts()
+free_shifts (void)
 {
   register shifts *sp,*sptmp;/* JF derefrenced freed ptr */
 
@@ -1471,7 +1467,7 @@ free_shifts()
 
 
 void
-free_reductions()
+free_reductions (void)
 {
   register reductions *rp,*rptmp;/* JF fixed freed ptr */
 
