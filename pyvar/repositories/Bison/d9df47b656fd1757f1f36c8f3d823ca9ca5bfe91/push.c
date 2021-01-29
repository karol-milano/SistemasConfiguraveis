@@ -51,6 +51,10 @@ m4_define_default([b4_stack_depth_init],  [200])
 ## Pure/impure interfaces.  ##
 ## ------------------------ ##
 
+b4_percent_define_default([[api.pure]], [[false]])
+b4_define_flag_if([pure])
+m4_define([b4_pure_flag],
+          [b4_percent_define_flag_if([[api.pure]], [[1]], [[0]])])
 
 # b4_yacc_pure_if(IF-TRUE, IF-FALSE)
 # ----------------------------------
@@ -163,14 +167,9 @@ b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
    define necessary library symbols; they are noted "INFRINGES ON
    USER NAME SPACE" below.  */
 
-]b4_identification[
-/* Push parsers.  */
-#define YYPUSH ]b4_push_flag[
+]b4_identification
 
-/* Pull parsers.  */
-#define YYPULL ]b4_pull_flag[
-
-]b4_percent_code_get([[top]])[]dnl
+b4_percent_code_get([[top]])[]dnl
 m4_if(b4_prefix, [yy], [],
 [[/* Substitute the variable and function names.  */
 ]b4_pull_if([[#define yyparse         ]b4_prefix[parse
