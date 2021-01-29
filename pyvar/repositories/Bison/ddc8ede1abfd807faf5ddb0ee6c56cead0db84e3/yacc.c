@@ -189,13 +189,15 @@ b4_token_enums_defines(b4_tokens)[
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 ]m4_ifdef([b4_stype],
-[[typedef union ]b4_union_name
-b4_user_stype
-	YYSTYPE;],
-[typedef int YYSTYPE;])[
+[[typedef union ]b4_union_name[
+]b4_user_stype[
+	YYSTYPE;
+# define YYSTYPE_IS_TRIVIAL 1]],
+[m4_if(b4_tag_seen_flag, 0,
+[[typedef int YYSTYPE;
+# define YYSTYPE_IS_TRIVIAL 1]])])[
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
-# define YYSTYPE_IS_TRIVIAL 1
 #endif
 
 ]b4_locations_if([#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
@@ -1499,13 +1501,15 @@ b4_token_enums_defines(b4_tokens)
 
 [#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 ]m4_ifdef([b4_stype],
-[[typedef union ]b4_union_name
-b4_user_stype
-	YYSTYPE;],
-[typedef int YYSTYPE;])[
+[[typedef union ]b4_union_name[
+]b4_user_stype[
+	YYSTYPE;
+# define YYSTYPE_IS_TRIVIAL 1]],
+[m4_if(b4_tag_seen_flag, 0,
+[[typedef int YYSTYPE;
+# define YYSTYPE_IS_TRIVIAL 1]])])[
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
-# define YYSTYPE_IS_TRIVIAL 1
 #endif
 
 ]b4_pure_if([],
