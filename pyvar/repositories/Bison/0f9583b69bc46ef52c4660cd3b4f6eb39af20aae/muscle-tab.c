@@ -550,16 +550,21 @@ muscle_percent_define_ensure (char const *variable, location loc,
                                   MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
 }
 
+/* Mark %define VARIABLE as used.  */
+static void
+muscle_percent_define_use (char const *variable)
+{
+  muscle_insert (muscle_name (variable, "bison_variables"), "");
+}
+
 char *
 muscle_percent_define_get (char const *variable)
 {
   uniqstr name = muscle_name (variable, NULL);
-  uniqstr usage_name = muscle_name (variable, "bison_variables");
   char *value = string_decode (name);
   if (!value)
     value = xstrdup ("");
-
-  muscle_insert (usage_name, "");
+  muscle_percent_define_use (variable);
   return value;
 }
 
@@ -587,15 +592,13 @@ muscle_percent_define_get_syncline (char const *variable)
 bool
 muscle_percent_define_ifdef (char const *variable)
 {
-  char const *value = muscle_find_const (muscle_name (variable, NULL));
-  if (value)
+  if (muscle_find_const (muscle_name (variable, NULL)))
     {
-      uniqstr usage_name = muscle_name (variable, "bison_variables");
-      muscle_insert (usage_name, "");
+      muscle_percent_define_use (variable);
       return true;
     }
-
-  return false;
+  else
+    return false;
 }
 
 bool
