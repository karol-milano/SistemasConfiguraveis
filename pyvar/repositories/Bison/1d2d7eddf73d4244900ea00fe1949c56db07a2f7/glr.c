@@ -926,7 +926,7 @@ yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[)
 
 #else
 
-  yyFail (yystack][]b4_lpure_args[, "parser stack overflow");
+  yyFail (yystack][]b4_pure_args[, "parser stack overflow");
 #endif
 }
 
