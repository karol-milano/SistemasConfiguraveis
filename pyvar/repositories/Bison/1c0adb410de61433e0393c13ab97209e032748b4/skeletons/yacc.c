@@ -671,8 +671,9 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
       }                                                           \
   while (0)
 
-/* Error token number */
+/* Error symbol internal number. */
 #define YYTERROR        1
+/* Error token external number. */
 #define YYERRCODE       256
 
 ]b4_locations_if([[
@@ -946,6 +947,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
 {
   yy_state_t *yyes_prev = yyssp;
   yy_state_t *yyesp = yyes_prev;
+  /* Reduce until we encounter a shift and thereby accept the token.  */
   YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name(yytoken)));
   if (yytoken == YYUNDEFTOK)
     {
@@ -959,6 +961,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
           || (yyrule += yytoken) < 0 || YYLAST < yyrule
           || yycheck[yyrule] != yytoken)
         {
+          /* Use the default action.  */
           yyrule = yydefact[+*yyesp];
           if (yyrule == 0)
             {
@@ -968,6 +971,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
         }
       else
         {
+          /* Use the action from yytable.  */
           yyrule = yytable[yyrule];
           if (yytable_value_is_error (yyrule))
             {
@@ -981,9 +985,12 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
             }
           yyrule = -yyrule;
         }
+      /* By now we know we have to simulate a reduce.  */
+      YYDPRINTF ((stderr, " R%d", yyrule - 1));
       {
+        /* Pop the corresponding number of values from the stack.  */
         YYPTRDIFF_T yylen = yyr2[yyrule];
-        YYDPRINTF ((stderr, " R%d", yyrule - 1));
+        /* First pop from the LAC stack as many tokens as possible.  */
         if (yyesp != yyes_prev)
           {
             YYPTRDIFF_T yysize = yyesp - *yyes + 1;
@@ -994,13 +1001,15 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
               }
             else
               {
-                yylen -= yysize;
                 yyesp = yyes_prev;
+                yylen -= yysize;
               }
           }
+        /* Only afterwards look at the main stack.  */
         if (yylen)
           yyesp = yyes_prev -= yylen;
       }
+      /* Push the resulting state of the reduction.  */
       {
         yy_state_fast_t yystate;
         {
@@ -1414,8 +1423,10 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
 ])],
   [b4_declare_parser_state_variables
 ])b4_lac_if([[
+  /* Whether LAC context is established.  A Boolean.  */
   int yy_lac_established = 0;]])[
   int yyn;
+  /* The return value of yyparse.  */
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
   int yytoken = 0;
