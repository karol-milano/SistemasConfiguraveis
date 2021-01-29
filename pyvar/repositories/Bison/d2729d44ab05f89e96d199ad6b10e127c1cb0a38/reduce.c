@@ -39,6 +39,7 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 extern char   **tags;		/* reader.c */
 extern int      verboseflag;	/* getargs.c */
 static int      statisticsflag;	/* XXXXXXX */
+extern int      fixed_outfiles;
 
 #ifndef TRUE
 #define TRUE	(1)
@@ -61,21 +62,22 @@ static int      nuseful_productions, nuseless_productions,
                 nuseful_nonterminals, nuseless_nonterminals;
 
 
-static void useless_nonterminals();
-static void inaccessable_symbols();
-static void reduce_grammar_tables();
-static void print_results();
-static void print_notices();
-void dump_grammar();
+bool bits_equal PARAMS((BSet, BSet, int));
+int nbits PARAMS((unsigned));
+int bits_size PARAMS((BSet, int));
+void reduce_grammar PARAMS((void));
+static void useless_nonterminals PARAMS((void));
+static void inaccessable_symbols PARAMS((void));
+static void reduce_grammar_tables PARAMS((void));
+static void print_results PARAMS((void));
+static void print_notices PARAMS((void));
+void dump_grammar PARAMS((void));
 
-extern void fatals ();
+extern void fatals PARAMS((char *, char *));
 
 
 bool
-bits_equal (L, R, n)
-BSet L;
-BSet R;
-int n;
+bits_equal (BSet L, BSet R, int n)
 {
   int i;
 
@@ -87,8 +89,7 @@ int n;
 
 
 int
-nbits (i)
-unsigned i;
+nbits (unsigned i)
 {
   int count = 0;
 
@@ -101,9 +102,7 @@ unsigned i;
 
 
 int
-bits_size (S, n)
-BSet S;
-int n;
+bits_size (BSet S, int n)
 {
   int i, count = 0;
 
@@ -113,7 +112,7 @@ int n;
 }
 
 void
-reduce_grammar ()
+reduce_grammar (void)
 {
   bool reduced;
 
@@ -169,14 +168,12 @@ reduce_grammar ()
 
 /*
  * Another way to do this would be with a set for each production and then do
- * subset tests against N, but even for the C grammar the whole reducing
+ * subset tests against N0, but even for the C grammar the whole reducing
  * process takes only 2 seconds on my 8Mhz AT.
  */
 
 static bool
-useful_production (i, N)
-int  i;
-BSet N;
+useful_production (int i, BSet N0)
 {
   rule  r;
   short n;
@@ -188,7 +185,7 @@ BSet N;
 
   for (r = &ritem[rrhs[i]]; *r > 0; r++)
     if (ISVAR(n = *r))
-      if (!BITISSET(N, n - ntokens))
+      if (!BITISSET(N0, n - ntokens))
 	return FALSE;
   return TRUE;
 }
@@ -197,7 +194,7 @@ BSet N;
 /* Remember that rules are 1-origin, symbols are 0-origin. */
 
 static void
-useless_nonterminals ()
+useless_nonterminals (void)
 {
   BSet Np, Ns;
   int  i, n;
@@ -254,7 +251,7 @@ useless_nonterminals ()
 }
 
 static void
-inaccessable_symbols ()
+inaccessable_symbols (void)
 {
   BSet  Vp, Vs, Pp;
   int   i, n;
@@ -353,7 +350,7 @@ inaccessable_symbols ()
 }
 
 static void
-reduce_grammar_tables ()
+reduce_grammar_tables (void)
 {
 /* This is turned off because we would need to change the numbers
    in the case statements in the actions file.  */
@@ -482,7 +479,7 @@ reduce_grammar_tables ()
 }
 
 static void
-print_results ()
+print_results (void)
 {
   int   i;
 /*  short j; JF unused */
@@ -532,7 +529,7 @@ print_results ()
 }
 
 void
-dump_grammar ()
+dump_grammar (void)
 {
   int i;
   rule r;
@@ -569,10 +566,8 @@ dump_grammar ()
 
 
 static void
-print_notices ()
+print_notices (void)
 {
-  extern int fixed_outfiles;
-
   if (fixed_outfiles && nuseless_productions)
     fprintf(stderr, _("%d rules never reduced\n"), nuseless_productions);
 
