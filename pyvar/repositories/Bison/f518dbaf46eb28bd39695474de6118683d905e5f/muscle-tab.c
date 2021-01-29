@@ -50,7 +50,7 @@ hash_compare_muscles (void const *x, void const *y)
 {
   muscle_entry const *m1 = x;
   muscle_entry const *m2 = y;
-  return strcmp (m1->key, m2->key) == 0;
+  return STREQ (m1->key, m2->key);
 }
 
 static size_t
@@ -407,7 +407,7 @@ muscle_percent_variable_update (char const *variable)
     };
   int i;
   for (i = 0; i < sizeof conversion / sizeof *conversion; ++i)
-    if (!strcmp (conversion[i].obsolete, variable))
+    if (STREQ (conversion[i].obsolete, variable))
       return conversion[i].updated;
   return variable;
 }
@@ -555,9 +555,9 @@ muscle_percent_define_flag_if (char const *variable)
   if (muscle_percent_define_ifdef (variable))
     {
       char *value = muscle_percent_define_get (variable);
-      if (value[0] == '\0' || 0 == strcmp (value, "true"))
+      if (value[0] == '\0' || STREQ (value, "true"))
         result = true;
-      else if (0 == strcmp (value, "false"))
+      else if (STREQ (value, "false"))
         result = false;
       else if (!muscle_find_const (invalid_boolean_name))
         {
@@ -614,7 +614,7 @@ muscle_percent_define_check_values (char const * const *values)
         {
           for (++values; *values; ++values)
             {
-              if (0 == strcmp (value, *values))
+              if (STREQ (value, *values))
                 break;
             }
           if (!*values)
