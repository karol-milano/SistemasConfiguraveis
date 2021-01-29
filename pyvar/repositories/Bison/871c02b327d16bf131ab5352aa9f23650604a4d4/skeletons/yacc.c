@@ -217,9 +217,9 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
        to reallocate them elsewhere.  */
 
     /* The state stack.  */
-    yytype_int16 yyssa[YYINITDEPTH];
-    yytype_int16 *yyss;
-    yytype_int16 *yyssp;
+    yy_state_num yyssa[YYINITDEPTH];
+    yy_state_num *yyss;
+    yy_state_num *yyssp;
 
     /* The semantic value stack.  */
     YYSTYPE yyvsa[YYINITDEPTH];
@@ -236,8 +236,8 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
 
     YYSIZE_T yystacksize;]b4_lac_if([[
 
-    yytype_int16 yyesa@{]b4_percent_define_get([[parse.lac.es-capacity-initial]])[@};
-    yytype_int16 *yyes;
+    yy_state_num yyesa@{]b4_percent_define_get([[parse.lac.es-capacity-initial]])[@};
+    yy_state_num *yyes;
     YYSIZE_T yyes_capacity;]])])
 
 
@@ -430,6 +430,11 @@ typedef short yytype_int16;
 
 #define YYSIZE_MAXIMUM ((YYSIZE_T) -1)
 
+
+/* State numbers. */
+typedef yytype_int16 yy_state_num;
+
+
 #ifndef YY_
 # if defined YYENABLE_NLS && YYENABLE_NLS
 #  if ENABLE_NLS
@@ -531,7 +536,7 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
 {
-  yytype_int16 yyss_alloc;
+  yy_state_num yyss_alloc;
   YYSTYPE yyvs_alloc;]b4_locations_if([
   YYLTYPE yyls_alloc;])[
 };
@@ -543,10 +548,10 @@ union yyalloc
    N elements.  */
 ]b4_locations_if(
 [# define YYSTACK_BYTES(N) \
-     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
+     ((N) * (sizeof (yy_state_num) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
       + 2 * YYSTACK_GAP_MAXIMUM)],
 [# define YYSTACK_BYTES(N) \
-     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
+     ((N) * (sizeof (yy_state_num) + sizeof (YYSTYPE)) \
       + YYSTACK_GAP_MAXIMUM)])[
 
 # define YYCOPY_NEEDED 1
@@ -606,6 +611,7 @@ union yyalloc
 #define YYUNDEFTOK  ]b4_undef_token_number[
 #define YYMAXUTOK   ]b4_user_token_number_max[
 
+
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
 ]b4_api_token_raw_if(dnl
@@ -729,8 +735,8 @@ do {                                                                      \
 `------------------------------------------------------------------*/
 
 ]b4_function_define([yy_stack_print], [static void],
-                   [[yytype_int16 *yybottom], [yybottom]],
-                   [[yytype_int16 *yytop],    [yytop]])[
+                   [[yy_state_num *yybottom], [yybottom]],
+                   [[yy_state_num *yytop],    [yytop]])[
 {
   YYFPRINTF (stderr, "Stack now");
   for (; yybottom <= yytop; yybottom++)
@@ -753,7 +759,7 @@ do {                                                            \
 `------------------------------------------------*/
 
 ]b4_function_define([yy_reduce_print], [static void],
-                   [[yytype_int16 *yyssp], [yyssp]],
+                   [[yy_state_num *yyssp], [yyssp]],
                    [[YYSTYPE *yyvsp], [yyvsp]],
     b4_locations_if([[[YYLTYPE *yylsp], [yylsp]],
                    ])[[int yyrule], [yyrule]]m4_ifset([b4_parse_param], [,
@@ -826,9 +832,9 @@ yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
                       char const *yydebug_prefix,
                       char const *yydebug_suffix,
 #endif
-                      yytype_int16 **yybottom,
-                      yytype_int16 *yybottom_no_free,
-                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
+                      yy_state_num **yybottom,
+                      yy_state_num *yybottom_no_free,
+                      yy_state_num **yytop, yy_state_num *yytop_empty)
 {
   YYSIZE_T yysize_old =
     (YYSIZE_T) (*yytop == yytop_empty ? 0 : *yytop - *yybottom + 1);
@@ -836,7 +842,7 @@ yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
   if (*yycapacity < yysize_new)
     {
       YYSIZE_T yyalloc = 2 * yysize_new;
-      yytype_int16 *yybottom_new;
+      yy_state_num *yybottom_new;
       /* Use YYMAXDEPTH for maximum stack size given that the stack
          should never need to grow larger than the main state stack
          needs to grow without LAC.  */
@@ -849,7 +855,7 @@ yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
       yybottom_new =
-        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
+        (yy_state_num*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
       if (!yybottom_new)
         {
           YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
@@ -952,11 +958,11 @@ do {                                                                     \
    contents of either array, alter *YYES and *YYES_CAPACITY, and free
    any old *YYES other than YYESA.  */
 static int
-yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
-        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
+yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
+        YYSIZE_T *yyes_capacity, yy_state_num *yyssp, int yytoken)
 {
-  yytype_int16 *yyes_prev = yyssp;
-  yytype_int16 *yyesp = yyes_prev;
+  yy_state_num *yyes_prev = yyssp;
+  yy_state_num *yyesp = yyes_prev;
   YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
   if (yytoken == YYUNDEFTOK)
     {
@@ -1013,11 +1019,11 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
           yyesp = yyes_prev -= yylen;
       }
       {
-        yytype_int16 yystate;
+        int yystate;
         {
           const int yylhs = yyr1[yyrule] - YYNTOKENS;
           const int yyi = yypgoto[yylhs] + *yyesp;
-          yystate = ((yytype_int16)
+          yystate = ((yy_state_num)
                      (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                       ? yytable[yyi]
                       : yydefgoto[yylhs]));
@@ -1025,7 +1031,7 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
         if (yyesp == yyes_prev)
           {
             yyesp = *yyes;
-            *yyesp = yystate;
+            *yyesp = (yy_state_num) yystate;
           }
         else
           {
@@ -1038,7 +1044,7 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
                 YYDPRINTF ((stderr, "\n"));
                 return 2;
               }
-            *++yyesp = yystate;
+            *++yyesp = (yy_state_num) yystate;
           }
         YYDPRINTF ((stderr, " G%d", (int) yystate));
       }
@@ -1147,8 +1153,8 @@ yytnamerr (char *yyres, const char *yystr)
    yy_lac returned 2]])[.  */
 static int
 yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
-                ]b4_lac_if([[yytype_int16 *yyesa, yytype_int16 **yyes,
-                YYSIZE_T *yyes_capacity, ]])[yytype_int16 *yyssp, int yytoken)
+                ]b4_lac_if([[yy_state_num *yyesa, yy_state_num **yyes,
+                YYSIZE_T *yyes_capacity, ]])[yy_state_num *yyssp, int yytoken)
 {
   YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
@@ -1500,7 +1506,7 @@ yynewstate:
 yysetstate:
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
   YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
-  *yyssp = (yytype_int16) yystate;
+  *yyssp = (yy_state_num) yystate;
 
   if (yyss + yystacksize - 1 <= yyssp)
 #if !defined yyoverflow && !defined YYSTACK_RELOCATE
@@ -1515,8 +1521,8 @@ yysetstate:
         /* Give user a chance to reallocate the stack.  Use copies of
            these so that the &'s don't force the real ones into
            memory.  */
-        YYSTYPE *yyvs1 = yyvs;
-        yytype_int16 *yyss1 = yyss;]b4_locations_if([
+        yy_state_num *yyss1 = yyss;
+        YYSTYPE *yyvs1 = yyvs;]b4_locations_if([
         YYLTYPE *yyls1 = yyls;])[
 
         /* Each stack pointer address is followed by the size of the
@@ -1541,7 +1547,7 @@ yysetstate:
         yystacksize = YYMAXDEPTH;
 
       {
-        yytype_int16 *yyss1 = yyss;
+        yy_state_num *yyss1 = yyss;
         union yyalloc *yyptr =
           (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
         if (! yyptr)
@@ -1655,7 +1661,7 @@ yyread_pushed_token:]])[
   yychar = YYEMPTY;]b4_lac_if([[
   YY_LAC_DISCARD ("shift");]])[
 
-  yystate = yyn;
+  yystate = (yy_state_num) yyn;
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   *++yyvsp = yylval;
   YY_IGNORE_MAYBE_UNINITIALIZED_END]b4_locations_if([
@@ -1888,7 +1894,7 @@ yyerrlab1:
   /* Shift the error token.  */
   YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);
 
-  yystate = yyn;
+  yystate = (yy_state_num) yyn;
   goto yynewstate;
 
 
