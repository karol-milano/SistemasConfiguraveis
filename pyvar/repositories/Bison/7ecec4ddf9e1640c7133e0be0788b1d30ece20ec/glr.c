@@ -180,8 +180,9 @@ b4_token_enums(b4_tokens)
 [#ifndef YYSTYPE
 ]m4_ifdef([b4_stype],
 [[typedef union ]b4_union_name[
+{
 ]b4_user_stype[
-	YYSTYPE;
+} YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1]],
 [m4_if(b4_tag_seen_flag, 0,
 [[typedef int YYSTYPE;
