@@ -238,13 +238,21 @@ b4_syncline([@oline@], [@ofile@])[
 # ifdef YYSTACK_ALLOC
    /* Pacify GCC's `empty if-body' warning. */
 #  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
+#  ifndef YYSTACK_ALLOC_MAXIMUM
+#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
+#  endif
 # else
 #  if defined (__STDC__) || defined (__cplusplus)
 #   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
 #   define YYSIZE_T size_t
+#  else
+#   define YYSIZE_T unsigned long int
 #  endif
 #  define YYSTACK_ALLOC YYMALLOC
 #  define YYSTACK_FREE YYFREE
+#  ifndef YYSTACK_ALLOC_MAXIMUM
+#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
+#  endif
 # endif
 #endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */
 
@@ -647,7 +655,7 @@ int yydebug;
    if the built-in stack extension method is used).
 
    Do not make this value too large; the results are undefined if
-   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
+   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
    evaluated with infinite-precision integer arithmetic.  */
 
 #ifndef YYMAXDEPTH
@@ -1081,12 +1089,36 @@ yyerrlab:
 
       if (YYPACT_NINF < yyn && yyn < YYLAST)
 	{
-	  YYSIZE_T yysize = 0;
 	  int yytype = YYTRANSLATE (yychar);
-	  const char* yyprefix;
-	  char *yymsg;
+	  YYSIZE_T yysize0 = yystrlen (yytname[yytype]);
+	  YYSIZE_T yysize = yysize0;
+	  YYSIZE_T yysize1;
+	  int yysize_overflow = 0;
+	  char *yymsg = 0;
+#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
+	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
 	  int yyx;
 
+#if 0
+	  /* This is so xgettext sees the translatable formats that are
+	     constructed on the fly.  */
+	  _("syntax error, unexpected %s");
+	  _("syntax error, unexpected %s, expecting %s");
+	  _("syntax error, unexpected %s, expecting %s or %s");
+	  _("syntax error, unexpected %s, expecting %s or %s or %s");
+	  _("syntax error, unexpected %s, expecting %s or %s or %s or %s");
+#endif
+	  char *yyfmt;
+	  char const *yyf;
+	  static char const yyunexpected[] = "syntax error, unexpected %s";
+	  static char const yyexpecting[] = ", expecting %s";
+	  static char const yyor[] = " or %s";
+	  char yyformat[sizeof yyunexpected
+			+ sizeof yyexpecting - 1
+			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
+			   * (sizeof yyor - 1))];
+	  char const *yyprefix = yyexpecting;
+
 	  /* Start YYX at -YYN if negative to avoid negative indexes in
 	     YYCHECK.  */
 	  int yyxbegin = yyn < 0 ? -yyn : 0;
@@ -1094,44 +1126,61 @@ yyerrlab:
 	  /* Stay within bounds of both yycheck and yytname.  */
 	  int yychecklim = YYLAST - yyn;
 	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-	  int yycount = 0;
+	  int yycount = 1;
+
+	  yyarg[0] = yytname[yytype];
+	  yyfmt = yystpcpy (yyformat, yyunexpected);
 
-	  yyprefix = _(", expecting ");
 	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 	      {
-		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
-		yycount += 1;
-		if (yycount == 5)
+		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 		  {
-		    yysize = 0;
+		    yycount = 1;
+		    yysize = yysize0;
+		    yyformat[sizeof yyunexpected - 1] = '\0';
 		    break;
 		  }
+		yyarg[yycount++] = yytname[yyx];
+		yysize1 = yysize + yystrlen (yytname[yyx]);
+		yysize_overflow |= yysize1 < yysize;
+		yysize = yysize1;
+		yyfmt = yystpcpy (yyfmt, yyprefix);
+		yyprefix = yyor;
 	      }
-	  yysize += (strlen (_("syntax error, unexpected "))
-		     + yystrlen (yytname[yytype]) + 1);
-	  yymsg = (char *) YYSTACK_ALLOC (yysize);
-	  if (yymsg != 0)
-	    {
-	      char *yyp = yystpcpy (yymsg, _("syntax error, unexpected "));
-	      yyp = yystpcpy (yyp, yytname[yytype]);
 
-	      if (yycount < 5)
+	  yyf = _(yyformat);
+	  yysize1 = yysize + strlen (yyf);
+	  yysize_overflow |= yysize1 < yysize;
+	  yysize = yysize1;
+
+	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
+	    yymsg = (char *) YYSTACK_ALLOC (yysize);
+	  if (yymsg)
+	    {
+	      /* Avoid sprintf, as that infringes on the user's name space.
+		 Don't have undefined behavior even if the translation
+		 produced a string with the wrong number of "%s"s.  */
+	      char *yyp = yymsg;
+	      int yyi = 0;
+	      while ((*yyp = *yyf))
 		{
-		  yyprefix = _(", expecting ");
-		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
-		      {
-			yyp = yystpcpy (yyp, yyprefix);
-			yyp = yystpcpy (yyp, yytname[yyx]);
-			yyprefix = _(" or ");
-		      }
+		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
+		    {
+		      yyp = yystpcpy (yyp, yyarg[yyi++]);
+		      yyf += 2;
+		    }
+		  else
+		    {
+		      yyp++;
+		      yyf++;
+		    }
 		}
 	      yyerror (]b4_yyerror_args[yymsg);
 	      YYSTACK_FREE (yymsg);
 	    }
 	  else
-	    yyerror (]b4_yyerror_args[_("syntax error; also virtual memory exhausted"));
+	    yyerror (]b4_yyerror_args[_("syntax error; also memory exhausted"));
 	}
       else
 #endif /* YYERROR_VERBOSE */
