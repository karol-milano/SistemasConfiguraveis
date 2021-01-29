@@ -158,7 +158,7 @@ m4_if(b4_prefix[], [yy], [],
 #define yychar  b4_prefix[]char
 #define yydebug b4_prefix[]debug
 #define yynerrs b4_prefix[]nerrs
-b4_location_if([#define yylloc b4_prefix[]lloc])])
+#define yylloc b4_prefix[]lloc])
 
 b4_token_defines(b4_tokens)
 
