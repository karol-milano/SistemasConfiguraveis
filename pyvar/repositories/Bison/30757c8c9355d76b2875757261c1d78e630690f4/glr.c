@@ -218,6 +218,18 @@ b4_syncline([@oline@], [@ofile@])
 #include <stdarg.h>
 #include <setjmp.h>
 
+#ifndef YY_
+# if YYENABLE_NLS
+#  if ENABLE_NLS
+#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
+#   define YY_(msgid) dgettext ("bison-runtime", msgid)
+#  endif
+# endif
+# ifndef YY_
+#  define YY_(msgid) msgid
+# endif
+#endif
+
 #ifndef YYFREE
 # define YYFREE free
 #endif
@@ -771,7 +783,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
 # undef YYBACKUP
 # define YYBACKUP(Token, Value)						     \
-  return yyerror (]b4_yyerror_args["syntax error: cannot back up"),	     \
+  return yyerror (]b4_yyerror_args[YY_("syntax error: cannot back up")),     \
 	 yyerrok, yyerr
 
   yylow = 1;
@@ -1524,7 +1536,7 @@ yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
   yyreportTree (yyx1, 2);
   YYFPRINTF (stderr, "\n");
 #endif
-  yyFail (yystack][]b4_pure_args[, "ambiguity detected");
+  yyFail (yystack][]b4_pure_args[, YY_("ambiguity detected"));
 }
 
 
@@ -1774,8 +1786,8 @@ yyreportSyntaxError (yyGLRStack* yystack,
 		yyprefix = yyor;
 	      }
 
-	  yyf = yyformat;
-	  yysize1 = yysize + (yyfmt - yyformat);
+	  yyf = YY_(yyformat);
+	  yysize1 = yysize + strlen (yyf);
 	  yysize_overflow |= yysize1 < yysize;
 	  yysize = yysize1;
 
@@ -1803,11 +1815,11 @@ yyreportSyntaxError (yyGLRStack* yystack,
 	      YYFREE (yymsg);
 	    }
 	  else
-	    yyerror (]b4_lyyerror_args["syntax error; also virtual memory exhausted");
+	    yyerror (]b4_lyyerror_args[YY_("syntax error; also memory exhausted"));
 	}
       else
 #endif /* YYERROR_VERBOSE */
-	yyerror (]b4_lyyerror_args["syntax error");
+	yyerror (]b4_lyyerror_args[YY_("syntax error"));
       yynerrs += 1;
     }
 }
@@ -2068,7 +2080,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	    {
 	      yyundeleteLastStack (&yystack);
 	      if (yystack.yytops.yysize == 0)
-		yyFail (&yystack][]b4_lpure_args[, "syntax error");
+		yyFail (&yystack][]b4_lpure_args[, YY_("syntax error"));
 	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
 ]b4_location_if([[	      yystack.yyerror_range[1].yystate.yyloc = *yyllocp;]])[
@@ -2098,7 +2110,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
   goto yyreturn;
 
  yyoverflowlab:
-  yyerror (]b4_lyyerror_args["parser stack overflow");
+  yyerror (]b4_lyyerror_args[YY_("parser stack overflow"));
   yyresult = 2;
   /* Fall through.  */
 
