@@ -384,21 +384,43 @@ muscle_user_name_list_grow (char const *key, char const *user_name,
   muscle_grow (key, "]]", "");
 }
 
+
+/** Return an allocated string that represents the %define directive
+    that performs the assignment.
+
+    @param assignment "VAR", or "VAR=VAL".
+    @param value      default value if VAL \a assignment has no '='.
+
+    For instance:
+    "foo", NULL      => "%define foo"
+    "foo", "baz"     => "%define foo baz"
+    "foo=bar", NULL  => "%define foo bar"
+    "foo=bar", "baz" => "%define foo bar"
+    "foo=", NULL     => "%define foo"
+    "foo=", "baz"    => "%define foo"
+ */
+
 static
 char *
 define_directive (char const *assignment, char const *value)
 {
-  char const *fmt = value && *value ? "%%define %s %s" : "%%define %s";
+  char *eq = strchr (assignment, '=');
+  char const *fmt = !eq && value && *value ? "%%define %s %s" : "%%define %s";
   char *res = xmalloc (strlen (fmt) + strlen (assignment)
                        + (value ? strlen (value) : 0));
   sprintf (res, fmt, assignment, value);
+  eq = strchr (res, '=');
+  if (eq)
+    *eq = eq[1] ? ' ' : '\0';
   return res;
 }
 
 /** If the \a variable name is obsolete, return the name to use,
- * otherwise \a variable. */
+ * otherwise \a variable.  If the \a value is obsolete, update it too.
+ *
+ * Allocates the returned value.  */
 static
-char const *
+char *
 muscle_percent_variable_update (char const *variable, location variable_loc,
                                 char const **value)
 {
@@ -417,22 +439,37 @@ muscle_percent_variable_update (char const *variable, location variable_loc,
       { "lr.keep-unreachable-states", "lr.keep-unreachable-state", },
       { "lr.keep_unreachable_states", "lr.keep-unreachable-state", },
       { "namespace", "api.namespace", },
+      { "variant=",     "api.value.type=variant", },
+      { "variant=true", "api.value.type=variant", },
       { NULL, NULL, }
     };
-  char const *res = variable;
   conversion_type const *c;
   for (c = conversion; c->obsolete; ++c)
-    if (STREQ (c->obsolete, variable))
-      {
-        char *old = define_directive (c->obsolete, *value);
-        char *upd = define_directive (c->updated, *value);
-        deprecated_directive (&variable_loc, old, upd);
-        free (old);
-        free (upd);
-        res = c->updated;
-        break;
+    {
+      char const *eq = strchr (c->obsolete, '=');
+      if (eq
+          ? (!strncmp (c->obsolete, variable, eq - c->obsolete)
+             && STREQ (eq + 1, *value))
+          : STREQ (c->obsolete, variable))
+        {
+          char *old = define_directive (c->obsolete, *value);
+          char *upd = define_directive (c->updated, *value);
+          deprecated_directive (&variable_loc, old, upd);
+          free (old);
+          free (upd);
+          char *res = xstrdup (c->updated);
+          {
+            char *eq2 = strchr (res, '=');
+            if (eq2)
+              {
+                *eq2 = '\0';
+                *value = eq2 + 1;
+              }
+          }
+          return res;
+        }
     }
-  return res;
+  return xstrdup (variable);
 }
 
 void
@@ -455,7 +492,7 @@ muscle_percent_define_insert (char const *var, location variable_loc,
       muscle_percent_define_how how_old = atoi (muscle_find_const (how_name));
       unsigned i = 0;
       if (how_old == MUSCLE_PERCENT_DEFINE_F)
-        return;
+        goto end;
       complain_indent (&variable_loc, complaint, &i,
                        _("%%define variable %s redefined"),
                        quote (variable));
@@ -472,6 +509,8 @@ muscle_percent_define_insert (char const *var, location variable_loc,
   muscle_user_name_list_grow ("percent_define_user_variables", variable,
                               variable_loc);
   MUSCLE_INSERT_INT (how_name, how);
+ end:
+  free (variable);
 }
 
 /* This is used for backward compatibility, e.g., "%define api.pure"
