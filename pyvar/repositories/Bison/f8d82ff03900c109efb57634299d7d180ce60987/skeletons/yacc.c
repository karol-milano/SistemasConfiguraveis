@@ -854,8 +854,10 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
       *yybottom = yybottom_new;
       *yycapacity = yyalloc;]m4_if(b4_percent_define_get([[parse.lac.memory-trace]]),
                                    [full], [[
+      YY_IGNORE_USELESS_CAST_BEGIN
       YYDPRINTF ((stderr, "%srealloc to %ld%s", yydebug_prefix,
-                  YY_CAST (long, yyalloc), yydebug_suffix));]])[
+                  YY_CAST (long, yyalloc), yydebug_suffix));
+      YY_IGNORE_USELESS_CAST_END]])[
     }
   return 0;
 }
@@ -1012,7 +1014,9 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
         if (yyesp == yyes_prev)
           {
             yyesp = *yyes;
+            YY_IGNORE_USELESS_CAST_BEGIN
             *yyesp = YY_CAST (yy_state_t, yystate);
+            YY_IGNORE_USELESS_CAST_END
           }
         else
           {
@@ -1025,7 +1029,9 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
                 YYDPRINTF ((stderr, "\n"));
                 return 2;
               }
+            YY_IGNORE_USELESS_CAST_BEGIN
             *++yyesp = YY_CAST (yy_state_t, yystate);
+            YY_IGNORE_USELESS_CAST_END
           }
         YYDPRINTF ((stderr, " G%d", yystate));
       }
@@ -1492,7 +1498,9 @@ yynewstate:
 yysetstate:
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
   YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
-   *yyssp = YY_CAST (yy_state_t, yystate);
+  YY_IGNORE_USELESS_CAST_BEGIN
+  *yyssp = YY_CAST (yy_state_t, yystate);
+  YY_IGNORE_USELESS_CAST_END
 
   if (yyss + yystacksize - 1 <= yyssp)
 #if !defined yyoverflow && !defined YYSTACK_RELOCATE
@@ -1552,8 +1560,10 @@ yysetstate:
       yyvsp = yyvs + yysize - 1;]b4_locations_if([
       yylsp = yyls + yysize - 1;])[
 
+      YY_IGNORE_USELESS_CAST_BEGIN
       YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                   YY_CAST (long, yystacksize)));
+      YY_IGNORE_USELESS_CAST_END
 
       if (yyss + yystacksize - 1 <= yyssp)
         YYABORT;
