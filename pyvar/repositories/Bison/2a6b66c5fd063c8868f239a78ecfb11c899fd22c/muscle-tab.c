@@ -398,6 +398,7 @@ muscle_percent_variable_update (char const *variable, location variable_loc)
   const conversion_type conversion[] =
     {
       { "api.push_pull", "api.push-pull", },
+      { "api.tokens.prefix", "api.token.prefix", },
       { "location_type", "api.location.type", },
       { "lr.keep_unreachable_states", "lr.keep-unreachable-states", },
       { "namespace", "api.namespace", },
