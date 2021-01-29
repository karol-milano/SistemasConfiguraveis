@@ -182,7 +182,7 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
     /* Number of syntax errors so far.  */
     int yynerrs;
 ]])[
-    int yystate;
+    yy_state_fast_t yystate;
     /* Number of tokens to shift before error messages enabled.  */
     int yyerrstatus;
 
@@ -195,9 +195,9 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
        to reallocate them elsewhere.  */
 
     /* The state stack.  */
-    yy_state_num yyssa[YYINITDEPTH];
-    yy_state_num *yyss;
-    yy_state_num *yyssp;
+    yy_state_t yyssa[YYINITDEPTH];
+    yy_state_t *yyss;
+    yy_state_t *yyssp;
 
     /* The semantic value stack.  */
     YYSTYPE yyvsa[YYINITDEPTH];
@@ -214,8 +214,8 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
 
     YYPTRDIFF_T yystacksize;]b4_lac_if([[
 
-    yy_state_num yyesa@{]b4_percent_define_get([[parse.lac.es-capacity-initial]])[@};
-    yy_state_num *yyes;
+    yy_state_t yyesa@{]b4_percent_define_get([[parse.lac.es-capacity-initial]])[@};
+    yy_state_t *yyes;
     YYPTRDIFF_T yyes_capacity;]])])
 
 
@@ -405,10 +405,11 @@ m4_if(b4_api_prefix, [yy], [],
 
 #define YYSIZEOF(X) ((YYPTRDIFF_T) sizeof (X))
 
+/* Stored state numbers (used for stacks). */
+typedef ]b4_int_type(0, m4_eval(b4_states_number - 1))[ yy_state_t;
 
-/* State numbers. */
-typedef ]b4_int_type(0, m4_eval(b4_states_number - 1))[ yy_state_num;
-
+/* State numbers in computations.  */
+typedef int yy_state_fast_t;
 
 #ifndef YY_
 # if defined YYENABLE_NLS && YYENABLE_NLS
@@ -511,7 +512,7 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
 {
-  yy_state_num yyss_alloc;
+  yy_state_t yyss_alloc;
   YYSTYPE yyvs_alloc;]b4_locations_if([
   YYLTYPE yyls_alloc;])[
 };
@@ -523,11 +524,11 @@ union yyalloc
    N elements.  */
 ]b4_locations_if(
 [# define YYSTACK_BYTES(N) \
-     ((N) * (YYSIZEOF (yy_state_num) + YYSIZEOF (YYSTYPE) \
+     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
              + YYSIZEOF (YYLTYPE)) \
       + 2 * YYSTACK_GAP_MAXIMUM)],
 [# define YYSTACK_BYTES(N) \
-     ((N) * (YYSIZEOF (yy_state_num) + YYSIZEOF (YYSTYPE)) \
+     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
       + YYSTACK_GAP_MAXIMUM)])[
 
 # define YYCOPY_NEEDED 1
@@ -711,8 +712,8 @@ do {                                                                      \
 `------------------------------------------------------------------*/
 
 ]b4_function_define([yy_stack_print], [static void],
-                   [[yy_state_num *yybottom], [yybottom]],
-                   [[yy_state_num *yytop],    [yytop]])[
+                   [[yy_state_t *yybottom], [yybottom]],
+                   [[yy_state_t *yytop],    [yytop]])[
 {
   YYFPRINTF (stderr, "Stack now");
   for (; yybottom <= yytop; yybottom++)
@@ -735,7 +736,7 @@ do {                                                            \
 `------------------------------------------------*/
 
 ]b4_function_define([yy_reduce_print], [static void],
-                   [[yy_state_num *yyssp], [yyssp]],
+                   [[yy_state_t *yyssp], [yyssp]],
                    [[YYSTYPE *yyvsp], [yyvsp]],
     b4_locations_if([[[YYLTYPE *yylsp], [yylsp]],
                    ])[[int yyrule], [yyrule]]m4_ifset([b4_parse_param], [,
@@ -808,9 +809,9 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
                       char const *yydebug_prefix,
                       char const *yydebug_suffix,
 #endif
-                      yy_state_num **yybottom,
-                      yy_state_num *yybottom_no_free,
-                      yy_state_num **yytop, yy_state_num *yytop_empty)
+                      yy_state_t **yybottom,
+                      yy_state_t *yybottom_no_free,
+                      yy_state_t **yytop, yy_state_t *yytop_empty)
 {
   YYPTRDIFF_T yysize_old =
     *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
@@ -818,7 +819,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
   if (*yycapacity < yysize_new)
     {
       YYPTRDIFF_T yyalloc = 2 * yysize_new;
-      yy_state_num *yybottom_new;
+      yy_state_t *yybottom_new;
       /* Use YYMAXDEPTH for maximum stack size given that the stack
          should never need to grow larger than the main state stack
          needs to grow without LAC.  */
@@ -831,7 +832,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
       yybottom_new =
-        (yy_state_num *) YYSTACK_ALLOC ((YYSIZE_T)
+        (yy_state_t *) YYSTACK_ALLOC ((YYSIZE_T)
                                         (yyalloc * YYSIZEOF (*yybottom_new)));
       if (!yybottom_new)
         {
@@ -935,11 +936,11 @@ do {                                                                     \
    contents of either array, alter *YYES and *YYES_CAPACITY, and free
    any old *YYES other than YYESA.  */
 static int
-yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
-        YYPTRDIFF_T *yyes_capacity, yy_state_num *yyssp, int yytoken)
+yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
+        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, int yytoken)
 {
-  yy_state_num *yyes_prev = yyssp;
-  yy_state_num *yyesp = yyes_prev;
+  yy_state_t *yyes_prev = yyssp;
+  yy_state_t *yyesp = yyes_prev;
   YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
   if (yytoken == YYUNDEFTOK)
     {
@@ -996,7 +997,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
           yyesp = yyes_prev -= yylen;
       }
       {
-        int yystate;
+        yy_state_fast_t yystate;
         {
           const int yylhs = yyr1[yyrule] - YYNTOKENS;
           const int yyi = yypgoto[yylhs] + *yyesp;
@@ -1007,7 +1008,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
         if (yyesp == yyes_prev)
           {
             yyesp = *yyes;
-            *yyesp = (yy_state_num) yystate;
+            *yyesp = (yy_state_t) yystate;
           }
         else
           {
@@ -1020,7 +1021,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
                 YYDPRINTF ((stderr, "\n"));
                 return 2;
               }
-            *++yyesp = (yy_state_num) yystate;
+            *++yyesp = (yy_state_t) yystate;
           }
         YYDPRINTF ((stderr, " G%d", yystate));
       }
@@ -1129,8 +1130,8 @@ yytnamerr (char *yyres, const char *yystr)
    yy_lac returned 2]])[.  */
 static int
 yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
-                ]b4_lac_if([[yy_state_num *yyesa, yy_state_num **yyes,
-                YYPTRDIFF_T *yyes_capacity, ]])[yy_state_num *yyssp, int yytoken)
+                ]b4_lac_if([[yy_state_t *yyesa, yy_state_t **yyes,
+                YYPTRDIFF_T *yyes_capacity, ]])[yy_state_t *yyssp, int yytoken)
 {
   YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
   YYPTRDIFF_T yysize = yysize0;
@@ -1483,7 +1484,7 @@ yynewstate:
 yysetstate:
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
   YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
-   *yyssp = (yy_state_num) yystate;
+   *yyssp = (yy_state_t) yystate;
 
   if (yyss + yystacksize - 1 <= yyssp)
 #if !defined yyoverflow && !defined YYSTACK_RELOCATE
@@ -1498,7 +1499,7 @@ yysetstate:
         /* Give user a chance to reallocate the stack.  Use copies of
            these so that the &'s don't force the real ones into
            memory.  */
-        yy_state_num *yyss1 = yyss;
+        yy_state_t *yyss1 = yyss;
         YYSTYPE *yyvs1 = yyvs;]b4_locations_if([
         YYLTYPE *yyls1 = yyls;])[
 
@@ -1524,7 +1525,7 @@ yysetstate:
         yystacksize = YYMAXDEPTH;
 
       {
-        yy_state_num *yyss1 = yyss;
+        yy_state_t *yyss1 = yyss;
         union yyalloc *yyptr =
           (union yyalloc *) YYSTACK_ALLOC ((YYSIZE_T)
                                            YYSTACK_BYTES (yystacksize));
