@@ -217,9 +217,9 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 
 /* C GLR parser skeleton written by Paul Hilfinger.  */
 
-]b4_identification
+]b4_identification[
 
-b4_percent_code_get([[top]])[
+]b4_percent_code_get([[top]])[
 ]m4_if(b4_api_prefix, [yy], [],
 [[/* Substitute the type names.  */
 #define YYSTYPE ]b4_api_PREFIX[STYPE]b4_locations_if([[
