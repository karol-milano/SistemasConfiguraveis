@@ -698,7 +698,7 @@ yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yymsg)
 }
 
 static void
-yyStackOverflow (yyGLRStack* yystack]b4_pure_formals[)
+yyMemoryExhausted (yyGLRStack* yystack)
 {
   longjmp (yystack->yyexception_buffer, 2);
 }
@@ -995,13 +995,13 @@ yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[)
   size_t yyn;
   yysize = yystack->yynextFree - yystack->yyitems;
   if (YYMAXDEPTH <= yysize)
-    yyStackOverflow (yystack]b4_pure_args[);
+    yyMemoryExhausted (yystack);
   yynewSize = 2*yysize;
   if (YYMAXDEPTH < yynewSize)
     yynewSize = YYMAXDEPTH;
   yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
   if (! yynewItems)
-    yyStackOverflow (yystack]b4_pure_args[);
+    yyMemoryExhausted (yystack);
   for (yyp0 = yystack->yyitems, yyp1 = yynewItems, yyn = yysize;
        0 < yyn;
        yyn -= 1, yyp0 += 1, yyp1 += 1)
@@ -1044,7 +1044,7 @@ yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[)
 
 #else
 
-  yyStackOverflow (yystack]b4_pure_args[);
+  yyMemoryExhausted (yystack);
 #endif
 }
 
@@ -1321,7 +1321,7 @@ yysplitStack (yyGLRStack* yystack, size_t yyk]b4_pure_formals[)
 		 (yyGLRState**) YYREALLOC (yystack->yytops.yystates,
 					   ((yystack->yytops.yycapacity *= 2)
 					    * sizeof yynewStates[0])))))
-	yyStackOverflow (yystack]b4_pure_args[);
+	yyMemoryExhausted (yystack);
       yystack->yytops.yystates = yynewStates;
     }
   yystack->yytops.yystates[yystack->yytops.yysize]
@@ -1536,7 +1536,7 @@ yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
   yyreportTree (yyx1, 2);
   YYFPRINTF (stderr, "\n");
 #endif
-  yyFail (yystack][]b4_pure_args[, YY_("ambiguity detected"));
+  yyFail (yystack][]b4_pure_args[, YY_("syntax is ambiguous"));
 }
 
 
@@ -1815,7 +1815,10 @@ yyreportSyntaxError (yyGLRStack* yystack,
 	      YYFREE (yymsg);
 	    }
 	  else
-	    yyerror (]b4_lyyerror_args[YY_("syntax error; also memory exhausted"));
+	    {
+	      yyerror (]b4_lyyerror_args[YY_("syntax error"));
+	      yyMemoryExhausted (yystack);
+	    }
 	}
       else
 #endif /* YYERROR_VERBOSE */
@@ -1993,11 +1996,11 @@ m4_popdef([b4_at_dollar])dnl
 b4_syncline([@oline@], [@ofile@])])dnl
 [
   if (! yyinitGLRStack (&yystack, YYINITDEPTH))
-    goto yyoverflowlab;
+    goto yyexhaustedlab;
   switch (setjmp (yystack.yyexception_buffer))
     {
     case 1: goto yyabortlab;
-    case 2: goto yyoverflowlab;
+    case 2: goto yyexhaustedlab;
     }
   yystack.yytokenp = &yytoken;
   yyglrShift (&yystack, 0, 0, 0, yylval, &yylloc]b4_user_args[);
@@ -2109,8 +2112,8 @@ b4_syncline([@oline@], [@ofile@])])dnl
   yyresult = 1;
   goto yyreturn;
 
- yyoverflowlab:
-  yyerror (]b4_lyyerror_args[YY_("parser stack overflow"));
+ yyexhaustedlab:
+  yyerror (]b4_lyyerror_args[YY_("memory exhausted"));
   yyresult = 2;
   /* Fall through.  */
 
