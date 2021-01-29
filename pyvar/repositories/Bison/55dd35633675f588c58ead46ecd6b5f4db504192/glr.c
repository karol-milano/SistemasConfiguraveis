@@ -1802,7 +1802,7 @@ yyreportAmbiguity (yySemanticOption* yyx0,
 
   yyerror (]b4_yyerror_args[YY_("syntax is ambiguous"));
   return yyabort;
-}
+}]b4_locations_if([[
 
 /** Starting at and including state S1, resolve the location for each of the
  *  previous N1 states that is unresolved.  The first semantic option of a state
@@ -1860,7 +1860,7 @@ yyresolveLocations (yyGLRState* yys1, int yyn1,
 	  yylloc = yylloc_current;
 	}
     }
-}
+}]])[
 
 /** Resolve the ambiguity represented in state S, perform the indicated
  *  actions, and set the semantic value of S.  If result != yyok, the chain of
@@ -1894,8 +1894,8 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
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
