@@ -2094,104 +2094,104 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 #if YYERROR_VERBOSE
       int yyn;
       yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
-      if (YYPACT_NINF < yyn && yyn <= YYLAST)
-	{
-	  yySymbol yytoken = YYTRANSLATE (yychar);
-	  size_t yysize0 = yytnamerr (NULL, yytokenName (yytoken));
-	  size_t yysize = yysize0;
-	  size_t yysize1;
-	  yybool yysize_overflow = yyfalse;
-	  char* yymsg = NULL;
-	  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
-          /* Internationalized format string. */
-          const char *yyformat = 0;
-          /* Arguments of yyformat. */
-	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-
-	  /* Start YYX at -YYN if negative to avoid negative indexes in
-	     YYCHECK.  In other words, skip the first -YYN actions for this
-	     state because they are default actions.  */
-	  int yyxbegin = yyn < 0 ? -yyn : 0;
-
-	  /* Stay within bounds of both yycheck and yytname.  */
-	  int yychecklim = YYLAST - yyn + 1;
-	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-
-          /* Number of reported tokens (one for the "unexpected", one per
-             "expected"). */
-          int yycount = 0;
+if (YYPACT_NINF < yyn && yyn <= YYLAST)
+  {
+  yySymbol yytoken = YYTRANSLATE (yychar);
+  size_t yysize0 = yytnamerr (NULL, yytokenName (yytoken));
+  size_t yysize = yysize0;
+  size_t yysize1;
+  yybool yysize_overflow = yyfalse;
+  char* yymsg = NULL;
+  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+  /* Internationalized format string. */
+  const char *yyformat = 0;
+  /* Arguments of yyformat. */
+  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
+
+          /* Start YYX at -YYN if negative to avoid negative indexes in
+             YYCHECK.  In other words, skip the first -YYN actions for this
+             state because they are default actions.  */
+          int yyxbegin = yyn < 0 ? -yyn : 0;
+
+          /* Stay within bounds of both yycheck and yytname.  */
+          int yychecklim = YYLAST - yyn + 1;
+          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
+
+  /* Number of reported tokens (one for the "unexpected", one per
+     "expected").  */
+  int yycount = 0;
           int yyx;
 
-	  yyarg[yycount++] = yytokenName (yytoken);
-
-	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
-		&& !yytable_value_is_error (yytable[yyx + yyn]))
-	      {
-		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
-		  {
-		    yycount = 1;
-		    yysize = yysize0;
-		    break;
-		  }
-		yyarg[yycount++] = yytokenName (yyx);
-		yysize1 = yysize + yytnamerr (NULL, yytokenName (yyx));
-		yysize_overflow |= yysize1 < yysize;
-		yysize = yysize1;
-	      }
-
-          switch (yycount)
-            {
-#define YYCASE_(N, S)                           \
-              case N:                           \
-                yyformat = S;                   \
-              break
-              YYCASE_(1, YY_("syntax error, unexpected %s"));
-              YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
-              YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
-              YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
-              YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
+    yyarg[yycount++] = yytokenName (yytoken);
+
+          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
+            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
+                && !yytable_value_is_error (yytable[yyx + yyn]))
+              {
+                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
+                  {
+                    yycount = 1;
+                    yysize = yysize0;
+                    break;
+                  }
+                yyarg[yycount++] = yytokenName (yyx);
+                yysize1 = yysize + yytnamerr (NULL, yytokenName (yyx));
+                yysize_overflow |= yysize1 < yysize;
+                yysize = yysize1;
+              }
+
+  switch (yycount)
+    {
+#define YYCASE_(N, S)                   \
+      case N:                           \
+        yyformat = S;                   \
+      break
+      YYCASE_(1, YY_("syntax error, unexpected %s"));
+      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
+      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
+      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
+      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
 #undef YYCASE_
-            }
+    }
 
-	  yysize1 = yysize + strlen (yyformat);
-	  yysize_overflow |= yysize1 < yysize;
-	  yysize = yysize1;
+  yysize1 = yysize + strlen (yyformat);
+  yysize_overflow |= yysize1 < yysize;
+  yysize = yysize1;
 
-	  if (!yysize_overflow)
-	    yymsg = (char *) YYMALLOC (yysize);
+  if (!yysize_overflow)
+    yymsg = (char *) YYMALLOC (yysize);
 
-	  if (yymsg)
-	    {
-	      char *yyp = yymsg;
-	      int yyi = 0;
-	      while ((*yyp = *yyformat))
-		{
-		  if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
-		    {
-		      yyp += yytnamerr (yyp, yyarg[yyi++]);
-		      yyformat += 2;
-		    }
-		  else
-		    {
-		      yyp++;
-		      yyformat++;
-		    }
-		}
-	      yyerror (]b4_lyyerror_args[yymsg);
-	      YYFREE (yymsg);
-	    }
-	  else
-	    {
-	      yyerror (]b4_lyyerror_args[YY_("syntax error"));
-	      yyMemoryExhausted (yystackp);
-	    }
-	}
-      else
-#endif /* YYERROR_VERBOSE */
-	yyerror (]b4_lyyerror_args[YY_("syntax error"));
-      yynerrs += 1;
+  if (yymsg)
+    {
+      char *yyp = yymsg;
+      int yyi = 0;
+      while ((*yyp = *yyformat))
+        {
+          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
+            {
+              yyp += yytnamerr (yyp, yyarg[yyi++]);
+              yyformat += 2;
+            }
+          else
+            {
+              yyp++;
+              yyformat++;
+            }
+        }
+      yyerror (]b4_lyyerror_args[yymsg);
+      YYFREE (yymsg);
+    }
+  else
+    {
+      yyerror (]b4_lyyerror_args[YY_("syntax error"));
+      yyMemoryExhausted (yystackp);
     }
+  }
+else
+#endif /* YYERROR_VERBOSE */
+  yyerror (]b4_lyyerror_args[YY_("syntax error"));
+  yynerrs += 1;
+}
 }
 
 /* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
