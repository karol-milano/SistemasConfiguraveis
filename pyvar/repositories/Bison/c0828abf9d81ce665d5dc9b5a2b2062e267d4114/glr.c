@@ -163,34 +163,9 @@ m4_define([b4_rhs_location],
 # Declaration that might either go into the header (if --defines)
 # or open coded in the parser body.
 m4_define([b4_shared_declarations],
-[b4_percent_code_get([[requires]])[]dnl
-
-b4_token_enums(b4_tokens)
-
-[#ifndef YYSTYPE
-]m4_ifdef([b4_stype],
-[[typedef union ]b4_union_name[
-{
-]b4_user_stype[
-} YYSTYPE;
-# define YYSTYPE_IS_TRIVIAL 1]],
-[m4_if(b4_tag_seen_flag, 0,
-[[typedef int YYSTYPE;
-# define YYSTYPE_IS_TRIVIAL 1]])])[
-#endif
-]b4_locations_if([[
-#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
-typedef struct YYLTYPE
-{
-  int first_line;
-  int first_column;
-  int last_line;
-  int last_column;
-} YYLTYPE;
-# define YYLTYPE_IS_DECLARED 1
-# define YYLTYPE_IS_TRIVIAL 1
-#endif
-]])[
+[b4_percent_code_get([[requires]])[
+]b4_token_enums(b4_tokens)[
+]b4_declare_yylstype[
 ]b4_percent_code_get([[provides]])[]dnl
 ])
 
