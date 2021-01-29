@@ -425,7 +425,7 @@ static const b4_int_type_for([b4_pgoto]) yypgoto[[]] =
 /* YYTABLE[[YYPACT[STATE-NUM]]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
-   If YYTABLE_NINF, parse error.  */
+   If YYTABLE_NINF, syntax error.  */
 #define YYTABLE_NINF b4_table_ninf
 static const b4_int_type_for([b4_table]) yytable[[]] =
 {
@@ -662,7 +662,7 @@ int yychar;
 /* The semantic value of the lookahead symbol.  */
 YYSTYPE yylval;
 
-/* Number of parse errors so far.  */
+/* Number of syntax errors so far.  */
 int yynerrs;b4_location_if([
 /* Location data for the lookahead symbol.  */
 YYLTYPE yylloc;])
@@ -1017,12 +1017,12 @@ yyerrlab:
 	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
 	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
-	  yysize += yystrlen ("parse error, unexpected ") + 1;
+	  yysize += yystrlen ("syntax error, unexpected ") + 1;
 	  yysize += yystrlen (yytname[yytype]);
 	  yymsg = (char *) YYSTACK_ALLOC (yysize);
 	  if (yymsg != 0)
 	    {
-	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
+	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
 	      yyp = yystpcpy (yyp, yytname[yytype]);
 
 	      if (yycount < 5)
@@ -1043,11 +1043,11 @@ yyerrlab:
 	      YYSTACK_FREE (yymsg);
 	    }
 	  else
-	    yyerror (]b4_yyerror_args["parse error; also virtual memory exhausted");
+	    yyerror (]b4_yyerror_args["syntax error; also virtual memory exhausted");
 	}
       else
 #endif /* YYERROR_VERBOSE */
-	yyerror (]b4_yyerror_args["parse error");
+	yyerror (]b4_yyerror_args["syntax error");
     }
   goto yyerrlab1;
 
