@@ -136,10 +136,10 @@ b4_copyright([Skeleton parser for GLR parsing with Bison], [2002])
 #define yynerrs b4_prefix[]nerrs
 b4_location_if([#define yylloc b4_prefix[]lloc])])
 
-/* Copy the first part of user declarations.  */
-b4_pre_prologue
+b4_token_defines(b4_tokens)
 
-b4_token_defines(b4_tokens)[
+/* Copy the first part of user declarations.  */
+b4_pre_prologue[
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
