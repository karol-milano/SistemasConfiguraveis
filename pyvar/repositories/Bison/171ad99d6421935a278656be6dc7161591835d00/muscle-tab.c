@@ -389,6 +389,30 @@ muscle_user_name_list_grow (char const *key, char const *user_name,
   muscle_grow (key, "]]", "");
 }
 
+/** If the \a variable name is obsolete, return the name to use,
+ * otherwise \a variable. */
+static
+char const *
+muscle_percent_variable_update (char const *variable)
+{
+  typedef struct
+  {
+    const char *obsolete;
+    const char *updated;
+  } conversion_type;
+  const conversion_type conversion[] =
+    {
+      { "api.push_pull", "api.push-pull", },
+      { "lr.keep_unreachable_states", "lr.keep-unreachable-states", },
+      { "namespace", "api.namespace", },
+    };
+  int i;
+  for (i = 0; i < sizeof conversion / sizeof *conversion; ++i)
+    if (!strcmp (conversion[i].obsolete, variable))
+      return conversion[i].updated;
+  return variable;
+}
+
 #define MUSCLE_USER_NAME_CONVERT(NAME, PREFIX, USER_NAME, SUFFIX)    \
 do {                                                                 \
   char *tmp;                                                         \
@@ -406,20 +430,13 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
                               char const *value,
                               muscle_percent_define_how how)
 {
-  char *variable_tr = NULL;
   char const *name;
   char const *loc_name;
   char const *syncline_name;
   char const *how_name;
 
   /* Permit certain names with underscores for backward compatibility.  */
-  if (0 == strcmp (variable, "api.push_pull")
-      || 0 == strcmp (variable, "lr.keep_unreachable_states"))
-    {
-      variable_tr = strdup (variable);
-      tr (variable_tr, '_', '-');
-      variable = variable_tr;
-    }
+  variable = muscle_percent_variable_update (variable);
 
   MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
   MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
@@ -434,10 +451,7 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
       muscle_percent_define_how how_old =
         atoi (muscle_find_const (how_name));
       if (how_old == MUSCLE_PERCENT_DEFINE_F)
-        {
-          free (variable_tr);
-          return;
-        }
+        return;
       complain_at (variable_loc, _("%s `%s' redefined"),
                    "%define variable", variable);
       complain_at (muscle_percent_define_get_loc (variable),
@@ -452,8 +466,6 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
   muscle_user_name_list_grow ("percent_define_user_variables", variable,
                               variable_loc);
   MUSCLE_INSERT_INT (how_name, how);
-
-  free (variable_tr);
 }
 
 /* This is used for backward compatibility, e.g., "%define api.pure"
