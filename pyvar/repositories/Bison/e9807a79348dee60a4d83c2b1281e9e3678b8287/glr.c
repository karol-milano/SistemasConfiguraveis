@@ -154,43 +154,14 @@ m4_define([b4_rhs_location],
 [(((yyGLRStackItem const *)yyvsp)@{YYFILL (($2) - ($1))@}.yystate.yyloc)])
 
 
-
 ## -------------- ##
-## Output files.  ##
+## Declarations.  ##
 ## -------------- ##
 
-# We do want M4 expansion after # for CPP macros.
-m4_changecom()
-m4_divert_push(0)dnl
-@output(b4_parser_file_name@)@
-b4_copyright([Skeleton implementation for Bison GLR parsers in C],
-             [2002-2012])
-[
-/* C GLR parser skeleton written by Paul Hilfinger.  */
-
-]b4_identification
-
-b4_percent_code_get([[top]])[]dnl
-m4_if(b4_prefix, [yy], [],
-[/* Substitute the variable and function names.  */
-#define yyparse b4_prefix[]parse
-#define yylex   b4_prefix[]lex
-#define yyerror b4_prefix[]error
-#define yylval  b4_prefix[]lval
-#define yychar  b4_prefix[]char
-#define yydebug b4_prefix[]debug
-#define yynerrs b4_prefix[]nerrs
-#define yylloc  b4_prefix[]lloc])[
-
-/* Copy the first part of user declarations.  */
-]b4_user_pre_prologue
-
-b4_null_define
-
-dnl # b4_shared_declarations
-dnl # ----------------------
-dnl # Declaration that might either go into the header (if --defines)
-dnl # or open coded in the parser body.
+# b4_shared_declarations
+# ----------------------
+# Declaration that might either go into the header (if --defines)
+# or open coded in the parser body.
 m4_define([b4_shared_declarations],
 [b4_percent_code_get([[requires]])[]dnl
 
@@ -223,7 +194,40 @@ typedef struct YYLTYPE
 ]b4_percent_code_get([[provides]])[]dnl
 ])
 
-b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
+
+## -------------- ##
+## Output files.  ##
+## -------------- ##
+
+# We do want M4 expansion after # for CPP macros.
+m4_changecom()
+m4_divert_push(0)dnl
+@output(b4_parser_file_name@)@
+b4_copyright([Skeleton implementation for Bison GLR parsers in C],
+             [2002-2012])
+[
+/* C GLR parser skeleton written by Paul Hilfinger.  */
+
+]b4_identification
+
+b4_percent_code_get([[top]])[]dnl
+m4_if(b4_prefix, [yy], [],
+[/* Substitute the variable and function names.  */
+#define yyparse b4_prefix[]parse
+#define yylex   b4_prefix[]lex
+#define yyerror b4_prefix[]error
+#define yylval  b4_prefix[]lval
+#define yychar  b4_prefix[]char
+#define yydebug b4_prefix[]debug
+#define yynerrs b4_prefix[]nerrs
+#define yylloc  b4_prefix[]lloc])[
+
+/* Copy the first part of user declarations.  */
+]b4_user_pre_prologue[
+
+]b4_null_define[
+
+]b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
               [b4_shared_declarations])[
 
 /* Enabling traces.  */
