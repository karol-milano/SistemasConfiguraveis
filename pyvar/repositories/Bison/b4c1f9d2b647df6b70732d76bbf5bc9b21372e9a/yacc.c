@@ -233,6 +233,8 @@ b4_syncline([@oline@], [@ofile@])[
 # define YYSIZE_T unsigned int
 #endif
 
+#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)
+
 #ifndef YY_
 # if YYENABLE_NLS
 #  if ENABLE_NLS
@@ -277,7 +279,7 @@ b4_syncline([@oline@], [@ofile@])[
 #  define YYSTACK_ALLOC YYMALLOC
 #  define YYSTACK_FREE YYFREE
 #  ifndef YYSTACK_ALLOC_MAXIMUM
-#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
+#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
 #  endif
 #  ifdef __cplusplus
 extern "C" {
@@ -788,8 +790,114 @@ yytnamerr (char *yyres, const char *yystr)
 }
 # endif
 
-#endif /* YYERROR_VERBOSE */
+/* Copy into YYRESULT an error message about the unexpected token
+   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
+   including the terminating null byte.  If YYRESULT is null, do not
+   copy anything; just return the number of bytes that would be
+   copied.  As a special case, return 0 if an ordinary "syntax error"
+   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
+   size calculation.  */
+static YYSIZE_T
+yysyntax_error (char *yyresult, int yystate, int yychar)
+{
+  int yyn = yypact[yystate];
 
+  if (! (YYPACT_NINF < yyn && yyn < YYLAST))
+    return 0;
+  else
+    {
+      int yytype = YYTRANSLATE (yychar);
+      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
+      YYSIZE_T yysize = yysize0;
+      YYSIZE_T yysize1;
+      int yysize_overflow = 0;
+      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
+      int yyx;
+
+# if 0
+      /* This is so xgettext sees the translatable formats that are
+         constructed on the fly.  */
+      YY_("syntax error, unexpected %s");
+      YY_("syntax error, unexpected %s, expecting %s");
+      YY_("syntax error, unexpected %s, expecting %s or %s");
+      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
+      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
+# endif
+      char *yyfmt;
+      char const *yyf;
+      static char const yyunexpected[] = "syntax error, unexpected %s";
+      static char const yyexpecting[] = ", expecting %s";
+      static char const yyor[] = " or %s";
+      char yyformat[sizeof yyunexpected
+                    + sizeof yyexpecting - 1
+                    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
+                       * (sizeof yyor - 1))];
+      char const *yyprefix = yyexpecting;
+
+      /* Start YYX at -YYN if negative to avoid negative indexes in
+         YYCHECK.  */
+      int yyxbegin = yyn < 0 ? -yyn : 0;
+
+      /* Stay within bounds of both yycheck and yytname.  */
+      int yychecklim = YYLAST - yyn;
+      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
+      int yycount = 1;
+
+      yyarg[0] = yytname[yytype];
+      yyfmt = yystpcpy (yyformat, yyunexpected);
+
+      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
+        if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+          {
+            if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
+              {
+                yycount = 1;
+                yysize = yysize0;
+                yyformat[sizeof yyunexpected - 1] = '\0';
+                break;
+              }
+            yyarg[yycount++] = yytname[yyx];
+            yysize1 = yysize + yytnamerr (0, yytname[yyx]);
+            yysize_overflow |= yysize1 < yysize;
+            yysize = yysize1;
+            yyfmt = yystpcpy (yyfmt, yyprefix);
+            yyprefix = yyor;
+          }
+
+      yyf = YY_(yyformat);
+      yysize1 = yysize + yystrlen (yyf);
+      yysize_overflow |= yysize1 < yysize;
+      yysize = yysize1;
+
+      if (yysize_overflow)
+	return YYSIZE_MAXIMUM;
+
+      if (yyresult)
+	{
+          /* Avoid sprintf, as that infringes on the user's name space.
+             Don't have undefined behavior even if the translation
+             produced a string with the wrong number of "%s"s.  */
+          char *yyp = yyresult;
+          int yyi = 0;
+          while ((*yyp = *yyf))
+            {
+              if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
+                {
+                  yyp += yytnamerr (yyp, yyarg[yyi++]);
+                  yyf += 2;
+                }
+              else
+                {
+                  yyp++;
+                  yyf++;
+                }
+            }
+        }
+      return yysize;
+    }
+}
+#endif /* YYERROR_VERBOSE */
 
 
 #if YYDEBUG
@@ -857,6 +965,12 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   int yyerrstatus;
   /* Look-ahead token as an internal (translated) token number.  */
   int yytoken = 0;
+#if YYERROR_VERBOSE
+  /* Buffer for error messages, and its allocated size.  */
+  char yymsgbuf[128];
+  char *yymsg = yymsgbuf;
+  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
+#endif
 
   /* Three stacks and their tools:
      `yyss': related to states,
@@ -1158,110 +1272,41 @@ yyerrlab:
   if (!yyerrstatus)
     {
       ++yynerrs;
-#if YYERROR_VERBOSE
-      yyn = yypact[yystate];
-
-      if (YYPACT_NINF < yyn && yyn < YYLAST)
-	{
-	  int yytype = YYTRANSLATE (yychar);
-	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
-	  YYSIZE_T yysize = yysize0;
-	  YYSIZE_T yysize1;
-	  int yysize_overflow = 0;
-	  char *yymsg = 0;
-#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
-	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-	  int yyx;
-
-#if 0
-	  /* This is so xgettext sees the translatable formats that are
-	     constructed on the fly.  */
-	  YY_("syntax error, unexpected %s");
-	  YY_("syntax error, unexpected %s, expecting %s");
-	  YY_("syntax error, unexpected %s, expecting %s or %s");
-	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
-	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
-#endif
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
-
-	  /* Start YYX at -YYN if negative to avoid negative indexes in
-	     YYCHECK.  */
-	  int yyxbegin = yyn < 0 ? -yyn : 0;
-
-	  /* Stay within bounds of both yycheck and yytname.  */
-	  int yychecklim = YYLAST - yyn;
-	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-	  int yycount = 1;
-
-	  yyarg[0] = yytname[yytype];
-	  yyfmt = yystpcpy (yyformat, yyunexpected);
-
-	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+#if ! YYERROR_VERBOSE
+      yyerror (]b4_yyerror_args[YY_("syntax error"));
+#else
+      {
+	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
+	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
+	  {
+	    YYSIZE_T yyalloc = 2 * yysize;
+	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
+	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
+	    if (yymsg != yymsgbuf)
+	      YYSTACK_FREE (yymsg);
+	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
+	    if (yymsg)
+	      yymsg_alloc = yyalloc;
+	    else
 	      {
-		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
-		  {
-		    yycount = 1;
-		    yysize = yysize0;
-		    yyformat[sizeof yyunexpected - 1] = '\0';
-		    break;
-		  }
-		yyarg[yycount++] = yytname[yyx];
-		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
-		yysize_overflow |= yysize1 < yysize;
-		yysize = yysize1;
-		yyfmt = yystpcpy (yyfmt, yyprefix);
-		yyprefix = yyor;
+		yymsg = yymsgbuf;
+		yymsg_alloc = sizeof yymsgbuf;
 	      }
+	  }
 
-	  yyf = YY_(yyformat);
-	  yysize1 = yysize + yystrlen (yyf);
-	  yysize_overflow |= yysize1 < yysize;
-	  yysize = yysize1;
-
-	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
-	    yymsg = (char *) YYSTACK_ALLOC (yysize);
-	  if (yymsg)
-	    {
-	      /* Avoid sprintf, as that infringes on the user's name space.
-		 Don't have undefined behavior even if the translation
-		 produced a string with the wrong number of "%s"s.  */
-	      char *yyp = yymsg;
-	      int yyi = 0;
-	      while ((*yyp = *yyf))
-		{
-		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
-		    {
-		      yyp += yytnamerr (yyp, yyarg[yyi++]);
-		      yyf += 2;
-		    }
-		  else
-		    {
-		      yyp++;
-		      yyf++;
-		    }
-		}
-	      yyerror (]b4_yyerror_args[yymsg);
-	      YYSTACK_FREE (yymsg);
-	    }
-	  else
-	    {
-	      yyerror (]b4_yyerror_args[YY_("syntax error"));
+	if (0 < yysize && yysize <= yymsg_alloc)
+	  {
+	    (void) yysyntax_error (yymsg, yystate, yychar);
+	    yyerror (]b4_yyerror_args[yymsg);
+	  }
+	else
+	  {
+	    yyerror (]b4_yyerror_args[YY_("syntax error"));
+	    if (yysize != 0)
 	      goto yyexhaustedlab;
-	    }
-	}
-      else
-#endif /* YYERROR_VERBOSE */
-	yyerror (]b4_yyerror_args[YY_("syntax error"));
+	  }
+      }
+#endif
     }
 
 ]b4_location_if([[  yyerror_range[0] = yylloc;]])[
@@ -1394,6 +1439,10 @@ yyreturn:
 #ifndef yyoverflow
   if (yyss != yyssa)
     YYSTACK_FREE (yyss);
+#endif
+#if YYERROR_VERBOSE
+  if (yymsg != yymsgbuf)
+    YYSTACK_FREE (yymsg);
 #endif
   return yyresult;
 ]}
