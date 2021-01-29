@@ -3,7 +3,7 @@
 # Yacc compatible skeleton for Bison
 
 # Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
-# 2007 Free Software Foundation, Inc.
+# 2007, 2008 Free Software Foundation, Inc.
 
 # This program is free software: you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
@@ -168,7 +168,6 @@ b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
    USER NAME SPACE" below.  */
 
 ]b4_identification
-
 b4_percent_code_get([[top]])[]dnl
 m4_if(b4_prefix, [yy], [],
 [[/* Substitute the variable and function names.  */
@@ -223,9 +222,9 @@ b4_token_enums_defines(b4_tokens)[
 # define YYSTYPE_IS_TRIVIAL 1]])])[
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
-#endif
+#endif]b4_locations_if([[
 
-]b4_locations_if([#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
+#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
 typedef struct YYLTYPE
 {
   int first_line;
@@ -236,9 +235,9 @@ typedef struct YYLTYPE
 # define yyltype YYLTYPE /* obsolescent; will be withdrawn */
 # define YYLTYPE_IS_DECLARED 1
 # define YYLTYPE_IS_TRIVIAL 1
-#endif])
+#endif]])b4_push_if([[
 
-b4_push_if([[#ifndef YYPUSH_DECLS
+#ifndef YYPUSH_DECLS
 #  define YYPUSH_DECLS
 struct yypstate;
 typedef struct yypstate yypstate;
@@ -257,8 +256,8 @@ b4_pull_if([b4_c_function_decl([[yypull_parse]], [[int]],
 b4_c_function_decl([[yypstate_new]], [[yypstate *]], [[[void]], []])
 b4_c_function_decl([[yypstate_delete]], [[void]],
                    [[[yypstate *yyps]], [[yyps]]])[
-#endif
-]])
+#endif]])
+
 b4_percent_code_get([[provides]])[]dnl
 
 [/* Copy the second part of user declarations.  */
@@ -417,10 +416,9 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 union yyalloc
 {
   yytype_int16 yyss_alloc;
-  YYSTYPE yyvs_alloc;
-  ]b4_locations_if([  YYLTYPE yyls_alloc;
-])dnl
-[};
+  YYSTYPE yyvs_alloc;]b4_locations_if([
+  YYLTYPE yyls_alloc;])[
+};
 
 /* The size of the maximum gap between one aligned stack and the next.  */
 # define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)
@@ -1041,10 +1039,10 @@ m4_define([b4_declare_parser_state_variables],
     /* Number of tokens to shift before error messages enabled.  */
     int yyerrstatus;
 
-    /* Three stacks and their tools:
-       `yyss': related to states,
-       `yyvs': related to semantic values,
-       `yyls': related to locations.
+    /* The stacks and their tools:
+       `yyss': related to states.
+       `yyvs': related to semantic values.]b4_locations_if([[
+       `yyls': related to locations.]])[
 
        Refer to the stacks thru separate pointers, to allow yyoverflow
        to reallocate them elsewhere.  */
@@ -1169,11 +1167,9 @@ static char yypstate_allocated = 0;]])[
 #define yyerror_range yyps->yyerror_range
 ]])[#define yystacksize yyps->yystacksize
 ]])[
-
 /*-------------------------.
 | yyparse or yypush_parse.  |
 `-------------------------*/
-
 ]b4_push_if([
 b4_c_function_def([[yypush_parse]], [[int]],
   [[[yypstate *yyps]], [[yyps]]]b4_pure_if([,
@@ -1195,7 +1191,7 @@ b4_push_if([b4_pure_if([], [[  int yypushed_char = yychar;
   [b4_declare_parser_state_variables])[
   int yyn;
   int yyresult;
-  /* Look-ahead token as an internal (translated) token number.  */
+  /* Lookahead token as an internal (translated) token number.  */
   int yytoken;
   /* The variables used to return semantic value and location from the
      action routines.  */
@@ -1240,16 +1236,15 @@ b4_push_if([b4_pure_if([], [[  int yypushed_char = yychar;
      so that they stay on the same level as the state stack.
      The wasted elements are never initialized.  */
   yyssp = yyss;
-  yyvsp = yyvs;
-]b4_locations_if([[  yylsp = yyls;
+  yyvsp = yyvs;]b4_locations_if([[
+  yylsp = yyls;
 
 #if YYLTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
   yylloc.first_line   = yylloc.last_line   = ]b4_location_initial_line[;
   yylloc.first_column = yylloc.last_column = ]b4_location_initial_column[;
-#endif
-]])
-m4_ifdef([b4_initial_action], [
+#endif]])
+m4_ifdef([b4_initial_action],[
 m4_pushdef([b4_at_dollar],     [m4_define([b4_at_dollar_used])yylloc])dnl
 m4_pushdef([b4_dollar_dollar], [m4_define([b4_dollar_dollar_used])yylval])dnl
 /* User initialization code.  */
@@ -1259,8 +1254,7 @@ m4_popdef([b4_at_dollar])])dnl
 m4_ifdef([b4_dollar_dollar_used],[[  yyvsp[0] = yylval;
 ]])dnl
 m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
-]])dnl
-[
+]])[
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -1285,8 +1279,8 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	   these so that the &'s don't force the real ones into
 	   memory.  */
 	YYSTYPE *yyvs1 = yyvs;
-	yytype_int16 *yyss1 = yyss;
-]b4_locations_if([	YYLTYPE *yyls1 = yyls;])[
+	yytype_int16 *yyss1 = yyss;]b4_locations_if([
+	YYLTYPE *yyls1 = yyls;])[
 
 	/* Each stack pointer address is followed by the size of the
 	   data in use in that stack, in bytes.  This used to be a
@@ -1294,10 +1288,11 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	   be undefined if yyoverflow is a macro.  */
 	yyoverflow (YY_("memory exhausted"),
 		    &yyss1, yysize * sizeof (*yyssp),
-		    &yyvs1, yysize * sizeof (*yyvsp),
-]b4_locations_if([		    &yyls1, yysize * sizeof (*yylsp),])[
+		    &yyvs1, yysize * sizeof (*yyvsp),]b4_locations_if([
+		    &yyls1, yysize * sizeof (*yylsp),])[
 		    &yystacksize);
-]b4_locations_if([	yyls = yyls1;])[
+]b4_locations_if([
+	yyls = yyls1;])[
 	yyss = yyss1;
 	yyvs = yyvs1;
       }
@@ -1319,8 +1314,8 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	if (! yyptr)
 	  goto yyexhaustedlab;
 	YYSTACK_RELOCATE (yyss_alloc, yyss);
-	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
-]b4_locations_if([	YYSTACK_RELOCATE (yyls_alloc, yyls);])[
+	YYSTACK_RELOCATE (yyvs_alloc, yyvs);]b4_locations_if([
+	YYSTACK_RELOCATE (yyls_alloc, yyls);])[
 #  undef YYSTACK_RELOCATE
 	if (yyss1 != yyssa)
 	  YYSTACK_FREE (yyss1);
@@ -1329,8 +1324,8 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 #endif /* no yyoverflow */
 
       yyssp = yyss + yysize - 1;
-      yyvsp = yyvs + yysize - 1;
-]b4_locations_if([      yylsp = yyls + yysize - 1;])[
+      yyvsp = yyvs + yysize - 1;]b4_locations_if([
+      yylsp = yyls + yysize - 1;])[
 
       YYDPRINTF ((stderr, "Stack size increased to %lu\n",
 		  (unsigned long int) yystacksize));
@@ -1475,8 +1470,8 @@ yyreduce:
   yylen = 0;
   YY_STACK_PRINT (yyss, yyssp);
 
-  *++yyvsp = yyval;
-]b4_locations_if([  *++yylsp = yyloc;])[
+  *++yyvsp = yyval;]b4_locations_if([
+  *++yylsp = yyloc;])[
 
   /* Now `shift' the result of the reduction.  Determine what state
      that goes to, based on the state we popped back to and the rule
@@ -1646,7 +1641,7 @@ yyabortlab:
   yyresult = 1;
   goto yyreturn;
 
-#ifndef yyoverflow
+#if !defined(yyoverflow) || YYERROR_VERBOSE
 /*-------------------------------------------------.
 | yyexhaustedlab -- memory exhaustion comes here.  |
 `-------------------------------------------------*/
@@ -1728,8 +1723,8 @@ typedef struct YYLTYPE
 
 ]b4_pure_if([], [[extern YYLTYPE ]b4_prefix[lloc;]])
 )dnl b4_locations_if
-
-b4_push_if([[#ifndef YYPUSH_DECLS
+b4_push_if([[
+#ifndef YYPUSH_DECLS
 #  define YYPUSH_DECLS
 struct ]b4_prefix[pstate;
 typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
