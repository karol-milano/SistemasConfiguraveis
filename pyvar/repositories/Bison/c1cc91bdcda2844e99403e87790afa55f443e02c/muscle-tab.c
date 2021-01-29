@@ -284,7 +284,7 @@ muscle_location_grow (char const *key, location loc)
   muscle_grow (key, "]]", "");
 }
 
-#define MUSCLE_COMMON_DECODE(Value)                             \
+#define COMMON_DECODE(Value)                                    \
   case '$':                                                     \
     aver (*++(Value) == ']');                                   \
     aver (*++(Value) == '[');                                   \
@@ -303,9 +303,9 @@ muscle_location_grow (char const *key, location loc)
     obstack_1grow (&muscle_obstack, *(Value));                  \
     break;
 
-/* Reverse of MUSCLE_OBSTACK_SGROW.  */
+/* Reverse of obstack_escape.  */
 static char *
-muscle_string_decode (char const *key)
+string_decode (char const *key)
 {
   char const *value;
   char *value_decoded;
@@ -317,7 +317,7 @@ muscle_string_decode (char const *key)
   do {
     switch (*value)
       {
-        MUSCLE_COMMON_DECODE (value)
+        COMMON_DECODE (value)
         case '[':
         case ']':
           aver (false);
@@ -332,7 +332,7 @@ muscle_string_decode (char const *key)
 
 /* Reverse of muscle_location_grow.  */
 static location
-muscle_location_decode (char const *key)
+location_decode (char const *key)
 {
   location loc;
   char const *value = muscle_find_const (key);
@@ -342,7 +342,7 @@ muscle_location_decode (char const *key)
   while (*++value)
     switch (*value)
       {
-        MUSCLE_COMMON_DECODE (value)
+        COMMON_DECODE (value)
         case '[':
           aver (false);
           break;
@@ -455,7 +455,7 @@ muscle_percent_define_get (char const *variable)
                                variable, ")");
 
   muscle_insert (usage_name, "");
-  value = muscle_string_decode (name);
+  value = string_decode (name);
   if (!value)
     value = xstrdup ("");
   return value;
@@ -469,7 +469,7 @@ muscle_percent_define_get_loc (char const *variable)
   if (!muscle_find_const (loc_name))
     fatal(_("%s: undefined %%define variable %s"),
           "muscle_percent_define_get_loc", quote (variable));
-  return muscle_location_decode (loc_name);
+  return location_decode (loc_name);
 }
 
 char const *
@@ -573,7 +573,7 @@ muscle_percent_define_check_values (char const * const *values)
 
       name = UNIQSTR_CONCAT ("percent_define(", *variablep, ")");
 
-      value = muscle_string_decode (name);
+      value = string_decode (name);
       if (value)
         {
           for (++values; *values; ++values)
