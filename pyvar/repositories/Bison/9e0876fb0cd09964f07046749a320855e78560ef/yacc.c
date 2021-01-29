@@ -416,7 +416,7 @@ static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 #endif
 
 #if YYDEBUG || YYERROR_VERBOSE
-/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
+/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals. */
 static const char *const yytname[] =
 {
@@ -645,8 +645,8 @@ do {								\
              yyrule - 1, yylno);
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
-    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
-  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
+    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
+  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
 }
 
 # define YY_REDUCE_PRINT(Rule)		\
@@ -735,7 +735,55 @@ yystpcpy (yydest, yysrc)
 #  endif
 # endif
 
-#endif /* !YYERROR_VERBOSE */
+# ifndef yytnamerr
+/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
+   quotes and backslashes, so that it's suitable for yyerror.  The
+   heuristic is that double-quoting is unnecessary unless the string
+   contains an apostrophe, a comma, or backslash (other than
+   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
+   null, do not copy; instead, return the length of what the result
+   would have been.  */
+static YYSIZE_T
+yytnamerr (char *yyres, const char *yystr)
+{
+  if (*yystr == '"')
+    {
+      size_t yyn = 0;
+      char const *yyp = yystr;
+
+      for (;;)
+	switch (*++yyp)
+	  {
+	  case '\'':
+	  case ',':
+	    goto do_not_strip_quotes;
+
+	  case '\\':
+	    if (*++yyp != '\\')
+	      goto do_not_strip_quotes;
+	    /* Fall through.  */
+	  default:
+	    if (yyres)
+	      yyres[yyn] = *yyp;
+	    yyn++;
+	    break;
+
+	  case '"':
+	    if (yyres)
+	      yyres[yyn] = '\0';
+	    return yyn;
+	  }
+    do_not_strip_quotes: ;
+    }
+
+  if (! yyres)
+    return yystrlen (yystr);
+
+  return yystpcpy (yyres, yystr) - yyres;
+}
+# endif
+
+#endif /* YYERROR_VERBOSE */
 
 
 
@@ -1111,7 +1159,7 @@ yyerrlab:
       if (YYPACT_NINF < yyn && yyn < YYLAST)
 	{
 	  int yytype = YYTRANSLATE (yychar);
-	  YYSIZE_T yysize0 = yystrlen (yytname[yytype]);
+	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
 	  YYSIZE_T yysize = yysize0;
 	  YYSIZE_T yysize1;
 	  int yysize_overflow = 0;
@@ -1163,7 +1211,7 @@ yyerrlab:
 		    break;
 		  }
 		yyarg[yycount++] = yytname[yyx];
-		yysize1 = yysize + yystrlen (yytname[yyx]);
+		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
 		yysize_overflow |= yysize1 < yysize;
 		yysize = yysize1;
 		yyfmt = yystpcpy (yyfmt, yyprefix);
@@ -1188,7 +1236,7 @@ yyerrlab:
 		{
 		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
 		    {
-		      yyp = yystpcpy (yyp, yyarg[yyi++]);
+		      yyp += yytnamerr (yyp, yyarg[yyi++]);
 		      yyf += 2;
 		    }
 		  else
