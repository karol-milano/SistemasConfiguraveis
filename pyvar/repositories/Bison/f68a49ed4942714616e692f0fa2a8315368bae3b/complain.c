@@ -63,6 +63,7 @@ static const char * const warnings_args[] =
   "conflicts-sr",
   "conflicts-rr",
   "deprecated",
+  "empty-rule",
   "precedence",
   "other",
   "all",
@@ -78,6 +79,7 @@ static const int warnings_types[] =
   Wconflicts_sr,
   Wconflicts_rr,
   Wdeprecated,
+  Wempty_rule,
   Wprecedence,
   Wother,
   Wall,