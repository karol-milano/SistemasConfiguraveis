@@ -64,20 +64,23 @@ static int      nuseful_productions, nuseless_productions,
                 nuseful_nonterminals, nuseless_nonterminals;
 
 
-bool bits_equal PARAMS((BSet, BSet, int));
-int nbits PARAMS((unsigned));
-int bits_size PARAMS((BSet, int));
-void reduce_grammar PARAMS((void));
+extern void reduce_grammar PARAMS((void));
+static bool bits_equal PARAMS((BSet, BSet, int));
+static int nbits PARAMS((unsigned));
+static int bits_size PARAMS((BSet, int));
 static void useless_nonterminals PARAMS((void));
 static void inaccessable_symbols PARAMS((void));
 static void reduce_grammar_tables PARAMS((void));
 static void print_results PARAMS((void));
 static void print_notices PARAMS((void));
-void dump_grammar PARAMS((void));
+
+#if 0                           /* XXX currently unused.  */
+static void dump_grammar PARAMS((void));
+#endif
 
 
 
-bool
+static bool
 bits_equal (BSet L, BSet R, int n)
 {
   int i;
@@ -89,7 +92,7 @@ bits_equal (BSet L, BSet R, int n)
 }
 
 
-int
+static int
 nbits (unsigned i)
 {
   int count = 0;
@@ -102,7 +105,7 @@ nbits (unsigned i)
 }
 
 
-int
+static int
 bits_size (BSet S, int n)
 {
   int i, count = 0;
@@ -142,13 +145,13 @@ reduce_grammar (void)
 	   tags[start_symbol]);
 
   reduce_grammar_tables();
-  /*
+#if 0
   if (verboseflag)
     {
       fprintf(foutput, "REDUCED GRAMMAR\n\n");
       dump_grammar();
     }
-  */
+#endif
   /**/ statisticsflag = FALSE; /* someday getopts should handle this */
   if (statisticsflag == TRUE)
     fprintf(stderr,
@@ -530,7 +533,8 @@ print_results (void)
     fprintf(foutput, "\n\n");
 }
 
-void
+#if 0                           /* XXX currently unused.  */
+static void
 dump_grammar (void)
 {
   int i;
@@ -565,6 +569,7 @@ dump_grammar (void)
     }
   fprintf(foutput, "\n\n");
 }
+#endif
 
 
 static void
