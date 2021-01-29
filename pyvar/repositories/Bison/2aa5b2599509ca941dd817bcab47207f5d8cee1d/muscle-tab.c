@@ -396,31 +396,45 @@ muscle_user_name_list_grow (char const *key, char const *user_name,
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
+    };
+  char const *res = variable;
+  int i;
+  for (i = 0; i < ARRAY_CARDINALITY (conversion); ++i)
+    if (STREQ (conversion[i].obsolete, variable))
+      {
+        res = conversion[i].updated;
+        break;
+      }
+  return res;
+}
+
 void
-muscle_percent_define_insert (char const *variable, location variable_loc,
+muscle_percent_define_insert (char const *var, location variable_loc,
                               char const *value,
                               muscle_percent_define_how how)
 {
-  char *variable_tr = NULL;
-  char const *name;
-  char const *loc_name;
-  char const *syncline_name;
-  char const *how_name;
-
-  /* Permit certain names with underscores for backward compatibility.  */
-  if (0 == strcmp (variable, "api.push_pull")
-      || 0 == strcmp (variable, "lr.keep_unreachable_states"))
-    {
-      variable_tr = strdup (variable);
-      tr (variable_tr, '_', '-');
-      variable = variable_tr;
-    }
-
-  name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
-  loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
-  syncline_name =
+  /* Backward compatibility.  */
+  char const *variable = muscle_percent_variable_update (var);
+  char const *name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
+  char const *loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
+  char const *syncline_name =
     UNIQSTR_CONCAT ("percent_define_syncline(", variable, ")");
-  how_name = UNIQSTR_CONCAT ("percent_define_how(", variable, ")");
+  char const *how_name = UNIQSTR_CONCAT ("percent_define_how(", variable, ")");
 
   /* Command-line options are processed before the grammar file.  */
   if (how == MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE
@@ -430,10 +444,7 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
       muscle_percent_define_how how_old =
         atoi (muscle_find_const (how_name));
       if (how_old == MUSCLE_PERCENT_DEFINE_F)
-        {
-          free (variable_tr);
-          return;
-        }
+        return;
       complain_at_indent (variable_loc, &i,
                           _("%%define variable %s redefined"), quote (variable));
       i += SUB_INDENT;
@@ -449,8 +460,6 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
   muscle_user_name_list_grow ("percent_define_user_variables", variable,
                               variable_loc);
   MUSCLE_INSERT_INT (how_name, how);
-
-  free (variable_tr);
 }
 
 char *
