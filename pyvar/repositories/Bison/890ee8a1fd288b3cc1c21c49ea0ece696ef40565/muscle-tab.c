@@ -407,10 +407,16 @@ muscle_user_name_list_grow (char const *key, char const *user_name,
 
 static
 char *
-define_directive (char const *assignment, char const *value)
+define_directive (char const *assignment,
+                  muscle_kind kind,
+                  char const *value)
 {
   char *eq = strchr (assignment, '=');
-  char const *fmt = !eq && value && *value ? "%%define %s %s" : "%%define %s";
+  char const *fmt
+    = eq || !value || !*value ? "%%define %s"
+    : kind == muscle_code     ? "%%define %s {%s}"
+    : kind == muscle_string   ? "%%define %s \"%s\""
+    :                           "%%define %s %s";
   char *res = xmalloc (strlen (fmt) + strlen (assignment)
                        + (value ? strlen (value) : 0));
   sprintf (res, fmt, assignment, value);
@@ -427,28 +433,31 @@ define_directive (char const *assignment, char const *value)
 static
 char *
 muscle_percent_variable_update (char const *variable, location variable_loc,
+                                muscle_kind kind,
                                 char const **value)
 {
   typedef struct
   {
     const char *obsolete;
     const char *updated;
+    muscle_kind kind;
   } conversion_type;
   const conversion_type conversion[] =
-    {
-      { "api.push_pull",              "api.push-pull", },
-      { "api.tokens.prefix",          "api.token.prefix", },
-      { "lex_symbol",                 "api.token.constructor", },
-      { "location_type",              "api.location.type", },
-      { "lr.default-reductions",      "lr.default-reduction", },
-      { "lr.keep-unreachable-states", "lr.keep-unreachable-state", },
-      { "lr.keep_unreachable_states", "lr.keep-unreachable-state", },
-      { "namespace",                  "api.namespace", },
-      { "stype",                      "api.value.type", },
-      { "variant=",                   "api.value.type=variant", },
-      { "variant=true",               "api.value.type=variant", },
-      { NULL, NULL, }
-    };
+  {
+    { "api.push_pull",              "api.push-pull",             muscle_keyword },
+    { "api.tokens.prefix",          "api.token.prefix",          muscle_code },
+    { "lex_symbol",                 "api.token.constructor",     -1 },
+    { "location_type",              "api.location.type",         muscle_code },
+    { "lr.default-reductions",      "lr.default-reduction",      muscle_keyword },
+    { "lr.keep-unreachable-states", "lr.keep-unreachable-state", muscle_keyword },
+    { "lr.keep_unreachable_states", "lr.keep-unreachable-state", muscle_keyword },
+    { "namespace",                  "api.namespace",             muscle_code },
+    { "parser_class_name",          "api.parser.class",          muscle_code },
+    { "stype",                      "api.value.type",            -1 },
+    { "variant=",                   "api.value.type=variant",    -1 },
+    { "variant=true",               "api.value.type=variant",    -1 },
+    { NULL, NULL, -1, }
+  };
 
   for (conversion_type const *c = conversion; c->obsolete; ++c)
     {
@@ -458,8 +467,8 @@ muscle_percent_variable_update (char const *variable, location variable_loc,
              && STREQ (eq + 1, *value))
           : STREQ (c->obsolete, variable))
         {
-          char *old = define_directive (c->obsolete, *value);
-          char *upd = define_directive (c->updated, *value);
+          char *old = define_directive (c->obsolete, kind, *value);
+          char *upd = define_directive (c->updated, c->kind, *value);
           deprecated_directive (&variable_loc, old, upd);
           free (old);
           free (upd);
@@ -483,7 +492,8 @@ muscle_percent_define_insert (char const *var, location variable_loc,
                               muscle_percent_define_how how)
 {
   /* Backward compatibility.  */
-  char *variable = muscle_percent_variable_update (var, variable_loc, &value);
+  char *variable
+    = muscle_percent_variable_update (var, variable_loc, kind, &value);
   uniqstr name = muscle_name (variable, NULL);
   uniqstr loc_name = muscle_name (variable, "loc");
   uniqstr syncline_name = muscle_name (variable, "syncline");
