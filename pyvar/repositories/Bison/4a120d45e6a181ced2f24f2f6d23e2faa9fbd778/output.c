@@ -135,35 +135,36 @@ extern short *goto_map;
 extern short *from_state;
 extern short *to_state;
 
-void output_headers PARAMS((void));
-void output_trailers PARAMS((void));
-void output PARAMS((void));
-void output_token_translations PARAMS((void));
-void output_gram PARAMS((void));
-void output_stos PARAMS((void));
-void output_rule_data PARAMS((void));
-void output_defines PARAMS((void));
-void output_actions PARAMS((void));
-void token_actions PARAMS((void));
-void save_row PARAMS((int));
-void goto_actions PARAMS((void));
-void save_column PARAMS((int, int));
-void sort_actions PARAMS((void));
-void pack_table PARAMS((void));
-void output_base PARAMS((void));
-void output_table PARAMS((void));
-void output_check PARAMS((void));
-void output_parser PARAMS((void));
-void output_program PARAMS((void));
-void free_shifts PARAMS((void));
-void free_reductions PARAMS((void));
-void free_itemsets PARAMS((void));
-int action_row PARAMS((int));
-int default_goto PARAMS((int));
-int matching_state PARAMS((int));
-int pack_vector PARAMS((int));
-
-extern void berror PARAMS((char *));
+extern void output_headers PARAMS((void));
+extern void output_trailers PARAMS((void));
+extern void output PARAMS((void));
+
+static void output_token_translations PARAMS((void));
+static void output_gram PARAMS((void));
+static void output_stos PARAMS((void));
+static void output_rule_data PARAMS((void));
+static void output_defines PARAMS((void));
+static void output_actions PARAMS((void));
+static void token_actions PARAMS((void));
+static void save_row PARAMS((int));
+static void goto_actions PARAMS((void));
+static void save_column PARAMS((int, int));
+static void sort_actions PARAMS((void));
+static void pack_table PARAMS((void));
+static void output_base PARAMS((void));
+static void output_table PARAMS((void));
+static void output_check PARAMS((void));
+static void output_parser PARAMS((void));
+static void output_program PARAMS((void));
+static void free_shifts PARAMS((void));
+static void free_reductions PARAMS((void));
+static void free_itemsets PARAMS((void));
+static int action_row PARAMS((int));
+static int default_goto PARAMS((int));
+static int matching_state PARAMS((int));
+static int pack_vector PARAMS((int));
+
+extern void berror PARAMS((const char *));
 extern void reader_output_yylsp PARAMS((FILE *));
 
 static int nvectors;
@@ -287,7 +288,7 @@ output (void)
 }
 
 
-void
+static void
 output_token_translations (void)
 {
   register int i, j;
@@ -331,7 +332,7 @@ output_token_translations (void)
 }
 
 
-void
+static void
 output_gram (void)
 {
   register int i;
@@ -396,7 +397,7 @@ output_gram (void)
 }
 
 
-void
+static void
 output_stos (void)
 {
   register int i;
@@ -426,7 +427,7 @@ output_stos (void)
 }
 
 
-void
+static void
 output_rule_data (void)
 {
   register int i;
@@ -612,7 +613,7 @@ static const short yyr2[] = {     0", ftable);
 }
 
 
-void
+static void
 output_defines (void)
 {
   fprintf(ftable, "\n\n#define\tYYFINAL\t\t%d\n", final_state);
@@ -624,7 +625,7 @@ output_defines (void)
 
 /* compute and output yydefact, yydefgoto, yypact, yypgoto, yytable and yycheck.  */
 
-void
+static void
 output_actions (void)
 {
   nvectors = nstates + nvars;
@@ -662,7 +663,7 @@ output_actions (void)
    The yydefact table is output now.  The detailed info is saved for
    putting into yytable later.  */
 
-void
+static void
 token_actions (void)
 {
   register int i;
@@ -713,7 +714,7 @@ token_actions (void)
    rules considered lower-numbered rules last, and the last rule
    considered that likes a token gets to handle it.  */
 
-int
+static int
 action_row (int state)
 {
   register int i;
@@ -882,7 +883,7 @@ action_row (int state)
 }
 
 
-void
+static void
 save_row (int state)
 {
   register int i;
@@ -926,7 +927,7 @@ save_row (int state)
    The yydefgoto table is output now.  The detailed info
    is saved for putting into yytable later.  */
 
-void
+static void
 goto_actions (void)
 {
   register int i;
@@ -965,7 +966,7 @@ goto_actions (void)
 
 
 
-int
+static int
 default_goto (int symbol)
 {
   register int i;
@@ -1002,7 +1003,7 @@ default_goto (int symbol)
 }
 
 
-void
+static void
 save_column (int symbol, int default_state)
 {
   register int i;
@@ -1050,7 +1051,7 @@ save_column (int symbol, int default_state)
 /* The next few functions decide how to pack the actions and gotos
    information into yytable. */
 
-void
+static void
 sort_actions (void)
 {
   register int i;
@@ -1086,7 +1087,7 @@ sort_actions (void)
 }
 
 
-void
+static void
 pack_table (void)
 {
   register int i;
@@ -1135,7 +1136,7 @@ pack_table (void)
 
 
 
-int
+static int
 matching_state (int vector)
 {
   register int i;
@@ -1175,7 +1176,7 @@ matching_state (int vector)
 
 
 
-int
+static int
 pack_vector (int vector)
 {
   register int i;
@@ -1244,7 +1245,7 @@ pack_vector (int vector)
 /* the following functions output yytable, yycheck
    and the vectors whose elements index the portion starts */
 
-void
+static void
 output_base (void)
 {
   register int i;
@@ -1295,7 +1296,7 @@ output_base (void)
 }
 
 
-void
+static void
 output_table (void)
 {
   register int i;
@@ -1327,7 +1328,7 @@ output_table (void)
 }
 
 
-void
+static void
 output_check (void)
 {
   register int i;
@@ -1361,7 +1362,7 @@ output_check (void)
 
 /* copy the parser code into the ftable file at the end.  */
 
-void
+static void
 output_parser (void)
 {
   register int c;
@@ -1439,7 +1440,7 @@ output_parser (void)
     }
 }
 
-void
+static void
 output_program (void)
 {
   register int c;
@@ -1456,7 +1457,7 @@ output_program (void)
 }
 
 
-void
+static void
 free_itemsets (void)
 {
   register core *cp,*cptmp;
@@ -1471,7 +1472,7 @@ free_itemsets (void)
 }
 
 
-void
+static void
 free_shifts (void)
 {
   register shifts *sp,*sptmp;/* JF derefrenced freed ptr */
@@ -1486,7 +1487,7 @@ free_shifts (void)
 }
 
 
-void
+static void
 free_reductions (void)
 {
   register reductions *rp,*rptmp;/* JF fixed freed ptr */
