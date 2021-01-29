@@ -491,18 +491,14 @@ void
 muscle_percent_define_ensure (char const *variable, location loc,
                               bool value)
 {
-  char const *val = value ? "" : "false";
   char const *name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
+  char const *val = value ? "" : "false";
 
-  /* %pure-parser is deprecated in favor of '%define api.pure', so use
-     '%define api.pure' in a backward-compatible manner here.  First,
-     don't complain if %pure-parser is specified multiple times.  */
+  /* Don't complain is VARIABLE is already defined, but be sure to set
+     its value to VAL.  */
   if (!muscle_find_const (name))
     muscle_percent_define_insert (variable, loc, val,
                                   MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
-  /* In all cases, use api.pure now so that the backend doesn't complain if
-     the skeleton ignores api.pure, but do warn now if there's a previous
-     conflicting definition from an actual %define.  */
   if (muscle_percent_define_flag_if (variable) != value)
     muscle_percent_define_insert (variable, loc, val,
                                   MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
