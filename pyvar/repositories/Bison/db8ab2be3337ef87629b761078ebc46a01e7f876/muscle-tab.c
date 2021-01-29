@@ -410,6 +410,7 @@ muscle_percent_variable_update (char const *variable)
   const conversion_type conversion[] =
     {
       { "api.push_pull", "api.push-pull", },
+      { "location_type", "api.location.type", },
       { "lr.keep_unreachable_states", "lr.keep-unreachable-states", },
     };
   char const *res = variable;
