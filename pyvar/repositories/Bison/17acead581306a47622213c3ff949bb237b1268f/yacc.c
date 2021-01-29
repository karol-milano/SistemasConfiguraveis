@@ -166,11 +166,11 @@ m4_if(b4_prefix[], [yy], [],
 #define yynerrs b4_prefix[]nerrs
 b4_location_if([#define yylloc b4_prefix[]lloc])])
 
+b4_token_defines(b4_tokens)
+
 /* Copy the first part of user declarations.  */
 b4_pre_prologue
 
-b4_token_defines(b4_tokens)
-
 /* Enabling traces.  */
 #ifndef YYDEBUG
 # define YYDEBUG b4_debug
