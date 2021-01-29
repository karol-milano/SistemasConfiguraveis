@@ -413,18 +413,6 @@ muscle_percent_variable_update (char const *variable)
   return variable;
 }
 
-#define MUSCLE_USER_NAME_CONVERT(NAME, PREFIX, USER_NAME, SUFFIX)    \
-do {                                                                 \
-  char *tmp;                                                         \
-  size_t length = strlen ((USER_NAME));                              \
-  tmp = xmalloc (sizeof (PREFIX) - 1 + length + sizeof (SUFFIX));    \
-  strcpy (tmp, (PREFIX));                                            \
-  strcpy (tmp + sizeof (PREFIX) - 1, (USER_NAME));                   \
-  strcpy (tmp + sizeof (PREFIX) - 1 + length, (SUFFIX));             \
-  (NAME) = uniqstr_new (tmp);                                        \
-  free (tmp);                                                        \
-} while (0)
-
 void
 muscle_percent_define_insert (char const *variable, location variable_loc,
                               char const *value,
@@ -438,11 +426,11 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
   /* Permit certain names with underscores for backward compatibility.  */
   variable = muscle_percent_variable_update (variable);
 
-  MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
-  MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
-  MUSCLE_USER_NAME_CONVERT (syncline_name,
-                            "percent_define_syncline(", variable, ")");
-  MUSCLE_USER_NAME_CONVERT (how_name, "percent_define_how(", variable, ")");
+  name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
+  loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
+  syncline_name =
+    UNIQSTR_CONCAT ("percent_define_syncline(", variable, ")");
+  how_name = UNIQSTR_CONCAT ("percent_define_how(", variable, ")");
 
   /* Command-line options are processed before the grammar file.  */
   if (how == MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE
@@ -476,7 +464,7 @@ muscle_percent_define_ensure (char const *variable, location loc,
 {
   char const *val = value ? "" : "false";
   char const *name;
-  MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
+  name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
 
   /* %pure-parser is deprecated in favor of `%define api.pure', so use
      `%define api.pure' in a backward-compatible manner here.  First,
@@ -499,9 +487,9 @@ muscle_percent_define_get (char const *variable)
   char const *usage_name;
   char *value;
 
-  MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
-  MUSCLE_USER_NAME_CONVERT (usage_name, "percent_define_bison_variables(",
-                            variable, ")");
+  name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
+  usage_name = UNIQSTR_CONCAT ("percent_define_bison_variables(",
+                               variable, ")");
 
   muscle_insert (usage_name, "");
   value = muscle_string_decode (name);
@@ -514,10 +502,10 @@ location
 muscle_percent_define_get_loc (char const *variable)
 {
   char const *loc_name;
-  MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
+  loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
   if (!muscle_find_const (loc_name))
-    fatal(_("undefined %%define variable `%s' passed to muscle_percent_define_get_loc"),
-          variable);
+    fatal(_("undefined %%define variable `%s' passed to"
+            " muscle_percent_define_get_loc"), variable);
   return muscle_location_decode (loc_name);
 }
 
@@ -526,12 +514,12 @@ muscle_percent_define_get_syncline (char const *variable)
 {
   char const *syncline_name;
   char const *syncline;
-  MUSCLE_USER_NAME_CONVERT (syncline_name,
-                            "percent_define_syncline(", variable, ")");
+  syncline_name =
+    UNIQSTR_CONCAT ("percent_define_syncline(", variable, ")");
   syncline = muscle_find_const (syncline_name);
   if (!syncline)
-    fatal(_("undefined %%define variable `%s' passed to muscle_percent_define_get_syncline"),
-          variable);
+    fatal(_("undefined %%define variable `%s' passed to"
+            " muscle_percent_define_get_syncline"), variable);
   return syncline;
 }
 
@@ -542,9 +530,9 @@ muscle_percent_define_ifdef (char const *variable)
   char const *usage_name;
   char const *value;
 
-  MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
-  MUSCLE_USER_NAME_CONVERT (usage_name, "percent_define_bison_variables(",
-                            variable, ")");
+  name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
+  usage_name =
+    UNIQSTR_CONCAT ("percent_define_bison_variables(", variable, ")");
 
   value = muscle_find_const (name);
   if (value)
@@ -562,8 +550,8 @@ muscle_percent_define_flag_if (char const *variable)
   char const *invalid_boolean_name;
   bool result = false;
 
-  MUSCLE_USER_NAME_CONVERT (invalid_boolean_name,
-                            "percent_define_invalid_boolean(", variable, ")");
+  invalid_boolean_name =
+    UNIQSTR_CONCAT ("percent_define_invalid_boolean(", variable, ")");
 
   if (muscle_percent_define_ifdef (variable))
     {
@@ -594,10 +582,10 @@ muscle_percent_define_default (char const *variable, char const *value)
   char const *name;
   char const *loc_name;
   char const *syncline_name;
-  MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
-  MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
-  MUSCLE_USER_NAME_CONVERT (syncline_name,
-                            "percent_define_syncline(", variable, ")");
+  name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
+  loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
+  syncline_name =
+    UNIQSTR_CONCAT ("percent_define_syncline(", variable, ")");
   if (!muscle_find_const (name))
     {
       location loc;
@@ -620,7 +608,7 @@ muscle_percent_define_check_values (char const * const *values)
       char const *name;
       char *value;
 
-      MUSCLE_USER_NAME_CONVERT (name, "percent_define(", *variablep, ")");
+      name = UNIQSTR_CONCAT ("percent_define(", *variablep, ")");
 
       value = muscle_string_decode (name);
       if (value)
@@ -658,7 +646,7 @@ muscle_percent_code_grow (char const *qualifier, location qualifier_loc,
                           char const *code, location code_loc)
 {
   char const *name;
-  MUSCLE_USER_NAME_CONVERT (name, "percent_code(", qualifier, ")");
+  name = UNIQSTR_CONCAT ("percent_code(", qualifier, ")");
   muscle_code_grow (name, code, code_loc);
   muscle_user_name_list_grow ("percent_code_user_qualifiers", qualifier,
                                qualifier_loc);
