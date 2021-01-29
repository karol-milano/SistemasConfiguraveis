@@ -918,27 +918,19 @@ yybackup:
       YYDPRINTF ((stderr, "\n"));
     }
 
-  /* Set YYN to the action to take in STATE on seeing token YYCHAR1.
-     Result YYN means
-     - YYN < 0:  Reduce on rule -YYN.
-     - YYN = 0:  Error.
-     - YYN > 0:  Shift to state YYN.  */
+  /* If the proper action on seeing token YYCHAR1 is to reduce or to
+     detect an error, take that action.  */
   yyn += yychar1;
   if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yychar1)
-    /* Defaulted action (reduction).  */
-    yyn = -yydefact[yystate];
-  else if (yytable[yyn] != YYTABLE_NINF)
-    yyn = yytable[yyn];
-  else
-    yyn = 0;
-
-  if (yyn < 0)
+    goto yydefault;
+  yyn = yytable[yyn];
+  if (yyn <= 0)
     {
+      if (yyn == 0 || yyn == YYTABLE_NINF)
+	goto yyerrlab;
       yyn = -yyn;
       goto yyreduce;
     }
-  else if (yyn == 0)
-    goto yyerrlab;
 
   if (yyn == YYFINAL)
     YYACCEPT;
