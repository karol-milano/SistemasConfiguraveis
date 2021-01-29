@@ -58,10 +58,13 @@ Frees itemset, ruleset and internal data.
 extern short **derives;
 extern char **tags;
 
-void set_fderives();
-void set_firsts();
+void initialize_closure PARAMS((int));
+void set_fderives PARAMS((void));
+void set_firsts PARAMS((void));
+void closure PARAMS((short *, int));
+void finalize_closure PARAMS((void));
 
-extern void RTC();
+extern void RTC PARAMS((unsigned *, int));
 
 short *itemset;
 short *itemsetend;
@@ -79,8 +82,7 @@ static int varsetsize;
 
 
 void
-initialize_closure(n)
-int n;
+initialize_closure (int n)
 {
   itemset = NEW2(n, short);
 
@@ -98,7 +100,7 @@ int n;
    the sequence of symbols 8 3 20, and one of the rules for deriving
    symbol 8 is rule 4, then the [5 - ntokens, 4] bit in fderives is set.  */
 void
-set_fderives()
+set_fderives (void)
 {
   register unsigned *rrow;
   register unsigned *vrow;
@@ -158,7 +160,7 @@ set_fderives()
    the symbol 8 can be the beginning of the data for symbol 5,
    so the bit [8 - ntokens, 5 - ntokens] in firsts is set. */
 void
-set_firsts()
+set_firsts (void)
 {
   register unsigned *row;
 /*   register int done; JF unused */
@@ -198,9 +200,7 @@ set_firsts()
 
 
 void
-closure(core, n)
-short *core;
-int n;
+closure (short *core, int n)
 {
   register int ruleno;
   register unsigned word;
@@ -282,7 +282,7 @@ int n;
 
 
 void
-finalize_closure()
+finalize_closure (void)
 {
   FREE(itemset);
   FREE(ruleset);
@@ -304,8 +304,8 @@ int n;
 }
 
 
-
-print_firsts()
+void
+print_firsts (void)
 {
   register int i;
   register int j;
@@ -326,8 +326,8 @@ print_firsts()
 }
 
 
-
-print_fderives()
+void
+print_fderives (void)
 {
   register int i;
   register int j;
