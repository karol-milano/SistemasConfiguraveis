@@ -35,14 +35,20 @@ extern unsigned *LA;
 extern short *LAruleno;
 extern short *lookaheads;
 extern int verboseflag;
-
-void set_conflicts();
-void resolve_sr_conflict();
-void flush_shift();
-void log_resolution();
-void total_conflicts();
-void count_sr_conflicts();
-void count_rr_conflicts();
+extern int fixed_outfiles;
+
+void initialize_conflicts PARAMS((void));
+void set_conflicts PARAMS((int));
+void resolve_sr_conflict PARAMS((int, int));
+void flush_shift PARAMS((int, int));
+void log_resolution PARAMS((int, int, int, char *));
+void conflict_log PARAMS((void));
+void verbose_conflict_log PARAMS((void));
+void total_conflicts PARAMS((void));
+void count_sr_conflicts PARAMS((int));
+void count_rr_conflicts PARAMS((int));
+void print_reductions PARAMS((int));
+void finalize_conflicts PARAMS((void));
 
 char any_conflicts;
 char *conflicts;
@@ -59,7 +65,7 @@ static int rrc_count;
 
 
 void
-initialize_conflicts()
+initialize_conflicts (void)
 {
   register int i;
 /*  register errs *sp; JF unused */
@@ -78,8 +84,7 @@ initialize_conflicts()
 
 
 void
-set_conflicts(state)
-int state;
+set_conflicts (int state)
 {
   register int i;
   register int k;
@@ -165,9 +170,7 @@ A conflict is resolved by modifying the shift or reduce tables
 so that there is no longer a conflict.  */
 
 void
-resolve_sr_conflict(state, lookaheadnum)
-int state;
-int lookaheadnum;
+resolve_sr_conflict (int state, int lookaheadnum)
 {
   register int i;
   register int mask;
@@ -268,9 +271,7 @@ int lookaheadnum;
 Used when we resolve a shift-reduce conflict in favor of the reduction.  */
 
 void
-flush_shift(state, token)
-int state;
-int token;
+flush_shift (int state, int token)
 {
   register shifts *shiftp;
   register int k, i;
@@ -291,9 +292,7 @@ int token;
 
 
 void
-log_resolution(state, LAno, token, resolution)
-int state, LAno, token;
-char *resolution;
+log_resolution (int state, int LAno, int token, char *resolution)
 {
   fprintf(foutput,
 	  _("Conflict in state %d between rule %d and token %s resolved as %s.\n"),
@@ -302,7 +301,7 @@ char *resolution;
 
 
 void
-conflict_log()
+conflict_log (void)
 {
   register int i;
 
@@ -325,7 +324,7 @@ conflict_log()
   
 
 void
-verbose_conflict_log()
+verbose_conflict_log (void)
 {
   register int i;
 
@@ -366,10 +365,8 @@ verbose_conflict_log()
 
 
 void
-total_conflicts()
+total_conflicts (void)
 {
-  extern int fixed_outfiles;
-
   if (src_total == expected_conflicts && rrc_total == 0)
     return;
 
@@ -410,8 +407,7 @@ total_conflicts()
 
 
 void
-count_sr_conflicts(state)
-int state;
+count_sr_conflicts (int state)
 {
   register int i;
   register int k;
@@ -478,8 +474,7 @@ int state;
 
 
 void
-count_rr_conflicts(state)
-int state;
+count_rr_conflicts (int state)
 {
   register int i;
   register int j;
@@ -525,8 +520,7 @@ int state;
 
 
 void
-print_reductions(state)
-int state;
+print_reductions (int state)
 {
   register int i;
   register int j;
@@ -745,7 +739,7 @@ int state;
 
 
 void
-finalize_conflicts()
+finalize_conflicts (void)
 {
   FREE(conflicts);
   FREE(shiftset);
