@@ -972,20 +972,13 @@ yytnamerr (char *yyres, const char *yystr)
 /* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
    about the unexpected token YYTOKEN while in state YYSTATE.
 
-   Return 0 if *YYMSG was successfully written.  Return 1 if an ordinary
-   "syntax error" message will suffice instead.  Return 2 if *YYMSG is
-   not large enough to hold the message.  In the last case, also set
-   *YYMSG_ALLOC to either (a) the required number of bytes or (b) zero
-   if the required number of bytes is too large to store.  */
+   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
+   not large enough to hold the message.  In that case, also set
+   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
+   required number of bytes is too large to store.  */
 static int
 yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                 int yystate, int yytoken)
-{
-  int yyn = yypact[yystate];
-
-  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
-    return 1;
-  else
 {
   YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
@@ -995,22 +988,51 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
   const char *yyformat = 0;
   /* Arguments of yyformat. */
   char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
+  /* Number of reported tokens (one for the "unexpected", one per
+     "expected"). */
+  int yycount = 0;
 
+  /* There are many possibilities here to consider:
+     - Assume YYFAIL is not used.  It's too flawed to consider.  See
+       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
+       for details.  YYERROR is fine as it does not invoke this
+       function.
+     - If this state is a consistent state with a default action, then
+       the only way this function was invoked is if the default action
+       is an error action.  In that case, don't check for expected
+       tokens because there are none.
+     - The only way there can be no lookahead present (in yychar) is if
+       this state is a consistent state with a default action.  Thus,
+       detecting the absence of a lookahead is sufficient to determine
+       that there is no unexpected or expected token to report.  In that
+       case, just report a simple "syntax error".
+     - Don't assume there isn't a lookahead just because this state is a
+       consistent state with a default action.  There might have been a
+       previous inconsistent state, consistent state with a non-default
+       action, or user semantic action that manipulated yychar.
+     - Of course, the expected token list depends on states to have
+       correct lookahead information, and it depends on the parser not
+       to perform extra reductions after fetching a lookahead from the
+       scanner and before detecting a syntax error.  Thus, state merging
+       (from LALR or IELR) and default reductions corrupt the expected
+       token list.  However, the list is correct for canonical LR with
+       one exception: it will still contain any token that will not be
+       accepted due to an error action in a later state.
+  */
+  if (yytoken != YYEMPTY)
+    {
+      int yyn = yypact[yystate];
+      yyarg[yycount++] = yytname[yytoken];
+      if (!yypact_value_is_default (yyn))
+        {
           /* Start YYX at -YYN if negative to avoid negative indexes in
              YYCHECK.  In other words, skip the first -YYN actions for
              this state because they are default actions.  */
           int yyxbegin = yyn < 0 ? -yyn : 0;
-
           /* Stay within bounds of both yycheck and yytname.  */
           int yychecklim = YYLAST - yyn + 1;
           int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-  /* Number of reported tokens (one for the "unexpected", one per
-     "expected"). */
-  int yycount = 0;
           int yyx;
-
-  yyarg[yycount++] = yytname[yytoken];
-
           for (yyx = yyxbegin; yyx < yyxend; ++yyx)
             if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                 && !yytable_value_is_error (yytable[yyx + yyn]))
@@ -1023,14 +1045,13 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                   }
                 yyarg[yycount++] = yytname[yyx];
                 yysize1 = yysize + yytnamerr (0, yytname[yyx]);
-                if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
-                  {
-                    /* Overflow.  */
-                    *yymsg_alloc = 0;
-                    return 2;
-                  }
+                if (! (yysize <= yysize1
+                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+                  return 2;
                 yysize = yysize1;
               }
+        }
+    }
 
   switch (yycount)
     {
@@ -1038,6 +1059,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
       case N:                               \
         yyformat = S;                       \
       break
+      YYCASE_(0, YY_("syntax error"));
       YYCASE_(1, YY_("syntax error, unexpected %s"));
       YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
       YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
@@ -1048,11 +1070,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 
   yysize1 = yysize + yystrlen (yyformat);
   if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
-    {
-      /* Overflow.  */
-      *yymsg_alloc = 0;
-      return 2;
-    }
+    return 2;
   yysize = yysize1;
 
   if (*yymsg_alloc < yysize)
@@ -1061,7 +1079,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
       if (! (yysize <= *yymsg_alloc
              && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
         *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
-      return 2;
+      return 1;
     }
 
   /* Avoid sprintf, as that infringes on the user's name space.
@@ -1084,7 +1102,6 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
   }
   return 0;
 }
-}
 #endif /* YYERROR_VERBOSE */
 
 
@@ -1533,7 +1550,7 @@ yyreduce:
 yyerrlab:
   /* Make sure we have latest lookahead translation.  See comments at
      user semantic actions for why this is necessary.  */
-  yytoken = YYTRANSLATE (yychar);
+  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
 
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
@@ -1549,7 +1566,7 @@ yyerrlab:
         int yysyntax_error_status = YYSYNTAX_ERROR;
         if (yysyntax_error_status == 0)
           yymsgp = yymsg;
-        else if (yysyntax_error_status == 2 && 0 < yymsg_alloc)
+        else if (yysyntax_error_status == 1)
           {
             if (yymsg != yymsgbuf)
               YYSTACK_FREE (yymsg);
@@ -1558,6 +1575,7 @@ yyerrlab:
               {
                 yymsg = yymsgbuf;
                 yymsg_alloc = sizeof yymsgbuf;
+                yysyntax_error_status = 2;
               }
             else
               {
