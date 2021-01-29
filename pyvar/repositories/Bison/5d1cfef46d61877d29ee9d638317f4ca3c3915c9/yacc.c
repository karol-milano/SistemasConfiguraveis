@@ -1018,10 +1018,10 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
 #endif
 
-  /* Three stacks and their tools:
-     `yyss': related to states,
-     `yyvs': related to semantic values,
-     `yyls': related to locations.
+  /* The stacks and their tools:
+     `yyss' is related to states.
+     `yyvs' is related to semantic values.]b4_locations_if([[
+     `yyls' is related to locations.]])[
 
      Refer to the stacks thru separate pointers, to allow yyoverflow
      to reallocate them elsewhere.  */
