@@ -344,10 +344,9 @@ string_decode (char const *key)
 
 /* Reverse of muscle_location_grow.  */
 static location
-location_decode (char const *key)
+location_decode (char const *value)
 {
   location loc;
-  char const *value = muscle_find_const (key);
   aver (value);
   aver (*value == '[');
   aver (*++value == '[');
@@ -557,6 +556,20 @@ muscle_percent_define_use (char const *variable)
   muscle_insert (muscle_name (variable, "bison_variables"), "");
 }
 
+/* The value of %define variable VARIABLE (corresponding to FIELD, if
+   defined).  Do not register as used, but diagnose unset variables.  */
+
+char const *
+muscle_percent_define_get_raw (char const *variable, char const *field)
+{
+  uniqstr name = muscle_name (variable, field);
+  char const *res = muscle_find_const (name);
+  if (!res)
+    complain (NULL, fatal, _("%s: undefined %%define variable %s"),
+              "muscle_percent_define_get_raw", quote (variable));
+  return res;
+}
+
 char *
 muscle_percent_define_get (char const *variable)
 {
@@ -571,22 +584,13 @@ muscle_percent_define_get (char const *variable)
 location
 muscle_percent_define_get_loc (char const *variable)
 {
-  uniqstr loc_name = muscle_name (variable, "loc");
-  if (!muscle_find_const (loc_name))
-    complain (NULL, fatal, _("%s: undefined %%define variable %s"),
-              "muscle_percent_define_get_loc", quote (variable));
-  return location_decode (loc_name);
+  return location_decode (muscle_percent_define_get_raw (variable, "loc"));
 }
 
 char const *
 muscle_percent_define_get_syncline (char const *variable)
 {
-  uniqstr syncline_name = muscle_name (variable, "syncline");
-  char const *syncline = muscle_find_const (syncline_name);
-  if (!syncline)
-    complain (NULL, fatal, _("%s: undefined %%define variable %s"),
-              "muscle_percent_define_get_syncline", quote (variable));
-  return syncline;
+  return muscle_percent_define_get_raw (variable, "syncline");
 }
 
 bool
