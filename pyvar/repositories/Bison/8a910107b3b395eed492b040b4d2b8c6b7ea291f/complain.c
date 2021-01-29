@@ -113,13 +113,14 @@ static const argmatch_warning_doc argmatch_warning_docs[] =
 {
   { "conflicts-sr",     N_("S/R conflicts (enabled by default)") },
   { "conflicts-rr",     N_("R/R conflicts (enabled by default)") },
+  { "dangling-alias",   N_("string aliases not attached to a symbol") },
   { "deprecated",       N_("obsolete constructs") },
   { "empty-rule",       N_("empty rules without %empty") },
   { "midrule-values",   N_("unset or unused midrule values") },
   { "precedence",       N_("useless precedence and associativity") },
   { "yacc",             N_("incompatibilities with POSIX Yacc") },
   { "other",            N_("all other warnings (enabled by default)") },
-  { "all",              N_("all the warnings except 'yacc'") },
+  { "all",              N_("all the warnings except 'dangling-alias' and 'yacc'") },
   { "no-CATEGORY",      N_("turn off warnings in CATEGORY") },
   { "none",             N_("turn off all the warnings") },
   { "error[=CATEGORY]", N_("treat warnings as errors") },
@@ -128,17 +129,18 @@ static const argmatch_warning_doc argmatch_warning_docs[] =
 
 static const argmatch_warning_arg argmatch_warning_args[] =
 {
-  { "none",           Wnone },
-  { "midrule-values", Wmidrule_values },
-  { "yacc",           Wyacc },
-  { "conflicts-sr",   Wconflicts_sr },
+  { "all",            Wall },
   { "conflicts-rr",   Wconflicts_rr },
+  { "conflicts-sr",   Wconflicts_sr },
+  { "dangling-alias", Wdangling_alias },
   { "deprecated",     Wdeprecated },
   { "empty-rule",     Wempty_rule },
-  { "precedence",     Wprecedence },
-  { "other",          Wother },
-  { "all",            Wall },
   { "everything",     Weverything },
+  { "midrule-values", Wmidrule_values },
+  { "none",           Wnone },
+  { "other",          Wother },
+  { "precedence",     Wprecedence },
+  { "yacc",           Wyacc },
   { NULL, Wnone }
 };
 
