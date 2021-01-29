@@ -2988,6 +2988,7 @@ handle_pure_parser (location const *loc, char const *directive)
 static int
 str_to_version (char const *version)
 {
+  IGNORE_TYPE_LIMITS_BEGIN
   int res = 0;
   errno = 0;
   char *cp = NULL;
@@ -3004,6 +3005,7 @@ str_to_version (char const *version)
       || INT_ADD_WRAPV (minor, res, &res))
     return -1;
 
+  IGNORE_TYPE_LIMITS_END
   return res;
 }
 
