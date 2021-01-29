@@ -332,7 +332,7 @@ static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 #endif
 
 #if (YYDEBUG) || YYERROR_VERBOSE
-/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
+/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals. */
 static const char *const yytname[] =
 {
@@ -600,6 +600,54 @@ yystpcpy (char *yydest, const char *yysrc)
 #  endif
 # endif
 
+# ifndef yytnamerr
+/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
+   quotes and backslashes, so that it's suitable for yyerror.  The
+   heuristic is that double-quoting is unnecessary unless the string
+   contains an apostrophe, a comma, or backslash (other than
+   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
+   null, do not copy; instead, return the length of what the result
+   would have been.  */
+static size_t
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
+    return strlen (yystr);
+
+  return yystpcpy (yyres, yystr) - yyres;
+}
+# endif
+
 #endif /* !YYERROR_VERBOSE */
 
 /** State numbers, as in LALR(1) machine */
@@ -1736,7 +1784,7 @@ yyreportSyntaxError (yyGLRStack* yystack,
       yyn = yypact[yystack->yytops.yystates[0]->yylrState];
       if (YYPACT_NINF < yyn && yyn < YYLAST)
 	{
-	  size_t yysize0 = strlen (yytokenName (*yytokenp));
+	  size_t yysize0 = yytnamerr (NULL, yytokenName (*yytokenp));
 	  size_t yysize = yysize0;
 	  size_t yysize1;
 	  yybool yysize_overflow = yyfalse;
@@ -1778,7 +1826,7 @@ yyreportSyntaxError (yyGLRStack* yystack,
 		    break;
 		  }
 		yyarg[yycount++] = yytokenName (yyx);
-		yysize1 = yysize + strlen (yytokenName (yyx));
+		yysize1 = yysize + yytnamerr (NULL, yytokenName (yyx));
 		yysize_overflow |= yysize1 < yysize;
 		yysize = yysize1;
 		yyfmt = yystpcpy (yyfmt, yyprefix);
@@ -1801,7 +1849,7 @@ yyreportSyntaxError (yyGLRStack* yystack,
 		{
 		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
 		    {
-		      yyp = yystpcpy (yyp, yyarg[yyi++]);
+		      yyp += yytnamerr (yyp, yyarg[yyi++]);
 		      yyf += 2;
 		    }
 		  else
