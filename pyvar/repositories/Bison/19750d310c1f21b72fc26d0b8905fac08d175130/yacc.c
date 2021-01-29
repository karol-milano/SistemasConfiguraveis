@@ -660,9 +660,9 @@ while (YYID (0))
 	    YYRHSLOC (Rhs, 0).last_column;				\
 	}								\
     while (YYID (0))
-#endif
+#endif]b4_locations_if([[
+
 
-]b4_locations_if([[
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
    we won't break user code: when these are the locations we know.  */
@@ -676,14 +676,15 @@ while (YYID (0))
 # else
 #  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 # endif
-#endif
-]], [[
+#endif]], [[
+
+
 /* This macro is provided for backward compatibility. */
 
 #ifndef YY_LOCATION_PRINT
 # define YY_LOCATION_PRINT(File, Loc) ((void) 0)
-#endif
-]])[
+#endif]])[
+
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
 
