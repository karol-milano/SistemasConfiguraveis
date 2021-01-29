@@ -34,6 +34,14 @@ m4_define_default([b4_stack_depth_init],  [200])
 ## ------------------------ ##
 
 
+# b4_user_formals
+# ---------------
+# This is specific to GLR because it relies on ISO C formal argument
+# declarations.
+m4_define([b4_user_formals],
+[m4_ifset([b4_parse_param], [, b4_c_ansi_formals(b4_parse_param)])])
+
+
 # b4_lex_param
 # ------------
 # Accumule in b4_lex_param all the yylex arguments.
@@ -44,12 +52,6 @@ b4_location_if([, [[YYLTYPE *], [yyllocp]]])])dnl
 m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
 
 
-# b4_user_formals
-# ---------------
-m4_define([b4_user_formals],
-[m4_ifset([b4_parse_param], [, b4_c_ansi_formals(b4_parse_param)])])
-
-
 # b4_yyerror_args
 # ---------------
 # Arguments passed to yyerror: user args plus yylloc.
@@ -534,15 +536,15 @@ do {						\
 
 ]b4_yysymprint_generate([b4_c_ansi_function_def])[
 
-# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
-do {								\
-  if (yydebug)							\
-    {								\
-      YYFPRINTF (stderr, "%s ", Title);				\
-      yysymprint (stderr,					\
-                  Type, Value]b4_location_if([, Location])[);	\
-      YYFPRINTF (stderr, "\n");					\
-    }								\
+# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			    \
+do {									    \
+  if (yydebug)								    \
+    {									    \
+      YYFPRINTF (stderr, "%s ", Title);					    \
+      yysymprint (stderr,						    \
+                  Type, Value]b4_location_if([, Location])[]b4_user_args[); \
+      YYFPRINTF (stderr, "\n");						    \
+    }									    \
 } while (/*CONSTCOND*/ 0)
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
@@ -902,11 +904,11 @@ yyrhsLength (yyRuleNum yyrule)
 }
 
 static void
-yydestroyGLRState (char const *yymsg, yyGLRState *yys)
+yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 {
   if (yys->yyresolved)
     yydestruct (yymsg, yystos[yys->yylrState],
-		&yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
+		&yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[]b4_user_args[);
   else
     {
 #if YYDEBUG
@@ -914,7 +916,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys)
 	{
 	  YYFPRINTF (stderr, "%s unresolved ", yymsg);
 	  yysymprint (stderr, yystos[yys->yylrState],
-		      &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
+		      &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[]b4_user_args[);
 	  YYFPRINTF (stderr, "\n");
 	}
 #endif
@@ -927,7 +929,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys)
           for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
                yyn > 0;
                yyrh = yyrh->yypred, yyn -= 1)
-            yydestroyGLRState (yymsg, yyrh);
+            yydestroyGLRState (yymsg, yyrh]b4_user_args[);
         }
     }
 }
@@ -1968,7 +1970,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    yyerror_range[2].yystate.yyloc = *yyllocp;
 	    YYLLOC_DEFAULT (yys->yyloc, yyerror_range, 2);]])[
 	    yydestruct ("Error: discarding",
-			*yytokenp, yylvalp]b4_location_if([, yyllocp])[);
+			*yytokenp, yylvalp]b4_location_if([, yyllocp])[]b4_user_args[);
 	  }
 	YYDPRINTF ((stderr, "Reading a token: "));
 	yychar = YYLEX;
@@ -2023,7 +2025,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    }
 	}
 ]b4_location_if([[      yystack->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
-      yydestroyGLRState ("Error: popping", yys);
+      yydestroyGLRState ("Error: popping", yys]b4_user_args[);
       yystack->yytops.yystates[0] = yys->yypred;
       yystack->yynextFree -= 1;
       yystack->yyspaceLeft += 1;
@@ -2218,7 +2220,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
  yyreturn:
   if (yytoken != YYEOF && yytoken != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
-                yytoken, yylvalp]b4_location_if([, yyllocp])[);
+                yytoken, yylvalp]b4_location_if([, yyllocp])[]b4_user_args[);
 
   /* If the stack is well-formed, pop the stack until it is empty,
      destroying its entries as we go.  But free the stack regardless
@@ -2231,7 +2233,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	  {
 	    yyGLRState *yys = yystates[0];
 ]b4_location_if([[	  yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
-)[	    yydestroyGLRState ("Cleanup: popping", yys);
+)[	    yydestroyGLRState ("Cleanup: popping", yys]b4_user_args[);
 	    yystates[0] = yys->yypred;
 	    yystack.yynextFree -= 1;
 	    yystack.yyspaceLeft += 1;
