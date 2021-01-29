@@ -1783,12 +1783,9 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
 }
 #endif
 
-static void yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
-			       yyGLRStack* yystackp]b4_pure_formals[)
-  __attribute__ ((__noreturn__));
-/*ARGSUSED*/ static void
-yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
-		   yyGLRStack* yystackp]b4_pure_formals[)
+/*ARGSUSED*/ static YYRESULTTAG
+yyreportAmbiguity (yySemanticOption* yyx0,
+		   yySemanticOption* yyx1]b4_pure_formals[)
 {
   YYUSE (yyx0);
   YYUSE (yyx1);
@@ -1801,7 +1798,9 @@ yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
   yyreportTree (yyx1, 2);
   YYFPRINTF (stderr, "\n");
 #endif
-  yyFail (yystackp][]b4_pure_args[, YY_("syntax is ambiguous"));
+
+  yyerror (]b4_yyerror_args[YY_("syntax is ambiguous"));
+  return yyabort;
 }
 
 
@@ -1838,7 +1837,7 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
 	  switch (yypreference (yybest, yyp))
 	    {
 	    case 0:
-	      yyreportAmbiguity (yybest, yyp, yystackp]b4_pure_args[);
+	      return yyreportAmbiguity (yybest, yyp]b4_pure_args[);
 	      break;
 	    case 1:
 	      yymerge = yytrue;
