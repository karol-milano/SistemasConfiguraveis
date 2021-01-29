@@ -60,7 +60,7 @@ typedef\n\
 \n"
 
 /* Number of slots allocated (but not necessarily used yet) in `rline'  */
-int rline_allocated;
+static int rline_allocated;
 
 extern int definesflag;
 extern int nolinesflag;
@@ -96,38 +96,39 @@ typedef
   symbol_list;
 
 
-void reader PARAMS((void));
-void reader_output_yylsp PARAMS((FILE *));
-void read_declarations PARAMS((void));
-void copy_definition PARAMS((void));
-void parse_token_decl PARAMS((int, int));
-void parse_start_decl PARAMS((void));
-void parse_type_decl PARAMS((void));
-void parse_assoc_decl PARAMS((int));
-void parse_union_decl PARAMS((void));
-void parse_expect_decl PARAMS((void));
-char *get_type_name PARAMS((int, symbol_list *));
-void copy_guard PARAMS((symbol_list *, int));
-void parse_thong_decl PARAMS((void));
-void copy_action PARAMS((symbol_list *, int));
-bucket *gensym PARAMS((void));
-void readgram PARAMS((void));
-void record_rule_line PARAMS((void));
-void packsymbols PARAMS((void));
-void output_token_defines PARAMS((FILE *));
-void packgram PARAMS((void));
-int read_signed_integer PARAMS((FILE *));
+extern void reader PARAMS((void));
+extern void reader_output_yylsp PARAMS((FILE *));
+
+static void read_declarations PARAMS((void));
+static void copy_definition PARAMS((void));
+static void parse_token_decl PARAMS((int, int));
+static void parse_start_decl PARAMS((void));
+static void parse_type_decl PARAMS((void));
+static void parse_assoc_decl PARAMS((int));
+static void parse_union_decl PARAMS((void));
+static void parse_expect_decl PARAMS((void));
+static char *get_type_name PARAMS((int, symbol_list *));
+static void copy_guard PARAMS((symbol_list *, int));
+static void parse_thong_decl PARAMS((void));
+static void copy_action PARAMS((symbol_list *, int));
+static bucket *gensym PARAMS((void));
+static void readgram PARAMS((void));
+static void record_rule_line PARAMS((void));
+static void packsymbols PARAMS((void));
+static void output_token_defines PARAMS((FILE *));
+static void packgram PARAMS((void));
+static int read_signed_integer PARAMS((FILE *));
 
 #if 0
 static int get_type PARAMS((void));
 #endif
 
 int lineno;
-symbol_list *grammar;
-int start_flag;
-bucket *startval;
 char **tags;
 int *user_toknums;
+static symbol_list *grammar;
+static int start_flag;
+static bucket *startval;
 
 /* Nonzero if components of semantic values are used, implying
    they must be unions.  */
@@ -163,16 +164,16 @@ skip_to_char (int target)
 }
 
 
-/* Dump the string from FINPUT to FOUTPUT.  MATCH is the delimiter of
+/* Dump the string from FIN to FOUT.  MATCH is the delimiter of
    the string (either ' or ").  */
 
 static inline void
-copy_string (FILE *finput, FILE *foutput, int match)
+copy_string (FILE *fin, FILE *fout, int match)
 {
   int c;
 
-  putc (match, foutput);
-  c = getc (finput);
+  putc (match, fout);
+  c = getc (fin);
 
   while (c != match)
     {
@@ -181,27 +182,27 @@ copy_string (FILE *finput, FILE *foutput, int match)
       if (c == '\n')
 	{
 	  complain (_("unterminated string"));
-	  ungetc (c, finput);
+	  ungetc (c, fin);
 	  c = match;		/* invent terminator */
 	  continue;
 	}
 
-      putc(c, foutput);
+      putc(c, fout);
 
       if (c == '\\')
 	{
-	  c = getc (finput);
+	  c = getc (fin);
 	  if (c == EOF)
 	    fatal (_("unterminated string at end of file"));
-	  putc (c, foutput);
+	  putc (c, fout);
 	  if (c == '\n')
 	    lineno++;
 	}
 
-      c = getc(finput);
+      c = getc(fin);
     }
 
-  putc(c, foutput);
+  putc(c, fout);
 }
 
 
@@ -265,13 +266,13 @@ copy_comment2 (FILE *in, FILE *out1, FILE* out2, int c)
 }
 
 
-/* Dump the comment from FINPUT to FOUTPUT.  C is either `*' or `/',
+/* Dump the comment from FIN to FOUT.  C is either `*' or `/',
    depending upon the type of comments used.  */
 
 static inline void
-copy_comment (FILE *finput, FILE *foutput, int c)
+copy_comment (FILE *fin, FILE *fout, int c)
 {
-  copy_comment2 (finput, foutput, NULL, c);
+  copy_comment2 (fin, fout, NULL, c);
 }
 
 
@@ -364,7 +365,7 @@ reader_output_yylsp (FILE *f)
    `%' declarations, and copy the contents of any `%{ ... %}' groups
    to fattrs.  */
 
-void
+static void
 read_declarations (void)
 {
   register int c;
@@ -459,7 +460,7 @@ read_declarations (void)
 /* Copy the contents of a `%{ ... %}' into the definitions file.  The
    `%{' has already been read.  Return after reading the `%}'.  */
 
-void
+static void
 copy_definition (void)
 {
   register int c;
@@ -527,7 +528,7 @@ copy_definition (void)
 For %token, what_is is STOKEN and what_is_not is SNTERM.
 For %nterm, the arguments are reversed.  */
 
-void
+static void
 parse_token_decl (int what_is, int what_is_not)
 {
   register int token = 0;
@@ -625,7 +626,7 @@ parse_token_decl (int what_is, int what_is_not)
  it is the literal string that is output to yytname
 */
 
-void
+static void
 parse_thong_decl (void)
 {
   register int token;
@@ -687,7 +688,7 @@ parse_thong_decl (void)
 
 /* Parse what comes after %start */
 
-void
+static void
 parse_start_decl (void)
 {
   if (start_flag)
@@ -705,7 +706,7 @@ parse_start_decl (void)
 
 /* read in a %type declaration and record its information for get_type_name to access */
 
-void
+static void
 parse_type_decl (void)
 {
   register int k;
@@ -762,7 +763,7 @@ parse_type_decl (void)
 /* read in a %left, %right or %nonassoc declaration and record its information.  */
 /* assoc is either LEFT_ASSOC, RIGHT_ASSOC or NON_ASSOC.  */
 
-void
+static void
 parse_assoc_decl (int assoc)
 {
   register int k;
@@ -845,7 +846,7 @@ parse_assoc_decl (int assoc)
    where it is made into the
    definition of YYSTYPE, the type of elements of the parser value stack.  */
 
-void
+static void
 parse_union_decl (void)
 {
   register int c;
@@ -915,7 +916,7 @@ parse_union_decl (void)
 /* parse the declaration %expect N which says to expect N
    shift-reduce conflicts.  */
 
-void
+static void
 parse_expect_decl (void)
 {
   register int c;
@@ -944,29 +945,29 @@ parse_expect_decl (void)
 
 /* that's all of parsing the declaration section */
 
-/* FINPUT is pointing to a location (i.e., a `@').  Output to FOUTPUT
+/* FIN is pointing to a location (i.e., a `@').  Output to FOUT
    a reference to this location. STACK_OFFSET is the number of values
    in the current rule so far, which says where to find `$0' with
    respect to the top of the stack.  */
 static inline void
-copy_at (FILE *finput, FILE *foutput, int stack_offset)
+copy_at (FILE *fin, FILE *fout, int stack_offset)
 {
   int c;
 
-  c = getc (finput);
+  c = getc (fin);
   if (c == '$')
     {
-      fprintf (foutput, "yyloc");
+      fprintf (fout, "yyloc");
       yylsp_needed = 1;
     }
   else if (isdigit(c) || c == '-')
     {
       int n;
 
-      ungetc (c, finput);
-      n = read_signed_integer (finput);
+      ungetc (c, fin);
+      n = read_signed_integer (fin);
 
-      fprintf (foutput, "yylsp[%d]", n - stack_offset);
+      fprintf (fout, "yylsp[%d]", n - stack_offset);
       yylsp_needed = 1;
     }
   else
@@ -977,7 +978,7 @@ copy_at (FILE *finput, FILE *foutput, int stack_offset)
 /* Get the data type (alternative in the union) of the value for
    symbol n in rule rule.  */
 
-char *
+static char *
 get_type_name (int n, symbol_list *rule)
 {
   register int i;
@@ -1015,7 +1016,7 @@ get_type_name (int n, symbol_list *rule)
    respect to the top of the stack, for the simple parser in which the
    stack is not popped until after the guard is run.  */
 
-void
+static void
 copy_guard (symbol_list *rule, int stack_offset)
 {
   register int c;
@@ -1165,7 +1166,7 @@ copy_guard (symbol_list *rule, int stack_offset)
    values in the current rule so far, which says where to find `$0'
    with respect to the top of the stack.  */
 
-void
+static void
 copy_action (symbol_list *rule, int stack_offset)
 {
   register int c;
@@ -1299,7 +1300,7 @@ copy_action (symbol_list *rule, int stack_offset)
 /* generate a dummy symbol, a nonterminal,
 whose name cannot conflict with the user's names. */
 
-bucket *
+static bucket *
 gensym (void)
 {
   register bucket *sym;
@@ -1320,7 +1321,7 @@ The next symbol is the lhs of the following rule.
 All guards and actions are copied out to the appropriate files,
 labelled by the rule number they apply to.  */
 
-void
+static void
 readgram (void)
 {
   register int t;
@@ -1617,7 +1618,7 @@ readgram (void)
 }
 
 
-void
+static void
 record_rule_line (void)
 {
   /* Record each rule's source line number in rline table.  */
@@ -1686,18 +1687,19 @@ get_type (void)
    fdefines.  Set up vectors tags and sprec of names and precedences
    of symbols.  */
 
-void
+static void
 packsymbols (void)
 {
   register bucket *bp;
   register int tokno = 1;
   register int i;
   register int last_user_token_number;
+  static char DOLLAR[] = "$";
 
   /* int lossage = 0; JF set but not used */
 
   tags = NEW2(nsyms + 1, char *);
-  tags[0] = "$";
+  tags[0] = DOLLAR;
   user_toknums = NEW2(nsyms + 1, int);
   user_toknums[0] = 0;
 
@@ -1771,15 +1773,15 @@ packsymbols (void)
 
   if (translations)
     {
-      register int i;
+      register int j;
 
       token_translations = NEW2(max_user_token_number+1, short);
 
       /* initialize all entries for literal tokens to 2, the internal
 	 token number for $undefined., which represents all invalid
 	 inputs.  */
-      for (i = 0; i <= max_user_token_number; i++)
-        token_translations[i] = 2;
+      for (j = 0; j <= max_user_token_number; j++)
+        token_translations[j] = 2;
 
       for (bp = firstsymbol; bp; bp = bp->next)
         {
@@ -1839,7 +1841,7 @@ packsymbols (void)
 /* For named tokens, but not literal ones, define the name.  The value
    is the user token number.  */
 
-void
+static void
 output_token_defines (FILE *file)
 {
   bucket *bp;
@@ -1883,7 +1885,7 @@ output_token_defines (FILE *file)
 
 /* convert the rules into the representation using rrhs, rlhs and ritems.  */
 
-void
+static void
 packgram (void)
 {
   register int itemno;
@@ -1944,7 +1946,7 @@ packgram (void)
 
 /* Read a signed integer from STREAM and return its value.  */
 
-int
+static int
 read_signed_integer (FILE *stream)
 {
   register int c = getc(stream);
