@@ -39,18 +39,20 @@ extern char any_conflicts;
 extern char *conflicts;
 extern int final_state;
 
-extern void conflict_log();
-extern void verbose_conflict_log();
-extern void print_reductions();
-
-void print_token();
-void print_state();
-void print_core();
-void print_actions();
-void print_grammar();
+extern void conflict_log PARAMS((void));
+extern void verbose_conflict_log PARAMS((void));
+extern void print_reductions PARAMS((int));
+
+void terse PARAMS((void));
+void verbose PARAMS((void));
+void print_token PARAMS((int, int));
+void print_state PARAMS((int));
+void print_core PARAMS((int));
+void print_actions PARAMS((int));
+void print_grammar PARAMS((void));
 
 void
-terse()
+terse (void)
 {
   if (any_conflicts)
     {
@@ -60,7 +62,7 @@ terse()
 
 
 void
-verbose()
+verbose (void)
 {
   register int i;
 
@@ -77,16 +79,14 @@ verbose()
 
 
 void
-print_token(extnum, token)
-int extnum, token;
+print_token (int extnum, int token)
 {
   fprintf(foutput, _(" type %d is %s\n"), extnum, tags[token]);
 }
 
 
 void
-print_state(state)
-int state;
+print_state (int state)
 {
   fprintf(foutput, _("\n\nstate %d\n\n"), state);
   print_core(state);
@@ -95,8 +95,7 @@ int state;
 
 
 void
-print_core(state)
-int state;
+print_core (int state)
 {
   register int i;
   register int k;
@@ -142,8 +141,7 @@ int state;
 
 
 void
-print_actions(state)
-int state;
+print_actions (int state)
 {
   register int i;
   register int k;
@@ -243,7 +241,7 @@ int state;
   else
 
 void
-print_grammar()
+print_grammar (void)
 {
   int i, j;
   short* rule;
