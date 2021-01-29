@@ -852,8 +852,8 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   yybool yynormal __attribute__ ((__unused__)) =
     (yystackp->yysplitPoint == NULL);
   int yylow;
-]b4_parse_param_use[]dnl
-[# undef yyerrok
+]b4_parse_param_use([yyvalp], [yylocp])[
+# undef yyerrok
 # define yyerrok (yystackp->yyerrState = 0)
 # undef YYACCEPT
 # define YYACCEPT return yyaccept
@@ -1330,8 +1330,7 @@ yy_reduce_print (int yynormal, yyGLRStackItem* yyvsp, size_t yyk,
   int yynrhs = yyrhsLength (yyrule);]b4_locations_if([
   int yylow = 1;])[
   int yyi;
-]b4_parse_param_use[]dnl
-[  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
+  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
              (unsigned long int) yyk, yyrule - 1,
              (unsigned long int) yyrline[yyrule]);
   if (! yynormal)
