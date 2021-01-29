@@ -400,7 +400,9 @@ muscle_percent_variable_update (char const *variable, location variable_loc)
       { "api.push_pull", "api.push-pull", },
       { "api.tokens.prefix", "api.token.prefix", },
       { "location_type", "api.location.type", },
-      { "lr.keep_unreachable_states", "lr.keep-unreachable-states", },
+      { "lr.default-reductions", "lr.default-reduction", },
+      { "lr.keep-unreachable-states", "lr.keep-unreachable-state", },
+      { "lr.keep_unreachable_states", "lr.keep-unreachable-state", },
       { "namespace", "api.namespace", },
     };
   char const *res = variable;
