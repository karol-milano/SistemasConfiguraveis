@@ -2720,5 +2720,6 @@ m4_if(b4_prefix, [yy], [],
 #define yynerrs ]b4_prefix[nerrs]b4_locations_if([[
 #define yylloc  ]b4_prefix[lloc]])])[
 
-]b4_epilogue[]dnl
+]b4_percent_code_get([[epilogue]])[]dnl
+b4_epilogue[]dnl
 b4_output_end
