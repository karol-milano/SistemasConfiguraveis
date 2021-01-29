@@ -83,7 +83,7 @@ static const char * const warnings_args[] =
   0
 };
 
-static const int warnings_types[] =
+static const warnings warnings_types[] =
 {
   Wnone,
   Wmidrule_values,
@@ -114,8 +114,7 @@ warning_argmatch (char const *arg, size_t no, size_t err)
       no = !no;
     }
 
-  size_t b;
-  for (b = 0; b < warnings_size; ++b)
+  for (size_t b = 0; b < warnings_size; ++b)
     if (value & 1 << b)
       {
         if (err && no)
@@ -176,8 +175,7 @@ complain_init (void)
   warnings warnings_default =
     Wconflicts_sr | Wconflicts_rr | Wdeprecated | Wother;
 
-  size_t b;
-  for (b = 0; b < warnings_size; ++b)
+  for (size_t b = 0; b < warnings_size; ++b)
     {
       warnings_flag[b] = (1 << b & warnings_default
                           ? severity_warning
@@ -204,8 +202,7 @@ warning_severity (warnings flags)
     {
       /* Diagnostics about warnings.  */
       severity res = severity_disabled;
-      size_t b;
-      for (b = 0; b < warnings_size; ++b)
+      for (size_t b = 0; b < warnings_size; ++b)
         if (flags & 1 << b)
           {
             res = res < warnings_flag[b] ? warnings_flag[b] : res;
@@ -225,8 +222,7 @@ warning_severity (warnings flags)
 bool
 warning_is_unset (warnings flags)
 {
-  size_t b;
-  for (b = 0; b < warnings_size; ++b)
+  for (size_t b = 0; b < warnings_size; ++b)
     if (flags & 1 << b && warnings_flag[b] != severity_unset)
       return false;
   return true;
@@ -238,8 +234,7 @@ static void
 warnings_print_categories (warnings warn_flags, FILE *f)
 {
   /* Display only the first match, the second is "-Wall".  */
-  size_t i;
-  for (i = 0; warnings_args[i]; ++i)
+  for (size_t i = 0; warnings_args[i]; ++i)
     if (warn_flags & warnings_types[i])
       {
         severity s = warning_severity (warnings_types[i]);
