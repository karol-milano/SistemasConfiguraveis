@@ -154,7 +154,7 @@ m4_if(b4_prefix[], [yy], [],
 #define yynerrs b4_prefix[]nerrs
 #define yylloc b4_prefix[]lloc])
 
-b4_token_enums_defines(b4_tokens)
+b4_token_enums(b4_tokens)
 
 /* Copy the first part of user declarations.  */
 b4_pre_prologue[
@@ -2321,7 +2321,7 @@ m4_if(b4_defines_flag, 0, [],
 b4_copyright([Skeleton parser for GLR parsing with Bison],
   [2002, 2003, 2004, 2005])
 
-b4_token_enums_defines(b4_tokens)
+b4_token_enums(b4_tokens)
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
 m4_ifdef([b4_stype],
