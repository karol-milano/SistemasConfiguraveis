@@ -252,6 +252,7 @@ static const char * const warnings_args[] =
   "conflicts-sr    - S/R conflicts",
   "conflicts-rr    - R/R conflicts",
   "deprecated      - obsolete constructs",
+  "precedence      - useless precedence and associativity",
   "other           - all other warnings",
   "all             - all of the above",
   "error           - warnings are errors",
@@ -266,6 +267,7 @@ static const int warnings_types[] =
   Wconflicts_sr,
   Wconflicts_rr,
   Wdeprecated,
+  Wprecedence,
   Wother,
   Wall,
   Werror
@@ -381,6 +383,7 @@ Warning categories include:\n\
   `conflicts-sr'      S/R conflicts (enabled by default)\n\
   `conflicts-rr'      R/R conflicts (enabled by default)\n\
   `deprecated'        obsolete constructs\n\
+  `precedence'        useless precedence and associativity\n\
   `other'             all other warnings (enabled by default)\n\
   `all'               all the warnings\n\
   `no-CATEGORY'       turn off warnings in CATEGORY\n\
