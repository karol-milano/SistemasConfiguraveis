@@ -316,8 +316,8 @@ m4_if(b4_prefix, [yy], [],
 #define yylval          ]b4_prefix[lval
 #define yychar          ]b4_prefix[char
 #define yydebug         ]b4_prefix[debug
-#define yynerrs         ]b4_prefix[nerrs
-]b4_locations_if([[#define yylloc          ]b4_prefix[lloc]])])[
+#define yynerrs         ]b4_prefix[nerrs]b4_locations_if([[
+#define yylloc          ]b4_prefix[lloc]])])[
 
 /* Copy the first part of user declarations.  */
 ]b4_user_pre_prologue[
