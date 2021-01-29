@@ -579,6 +579,42 @@ muscle_percent_define_get (char const *variable)
   return value;
 }
 
+/* The kind of VARIABLE.  An error if undefined.  */
+static muscle_kind
+muscle_percent_define_get_kind (char const *variable)
+{
+  return muscle_kind_new (muscle_percent_define_get_raw (variable, "kind"));
+}
+
+/* Check the kind of VARIABLE.  An error if undefined.  */
+static void
+muscle_percent_define_check_kind (char const *variable, muscle_kind kind)
+{
+  if (muscle_percent_define_get_kind (variable) != kind)
+    {
+      location loc = muscle_percent_define_get_loc (variable);
+      switch (kind)
+        {
+        case muscle_code:
+          complain (&loc, Wdeprecated,
+                    "%%define variable '%s' requires '{...}' values",
+                    variable);
+          break;
+        case muscle_keyword:
+          complain (&loc, Wdeprecated,
+                    "%%define variable '%s' requires keyword values",
+                    variable);
+          break;
+        case muscle_string:
+          complain (&loc, Wdeprecated,
+                    "%%define variable '%s' requires '\"...\"' values",
+                    variable);
+          break;
+        }
+    }
+}
+
+
 location
 muscle_percent_define_get_loc (char const *variable)
 {
@@ -612,6 +648,7 @@ muscle_percent_define_flag_if (char const *variable)
   if (muscle_percent_define_ifdef (variable))
     {
       char *value = muscle_percent_define_get (variable);
+      muscle_percent_define_check_kind (variable, muscle_keyword);
       if (value[0] == '\0' || STREQ (value, "true"))
         result = true;
       else if (STREQ (value, "false"))
@@ -640,6 +677,7 @@ muscle_percent_define_default (char const *variable, char const *value)
   if (!muscle_find_const (name))
     {
       MUSCLE_INSERT_STRING (name, value);
+      MUSCLE_INSERT_STRING (muscle_name (variable, "kind"), "keyword");
       {
         uniqstr loc_name = muscle_name (variable, "loc");
         location loc;
@@ -661,6 +699,7 @@ muscle_percent_define_check_values (char const * const *values)
       char const * const *variablep = values;
       uniqstr name = muscle_name (*variablep, NULL);
       char *value = string_decode (name);
+      muscle_percent_define_check_kind (*variablep, muscle_keyword);
       if (value)
         {
           for (++values; *values; ++values)
