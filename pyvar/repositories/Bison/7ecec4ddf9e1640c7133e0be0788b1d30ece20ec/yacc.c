@@ -192,8 +192,9 @@ b4_token_enums_defines(b4_tokens)[
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 ]m4_ifdef([b4_stype],
 [[typedef union ]b4_union_name[
+{
 ]b4_user_stype[
-	YYSTYPE;
+} YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1]],
 [m4_if(b4_tag_seen_flag, 0,
 [[typedef int YYSTYPE;
@@ -1497,8 +1498,9 @@ b4_token_enums_defines(b4_tokens)
 [#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 ]m4_ifdef([b4_stype],
 [[typedef union ]b4_union_name[
+{
 ]b4_user_stype[
-	YYSTYPE;
+} YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1]],
 [m4_if(b4_tag_seen_flag, 0,
 [[typedef int YYSTYPE;
