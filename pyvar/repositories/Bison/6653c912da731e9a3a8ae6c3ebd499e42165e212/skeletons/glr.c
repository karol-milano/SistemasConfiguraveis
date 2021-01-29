@@ -96,6 +96,7 @@ m4_define([b4_pure_formals],
 
 # b4_locuser_formals(LOC = yylocp)
 # --------------------------------
+# User formal arguments, possibly preceded by location argument.
 m4_define([b4_locuser_formals],
 [b4_locations_if([, YYLTYPE *m4_default([$1], [yylocp])])[]b4_user_formals])
 
@@ -758,6 +759,32 @@ yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
     }
 }
 
+]m4_define([b4_yygetToken_call],
+           [[yygetToken (&yychar][]b4_pure_if([, yystackp])[]b4_user_args[)]])[
+/** If yychar is empty, fetch the next token.  */
+static inline yySymbol
+yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals[)
+{
+  yySymbol yytoken;
+]b4_parse_param_use()dnl
+[  if (*yycharp == YYEMPTY)
+    {
+      YYDPRINTF ((stderr, "Reading a token: "));
+      *yycharp = ]b4_lex[;
+    }
+  if (*yycharp <= YYEOF)
+    {
+      *yycharp = yytoken = YYEOF;
+      YYDPRINTF ((stderr, "Now at end of input.\n"));
+    }
+  else
+    {
+      yytoken = YYTRANSLATE (*yycharp);
+      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
+    }
+  return yytoken;
+}
+
 /* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
  * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
  * For convenience, always return YYLOW1.  */
@@ -1918,23 +1945,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
           const short* yyconflicts;
 
           yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
-          if (yychar == YYEMPTY)
-            {
-              YYDPRINTF ((stderr, "Reading a token: "));
-              yychar = ]b4_lex[;
-            }
-
-          if (yychar <= YYEOF)
-            {
-              yychar = yytoken = YYEOF;
-              YYDPRINTF ((stderr, "Now at end of input.\n"));
-            }
-          else
-            {
-              yytoken = YYTRANSLATE (yychar);
-              YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
-            }
-
+          yytoken = ]b4_yygetToken_call[;
           yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
 
           while (*yyconflicts != 0)
@@ -2155,19 +2166,9 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
             yytoken = YYTRANSLATE (yychar);
             yydestruct ("Error: discarding",
                         yytoken, &yylval]b4_locuser_args([&yylloc])[);
+            yychar = YYEMPTY;
           }
-        YYDPRINTF ((stderr, "Reading a token: "));
-        yychar = ]b4_lex[;
-        if (yychar <= YYEOF)
-          {
-            yychar = yytoken = YYEOF;
-            YYDPRINTF ((stderr, "Now at end of input.\n"));
-          }
-        else
-          {
-            yytoken = YYTRANSLATE (yychar);
-            YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
-          }
+        yytoken = ]b4_yygetToken_call[;
         yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
         if (yypact_value_is_default (yyj))
           return;
@@ -2305,26 +2306,9 @@ b4_dollar_popdef])[]dnl
             }
           else
             {
+              yySymbol yytoken = ]b4_yygetToken_call;[
               int yyaction;
               const short* yyconflicts;
-              yySymbol yytoken;
-              if (yychar == YYEMPTY)
-                {
-                  YYDPRINTF ((stderr, "Reading a token: "));
-                  yychar = ]b4_lex[;
-                }
-
-              if (yychar <= YYEOF)
-                {
-                  yychar = yytoken = YYEOF;
-                  YYDPRINTF ((stderr, "Now at end of input.\n"));
-                }
-              else
-                {
-                  yytoken = YYTRANSLATE (yychar);
-                  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
-                }
-
               yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
               if (*yyconflicts != 0)
                 break;
