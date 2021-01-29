@@ -59,11 +59,12 @@ Frees itemset, ruleset and internal data.
 extern short **derives;
 extern char **tags;
 
-void initialize_closure PARAMS((int));
-void set_fderives PARAMS((void));
-void set_firsts PARAMS((void));
-void closure PARAMS((short *, int));
-void finalize_closure PARAMS((void));
+extern void initialize_closure PARAMS((int));
+extern void closure PARAMS((short *, int));
+extern void finalize_closure PARAMS((void));
+
+static void set_fderives PARAMS((void));
+static void set_firsts PARAMS((void));
 
 extern void RTC PARAMS((unsigned *, int));
 
@@ -81,6 +82,11 @@ static int rulesetsize;
 /* number of words required to hold a bit for each variable */
 static int varsetsize;
 
+#ifdef DEBUG
+static void print_closure PARAMS((int));
+static void print_fderives PARAMS((void));
+static void print_firsts PARAMS((void));
+#endif
 
 void
 initialize_closure (int n)
@@ -100,7 +106,7 @@ initialize_closure (int n)
    for each nonterminal.  For example, if symbol 5 can be derived as
    the sequence of symbols 8 3 20, and one of the rules for deriving
    symbol 8 is rule 4, then the [5 - ntokens, 4] bit in fderives is set.  */
-void
+static void
 set_fderives (void)
 {
   register unsigned *rrow;
@@ -164,7 +170,7 @@ set_fderives (void)
    symbol 5, so the bit [8 - ntokens, 5 - ntokens] in firsts is
    set. */
 
-void
+static void
 set_firsts (void)
 {
   register unsigned *row;
@@ -298,8 +304,8 @@ finalize_closure (void)
 
 #ifdef	DEBUG
 
-print_closure(n)
-int n;
+static void
+print_closure(int n)
 {
   register short *isp;
 
@@ -309,7 +315,7 @@ int n;
 }
 
 
-void
+static void
 print_firsts (void)
 {
   register int i;
@@ -331,7 +337,7 @@ print_firsts (void)
 }
 
 
-void
+static void
 print_fderives (void)
 {
   register int i;
