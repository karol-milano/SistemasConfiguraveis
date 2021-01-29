@@ -223,9 +223,9 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
     int yyerrstatus;
 
     /* The stacks and their tools:
-       `yyss': related to states.
-       `yyvs': related to semantic values.]b4_locations_if([[
-       `yyls': related to locations.]])[
+       'yyss': related to states.
+       'yyvs': related to semantic values.]b4_locations_if([[
+       'yyls': related to locations.]])[
 
        Refer to the stacks through separate pointers, to allow yyoverflow
        to reallocate them elsewhere.  */
@@ -468,7 +468,7 @@ b4_push_if([], [b4_lac_if([], [[
 # endif]])])[
 
 # ifdef YYSTACK_ALLOC
-   /* Pacify GCC's `empty if-body' warning.  */
+   /* Pacify GCC's 'empty if-body' warning.  */
 #  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
 #  ifndef YYSTACK_ALLOC_MAXIMUM
     /* The OS might guarantee only one guard page at the bottom of the stack,
@@ -1654,7 +1654,7 @@ yyreduce:
   yylen = yyr2[yyn];
 
   /* If YYLEN is nonzero, implement the default value of the action:
-     `$$ = $1'.
+     '$$ = $1'.
 
      Otherwise, the following line sets YYVAL to garbage.
      This behavior is undocumented and Bison
@@ -1702,7 +1702,7 @@ yyreduce:
   *++yyvsp = yyval;]b4_locations_if([
   *++yylsp = yyloc;])[
 
-  /* Now `shift' the result of the reduction.  Determine what state
+  /* Now 'shift' the result of the reduction.  Determine what state
      that goes to, based on the state we popped back to and the rule
      number reduced by.  */
 
