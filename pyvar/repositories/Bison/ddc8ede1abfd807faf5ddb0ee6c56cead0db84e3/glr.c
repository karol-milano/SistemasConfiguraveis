@@ -175,14 +175,15 @@ m4_define([b4_shared_declarations],
 
 b4_token_enums(b4_tokens)
 
-[#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
+[#ifndef YYSTYPE
 ]m4_ifdef([b4_stype],
-[typedef union b4_union_name
-b4_user_stype
-	YYSTYPE;],
-[typedef int YYSTYPE;])[
-# define YYSTYPE_IS_DECLARED 1
-# define YYSTYPE_IS_TRIVIAL 1
+[[typedef union ]b4_union_name[
+]b4_user_stype[
+	YYSTYPE;
+# define YYSTYPE_IS_TRIVIAL 1]],
+[m4_if(b4_tag_seen_flag, 0,
+[[typedef int YYSTYPE;
+# define YYSTYPE_IS_TRIVIAL 1]])])[
 #endif
 
 #if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
