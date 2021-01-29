@@ -232,7 +232,7 @@ b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
 # undef YYERROR_VERBOSE
 # define YYERROR_VERBOSE 1
 #else
-# define YYERROR_VERBOSE ]b4_error_verbose_flag[
+# define YYERROR_VERBOSE ]b4_error_verbose_if([1], [0])[
 #endif
 
 /* Enabling the token table.  */
