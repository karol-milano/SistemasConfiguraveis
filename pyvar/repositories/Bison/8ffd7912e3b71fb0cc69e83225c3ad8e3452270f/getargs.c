@@ -63,7 +63,7 @@ bool glr_parser = false;
 
 int report_flag = report_none;
 int trace_flag = trace_none;
-int warnings_flag = warnings_none;
+int warnings_flag = warnings_other;
 
 static struct bison_language const valid_languages[] = {
   { "c", "c-skel.m4", ".c", ".h", true },
@@ -234,6 +234,7 @@ static const char * const warnings_args[] =
   "none            - no warnings",
   "midrule-values  - unset or unused midrule values",
   "yacc            - incompatibilities with POSIX Yacc",
+  "other           - all other warnings",
   "all             - all of the above",
   "error           - warnings are errors",
   0
@@ -244,6 +245,7 @@ static const int warnings_types[] =
   warnings_none,
   warnings_midrule_values,
   warnings_yacc,
+  warnings_other,
   warnings_all,
   warnings_error
 };
@@ -333,6 +335,7 @@ Output:\n\
 Warning categories include:\n\
   `midrule-values'  unset or unused midrule values\n\
   `yacc'            incompatibilities with POSIX Yacc\n\
+  `other'           all other warnings (enabled by default)\n\
   `all'             all the warnings\n\
   `no-CATEGORY'     turn off warnings in CATEGORY\n\
   `none'            turn off all the warnings\n\
