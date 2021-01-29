@@ -955,26 +955,27 @@ yytnamerr (char *yyres, const char *yystr)
 }
 # endif
 
-/* Copy into YYRESULT an error message about the unexpected token
-   YYTOKEN while in state YYSTATE.  Return the number of bytes copied,
-   including the terminating null byte.  If YYRESULT is null, do not
-   copy anything; just return the number of bytes that would be
-   copied.  As a special case, return 0 if an ordinary "syntax error"
-   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
-   size calculation.  */
-static YYSIZE_T
-yysyntax_error (char *yyresult, int yystate, int yytoken)
+/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
+   about the unexpected token YYTOKEN while in state YYSTATE.
+
+   Return 0 if *YYMSG was successfully written.  Return 1 if an ordinary
+   "syntax error" message will suffice instead.  Return 2 if *YYMSG is
+   not large enough to hold the message.  In the last case, also set
+   *YYMSG_ALLOC to either (a) the required number of bytes or (b) zero
+   if the required number of bytes is too large to store.  */
+static int
+yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
+                int yystate, int yytoken)
 {
   int yyn = yypact[yystate];
 
   if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
-    return 0;
+    return 1;
   else
     {
       YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
       YYSIZE_T yysize = yysize0;
       YYSIZE_T yysize1;
-      int yysize_overflow = 0;
       enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
       /* Internationalized format string. */
       const char *yyformat = 0;
@@ -1008,11 +1009,17 @@ yysyntax_error (char *yyresult, int yystate, int yytoken)
 	      }
 	    yyarg[yycount++] = yytname[yyx];
 	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
-	    yysize_overflow |= (yysize1 < yysize);
+	    if (! (yysize <= yysize1
+		   && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+	      {
+		/* Overflow.  */
+		*yymsg_alloc = 0;
+		return 2;
+	      }
 	    yysize = yysize1;
 	  }
 
-        switch (yycount)
+      switch (yycount)
         {
 #define YYCASE_(N, S)                           \
           case N:                               \
@@ -1027,32 +1034,42 @@ yysyntax_error (char *yyresult, int yystate, int yytoken)
         }
 
       yysize1 = yysize + yystrlen (yyformat);
-      yysize_overflow |= (yysize1 < yysize);
+      if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+        {
+          /* Overflow.  */
+          *yymsg_alloc = 0;
+          return 2;
+        }
       yysize = yysize1;
 
-      if (yysize_overflow)
-	return YYSIZE_MAXIMUM;
+      if (*yymsg_alloc < yysize)
+        {
+          *yymsg_alloc = 2 * yysize;
+          if (! (yysize <= *yymsg_alloc
+                 && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
+            *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
+          return 2;
+        }
 
-      if (yyresult)
-	{
-	  /* Avoid sprintf, as that infringes on the user's name space.
-	     Don't have undefined behavior even if the translation
-	     produced a string with the wrong number of "%s"s.  */
-	  char *yyp = yyresult;
-	  int yyi = 0;
-	  while ((*yyp = *yyformat) != '\0')
-            if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
-              {
-                yyp += yytnamerr (yyp, yyarg[yyi++]);
-                yyformat += 2;
-              }
-            else
-              {
-                yyp++;
-                yyformat++;
-              }
-	}
-      return yysize;
+      /* Avoid sprintf, as that infringes on the user's name space.
+         Don't have undefined behavior even if the translation
+         produced a string with the wrong number of "%s"s.  */
+      {
+        char *yyp = *yymsg;
+        int yyi = 0;
+        while ((*yyp = *yyformat) != '\0')
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
+      }
+      return 0;
     }
 }
 #endif /* YYERROR_VERBOSE */
@@ -1497,37 +1514,28 @@ yyerrlab:
 #if ! YYERROR_VERBOSE
       yyerror (]b4_yyerror_args[YY_("syntax error"));
 #else
-      {
-	YYSIZE_T yysize = yysyntax_error (0, yystate, yytoken);
-	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
-	  {
-	    YYSIZE_T yyalloc = 2 * yysize;
-	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
-	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
-	    if (yymsg != yymsgbuf)
-	      YYSTACK_FREE (yymsg);
-	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
-	    if (yymsg)
-	      yymsg_alloc = yyalloc;
-	    else
-	      {
-		yymsg = yymsgbuf;
-		yymsg_alloc = sizeof yymsgbuf;
-	      }
-	  }
-
-	if (0 < yysize && yysize <= yymsg_alloc)
-	  {
-	    (void) yysyntax_error (yymsg, yystate, yytoken);
-	    yyerror (]b4_yyerror_args[yymsg);
-	  }
-	else
-	  {
-	    yyerror (]b4_yyerror_args[YY_("syntax error"));
-	    if (yysize != 0)
-	      goto yyexhaustedlab;
-	  }
-      }
+      while (1)
+        {
+          int yysyntax_error_status =
+            yysyntax_error (&yymsg_alloc, &yymsg, yystate, yytoken);
+          if (yysyntax_error_status == 2 && 0 < yymsg_alloc)
+            {
+              if (yymsg != yymsgbuf)
+                YYSTACK_FREE (yymsg);
+              yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
+              if (yymsg)
+                continue;
+              yymsg = yymsgbuf;
+              yymsg_alloc = sizeof yymsgbuf;
+            }
+          if (yysyntax_error_status == 0)
+            yyerror (]b4_yyerror_args[yymsg);
+          else
+            yyerror (]b4_yyerror_args[YY_("syntax error"));
+          if (yysyntax_error_status == 2)
+            goto yyexhaustedlab;
+          break;
+        }
 #endif
     }
 
