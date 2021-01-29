@@ -38,23 +38,24 @@ extern short *lookaheads;
 extern int verboseflag;
 extern int fixed_outfiles;
 
-void initialize_conflicts PARAMS((void));
-void set_conflicts PARAMS((int));
-void resolve_sr_conflict PARAMS((int, int));
-void flush_shift PARAMS((int, int));
-void log_resolution PARAMS((int, int, int, char *));
-void conflict_log PARAMS((void));
-void verbose_conflict_log PARAMS((void));
-void total_conflicts PARAMS((void));
-void count_sr_conflicts PARAMS((int));
-void count_rr_conflicts PARAMS((int));
-void print_reductions PARAMS((int));
-void finalize_conflicts PARAMS((void));
+extern void initialize_conflicts PARAMS((void));
+extern void conflict_log PARAMS((void));
+extern void verbose_conflict_log PARAMS((void));
+extern void print_reductions PARAMS((int));
+extern void finalize_conflicts PARAMS((void));
+
+static void set_conflicts PARAMS((int));
+static void resolve_sr_conflict PARAMS((int, int));
+static void flush_shift PARAMS((int, int));
+static void log_resolution PARAMS((int, int, int, char *));
+static void total_conflicts PARAMS((void));
+static void count_sr_conflicts PARAMS((int));
+static void count_rr_conflicts PARAMS((int));
 
 char any_conflicts;
-char *conflicts;
 errs **err_table;
 int expected_conflicts;
+static char *conflicts;
 
 
 static unsigned *shiftset;
@@ -84,7 +85,7 @@ initialize_conflicts (void)
 }
 
 
-void
+static void
 set_conflicts (int state)
 {
   register int i;
@@ -170,7 +171,7 @@ It has already been checked that the rule has a precedence.
 A conflict is resolved by modifying the shift or reduce tables
 so that there is no longer a conflict.  */
 
-void
+static void
 resolve_sr_conflict (int state, int lookaheadnum)
 {
   register int i;
@@ -271,7 +272,7 @@ resolve_sr_conflict (int state, int lookaheadnum)
 /* turn off the shift recorded for the specified token in the specified state.
 Used when we resolve a shift-reduce conflict in favor of the reduction.  */
 
-void
+static void
 flush_shift (int state, int token)
 {
   register shifts *shiftp;
@@ -292,7 +293,7 @@ flush_shift (int state, int token)
 }
 
 
-void
+static void
 log_resolution (int state, int LAno, int token, char *resolution)
 {
   fprintf(foutput,
@@ -365,7 +366,7 @@ verbose_conflict_log (void)
 }
 
 
-void
+static void
 total_conflicts (void)
 {
   if (src_total == expected_conflicts && rrc_total == 0)
@@ -407,7 +408,7 @@ total_conflicts (void)
 }
 
 
-void
+static void
 count_sr_conflicts (int state)
 {
   register int i;
@@ -474,7 +475,7 @@ count_sr_conflicts (int state)
 }
 
 
-void
+static void
 count_rr_conflicts (int state)
 {
   register int i;
