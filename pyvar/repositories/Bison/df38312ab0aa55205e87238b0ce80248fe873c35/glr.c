@@ -730,10 +730,10 @@ yydefaultAction (yyStateNum yystate)
   return yydefact[yystate];
 }
 
-#define yyis_table_ninf(yyindex) \
+#define yyis_table_ninf(yytable_value) \
   ]m4_if(m4_eval(b4_table_ninf < b4_table_min), 1,
 	 0,
-	 ((yyindex) == YYTABLE_NINF))[
+	 ((yytable_value) == YYTABLE_NINF))[
 
 /** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
  *  Result R means
@@ -753,7 +753,7 @@ yygetLRActions (yyStateNum yystate, int yytoken,
       *yyaction = -yydefact[yystate];
       *yyconflicts = yyconfl;
     }
-  else if (! yyis_table_ninf (yyindex))
+  else if (! yyis_table_ninf (yytable[yyindex]))
     {
       *yyaction = yytable[yyindex];
       *yyconflicts = yyconfl + yyconflp[yyindex];
