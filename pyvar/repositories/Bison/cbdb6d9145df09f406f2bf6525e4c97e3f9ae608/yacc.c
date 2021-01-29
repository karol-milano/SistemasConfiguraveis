@@ -197,7 +197,7 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
        `yyvs': related to semantic values.]b4_locations_if([[
        `yyls': related to locations.]])[
 
-       Refer to the stacks thru separate pointers, to allow yyoverflow
+       Refer to the stacks through separate pointers, to allow yyoverflow
        to reallocate them elsewhere.  */
 
     /* The state stack.  */
