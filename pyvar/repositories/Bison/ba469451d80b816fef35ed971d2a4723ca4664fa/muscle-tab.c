@@ -446,6 +446,8 @@ muscle_percent_variable_update (char const *variable,
   } conversion_type;
   const conversion_type conversion[] =
   {
+    { "%error-verbose",             "parse.error=verbose",       muscle_keyword },
+    { "%error_verbose",             "parse.error=verbose",       muscle_keyword },
     { "abstract",                   "api.parser.abstract",       muscle_keyword },
     { "annotations",                "api.parser.annotations",    muscle_code },
     { "api.push_pull",              "api.push-pull",             muscle_keyword },
@@ -477,7 +479,9 @@ muscle_percent_variable_update (char const *variable,
           : STREQ (c->obsolete, variable))
         {
           /* Generate the deprecation warning. */
-          *old = define_directive (c->obsolete, kind, *value);
+          *old = c->obsolete[0] == '%'
+            ? xstrdup (c->obsolete)
+            : define_directive (c->obsolete, kind, *value);
           *upd = define_directive (c->updated, c->kind, *value);
           /* Update the variable and its value.  */
           {
