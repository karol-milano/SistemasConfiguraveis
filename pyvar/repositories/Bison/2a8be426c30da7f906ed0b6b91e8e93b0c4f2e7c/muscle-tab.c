@@ -388,7 +388,7 @@ muscle_user_name_list_grow (char const *key, char const *user_name,
  * otherwise \a variable. */
 static
 char const *
-muscle_percent_variable_update (char const *variable)
+muscle_percent_variable_update (char const *variable, location variable_loc)
 {
   typedef struct
   {
@@ -401,11 +401,18 @@ muscle_percent_variable_update (char const *variable)
       { "lr.keep_unreachable_states", "lr.keep-unreachable-states", },
       { "namespace", "api.namespace", },
     };
+  char const *res = variable;
   int i;
-  for (i = 0; i < sizeof conversion / sizeof *conversion; ++i)
+  for (i = 0; i < ARRAY_CARDINALITY (conversion); ++i)
     if (STREQ (conversion[i].obsolete, variable))
-      return conversion[i].updated;
-  return variable;
+      {
+        res = conversion[i].updated;
+        complain_at (variable_loc, Wdeprecated,
+                     _("deprecated %%define variable name: %s, use %s"),
+                     quote (variable), quote_n (1, res));
+        break;
+      }
+  return res;
 }
 
 void
@@ -419,7 +426,7 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
   char const *how_name;
 
   /* Permit certain names with underscores for backward compatibility.  */
-  variable = muscle_percent_variable_update (variable);
+  variable = muscle_percent_variable_update (variable, variable_loc);
 
   name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
   loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
