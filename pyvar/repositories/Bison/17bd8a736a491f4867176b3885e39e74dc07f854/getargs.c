@@ -203,16 +203,18 @@ static const char * const warnings_args[] =
 {
   /* In a series of synonyms, present the most meaningful first, so
      that argmatch_valid be more readable.  */
-  "none       - no warnings",
-  "yacc       - incompatibilities with POSIX YACC",
-  "all        - all of the above",
-  "error      - warnings are errors",
+  "none            - no warnings",
+  "midrule-values  - unset or unused midrule values",
+  "yacc            - incompatibilities with POSIX YACC",
+  "all             - all of the above",
+  "error           - warnings are errors",
   0
 };
 
 static const int warnings_types[] =
 {
   warnings_none,
+  warnings_midrule_values,
   warnings_yacc,
   warnings_all,
   warnings_error
