@@ -63,6 +63,18 @@ typedef struct
   muscle_kind kind;
 } muscle_entry;
 
+
+/* The name of muscle for the %define variable VAR (corresponding to
+   FIELD, if defined).  */
+static uniqstr
+muscle_name (char const *var, char const *field)
+{
+  if (field)
+    return UNIQSTR_CONCAT ("percent_define_", field, "(", var, ")");
+  else
+    return UNIQSTR_CONCAT ("percent_define(", var, ")");
+}
+
 /* An obstack used to create some entries.  */
 struct obstack muscle_obstack;
 
@@ -484,13 +496,11 @@ muscle_percent_define_insert (char const *var, location variable_loc,
 {
   /* Backward compatibility.  */
   char *variable = muscle_percent_variable_update (var, variable_loc, &value);
-  char const *name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
-  char const *loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
-  char const *syncline_name =
-    UNIQSTR_CONCAT ("percent_define_syncline(", variable, ")");
-  char const *how_name = UNIQSTR_CONCAT ("percent_define_how(", variable, ")");
-  char const *kind_name =
-    UNIQSTR_CONCAT ("percent_define_kind(", variable, ")");
+  uniqstr name = muscle_name (variable, NULL);
+  uniqstr loc_name = muscle_name (variable, "loc");
+  uniqstr syncline_name = muscle_name (variable, "syncline");
+  uniqstr how_name = muscle_name (variable, "how");
+  uniqstr kind_name = muscle_name (variable, "kind");
 
   /* Command-line options are processed before the grammar file.  */
   if (how == MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE
@@ -527,7 +537,7 @@ void
 muscle_percent_define_ensure (char const *variable, location loc,
                               bool value)
 {
-  char const *name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
+  uniqstr name = muscle_name (variable, NULL);
   char const *val = value ? "" : "false";
 
   /* Don't complain is VARIABLE is already defined, but be sure to set
@@ -543,9 +553,8 @@ muscle_percent_define_ensure (char const *variable, location loc,
 char *
 muscle_percent_define_get (char const *variable)
 {
-  char const *name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
-  char const *usage_name =
-    UNIQSTR_CONCAT ("percent_define_bison_variables(", variable, ")");
+  uniqstr name = muscle_name (variable, NULL);
+  uniqstr usage_name = muscle_name (variable, "bison_variables");
   char *value = string_decode (name);
   if (!value)
     value = xstrdup ("");
@@ -557,7 +566,7 @@ muscle_percent_define_get (char const *variable)
 location
 muscle_percent_define_get_loc (char const *variable)
 {
-  char const *loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
+  uniqstr loc_name = muscle_name (variable, "loc");
   if (!muscle_find_const (loc_name))
     complain (NULL, fatal, _("%s: undefined %%define variable %s"),
               "muscle_percent_define_get_loc", quote (variable));
@@ -567,8 +576,7 @@ muscle_percent_define_get_loc (char const *variable)
 char const *
 muscle_percent_define_get_syncline (char const *variable)
 {
-  char const *syncline_name =
-    UNIQSTR_CONCAT ("percent_define_syncline(", variable, ")");
+  uniqstr syncline_name = muscle_name (variable, "syncline");
   char const *syncline = muscle_find_const (syncline_name);
   if (!syncline)
     complain (NULL, fatal, _("%s: undefined %%define variable %s"),
@@ -579,12 +587,10 @@ muscle_percent_define_get_syncline (char const *variable)
 bool
 muscle_percent_define_ifdef (char const *variable)
 {
-  char const *name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
-  char const *usage_name =
-    UNIQSTR_CONCAT ("percent_define_bison_variables(", variable, ")");
-  char const *value = muscle_find_const (name);
+  char const *value = muscle_find_const (muscle_name (variable, NULL));
   if (value)
     {
+      uniqstr usage_name = muscle_name (variable, "bison_variables");
       muscle_insert (usage_name, "");
       return true;
     }
@@ -595,8 +601,7 @@ muscle_percent_define_ifdef (char const *variable)
 bool
 muscle_percent_define_flag_if (char const *variable)
 {
-  char const *invalid_boolean_name =
-    UNIQSTR_CONCAT ("percent_define_invalid_boolean(", variable, ")");
+  uniqstr invalid_boolean_name = muscle_name (variable, "invalid_boolean");
   bool result = false;
 
   if (muscle_percent_define_ifdef (variable))
@@ -626,10 +631,9 @@ muscle_percent_define_flag_if (char const *variable)
 void
 muscle_percent_define_default (char const *variable, char const *value)
 {
-  char const *name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
-  char const *loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
-  char const *syncline_name =
-    UNIQSTR_CONCAT ("percent_define_syncline(", variable, ")");
+  uniqstr name = muscle_name (variable, NULL);
+  uniqstr loc_name = muscle_name (variable, "loc");
+  uniqstr syncline_name = muscle_name (variable, "syncline");
   if (!muscle_find_const (name))
     {
       location loc;
@@ -649,7 +653,7 @@ muscle_percent_define_check_values (char const * const *values)
   for (; *values; ++values)
     {
       char const * const *variablep = values;
-      char const *name = UNIQSTR_CONCAT ("percent_define(", *variablep, ")");
+      uniqstr name = muscle_name (*variablep, NULL);
       char *value = string_decode (name);
       if (value)
         {
