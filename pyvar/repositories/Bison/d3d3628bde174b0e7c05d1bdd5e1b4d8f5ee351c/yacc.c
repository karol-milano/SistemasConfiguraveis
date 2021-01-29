@@ -977,28 +977,10 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       YYSIZE_T yysize1;
       int yysize_overflow = 0;
       enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+      /* Internationalized format string. */
+      const char *yyformat = 0;
+      /* Arguments of yyformat. */
       char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-      int yyx;
-
-# if 0
-      /* This is so xgettext sees the translatable formats that are
-	 constructed on the fly.  */
-      YY_("syntax error, unexpected %s");
-      YY_("syntax error, unexpected %s, expecting %s");
-      YY_("syntax error, unexpected %s, expecting %s or %s");
-      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
-      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
-# endif
-      char *yyfmt;
-      char const *yyf;
-      static char const yyunexpected[] = "syntax error, unexpected %s";
-      static char const yyexpecting[] = ", expecting %s";
-      static char const yyor[] = " or %s";
-      char yyformat[sizeof yyunexpected
-		    + sizeof yyexpecting - 1
-		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
-		       * (sizeof yyor - 1))];
-      char const *yyprefix = yyexpecting;
 
       /* Start YYX at -YYN if negative to avoid negative indexes in
 	 YYCHECK.  In other words, skip the first -YYN actions for this
@@ -1008,10 +990,12 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       /* Stay within bounds of both yycheck and yytname.  */
       int yychecklim = YYLAST - yyn + 1;
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-      int yycount = 1;
+      /* Number of reported tokens (one for the "unexpected", one per
+         "expected"). */
+      int yycount = 0;
+      int yyx;
 
-      yyarg[0] = yytname[yytype];
-      yyfmt = yystpcpy (yyformat, yyunexpected);
+      yyarg[yycount++] = yytname[yytype];
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
@@ -1021,19 +1005,29 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 	      {
 		yycount = 1;
 		yysize = yysize0;
-		yyformat[sizeof yyunexpected - 1] = '\0';
 		break;
 	      }
 	    yyarg[yycount++] = yytname[yyx];
 	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
 	    yysize_overflow |= (yysize1 < yysize);
 	    yysize = yysize1;
-	    yyfmt = yystpcpy (yyfmt, yyprefix);
-	    yyprefix = yyor;
 	  }
 
-      yyf = YY_(yyformat);
-      yysize1 = yysize + yystrlen (yyf);
+        switch (yycount)
+        {
+#define YYCASE_(N, S)                           \
+          case N:                               \
+            yyformat = S;                       \
+          break
+          YYCASE_(1, YY_("syntax error, unexpected %s"));
+          YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
+          YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
+          YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
+          YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
+#undef YYCASE_
+        }
+
+      yysize1 = yysize + yystrlen (yyformat);
       yysize_overflow |= (yysize1 < yysize);
       yysize = yysize1;
 
@@ -1047,19 +1041,17 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 	     produced a string with the wrong number of "%s"s.  */
 	  char *yyp = yyresult;
 	  int yyi = 0;
-	  while ((*yyp = *yyf) != '\0')
-	    {
-	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
-		{
-		  yyp += yytnamerr (yyp, yyarg[yyi++]);
-		  yyf += 2;
-		}
-	      else
-		{
-		  yyp++;
-		  yyf++;
-		}
-	    }
+	  while ((*yyp = *yyformat) != '\0')
+            if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
+              {
+                yyp += yytnamerr (yyp, yyarg[yyi++]);
+                yyformat += 2;
+              }
+            else
+              {
+                yyp++;
+                yyformat++;
+              }
 	}
       return yysize;
     }
