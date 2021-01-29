@@ -305,11 +305,10 @@ muscle_location_grow (char const *key, location loc)
 static char *
 string_decode (char const *key)
 {
-  char const *value;
+  char const *value = muscle_find_const (key);
   char *value_decoded;
   char *result;
 
-  value = muscle_find_const (key);
   if (!value)
     return NULL;
   do {
@@ -432,8 +431,7 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
   if (how == MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE
       && muscle_find_const (name))
     {
-      muscle_percent_define_how how_old =
-        atoi (muscle_find_const (how_name));
+      muscle_percent_define_how how_old = atoi (muscle_find_const (how_name));
       if (how_old == MUSCLE_PERCENT_DEFINE_F)
         return;
       complain_at (variable_loc, complaint, _("%%define variable %s redefined"),
@@ -459,8 +457,7 @@ muscle_percent_define_ensure (char const *variable, location loc,
                               bool value)
 {
   char const *val = value ? "" : "false";
-  char const *name;
-  name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
+  char const *name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
 
   /* %pure-parser is deprecated in favor of `%define api.pure', so use
      `%define api.pure' in a backward-compatible manner here.  First,
@@ -479,58 +476,46 @@ muscle_percent_define_ensure (char const *variable, location loc,
 char *
 muscle_percent_define_get (char const *variable)
 {
-  char const *name;
-  char const *usage_name;
-  char *value;
-
-  name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
-  usage_name = UNIQSTR_CONCAT ("percent_define_bison_variables(",
-                               variable, ")");
-
-  muscle_insert (usage_name, "");
-  value = string_decode (name);
+  char const *name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
+  char const *usage_name =
+    UNIQSTR_CONCAT ("percent_define_bison_variables(", variable, ")");
+  char *value = string_decode (name);
   if (!value)
     value = xstrdup ("");
+
+  muscle_insert (usage_name, "");
   return value;
 }
 
 location
 muscle_percent_define_get_loc (char const *variable)
 {
-  char const *loc_name;
-  loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
+  char const *loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
   if (!muscle_find_const (loc_name))
     complain (fatal, _("%s: undefined %%define variable %s"),
-          "muscle_percent_define_get_loc", quote (variable));
+              "muscle_percent_define_get_loc", quote (variable));
   return location_decode (loc_name);
 }
 
 char const *
 muscle_percent_define_get_syncline (char const *variable)
 {
-  char const *syncline_name;
-  char const *syncline;
-  syncline_name =
+  char const *syncline_name =
     UNIQSTR_CONCAT ("percent_define_syncline(", variable, ")");
-  syncline = muscle_find_const (syncline_name);
+  char const *syncline = muscle_find_const (syncline_name);
   if (!syncline)
     complain (fatal, _("%s: undefined %%define variable %s"),
-          "muscle_percent_define_get_syncline", quote (variable));
+              "muscle_percent_define_get_syncline", quote (variable));
   return syncline;
 }
 
 bool
 muscle_percent_define_ifdef (char const *variable)
 {
-  char const *name;
-  char const *usage_name;
-  char const *value;
-
-  name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
-  usage_name =
+  char const *name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
+  char const *usage_name =
     UNIQSTR_CONCAT ("percent_define_bison_variables(", variable, ")");
-
-  value = muscle_find_const (name);
+  char const *value = muscle_find_const (name);
   if (value)
     {
       muscle_insert (usage_name, "");
@@ -543,11 +528,9 @@ muscle_percent_define_ifdef (char const *variable)
 bool
 muscle_percent_define_flag_if (char const *variable)
 {
-  char const *invalid_boolean_name;
-  bool result = false;
-
-  invalid_boolean_name =
+  char const *invalid_boolean_name =
     UNIQSTR_CONCAT ("percent_define_invalid_boolean(", variable, ")");
+  bool result = false;
 
   if (muscle_percent_define_ifdef (variable))
     {
@@ -576,12 +559,9 @@ muscle_percent_define_flag_if (char const *variable)
 void
 muscle_percent_define_default (char const *variable, char const *value)
 {
-  char const *name;
-  char const *loc_name;
-  char const *syncline_name;
-  name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
-  loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
-  syncline_name =
+  char const *name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
+  char const *loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
+  char const *syncline_name =
     UNIQSTR_CONCAT ("percent_define_syncline(", variable, ")");
   if (!muscle_find_const (name))
     {
@@ -602,12 +582,8 @@ muscle_percent_define_check_values (char const * const *values)
   for (; *values; ++values)
     {
       char const * const *variablep = values;
-      char const *name;
-      char *value;
-
-      name = UNIQSTR_CONCAT ("percent_define(", *variablep, ")");
-
-      value = string_decode (name);
+      char const *name = UNIQSTR_CONCAT ("percent_define(", *variablep, ")");
+      char *value = string_decode (name);
       if (value)
         {
           for (++values; *values; ++values)
@@ -642,8 +618,7 @@ void
 muscle_percent_code_grow (char const *qualifier, location qualifier_loc,
                           char const *code, location code_loc)
 {
-  char const *name;
-  name = UNIQSTR_CONCAT ("percent_code(", qualifier, ")");
+  char const *name = UNIQSTR_CONCAT ("percent_code(", qualifier, ")");
   muscle_code_grow (name, code, code_loc);
   muscle_user_name_list_grow ("percent_code_user_qualifiers", qualifier,
                                qualifier_loc);
@@ -657,8 +632,9 @@ muscle_percent_code_grow (char const *qualifier, location qualifier_loc,
 static inline bool
 muscle_m4_output (muscle_entry *entry, FILE *out)
 {
-  fprintf (out, "m4_define([b4_%s],\n", entry->key);
-  fprintf (out, "[[%s]])\n\n\n", entry->value);
+  fprintf (out,
+           "m4_define([b4_%s],\n"
+           "[[%s]])\n\n\n", entry->key, entry->value);
   return true;
 }
 
