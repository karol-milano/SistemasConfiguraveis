@@ -127,6 +127,18 @@ m4_define([b4_int_type],
 
                                                [int])])
 
+# b4_state_num_type(MIN, MAX)
+# ---------------------------
+# Likewise, but prefer 'int' to 'unsigned' for large integers.
+m4_define([b4_state_num_type],
+[m4_if(b4_ints_in($@,      [0],   [255]), [1], [yytype_uint8],
+       b4_ints_in($@,   [-128],   [127]), [1], [yytype_int8],
+
+       b4_ints_in($@,      [0], [65535]), [1], [yytype_uint16],
+       b4_ints_in($@, [-32768], [32767]), [1], [yytype_int16],
+
+                                               [int])])
+
 
 ## ----------------- ##
 ## Semantic Values.  ##
@@ -432,7 +444,7 @@ typedef short yytype_int16;
 
 
 /* State numbers. */
-typedef yytype_int16 yy_state_num;
+typedef ]b4_state_num_type(0, m4_eval(b4_states_number - 1))[ yy_state_num;
 
 
 #ifndef YY_
@@ -740,10 +752,7 @@ do {                                                                      \
 {
   YYFPRINTF (stderr, "Stack now");
   for (; yybottom <= yytop; yybottom++)
-    {
-      int yybot = *yybottom;
-      YYFPRINTF (stderr, " %d", yybot);
-    }
+    YYFPRINTF (stderr, " %u", (unsigned) *yybottom);
   YYFPRINTF (stderr, "\n");
 }
 
@@ -985,7 +994,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
         }
       else
         {
-          yyrule = yytable[yyrule];
+          yyrule = (int) yytable[yyrule];
           if (yytable_value_is_error (yyrule))
             {
               YYDPRINTF ((stderr, " Err\n"));
@@ -1022,11 +1031,10 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
         int yystate;
         {
           const int yylhs = yyr1[yyrule] - YYNTOKENS;
-          const int yyi = yypgoto[yylhs] + *yyesp;
-          yystate = ((yy_state_num)
-                     (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
-                      ? yytable[yyi]
-                      : yydefgoto[yylhs]));
+          const int yyi = yypgoto[yylhs] + (int) *yyesp;
+          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
+                     ? (int) yytable[yyi]
+                     : yydefgoto[yylhs]);
         }
         if (yyesp == yyes_prev)
           {
@@ -1046,7 +1054,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
               }
             *++yyesp = (yy_state_num) yystate;
           }
-        YYDPRINTF ((stderr, " G%d", (int) yystate));
+        YYDPRINTF ((stderr, " G%d", yystate));
       }
     }
 }]])[
@@ -1639,7 +1647,7 @@ yyread_pushed_token:]])[
       goto yydefault;
     }]], [[
     goto yydefault;]])[
-  yyn = yytable[yyn];
+  yyn = (int) yytable[yyn];
   if (yyn <= 0)
     {
       if (yytable_value_is_error (yyn))
@@ -1661,7 +1669,7 @@ yyread_pushed_token:]])[
   yychar = YYEMPTY;]b4_lac_if([[
   YY_LAC_DISCARD ("shift");]])[
 
-  yystate = (yy_state_num) yyn;
+  yystate = yyn;
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   *++yyvsp = yylval;
   YY_IGNORE_MAYBE_UNINITIALIZED_END]b4_locations_if([
@@ -1741,9 +1749,9 @@ yyreduce:
      number reduced by.  */
   {
     const int yylhs = yyr1[yyn] - YYNTOKENS;
-    const int yyi = yypgoto[yylhs] + *yyssp;
+    const int yyi = yypgoto[yylhs] + (int) *yyssp;
     yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
-               ? yytable[yyi]
+               ? (int) yytable[yyi]
                : yydefgoto[yylhs]);
   }
 
@@ -1859,7 +1867,7 @@ yyerrlab1:
           yyn += YYTERROR;
           if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
             {
-              yyn = yytable[yyn];
+              yyn = (int) yytable[yyn];
               if (0 < yyn)
                 break;
             }
@@ -1894,7 +1902,7 @@ yyerrlab1:
   /* Shift the error token.  */
   YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);
 
-  yystate = (yy_state_num) yyn;
+  yystate = yyn;
   goto yynewstate;
 
 
