@@ -464,7 +464,7 @@ typedef short int yytype_int16;
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
 
 # ifdef YYSTACK_ALLOC
-   /* Pacify GCC's `empty if-body' warning.  */
+   /* Pacify GCC's 'empty if-body' warning.  */
 #  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
 #  ifndef YYSTACK_ALLOC_MAXIMUM
     /* The OS might guarantee only one guard page at the bottom of the stack,
@@ -1794,9 +1794,9 @@ YYLTYPE yylloc = yyloc_default;
     int yyerrstatus;
 
     /* The stacks and their tools:
-       `yyss': related to states.
-       `yyvs': related to semantic values.
-       `yyls': related to locations.
+       'yyss': related to states.
+       'yyvs': related to semantic values.
+       'yyls': related to locations.
 
        Refer to the stacks through separate pointers, to allow yyoverflow
        to reallocate them elsewhere.  */
@@ -2050,7 +2050,7 @@ yyreduce:
   yylen = yyr2[yyn];
 
   /* If YYLEN is nonzero, implement the default value of the action:
-     `$$ = $1'.
+     '$$ = $1'.
 
      Otherwise, the following line sets YYVAL to garbage.
      This behavior is undocumented and Bison
@@ -2780,7 +2780,7 @@ yyreduce:
   *++yyvsp = yyval;
   *++yylsp = yyloc;
 
-  /* Now `shift' the result of the reduction.  Determine what state
+  /* Now 'shift' the result of the reduction.  Determine what state
      that goes to, based on the state we popped back to and the rule
      number reduced by.  */
 
