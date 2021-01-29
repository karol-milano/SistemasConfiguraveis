@@ -373,9 +373,9 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
 {
-  yytype_int16 yyss;
-  YYSTYPE yyvs;
-  ]b4_locations_if([  YYLTYPE yyls;
+  yytype_int16 yyss_alloc;
+  YYSTYPE yyvs_alloc;
+  ]b4_locations_if([  YYLTYPE yyls_alloc;
 ])dnl
 [};
 
@@ -415,12 +415,12 @@ union yyalloc
    elements in the stack, and YYPTR gives the new location of the
    stack.  Advance YYPTR to a properly aligned location for the next
    stack.  */
-# define YYSTACK_RELOCATE(Stack)					\
+# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
     do									\
       {									\
 	YYSIZE_T yynewbytes;						\
-	YYCOPY (&yyptr->Stack, Stack, yysize);				\
-	Stack = &yyptr->Stack;						\
+	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
+	Stack = &yyptr->Stack_alloc;					\
 	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
 	yyptr += yynewbytes / sizeof (*yyptr);				\
       }									\
@@ -1277,9 +1277,9 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
 	if (! yyptr)
 	  goto yyexhaustedlab;
-	YYSTACK_RELOCATE (yyss);
-	YYSTACK_RELOCATE (yyvs);
-]b4_locations_if([	YYSTACK_RELOCATE (yyls);])[
+	YYSTACK_RELOCATE (yyss_alloc, yyss);
+	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
+]b4_locations_if([	YYSTACK_RELOCATE (yyls_alloc, yyls);])[
 #  undef YYSTACK_RELOCATE
 	if (yyss1 != ]b4_yyssa[)
 	  YYSTACK_FREE (yyss1);
