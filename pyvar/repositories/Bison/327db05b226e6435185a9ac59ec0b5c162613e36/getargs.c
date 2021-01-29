@@ -61,8 +61,8 @@ bool glr_parser = false;
 
 int report_flag = report_none;
 int trace_flag = trace_none;
-int warnings_flag = warnings_conflicts_sr | warnings_conflicts_rr
-                    | warnings_other;
+int warnings_flag = Wconflicts_sr | Wconflicts_rr
+                    | Wother;
 
 static struct bison_language const valid_languages[] = {
   { "c", "c-skel.m4", ".c", ".h", true },
@@ -129,15 +129,15 @@ flags_argmatch (const char *option,
  *
  *  \param FlagName  the flag familly to update.
  *  \param Args      the effective sub arguments to decode.
+ *  \param All       the "all" value.
  *
  *  \arg FlagName_args   the list of keys.
  *  \arg FlagName_types  the list of values.
- *  \arg FlagName_all    the all value.
  *  \arg FlagName_flag   the flag to update.
  */
-#define FLAGS_ARGMATCH(FlagName, Args)                                  \
+#define FLAGS_ARGMATCH(FlagName, Args, All)                             \
   flags_argmatch ("--" #FlagName, FlagName ## _args, FlagName ## _types, \
-                  FlagName ## _all, &FlagName ## _flag, Args)
+                  All, &FlagName ## _flag, Args)
 
 
 /*----------------------.
@@ -241,14 +241,14 @@ static const char * const warnings_args[] =
 
 static const int warnings_types[] =
 {
-  warnings_none,
-  warnings_midrule_values,
-  warnings_yacc,
-  warnings_conflicts_sr,
-  warnings_conflicts_rr,
-  warnings_other,
-  warnings_all,
-  warnings_error
+  Wnone,
+  Wmidrule_values,
+  Wyacc,
+  Wconflicts_sr,
+  Wconflicts_rr,
+  Wother,
+  Wall,
+  Werror
 };
 
 ARGMATCH_VERIFY (warnings_args, warnings_types);
@@ -584,7 +584,7 @@ getargs (int argc, char *argv[])
         break;
 
       case 'T':
-        FLAGS_ARGMATCH (trace, optarg);
+        FLAGS_ARGMATCH (trace, optarg, trace_all);
         break;
 
       case 'V':
@@ -592,7 +592,7 @@ getargs (int argc, char *argv[])
         exit (EXIT_SUCCESS);
 
       case 'W':
-        FLAGS_ARGMATCH (warnings, optarg);
+        FLAGS_ARGMATCH (warnings, optarg, Wall);
         break;
 
       case 'b':
@@ -638,7 +638,7 @@ getargs (int argc, char *argv[])
         break;
 
       case 'r':
-        FLAGS_ARGMATCH (report, optarg);
+        FLAGS_ARGMATCH (report, optarg, report_all);
         break;
 
       case 't':
