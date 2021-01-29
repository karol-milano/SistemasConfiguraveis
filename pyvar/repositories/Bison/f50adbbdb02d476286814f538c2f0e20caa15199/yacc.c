@@ -414,7 +414,8 @@ static const b4_int_type_for([b4_pgoto]) yypgoto[[]] =
 
 /* YYTABLE[[YYPACT[STATE-NUM]]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
-   number is the opposite.  If zero, do what YYDEFACT says.  */
+   number is the opposite.  If zero, do what YYDEFACT says.
+   If YYTABLE_NINF, parse error.  */
 #define YYTABLE_NINF b4_table_ninf
 static const b4_int_type_for([b4_table]) yytable[[]] =
 {
@@ -917,23 +918,22 @@ yybackup:
       YYDPRINTF ((stderr, "\n"));
     }
 
+  /* Set YYN to the action to take in STATE on seeing token YYCHAR1.
+     Result YYN means
+     - YYN < 0:  Reduce on rule -YYN.
+     - YYN = 0:  Error.
+     - YYN > 0:  Shift to state YYN.  */
   yyn += yychar1;
   if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yychar1)
-    goto yydefault;
-
-  yyn = yytable[yyn];
-
-  /* yyn is what to do for this token type in this state.
-     Negative => reduce, -yyn is rule number.
-     Positive => shift, yyn is new state.
-       New state is final state => don't bother to shift,
-       just return success.
-     0, or most negative number => error.  */
+    /* Defaulted action (reduction).  */
+    yyn = -yydefact[yystate];
+  else if (yytable[yyn] != YYTABLE_NINF)
+    yyn = yytable[yyn];
+  else
+    yyn = 0;
 
   if (yyn < 0)
     {
-      if (yyn == YYTABLE_NINF)
-	goto yyerrlab;
       yyn = -yyn;
       goto yyreduce;
     }
