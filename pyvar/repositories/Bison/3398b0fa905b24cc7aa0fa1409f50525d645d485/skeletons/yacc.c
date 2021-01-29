@@ -339,13 +339,13 @@ m4_if(b4_api_prefix, [yy], [],
 #define yylex           ]b4_prefix[lex
 #define yyerror         ]b4_prefix[error
 #define yydebug         ]b4_prefix[debug
-#define yynerrs         ]b4_prefix[nerrs
-]]b4_pure_if([], [[
+#define yynerrs         ]b4_prefix[nerrs]]b4_pure_if([], [[
 #define yylval          ]b4_prefix[lval
 #define yychar          ]b4_prefix[char]b4_locations_if([[
 #define yylloc          ]b4_prefix[lloc]])]))[
 
 ]b4_user_pre_prologue[
+]b4_cast_define[
 ]b4_null_define[
 
 /* Enabling verbose error messages.  */
@@ -400,10 +400,13 @@ m4_if(b4_api_prefix, [yy], [],
 # endif
 #endif
 
-#define YYSIZE_MAXIMUM ((YYPTRDIFF_T) (YYPTRDIFF_MAXIMUM < (YYSIZE_T) -1 \
-                                       ? YYPTRDIFF_MAXIMUM : (YYSIZE_T) -1))
+#define YYSIZE_MAXIMUM                                  \
+  YY_CAST (YYPTRDIFF_T,                                 \
+           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
+            ? YYPTRDIFF_MAXIMUM                         \
+            : YY_CAST (YYSIZE_T, -1)))
 
-#define YYSIZEOF(X) ((YYPTRDIFF_T) sizeof (X))
+#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))
 
 /* Stored state numbers (used for stacks). */
 typedef ]b4_int_type(0, m4_eval(b4_states_number - 1))[ yy_state_t;
@@ -557,7 +560,7 @@ union yyalloc
 # ifndef YYCOPY
 #  if defined __GNUC__ && 1 < __GNUC__
 #   define YYCOPY(Dst, Src, Count) \
-      __builtin_memcpy (Dst, Src, (YYSIZE_T) (Count) * sizeof (*(Src)))
+      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
 #  else
 #   define YYCOPY(Dst, Src, Count)              \
       do                                        \
@@ -832,8 +835,8 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
       yybottom_new =
-        (yy_state_t *) YYSTACK_ALLOC ((YYSIZE_T)
-                                        (yyalloc * YYSIZEOF (*yybottom_new)));
+        YY_CAST(yy_state_t *,
+                YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yyalloc * YYSIZEOF (*yybottom_new))));
       if (!yybottom_new)
         {
           YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
@@ -851,7 +854,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
       *yycapacity = yyalloc;]m4_if(b4_percent_define_get([[parse.lac.memory-trace]]),
                                    [full], [[
       YYDPRINTF ((stderr, "%srealloc to %ld%s", yydebug_prefix,
-                  (long) yyalloc, yydebug_suffix));]])[
+                  YY_CAST (long, yyalloc), yydebug_suffix));]])[
     }
   return 0;
 }
@@ -1008,7 +1011,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
         if (yyesp == yyes_prev)
           {
             yyesp = *yyes;
-            *yyesp = (yy_state_t) yystate;
+            *yyesp = YY_CAST (yy_state_t, yystate);
           }
         else
           {
@@ -1021,7 +1024,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
                 YYDPRINTF ((stderr, "\n"));
                 return 2;
               }
-            *++yyesp = (yy_state_t) yystate;
+            *++yyesp = YY_CAST (yy_state_t, yystate);
           }
         YYDPRINTF ((stderr, " G%d", yystate));
       }
@@ -1033,7 +1036,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
 
 # ifndef yystrlen
 #  if defined __GLIBC__ && defined _STRING_H
-#   define yystrlen(S) ((YYPTRDIFF_T) strlen (S))
+#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
 #  else
 /* Return the length of YYSTR.  */
 ]b4_function_define([yystrlen], [static YYPTRDIFF_T],
@@ -1342,7 +1345,7 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
   yypstate *yyps;]b4_pure_if([], [[
   if (yypstate_allocated)
     return YY_NULLPTR;]])[
-  yyps = (yypstate *) malloc (sizeof *yyps);
+  yyps = YY_CAST (yypstate *, malloc (sizeof *yyps));
   if (!yyps)
     return YY_NULLPTR;
   yyps->yynew = 1;]b4_pure_if([], [[
@@ -1484,7 +1487,7 @@ yynewstate:
 yysetstate:
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
   YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
-   *yyssp = (yy_state_t) yystate;
+   *yyssp = YY_CAST (yy_state_t, yystate);
 
   if (yyss + yystacksize - 1 <= yyssp)
 #if !defined yyoverflow && !defined YYSTACK_RELOCATE
@@ -1527,8 +1530,8 @@ yysetstate:
       {
         yy_state_t *yyss1 = yyss;
         union yyalloc *yyptr =
-          (union yyalloc *) YYSTACK_ALLOC ((YYSIZE_T)
-                                           YYSTACK_BYTES (yystacksize));
+          YY_CAST (union yyalloc *,
+                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
         if (! yyptr)
           goto yyexhaustedlab;
         YYSTACK_RELOCATE (yyss_alloc, yyss);
@@ -1545,7 +1548,7 @@ yysetstate:
       yylsp = yyls + yysize - 1;])[
 
       YYDPRINTF ((stderr, "Stack size increased to %ld\n",
-                  (long) yystacksize));
+                  YY_CAST (long, yystacksize)));
 
       if (yyss + yystacksize - 1 <= yyssp)
         YYABORT;
@@ -1758,7 +1761,7 @@ yyerrlab:
           {
             if (yymsg != yymsgbuf)
               YYSTACK_FREE (yymsg);
-            yymsg = (char *) YYSTACK_ALLOC ((YYSIZE_T) yymsg_alloc);
+            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
             if (!yymsg)
               {
                 yymsg = yymsgbuf;
