@@ -429,9 +429,10 @@ define_directive (char const *assignment,
 /** If the \a variable name is obsolete, return the name to use,
  * otherwise \a variable.  If the \a value is obsolete, update it too.
  *
- * Allocates the returned value.  */
+ * Allocates the returned value if needed, otherwise the returned
+ * value is exactly \a variable.  */
 static
-char *
+char const *
 muscle_percent_variable_update (char const *variable, location variable_loc,
                                 muscle_kind kind,
                                 char const **value)
@@ -474,22 +475,28 @@ muscle_percent_variable_update (char const *variable, location variable_loc,
              && STREQ (eq + 1, *value))
           : STREQ (c->obsolete, variable))
         {
-          char *old = define_directive (c->obsolete, kind, *value);
-          char *upd = define_directive (c->updated, c->kind, *value);
-          deprecated_directive (&variable_loc, old, upd);
-          free (old);
-          free (upd);
-          char *res = xstrdup (c->updated);
-          char *eq2 = strchr (res, '=');
-          if (eq2)
-            {
-              *eq2 = '\0';
-              *value = eq2 + 1;
-            }
-          return res;
+          /* Generate the deprecation warning. */
+          {
+            char *old = define_directive (c->obsolete, kind, *value);
+            char *upd = define_directive (c->updated, c->kind, *value);
+            deprecated_directive (&variable_loc, old, upd);
+            free (old);
+            free (upd);
+          }
+          /* Update the variable and its value.  */
+          {
+            char *res = xstrdup (c->updated);
+            char *eq2 = strchr (res, '=');
+            if (eq2)
+              {
+                *eq2 = '\0';
+                *value = eq2 + 1;
+              }
+            return res;
+          }
         }
     }
-  return xstrdup (variable);
+  return variable;
 }
 
 void
@@ -499,7 +506,7 @@ muscle_percent_define_insert (char const *var, location variable_loc,
                               muscle_percent_define_how how)
 {
   /* Backward compatibility.  */
-  char *variable
+  char const *variable
     = muscle_percent_variable_update (var, variable_loc, kind, &value);
   uniqstr name = muscle_name (variable, NULL);
   uniqstr loc_name = muscle_name (variable, "loc");
@@ -533,7 +540,8 @@ muscle_percent_define_insert (char const *var, location variable_loc,
   MUSCLE_INSERT_INT (how_name, how);
   MUSCLE_INSERT_STRING (kind_name, muscle_kind_string (kind));
  end:
-  free (variable);
+  if (variable != var)
+    free ((char *) variable);
 }
 
 /* This is used for backward compatibility, e.g., "%define api.pure"
