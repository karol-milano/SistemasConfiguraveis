@@ -986,105 +986,104 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
   if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
     return 1;
   else
-    {
-      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
-      YYSIZE_T yysize = yysize0;
-      YYSIZE_T yysize1;
-      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
-      /* Internationalized format string. */
-      const char *yyformat = 0;
-      /* Arguments of yyformat. */
-      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-
-      /* Start YYX at -YYN if negative to avoid negative indexes in
-	 YYCHECK.  In other words, skip the first -YYN actions for this
-	 state because they are default actions.  */
-      int yyxbegin = yyn < 0 ? -yyn : 0;
-
-      /* Stay within bounds of both yycheck and yytname.  */
-      int yychecklim = YYLAST - yyn + 1;
-      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-      /* Number of reported tokens (one for the "unexpected", one per
-         "expected"). */
-      int yycount = 0;
-      int yyx;
-
-      yyarg[yycount++] = yytname[yytoken];
-
-      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
-	    && !yytable_value_is_error (yytable[yyx + yyn]))
-	  {
-	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
-	      {
-		yycount = 1;
-		yysize = yysize0;
-		break;
-	      }
-	    yyarg[yycount++] = yytname[yyx];
-	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
-	    if (! (yysize <= yysize1
-		   && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
-	      {
-		/* Overflow.  */
-		*yymsg_alloc = 0;
-		return 2;
-	      }
-	    yysize = yysize1;
-	  }
+{
+  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
+  YYSIZE_T yysize = yysize0;
+  YYSIZE_T yysize1;
+  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+  /* Internationalized format string. */
+  const char *yyformat = 0;
+  /* Arguments of yyformat. */
+  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
+
+          /* Start YYX at -YYN if negative to avoid negative indexes in
+             YYCHECK.  In other words, skip the first -YYN actions for
+             this state because they are default actions.  */
+          int yyxbegin = yyn < 0 ? -yyn : 0;
+
+          /* Stay within bounds of both yycheck and yytname.  */
+          int yychecklim = YYLAST - yyn + 1;
+          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
+  /* Number of reported tokens (one for the "unexpected", one per
+     "expected"). */
+  int yycount = 0;
+          int yyx;
+
+  yyarg[yycount++] = yytname[yytoken];
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
+                yyarg[yycount++] = yytname[yyx];
+                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
+                if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+                  {
+                    /* Overflow.  */
+                    *yymsg_alloc = 0;
+                    return 2;
+                  }
+                yysize = yysize1;
+              }
 
-      switch (yycount)
-        {
-#define YYCASE_(N, S)                           \
-          case N:                               \
-            yyformat = S;                       \
-          break
-          YYCASE_(1, YY_("syntax error, unexpected %s"));
-          YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
-          YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
-          YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
-          YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
+  switch (yycount)
+    {
+#define YYCASE_(N, S)                       \
+      case N:                               \
+        yyformat = S;                       \
+      break
+      YYCASE_(1, YY_("syntax error, unexpected %s"));
+      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
+      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
+      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
+      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
 #undef YYCASE_
-        }
+    }
+
+  yysize1 = yysize + yystrlen (yyformat);
+  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+    {
+      /* Overflow.  */
+      *yymsg_alloc = 0;
+      return 2;
+    }
+  yysize = yysize1;
+
+  if (*yymsg_alloc < yysize)
+    {
+      *yymsg_alloc = 2 * yysize;
+      if (! (yysize <= *yymsg_alloc
+             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
+        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
+      return 2;
+    }
 
-      yysize1 = yysize + yystrlen (yyformat);
-      if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+  /* Avoid sprintf, as that infringes on the user's name space.
+     Don't have undefined behavior even if the translation
+     produced a string with the wrong number of "%s"s.  */
+  {
+    char *yyp = *yymsg;
+    int yyi = 0;
+    while ((*yyp = *yyformat) != '\0')
+      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
         {
-          /* Overflow.  */
-          *yymsg_alloc = 0;
-          return 2;
+          yyp += yytnamerr (yyp, yyarg[yyi++]);
+          yyformat += 2;
         }
-      yysize = yysize1;
-
-      if (*yymsg_alloc < yysize)
+      else
         {
-          *yymsg_alloc = 2 * yysize;
-          if (! (yysize <= *yymsg_alloc
-                 && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
-            *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
-          return 2;
+          yyp++;
+          yyformat++;
         }
-
-      /* Avoid sprintf, as that infringes on the user's name space.
-         Don't have undefined behavior even if the translation
-         produced a string with the wrong number of "%s"s.  */
-      {
-        char *yyp = *yymsg;
-        int yyi = 0;
-        while ((*yyp = *yyformat) != '\0')
-          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
-            {
-              yyp += yytnamerr (yyp, yyarg[yyi++]);
-              yyformat += 2;
-            }
-          else
-            {
-              yyp++;
-              yyformat++;
-            }
-      }
-      return 0;
-    }
+  }
+  return 0;
+}
 }
 #endif /* YYERROR_VERBOSE */
 
