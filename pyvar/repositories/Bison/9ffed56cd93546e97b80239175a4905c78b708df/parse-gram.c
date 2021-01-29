@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.2.2.  */
+/* A Bison parser, made by GNU Bison 3.2.1.46-77eb-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -47,7 +47,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.2.2"
+#define YYBISON_VERSION "3.2.1.46-77eb-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1905,11 +1905,14 @@ yysetstate:
   *yyssp = (yytype_int16) yystate;
 
   if (yyss + yystacksize - 1 <= yyssp)
+#if !defined yyoverflow && !defined YYSTACK_RELOCATE
+    goto yyexhaustedlab;
+#else
     {
       /* Get the current used size of the three stacks, in elements.  */
       YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);
 
-#ifdef yyoverflow
+# if defined yyoverflow
       {
         /* Give user a chance to reallocate the stack.  Use copies of
            these so that the &'s don't force the real ones into
@@ -1931,10 +1934,7 @@ yysetstate:
         yyvs = yyvs1;
         yyls = yyls1;
       }
-#else /* no yyoverflow */
-# ifndef YYSTACK_RELOCATE
-      goto yyexhaustedlab;
-# else
+# else /* defined YYSTACK_RELOCATE */
       /* Extend the stack our own way.  */
       if (YYMAXDEPTH <= yystacksize)
         goto yyexhaustedlab;
@@ -1951,12 +1951,11 @@ yysetstate:
         YYSTACK_RELOCATE (yyss_alloc, yyss);
         YYSTACK_RELOCATE (yyvs_alloc, yyvs);
         YYSTACK_RELOCATE (yyls_alloc, yyls);
-#  undef YYSTACK_RELOCATE
+# undef YYSTACK_RELOCATE
         if (yyss1 != yyssa)
           YYSTACK_FREE (yyss1);
       }
 # endif
-#endif /* no yyoverflow */
 
       yyssp = yyss + yysize - 1;
       yyvsp = yyvs + yysize - 1;
@@ -1968,6 +1967,7 @@ yysetstate:
       if (yyss + yystacksize - 1 <= yyssp)
         YYABORT;
     }
+#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */
 
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
 
@@ -2854,11 +2854,10 @@ yyerrlab:
 | yyerrorlab -- error raised explicitly by YYERROR.  |
 `---------------------------------------------------*/
 yyerrorlab:
-  /* Pacify compilers like GCC when the user code never invokes
-     YYERROR and the label yyerrorlab therefore never appears in user
-     code.  */
+  /* Pacify compilers when the user code never invokes YYERROR and the
+     label yyerrorlab therefore never appears in user code.  */
   if (0)
-    goto yyerrorlab;
+    YYERROR;
 
   /* Do not reclaim the symbols of the rule whose action triggered
      this YYERROR.  */
@@ -2983,7 +2982,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 685 "src/parse-gram.y" /* yacc.c:1916  */
+#line 685 "src/parse-gram.y" /* yacc.c:1915  */
 
 
 /* Return the location of the left-hand side of a rule whose
