@@ -306,13 +306,6 @@ b4_percent_code_get[]dnl
 # endif
 #endif
 
-]b4_locations_if([#define YYOPTIONAL_LOC(Name) Name],[
-#ifdef __cplusplus
-# define YYOPTIONAL_LOC(Name) /* empty */
-#else
-# define YYOPTIONAL_LOC(Name) Name __attribute__ ((__unused__))
-#endif])[
-
 #ifndef YYASSERT
 # define YYASSERT(Condition) ((void) ((Condition) || (abort (), 0)))
 #endif
