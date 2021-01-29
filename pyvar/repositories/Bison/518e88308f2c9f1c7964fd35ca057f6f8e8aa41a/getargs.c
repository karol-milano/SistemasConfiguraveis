@@ -218,6 +218,7 @@ static const char * const warnings_args[] =
   "yacc            - incompatibilities with POSIX Yacc",
   "conflicts-sr    - S/R conflicts",
   "conflicts-rr    - R/R conflicts",
+  "deprecated      - obsolete constructs",
   "other           - all other warnings",
   "all             - all of the above",
   "error           - warnings are errors",
@@ -231,6 +232,7 @@ static const int warnings_types[] =
   Wyacc,
   Wconflicts_sr,
   Wconflicts_rr,
+  Wdeprecated,
   Wother,
   Wall,
   Werror
