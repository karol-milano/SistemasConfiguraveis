@@ -447,12 +447,7 @@ typedef short int yytype_int16;
 # endif
 #endif
 
-/* Suppress unused-variable warnings by "using" E.  */
-#if ! defined lint || defined __GNUC__
-# define YYUSE(E) ((void) (E))
-#else
-# define YYUSE(E) /* empty */
-#endif
+]b4_attribute_define[
 
 /* Identity function, used to suppress warnings about constant conditions.  */
 #ifndef lint
