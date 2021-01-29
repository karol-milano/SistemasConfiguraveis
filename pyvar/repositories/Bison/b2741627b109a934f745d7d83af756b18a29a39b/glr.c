@@ -783,7 +783,9 @@ struct yyGLRStack {
   yyGLRStateSet yytops;
 };
 
+#if YYSTACKEXPANDABLE
 static void yyexpandGLRStack (yyGLRStack* yystack);
+#endif
 
 static void yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yymsg)
   __attribute__ ((__noreturn__));
