@@ -164,7 +164,7 @@ m4_if(b4_prefix[], [yy], [],
 #define yynerrs b4_prefix[]nerrs
 b4_location_if([#define yylloc b4_prefix[]lloc])])[
 
-]b4_token_defines(b4_tokens)[
+]b4_token_enums_defines(b4_tokens)[
 
 /* Copy the first part of user declarations.  */
 ]b4_pre_prologue[
@@ -1410,7 +1410,7 @@ b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
    This special exception was added by the Free Software Foundation
    in version 1.24 of Bison.  */
 
-b4_token_defines(b4_tokens)
+b4_token_enums_defines(b4_tokens)
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
 m4_ifdef([b4_stype],
