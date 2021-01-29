@@ -114,6 +114,7 @@ static const argmatch_warning_doc argmatch_warning_docs[] =
 {
   { "conflicts-sr",     N_("S/R conflicts (enabled by default)") },
   { "conflicts-rr",     N_("R/R conflicts (enabled by default)") },
+  { "counterexample",   N_("Conflict counter examples") },
   { "dangling-alias",   N_("string aliases not attached to a symbol") },
   { "deprecated",       N_("obsolete constructs") },
   { "empty-rule",       N_("empty rules without %empty") },
@@ -133,6 +134,7 @@ static const argmatch_warning_arg argmatch_warning_args[] =
   { "all",            Wall },
   { "conflicts-rr",   Wconflicts_rr },
   { "conflicts-sr",   Wconflicts_sr },
+  { "counterexample", Wcounterexample },
   { "dangling-alias", Wdangling_alias },
   { "deprecated",     Wdeprecated },
   { "empty-rule",     Wempty_rule },
