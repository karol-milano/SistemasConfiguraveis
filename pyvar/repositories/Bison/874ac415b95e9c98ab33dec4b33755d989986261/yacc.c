@@ -730,7 +730,7 @@ while (YYID (0))
     while (YYID (0))
 #endif
 
-
+]b4_locations_if([[
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
    we won't break user code: when these are the locations we know.  */
@@ -745,7 +745,13 @@ while (YYID (0))
 #  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 # endif
 #endif
+]], [[
+/* This macro is provided for backward compatibility. */
 
+#ifndef YY_LOCATION_PRINT
+# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
+#endif
+]])[
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
 
