@@ -2043,18 +2043,10 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	  yybool yysize_overflow = yyfalse;
 	  char* yymsg = NULL;
 	  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+          /* Internationalized format string. */
+          const char *yyformat = 0;
+          /* Arguments of yyformat. */
 	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-	  int yyx;
-	  char *yyfmt;
-	  char const *yyf;
-	  static char const yyunexpected[] = "syntax error, unexpected %s";
-	  static char const yyexpecting[] = ", expecting %s";
-	  static char const yyor[] = " or %s";
-	  char yyformat[sizeof yyunexpected
-			+ sizeof yyexpecting - 1
-			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
-			   * (sizeof yyor - 1))];
-	  char const *yyprefix = yyexpecting;
 
 	  /* Start YYX at -YYN if negative to avoid negative indexes in
 	     YYCHECK.  */
@@ -2063,10 +2055,13 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	  /* Stay within bounds of both yycheck and yytname.  */
 	  int yychecklim = YYLAST - yyn + 1;
 	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-	  int yycount = 1;
 
-	  yyarg[0] = yytokenName (yytoken);
-	  yyfmt = yystpcpy (yyformat, yyunexpected);
+          /* Number of reported tokens (one for the "unexpected", one per
+             "expected"). */
+          int yycount = 0;
+          int yyx;
+
+	  yyarg[yycount++] = yytokenName (yytoken);
 
 	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
@@ -2075,19 +2070,29 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 		  {
 		    yycount = 1;
 		    yysize = yysize0;
-		    yyformat[sizeof yyunexpected - 1] = '\0';
 		    break;
 		  }
 		yyarg[yycount++] = yytokenName (yyx);
 		yysize1 = yysize + yytnamerr (NULL, yytokenName (yyx));
 		yysize_overflow |= yysize1 < yysize;
 		yysize = yysize1;
-		yyfmt = yystpcpy (yyfmt, yyprefix);
-		yyprefix = yyor;
 	      }
 
-	  yyf = YY_(yyformat);
-	  yysize1 = yysize + strlen (yyf);
+          switch (yycount)
+            {
+#define YYCASE_(N, S)                           \
+              case N:                           \
+                yyformat = S;                   \
+              break
+              YYCASE_(1, YY_("syntax error, unexpected %s"));
+              YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
+              YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
+              YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
+              YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
+#undef YYCASE_
+            }
+
+	  yysize1 = yysize + strlen (yyformat);
 	  yysize_overflow |= yysize1 < yysize;
 	  yysize = yysize1;
 
@@ -2098,17 +2103,17 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	    {
 	      char *yyp = yymsg;
 	      int yyi = 0;
-	      while ((*yyp = *yyf))
+	      while ((*yyp = *yyformat))
 		{
-		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
+		  if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
 		    {
 		      yyp += yytnamerr (yyp, yyarg[yyi++]);
-		      yyf += 2;
+		      yyformat += 2;
 		    }
 		  else
 		    {
 		      yyp++;
-		      yyf++;
+		      yyformat++;
 		    }
 		}
 	      yyerror (]b4_lyyerror_args[yymsg);
