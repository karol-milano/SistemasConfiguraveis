@@ -1188,15 +1188,8 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
       yyarg[yycount++] = yytname[yytoken];
       if (!yypact_value_is_default (yyn))
-        {]b4_lac_if([], [[
-          /* Start YYX at -YYN if negative to avoid negative indexes in
-             YYCHECK.  In other words, skip the first -YYN actions for
-             this state because they are default actions.  */
-          int yyxbegin = yyn < 0 ? -yyn : 0;
-          /* Stay within bounds of both yycheck and yytname.  */
-          int yychecklim = YYLAST - yyn + 1;
-          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;]])[
-          int yyx;]b4_lac_if([[
+        {]b4_lac_if([[
+          int yyx;
 
           for (yyx = 0; yyx < YYNTOKENS; ++yyx)
             if (yyx != YYTERROR && yyx != YYUNDEFTOK)
@@ -1209,6 +1202,14 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                   if (yy_lac_status == 1)
                     continue;
                 }]], [[
+          /* Start YYX at -YYN if negative to avoid negative indexes in
+             YYCHECK.  In other words, skip the first -YYN actions for
+             this state because they are default actions.  */
+          int yyxbegin = yyn < 0 ? -yyn : 0;
+          /* Stay within bounds of both yycheck and yytname.  */
+          int yychecklim = YYLAST - yyn + 1;
+          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
+          int yyx;
 
           for (yyx = yyxbegin; yyx < yyxend; ++yyx)
             if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
