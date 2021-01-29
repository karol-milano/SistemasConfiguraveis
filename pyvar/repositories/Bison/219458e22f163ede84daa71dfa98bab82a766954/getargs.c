@@ -240,7 +240,7 @@ ARGMATCH_VERIFY (trace_args, trace_types);
 | --warnings's handling.  |
 `------------------------*/
 
-static const char * const warnings_args[] =
+const char * const warnings_args[] =
 {
   "none",
   "midrule-values",
@@ -255,7 +255,7 @@ static const char * const warnings_args[] =
   0
 };
 
-static const int warnings_types[] =
+const int warnings_types[] =
 {
   Wnone,
   Wmidrule_values,
