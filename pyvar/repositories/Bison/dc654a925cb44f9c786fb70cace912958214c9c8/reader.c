@@ -619,7 +619,7 @@ packgram (void)
       /* If the midrule's $$ is set or its $n is used, remove the '$' from the
          symbol name so that it's a user-defined symbol so that the default
          %destructor and %printer apply.  */
-      if (lhs->midrule_parent_rule
+      if (lhs->midrule_parent_rule /* i.e., symbol_is_dummy (lhs->content.sym).  */
           && (lhs->action_props.is_value_used
               || (symbol_list_n_get (lhs->midrule_parent_rule,
                                      lhs->midrule_parent_rhs_index)
