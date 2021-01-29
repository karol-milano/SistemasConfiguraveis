@@ -614,10 +614,10 @@ yytnamerr (char *yyres, const char *yystr)
     do_not_strip_quotes: ;
     }
 
-  if (! yyres)
+  if (yyres)
+    return yystpcpy (yyres, yystr) - yyres;
+  else
     return (ptrdiff_t) strlen (yystr);
-
-  return yystpcpy (yyres, yystr) - yyres;
 }
 # endif
 
@@ -672,7 +672,8 @@ struct yyGLRStateSet {
    *  operation, yylookaheadNeeds[0] is not maintained since it would merely
    *  duplicate yychar != YYEMPTY.  */
   yybool* yylookaheadNeeds;
-  ptrdiff_t yysize, yycapacity;
+  ptrdiff_t yysize;
+  ptrdiff_t yycapacity;
 };
 
 struct yySemanticOption {
@@ -1991,13 +1992,10 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
         }
       else
         {
-          yySymbol yytoken;
-          int yyaction;
+          yySymbol yytoken = ]b4_yygetToken_call[;
           const short* yyconflicts;
-
+          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
           yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
-          yytoken = ]b4_yygetToken_call[;
-          yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
 
           while (*yyconflicts != 0)
             {
