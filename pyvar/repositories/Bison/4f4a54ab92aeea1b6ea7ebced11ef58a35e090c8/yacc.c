@@ -171,7 +171,7 @@ m4_define([b4_declare_scanner_communication_variables], [[
 int yychar;
 
 ]b4_pure_if([[
-#if defined __GNUC__ && (4 < __GNUC__ + (6 <= __GNUC_MINOR__))
+#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
 /* Suppress an incorrect diagnostic about yylval being uninitialized.  */
 # define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
     _Pragma ("GCC diagnostic push") \
