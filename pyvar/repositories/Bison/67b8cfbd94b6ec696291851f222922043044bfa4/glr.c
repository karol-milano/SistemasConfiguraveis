@@ -1757,7 +1757,7 @@ yyreportAmbiguity (yySemanticOption* yyx0,
 
   yyerror (]b4_yyerror_args[YY_("syntax is ambiguous"));
   return yyabort;
-}
+}]b4_locations_if([[
 
 /** Resolve the locations for each of the YYN1 states in *YYSTACKP,
  *  ending at YYS1.  Has no effect on previously resolved states.
@@ -1815,7 +1815,7 @@ yyresolveLocations (yyGLRState* yys1, int yyn1,
 	  yylloc = yylloc_current;
 	}
     }
-}
+}]])[
 
 /** Resolve the ambiguity represented in state YYS in *YYSTACKP,
  *  perform the indicated actions, and set the semantic value of YYS.
@@ -1850,8 +1850,8 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
 	{
 	  switch (yypreference (yybest, yyp))
 	    {
-	    case 0:
-	      yyresolveLocations (yys, 1, yystackp]b4_user_args[);
+	    case 0:]b4_locations_if([[
+	      yyresolveLocations (yys, 1, yystackp]b4_user_args[);]])[
 	      return yyreportAmbiguity (yybest, yyp]b4_pure_args[);
 	      break;
 	    case 1:
