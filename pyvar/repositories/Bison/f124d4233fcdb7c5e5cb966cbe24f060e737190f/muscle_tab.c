@@ -275,6 +275,52 @@ muscle_location_grow (char const *key, location loc)
   muscle_grow (key, "]]", "");
 }
 
+#define MUSCLE_COMMON_DECODE(Value)                                           \
+  case '$':                                                                   \
+    aver (*++(Value) == ']');                                                 \
+    aver (*++(Value) == '[');                                                 \
+    obstack_sgrow (&muscle_obstack, "$");                                     \
+    break;                                                                    \
+  case '@':                                                                   \
+    switch (*++(Value))                                                       \
+      {                                                                       \
+        case '@': obstack_sgrow (&muscle_obstack, "@" ); break;               \
+        case '{': obstack_sgrow (&muscle_obstack, "[" ); break;               \
+        case '}': obstack_sgrow (&muscle_obstack, "]" ); break;               \
+        default: aver (false); break;                                         \
+      }                                                                       \
+    break;                                                                    \
+  default:                                                                    \
+    obstack_1grow (&muscle_obstack, *(Value));                                \
+    break;
+
+/* Reverse of MUSCLE_OBSTACK_SGROW.  */
+static char *
+muscle_string_decode (char const *key)
+{
+  char const *value;
+  char *value_decoded;
+  char *result;
+
+  value = muscle_find_const (key);
+  if (!value)
+    return NULL;
+  do {
+    switch (*value)
+      {
+        MUSCLE_COMMON_DECODE (value)
+        case '[':
+        case ']':
+          aver (false);
+          break;
+      }
+  } while (*value++);
+  value_decoded = obstack_finish (&muscle_obstack);
+  result = xstrdup (value_decoded);
+  obstack_free (&muscle_obstack, value_decoded);
+  return result;
+}
+
 /* Reverse of muscle_location_grow.  */
 static location
 muscle_location_decode (char const *key)
@@ -287,20 +333,7 @@ muscle_location_decode (char const *key)
   while (*++value)
     switch (*value)
       {
-        case '$':
-          aver (*++value == ']');
-          aver (*++value == '[');
-          obstack_sgrow (&muscle_obstack, "$");
-          break;
-        case '@':
-          switch (*++value)
-            {
-              case '@': obstack_sgrow (&muscle_obstack, "@" ); break;
-              case '{': obstack_sgrow (&muscle_obstack, "[" ); break;
-              case '}': obstack_sgrow (&muscle_obstack, "]" ); break;
-              default: aver (false); break;
-            }
-          break;
+        MUSCLE_COMMON_DECODE (value)
         case '[':
           aver (false);
           break;
@@ -330,9 +363,6 @@ muscle_location_decode (char const *key)
               }
           }
           break;
-        default:
-          obstack_1grow (&muscle_obstack, *value);
-          break;
       }
   aver (false);
   return loc;
@@ -385,13 +415,51 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
                               variable_loc);
 }
 
+char *
+muscle_percent_define_get (char const *variable)
+{
+  char const *name;
+  char const *usage_name;
+  char *value;
+
+  MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
+  MUSCLE_USER_NAME_CONVERT (usage_name, "percent_define_bison_variables(",
+                            variable, ")");
+
+  muscle_insert (usage_name, "");
+  value = muscle_string_decode (name);
+  if (!value)
+    value = xstrdup ("");
+  return value;
+}
+
+bool
+muscle_percent_define_ifdef (char const *variable)
+{
+  char const *name;
+  char const *usage_name;
+  char const *value;
+
+  MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
+  MUSCLE_USER_NAME_CONVERT (usage_name, "percent_define_bison_variables(",
+                            variable, ")");
+
+  value = muscle_find_const (name);
+  if (value)
+    {
+      muscle_insert (usage_name, "");
+      return true;
+    }
+
+  return false;
+}
+
 bool
 muscle_percent_define_flag_if (char const *variable)
 {
   char const *name;
   char const *loc_name;
   char const *usage_name;
-  char const *value;
   bool result = false;
 
   MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
@@ -399,9 +467,9 @@ muscle_percent_define_flag_if (char const *variable)
   MUSCLE_USER_NAME_CONVERT (usage_name, "percent_define_bison_variables(",
                             variable, ")");
 
-  value = muscle_find_const (name);
-  if (value)
+  if (muscle_percent_define_ifdef (variable))
     {
+      char *value = muscle_percent_define_get (variable);
       if (value[0] == '\0' || 0 == strcmp (value, "true"))
         result = true;
       else if (0 == strcmp (value, "false"))
@@ -410,13 +478,12 @@ muscle_percent_define_flag_if (char const *variable)
         complain_at(muscle_location_decode (loc_name),
                     _("invalid value for %%define boolean variable `%s'"),
                     variable);
+      free (value);
     }
   else
     fatal(_("undefined %%define variable `%s' passed to muscle_percent_define_flag_if"),
           variable);
 
-  muscle_insert (usage_name, "");
-
   return result;
 }
 
@@ -439,6 +506,16 @@ muscle_percent_define_default (char const *variable, char const *value)
     }
 }
 
+void
+muscle_percent_define_invalid_value (char const *variable)
+{
+  char const *loc_name;
+  MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
+  complain_at(muscle_location_decode (loc_name),
+              _("invalid value for %%define variable `%s'"), variable);
+}
+
+
 void
 muscle_percent_code_grow (char const *qualifier, location qualifier_loc,
                           char const *code, location code_loc)
