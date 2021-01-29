@@ -114,7 +114,7 @@ static const argmatch_warning_doc argmatch_warning_docs[] =
 {
   { "conflicts-sr",     N_("S/R conflicts (enabled by default)") },
   { "conflicts-rr",     N_("R/R conflicts (enabled by default)") },
-  { "counterexample",   N_("Conflict counter examples") },
+  { "counterexamples",  N_("generate conflict counterexamples") },
   { "dangling-alias",   N_("string aliases not attached to a symbol") },
   { "deprecated",       N_("obsolete constructs") },
   { "empty-rule",       N_("empty rules without %empty") },
@@ -122,7 +122,7 @@ static const argmatch_warning_doc argmatch_warning_docs[] =
   { "precedence",       N_("useless precedence and associativity") },
   { "yacc",             N_("incompatibilities with POSIX Yacc") },
   { "other",            N_("all other warnings (enabled by default)") },
-  { "all",              N_("all the warnings except 'dangling-alias' and 'yacc'") },
+  { "all",              N_("all the warnings except 'counterexamples', 'dangling-alias' and 'yacc'") },
   { "no-CATEGORY",      N_("turn off warnings in CATEGORY") },
   { "none",             N_("turn off all the warnings") },
   { "error[=CATEGORY]", N_("treat warnings as errors") },
@@ -131,19 +131,19 @@ static const argmatch_warning_doc argmatch_warning_docs[] =
 
 static const argmatch_warning_arg argmatch_warning_args[] =
 {
-  { "all",            Wall },
-  { "conflicts-rr",   Wconflicts_rr },
-  { "conflicts-sr",   Wconflicts_sr },
-  { "counterexample", Wcounterexample },
-  { "dangling-alias", Wdangling_alias },
-  { "deprecated",     Wdeprecated },
-  { "empty-rule",     Wempty_rule },
-  { "everything",     Weverything },
-  { "midrule-values", Wmidrule_values },
-  { "none",           Wnone },
-  { "other",          Wother },
-  { "precedence",     Wprecedence },
-  { "yacc",           Wyacc },
+  { "all",             Wall },
+  { "conflicts-rr",    Wconflicts_rr },
+  { "conflicts-sr",    Wconflicts_sr },
+  { "counterexamples", Wcounterexamples }, { "cex", Wcounterexamples }, // Show cex second.
+  { "dangling-alias",  Wdangling_alias },
+  { "deprecated",      Wdeprecated },
+  { "empty-rule",      Wempty_rule },
+  { "everything",      Weverything },
+  { "midrule-values",  Wmidrule_values },
+  { "none",            Wnone },
+  { "other",           Wother },
+  { "precedence",      Wprecedence },
+  { "yacc",            Wyacc },
   { NULL, Wnone }
 };
 
