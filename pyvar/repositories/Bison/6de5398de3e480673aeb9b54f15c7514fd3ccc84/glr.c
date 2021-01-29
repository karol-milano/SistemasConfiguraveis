@@ -116,7 +116,7 @@ m4_define([b4_lhs_value],
 # Expansion of $<TYPE>NUM, where the current rule has RULE-LENGTH
 # symbols on RHS.
 m4_define([b4_rhs_value],
-[(((yyGLRStackItem const *)yyvsp)@{YYFILL ($2 - $1)@}.yystate.yysemantics.yysval[]m4_ifval([$3], [.$3]))])
+[(((yyGLRStackItem const *)yyvsp)@{YYFILL (($2) - ($1))@}.yystate.yysemantics.yysval[]m4_ifval([$3], [.$3]))])
 
 
 
@@ -136,7 +136,7 @@ m4_define([b4_lhs_location],
 # Expansion of @NUM, where the current rule has RULE-LENGTH symbols
 # on RHS.
 m4_define([b4_rhs_location],
-[(((yyGLRStackItem const *)yyvsp)@{YYFILL ($2 - $1)@}.yystate.yyloc)])
+[(((yyGLRStackItem const *)yyvsp)@{YYFILL (($2) - ($1))@}.yystate.yyloc)])
 
 
 
@@ -1382,14 +1382,13 @@ yy_reduce_print (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 [  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
 	     (unsigned long int) yyk, yyrule - 1,
 	     (unsigned long int) yyrline[yyrule]);
-  /* Print the symbols being reduced, and their result.  */
-  //for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
+  /* The symbols being reduced.  */
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
       fprintf (stderr, "   $%d = ", yyi + 1);
       yysymprint (stderr, yyrhs[yyprhs[yyrule] + yyi],
-                  &]b4_rhs_value(yynrhs, yyi)[
-                  ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi))[]dnl
+                  &]b4_rhs_value(yynrhs, yyi - 1)[
+                  ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi - 1))[]dnl
 	          b4_user_args[);
       fprintf (stderr, "\n");
     }
