@@ -1453,11 +1453,14 @@ yysetstate:
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
@@ -1479,10 +1482,7 @@ yysetstate:
         yyvs = yyvs1;]b4_locations_if([
         yyls = yyls1;])[
       }
-#else /* no yyoverflow */
-# ifndef YYSTACK_RELOCATE
-      goto yyexhaustedlab;
-# else
+# else /* defined YYSTACK_RELOCATE */
       /* Extend the stack our own way.  */
       if (YYMAXDEPTH <= yystacksize)
         goto yyexhaustedlab;
@@ -1499,12 +1499,11 @@ yysetstate:
         YYSTACK_RELOCATE (yyss_alloc, yyss);
         YYSTACK_RELOCATE (yyvs_alloc, yyvs);]b4_locations_if([
         YYSTACK_RELOCATE (yyls_alloc, yyls);])[
-#  undef YYSTACK_RELOCATE
+# undef YYSTACK_RELOCATE
         if (yyss1 != yyssa)
           YYSTACK_FREE (yyss1);
       }
 # endif
-#endif /* no yyoverflow */
 
       yyssp = yyss + yysize - 1;
       yyvsp = yyvs + yysize - 1;]b4_locations_if([
@@ -1516,6 +1515,7 @@ yysetstate:
       if (yyss + yystacksize - 1 <= yyssp)
         YYABORT;
     }
+#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */
 
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
 
