@@ -113,9 +113,8 @@ m4_ifset([b4_parse_param], [b4_args(b4_parse_param), ])])
 # b4_int_type(MIN, MAX)
 # ---------------------
 # Return a narrow int type able to handle numbers ranging from
-# MIN to MAX (included).  Overwrite the version from c.m4, which
-# uses only C89 types, so that the user can override the shorter
-# types, and so that pre-C89 compilers are handled correctly.
+# MIN to MAX (included).  Overwrite the version from c.m4,
+# so that the user can override the shorter types.
 m4_define([b4_int_type],
 [m4_if(b4_ints_in($@,   [-127],   [127]), [1], [yytype_int8],
        b4_ints_in($@,      [0],   [255]), [1], [yytype_uint8],
@@ -125,18 +124,6 @@ m4_define([b4_int_type],
 
                                                [int])])
 
-# b4_state_num_type(MIN, MAX)
-# ---------------------------
-# Likewise, but prefer 'int' to 'unsigned' for large integers.
-m4_define([b4_state_num_type],
-[m4_if(b4_ints_in($@,      [0],   [255]), [1], [yytype_uint8],
-       b4_ints_in($@,   [-128],   [127]), [1], [yytype_int8],
-
-       b4_ints_in($@,      [0], [65535]), [1], [yytype_uint16],
-       b4_ints_in($@, [-32768], [32767]), [1], [yytype_int16],
-
-                                               [int])])
-
 
 ## ----------------- ##
 ## Semantic Values.  ##
@@ -464,7 +451,7 @@ typedef short yytype_int16;
 
 
 /* State numbers. */
-typedef ]b4_state_num_type(0, m4_eval(b4_states_number - 1))[ yy_state_num;
+typedef ]b4_int_type(0, m4_eval(b4_states_number - 1))[ yy_state_num;
 
 
 #ifndef YY_
@@ -481,6 +468,18 @@ typedef ]b4_state_num_type(0, m4_eval(b4_states_number - 1))[ yy_state_num;
 
 ]b4_attribute_define[
 
+/* Suppress bogus -Wconversion warnings from GCC.  */
+#if 4 < __GNUC__ + (7 <= __GNUC_MINOR__)
+# define YY_CONVERT_INT_BEGIN \
+    _Pragma ("GCC diagnostic push") \
+    _Pragma ("GCC diagnostic ignored \"-Wconversion\"")
+# define YY_CONVERT_INT_END \
+    _Pragma ("GCC diagnostic pop")
+#else
+# define YY_CONVERT_INT_BEGIN
+# define YY_CONVERT_INT_END
+#endif
+
 ]b4_parse_assert_if([[#ifdef NDEBUG
 # define YY_ASSERT(E) ((void) (0 && (E)))
 #else
@@ -650,7 +649,7 @@ union yyalloc
 ]b4_api_token_raw_if(dnl
 [[#define YYTRANSLATE(YYX) (YYX)]],
 [[#define YYTRANSLATE(YYX)                                                \
-  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
+  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex.  */
@@ -773,7 +772,10 @@ do {                                                                      \
 {
   YYFPRINTF (stderr, "Stack now");
   for (; yybottom <= yytop; yybottom++)
-    YYFPRINTF (stderr, " %u", (unsigned) *yybottom);
+    {
+      int yybot = *yybottom;
+      YYFPRINTF (stderr, " %d", yybot);
+    }
   YYFPRINTF (stderr, "\n");
 }
 
@@ -1015,7 +1017,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
         }
       else
         {
-          yyrule = (int) yytable[yyrule];
+          yyrule = yytable[yyrule];
           if (yytable_value_is_error (yyrule))
             {
               YYDPRINTF ((stderr, " Err\n"));
@@ -1052,15 +1054,17 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
         int yystate;
         {
           const int yylhs = yyr1[yyrule] - YYNTOKENS;
-          const int yyi = yypgoto[yylhs] + (int) *yyesp;
+          const int yyi = yypgoto[yylhs] + *yyesp;
           yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
-                     ? (int) yytable[yyi]
+                     ? yytable[yyi]
                      : yydefgoto[yylhs]);
         }
         if (yyesp == yyes_prev)
           {
             yyesp = *yyes;
-            *yyesp = (yy_state_num) yystate;
+            YY_CONVERT_INT_BEGIN
+            *yyesp = yystate;
+            YY_CONVERT_INT_END
           }
         else
           {
@@ -1073,7 +1077,9 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
                 YYDPRINTF ((stderr, "\n"));
                 return 2;
               }
-            *++yyesp = (yy_state_num) yystate;
+            YY_CONVERT_INT_BEGIN
+            *++yyesp = yystate;
+            YY_CONVERT_INT_END
           }
         YYDPRINTF ((stderr, " G%d", yystate));
       }
@@ -1536,7 +1542,9 @@ yynewstate:
 yysetstate:
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
   YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
-  *yyssp = (yy_state_num) yystate;
+  YY_CONVERT_INT_BEGIN
+  *yyssp = yystate;
+  YY_CONVERT_INT_END
 
   if (yyss + yystacksize - 1 <= yyssp)
 #if !defined yyoverflow && !defined YYSTACK_RELOCATE
@@ -1670,7 +1678,7 @@ yyread_pushed_token:]])[
       goto yydefault;
     }]], [[
     goto yydefault;]])[
-  yyn = (int) yytable[yyn];
+  yyn = yytable[yyn];
   if (yyn <= 0)
     {
       if (yytable_value_is_error (yyn))
@@ -1772,9 +1780,9 @@ yyreduce:
      number reduced by.  */
   {
     const int yylhs = yyr1[yyn] - YYNTOKENS;
-    const int yyi = yypgoto[yylhs] + (int) *yyssp;
+    const int yyi = yypgoto[yylhs] + *yyssp;
     yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
-               ? (int) yytable[yyi]
+               ? yytable[yyi]
                : yydefgoto[yylhs]);
   }
 
@@ -1890,7 +1898,7 @@ yyerrlab1:
           yyn += YYTERROR;
           if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
             {
-              yyn = (int) yytable[yyn];
+              yyn = yytable[yyn];
               if (0 < yyn)
                 break;
             }
