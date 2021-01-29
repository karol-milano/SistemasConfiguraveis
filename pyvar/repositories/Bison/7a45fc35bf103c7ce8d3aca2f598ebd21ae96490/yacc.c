@@ -788,7 +788,7 @@ yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
                       yytype_int16 **yytop, yytype_int16 *yytop_empty)
 {
   YYSIZE_T yysize_old =
-    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
+    (YYSIZE_T) (*yytop == yytop_empty ? 0 : *yytop - *yybottom + 1);
   YYSIZE_T yysize_new = yysize_old + yyadd;
   if (*yycapacity < yysize_new)
     {
@@ -954,7 +954,7 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
         YYDPRINTF ((stderr, " R%d", yyrule - 1));
         if (yyesp != yyes_prev)
           {
-            YYSIZE_T yysize = yyesp - *yyes + 1;
+            YYSIZE_T yysize = (YYSIZE_T) (yyesp - *yyes + 1);
             if (yylen < yysize)
               {
                 yyesp -= yylen;
@@ -970,7 +970,7 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
           yyesp = yyes_prev -= yylen;
       }
       {
-        int yystate;
+        yytype_int16 yystate;
         {
           const int yylhs = yyr1[yyrule] - YYNTOKENS;
           const int yyi = yypgoto[yylhs] + *yyesp;
@@ -1084,7 +1084,7 @@ yytnamerr (char *yyres, const char *yystr)
   if (! yyres)
     return yystrlen (yystr);
 
-  return yystpcpy (yyres, yystr) - yyres;
+  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
 }
 # endif
 
@@ -1445,12 +1445,12 @@ b4_locations_if([[  yylsp[0] = ]b4_push_if([b4_pure_if([*])yypushed_loc], [yyllo
   yyssp++;
 
  yysetstate:
-  *yyssp = yystate;
+  *yyssp = (yytype_int16) yystate;
 
   if (yyss + yystacksize - 1 <= yyssp)
     {
       /* Get the current used size of the three stacks, in elements.  */
-      YYSIZE_T yysize = yyssp - yyss + 1;
+      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);
 
 #ifdef yyoverflow
       {
@@ -1470,10 +1470,9 @@ b4_locations_if([[  yylsp[0] = ]b4_push_if([b4_pure_if([*])yypushed_loc], [yyllo
                     &yyvs1, yysize * sizeof (*yyvsp),]b4_locations_if([
                     &yyls1, yysize * sizeof (*yylsp),])[
                     &yystacksize);
-]b4_locations_if([
-        yyls = yyls1;])[
         yyss = yyss1;
-        yyvs = yyvs1;
+        yyvs = yyvs1;]b4_locations_if([
+        yyls = yyls1;])[
       }
 #else /* no yyoverflow */
 # ifndef YYSTACK_RELOCATE
