@@ -158,9 +158,9 @@ m4_define([b4_rhs_location],
 [(yylsp@{($2) - ($1)@})])
 
 
-## ------------------ ##
-## Parser variables.  ##
-## ------------------ ##
+## -------------- ##
+## Declarations.  ##
+## -------------- ##
 
 # b4_declare_scanner_communication_variables
 # ------------------------------------------
@@ -224,10 +224,9 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
     yytype_int16 *yyes;
     YYSIZE_T yyes_capacity;]])])
 
-
-## --------------------------------------------------------- ##
-## Defining symbol actions, e.g., printers and destructors.  ##
-## --------------------------------------------------------- ##
+## -------------- ##
+## Output files.  ##
+## -------------- ##
 
 # We do want M4 expansion after # for CPP macros.
 m4_changecom()
@@ -287,37 +286,10 @@ m4_if(b4_prefix, [yy], [],
 # define YYTOKEN_TABLE ]b4_token_table[
 #endif
 
-]b4_percent_code_get([[requires]])[]dnl
-
-b4_token_enums_defines(b4_tokens)[
-
-#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
-]m4_ifdef([b4_stype],
-[[typedef union ]b4_union_name[
-{
-]b4_user_stype[
-} YYSTYPE;
-# define YYSTYPE_IS_TRIVIAL 1]],
-[m4_if(b4_tag_seen_flag, 0,
-[[typedef int YYSTYPE;
-# define YYSTYPE_IS_TRIVIAL 1]])])[
-# define yystype YYSTYPE /* obsolescent; will be withdrawn */
-# define YYSTYPE_IS_DECLARED 1
-#endif]b4_locations_if([[
-
-#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
-typedef struct YYLTYPE
-{
-  int first_line;
-  int first_column;
-  int last_line;
-  int last_column;
-} YYLTYPE;
-# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
-# define YYLTYPE_IS_DECLARED 1
-# define YYLTYPE_IS_TRIVIAL 1
-#endif]])b4_push_if([[
-
+]b4_percent_code_get([[requires]])[
+]b4_token_enums_defines(b4_tokens)[
+]b4_declare_yylstype[
+]b4_push_if([[
 #ifndef YYPUSH_DECLS
 #  define YYPUSH_DECLS
 struct yypstate;
@@ -2076,40 +2048,10 @@ b4_copyright([Bison interface for Yacc-like parsers in C],
 
 b4_percent_code_get([[requires]])[]dnl
 
-b4_token_enums_defines(b4_tokens)
-
-[#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
-]m4_ifdef([b4_stype],
-[[typedef union ]b4_union_name[
-{
-]b4_user_stype[
-} YYSTYPE;
-# define YYSTYPE_IS_TRIVIAL 1]],
-[m4_if(b4_tag_seen_flag, 0,
-[[typedef int YYSTYPE;
-# define YYSTYPE_IS_TRIVIAL 1]])])[
-# define yystype YYSTYPE /* obsolescent; will be withdrawn */
-# define YYSTYPE_IS_DECLARED 1
-#endif
-
-]b4_pure_if([], [[extern YYSTYPE ]b4_prefix[lval;]])
-
-b4_locations_if(
-[#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
-typedef struct YYLTYPE
-{
-  int first_line;
-  int first_column;
-  int last_line;
-  int last_column;
-} YYLTYPE;
-# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
-# define YYLTYPE_IS_DECLARED 1
-# define YYLTYPE_IS_TRIVIAL 1
-#endif
-
-]b4_pure_if([], [[extern YYLTYPE ]b4_prefix[lloc;]])
-)dnl b4_locations_if
+b4_token_enums_defines(b4_tokens)[
+]b4_declare_yylstype[
+]b4_pure_if([], [[extern YYSTYPE ]b4_prefix[lval;
+]b4_locations_if([[extern YYLTYPE ]b4_prefix[lloc;]])])dnl
 b4_push_if([[
 #ifndef YYPUSH_DECLS
 #  define YYPUSH_DECLS
