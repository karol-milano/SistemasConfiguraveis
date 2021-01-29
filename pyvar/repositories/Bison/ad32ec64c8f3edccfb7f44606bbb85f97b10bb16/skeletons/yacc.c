@@ -835,8 +835,9 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
       yybottom_new =
-        YY_CAST(yy_state_t *,
-                YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yyalloc * YYSIZEOF (*yybottom_new))));
+        YY_CAST (yy_state_t *,
+                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
+                                         yyalloc * YYSIZEOF (*yybottom_new))));
       if (!yybottom_new)
         {
           YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
