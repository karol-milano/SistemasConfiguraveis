@@ -220,7 +220,6 @@ static YYLTYPE yyloc_default;
 
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  ]b4_final_state_number[
-#define YYFLAG	 ]b4_flag[
 #define YYLAST   ]b4_last[
 
 /* YYNTOKENS -- Number of terminals. */
@@ -341,17 +340,17 @@ static const ]b4_int_type_for([b4_table])[ yytable[] =
   ]b4_table[
 };
 
-/* YYCONFLP[YYPACT[STATE-NUM]] -- pointer into yyconfl of start of list
-   of conflicting reductions corresponding to action entry for state
-   STATE-NUM in yytable.  0 means no conflicts.  The list in yyconfl
-   is terminated by a rule number of 0. */
+/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
+   list of conflicting reductions corresponding to action entry for
+   state STATE-NUM in yytable.  0 means no conflicts.  The list in
+   yyconfl is terminated by a rule number of 0.  */
 static const ]b4_int_type_for([b4_conflict_list_heads])[ yyconflp[] =
 {
   ]b4_conflict_list_heads[
 };
 
-/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated
-   by 0, pointed into by YYCONFLP. */
+/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
+   0, pointed into by YYCONFLP.  */
 ]dnl Do not use b4_int_type_for here, since there are places where
 dnl pointers onto yyconfl are taken, which type is "short *".
 dnl We probably ought to introduce a type for confl.
@@ -1591,7 +1590,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	  /* Something's not right; we shouldn't be here.  */
 	  yyFail (yystack, NULL);
 	yyj += *yytokenp;
-	if (yyj < 0 || yyj > YYLAST || yycheck[yyj] != *yytokenp)
+	if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != *yytokenp)
 	  {
 	    if (yydefact[yystack->yytops.yystates[0]->yylrState] != 0)
 	      return;
