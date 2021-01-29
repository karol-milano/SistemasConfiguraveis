@@ -384,11 +384,23 @@ muscle_user_name_list_grow (char const *key, char const *user_name,
   muscle_grow (key, "]]", "");
 }
 
+static
+char *
+define_directive (char const *assignment, char const *value)
+{
+  char const *fmt = value && *value ? "%%define %s %s" : "%%define %s";
+  char *res = xmalloc (strlen (fmt) + strlen (assignment)
+                       + (value ? strlen (value) : 0));
+  sprintf (res, fmt, assignment, value);
+  return res;
+}
+
 /** If the \a variable name is obsolete, return the name to use,
  * otherwise \a variable. */
 static
 char const *
-muscle_percent_variable_update (char const *variable, location variable_loc)
+muscle_percent_variable_update (char const *variable, location variable_loc,
+                                char const **value)
 {
   typedef struct
   {
@@ -405,18 +417,21 @@ muscle_percent_variable_update (char const *variable, location variable_loc)
       { "lr.keep-unreachable-states", "lr.keep-unreachable-state", },
       { "lr.keep_unreachable_states", "lr.keep-unreachable-state", },
       { "namespace", "api.namespace", },
+      { NULL, NULL, }
     };
   char const *res = variable;
-  int i;
-  for (i = 0; i < ARRAY_CARDINALITY (conversion); ++i)
-    if (STREQ (conversion[i].obsolete, variable))
+  conversion_type const *c;
+  for (c = conversion; c->obsolete; ++c)
+    if (STREQ (c->obsolete, variable))
       {
-        res = conversion[i].updated;
-        complain (&variable_loc, Wdeprecated,
-                  _("deprecated %%define variable name: %s, use %s"),
-                  quote (variable), quote_n (1, res));
+        char *old = define_directive (c->obsolete, *value);
+        char *upd = define_directive (c->updated, *value);
+        deprecated_directive (&variable_loc, old, upd);
+        free (old);
+        free (upd);
+        res = c->updated;
         break;
-      }
+    }
   return res;
 }
 
@@ -426,7 +441,7 @@ muscle_percent_define_insert (char const *var, location variable_loc,
                               muscle_percent_define_how how)
 {
   /* Backward compatibility.  */
-  char const *variable = muscle_percent_variable_update (var, variable_loc);
+  char *variable = muscle_percent_variable_update (var, variable_loc, &value);
   char const *name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
   char const *loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
   char const *syncline_name =
