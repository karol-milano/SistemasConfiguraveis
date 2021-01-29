@@ -63,7 +63,8 @@ bool glr_parser = false;
 
 int report_flag = report_none;
 int trace_flag = trace_none;
-int warnings_flag = warnings_other;
+int warnings_flag = warnings_conflicts_sr | warnings_conflicts_rr
+                    | warnings_other;
 
 static struct bison_language const valid_languages[] = {
   { "c", "c-skel.m4", ".c", ".h", true },
@@ -234,6 +235,8 @@ static const char * const warnings_args[] =
   "none            - no warnings",
   "midrule-values  - unset or unused midrule values",
   "yacc            - incompatibilities with POSIX Yacc",
+  "conflicts-sr    - S/R conflicts",
+  "conflicts-rr    - R/R conflicts",
   "other           - all other warnings",
   "all             - all of the above",
   "error           - warnings are errors",
@@ -245,6 +248,8 @@ static const int warnings_types[] =
   warnings_none,
   warnings_midrule_values,
   warnings_yacc,
+  warnings_conflicts_sr,
+  warnings_conflicts_rr,
   warnings_other,
   warnings_all,
   warnings_error
@@ -335,6 +340,8 @@ Output:\n\
 Warning categories include:\n\
   `midrule-values'  unset or unused midrule values\n\
   `yacc'            incompatibilities with POSIX Yacc\n\
+  `conflicts-sr'    S/R conflicts (enabled by default)\n\
+  `conflicts-rr'    R/R conflicts (enabled by default)\n\
   `other'           all other warnings (enabled by default)\n\
   `all'             all the warnings\n\
   `no-CATEGORY'     turn off warnings in CATEGORY\n\
