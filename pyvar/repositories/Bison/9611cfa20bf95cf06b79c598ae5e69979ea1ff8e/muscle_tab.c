@@ -26,6 +26,7 @@
 #include <hash.h>
 #include <quotearg.h>
 
+#include "complain.h"
 #include "files.h"
 #include "muscle_tab.h"
 #include "getargs.h"
@@ -249,6 +250,207 @@ muscle_find (char const *key)
 }
 
 
+void
+muscle_boundary_grow (char const *key, boundary bound)
+{
+  char *extension;
+  MUSCLE_OBSTACK_SGROW (&muscle_obstack, bound.file);
+  obstack_1grow (&muscle_obstack, ':');
+  obstack_fgrow1 (&muscle_obstack, "%d", bound.line);
+  obstack_1grow (&muscle_obstack, '.');
+  obstack_fgrow1 (&muscle_obstack, "%d", bound.column);
+  obstack_1grow (&muscle_obstack, '\0');
+  extension = obstack_finish (&muscle_obstack);
+  muscle_grow (key, extension, "");
+  obstack_free (&muscle_obstack, extension);
+}
+
+void
+muscle_location_grow (char const *key, location loc)
+{
+  muscle_grow (key, "[[", "");
+  muscle_boundary_grow (key, loc.start);
+  muscle_grow (key, "]], [[", "");
+  muscle_boundary_grow (key, loc.end);
+  muscle_grow (key, "]]", "");
+}
+
+/* Reverse of muscle_location_grow.  */
+static location
+muscle_location_decode (char const *key)
+{
+  location loc;
+  char const *value = muscle_find_const (key);
+  aver (value);
+  aver (*value == '[');
+  aver (*++value == '[');
+  while (*++value)
+    switch (*value)
+      {
+        case '$':
+          aver (*++value == ']');
+          aver (*++value == '[');
+          obstack_sgrow (&muscle_obstack, "$");
+          break;
+        case '@':
+          switch (*++value)
+            {
+              case '@': obstack_sgrow (&muscle_obstack, "@" ); break;
+              case '{': obstack_sgrow (&muscle_obstack, "[" ); break;
+              case '}': obstack_sgrow (&muscle_obstack, "]" ); break;
+              default: aver (false); break;
+            }
+          break;
+        case '[':
+          aver (false);
+          break;
+        case ']':
+          {
+            char *boundary_str;
+            aver (*++value == ']');
+            obstack_1grow (&muscle_obstack, '\0');
+            boundary_str = obstack_finish (&muscle_obstack);
+            switch (*++value)
+              {
+                case ',':
+                  boundary_set_from_string (&loc.start, boundary_str);
+                  obstack_free (&muscle_obstack, boundary_str);
+                  aver (*++value == ' ');
+                  aver (*++value == '[');
+                  aver (*++value == '[');
+                  break;
+                case '\0':
+                  boundary_set_from_string (&loc.end, boundary_str);
+                  obstack_free (&muscle_obstack, boundary_str);
+                  return loc;
+                  break;
+                default:
+                  aver (false);
+                  break;
+              }
+          }
+          break;
+        default:
+          obstack_1grow (&muscle_obstack, *value);
+          break;
+      }
+  aver (false);
+  return loc;
+}
+
+void
+muscle_user_name_list_grow (char const *key, char const *user_name,
+                            location loc)
+{
+  muscle_grow (key, "[[[[", ",");
+  muscle_grow (key, user_name, "");
+  muscle_grow (key, "]], ", "");
+  muscle_location_grow (key, loc);
+  muscle_grow (key, "]]", "");
+}
+
+#define MUSCLE_USER_NAME_CONVERT(NAME, PREFIX, USER_NAME, SUFFIX)    \
+do {                                                                 \
+  char *tmp;                                                         \
+  size_t length = strlen ((USER_NAME));                              \
+  tmp = xmalloc (sizeof (PREFIX) - 1 + length + sizeof (SUFFIX));    \
+  strcpy (tmp, (PREFIX));                                            \
+  strcpy (tmp + sizeof (PREFIX) - 1, (USER_NAME));                   \
+  strcpy (tmp + sizeof (PREFIX) - 1 + length, (SUFFIX));             \
+  (NAME) = uniqstr_new (tmp);                                        \
+  free (tmp);                                                        \
+} while (0)
+
+void
+muscle_percent_define_insert (char const *variable, location variable_loc,
+                              char const *value)
+{
+  char const *name;
+  char const *loc_name;
+
+  MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
+  MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
+
+  if (muscle_find_const (name))
+    {
+      warn_at (variable_loc, _("%s `%s' redefined"),
+               "%define variable", variable);
+      warn_at (muscle_location_decode (loc_name), _("previous definition"));
+    }
+  MUSCLE_INSERT_STRING (name, value);
+
+  muscle_insert (loc_name, "");
+  muscle_location_grow (loc_name, variable_loc);
+  muscle_user_name_list_grow ("percent_define_user_variables", variable,
+                              variable_loc);
+}
+
+bool
+muscle_percent_define_flag_if (char const *variable)
+{
+  char const *name;
+  char const *loc_name;
+  char const *usage_name;
+  char const *value;
+  bool result = false;
+
+  MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
+  MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
+  MUSCLE_USER_NAME_CONVERT (usage_name, "percent_define_bison_variables(",
+                            variable, ")");
+
+  value = muscle_find_const (name);
+  if (value)
+    {
+      if (value[0] == '\0' || 0 == strcmp (value, "true"))
+        result = true;
+      else if (0 == strcmp (value, "false"))
+        result = false;
+      else if (!muscle_find_const (usage_name))
+        complain_at(muscle_location_decode (loc_name),
+                    _("invalid value for %%define boolean variable `%s'"),
+                    variable);
+    }
+  else
+    fatal(_("undefined %%define variable `%s' passed to muscle_percent_define_flag_if"),
+          variable);
+
+  muscle_insert (usage_name, "");
+
+  return result;
+}
+
+void
+muscle_percent_define_default (char const *variable, char const *value)
+{
+  char const *name;
+  char const *loc_name;
+  MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
+  MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
+  if (!muscle_find_const (name))
+    {
+      location loc;
+      MUSCLE_INSERT_STRING (name, value);
+      loc.start.file = loc.end.file = "[Bison:muscle_percent_define_default]";
+      loc.start.line = loc.start.column = 0;
+      loc.end.line = loc.end.column = 0;
+      muscle_insert (loc_name, "");
+      muscle_location_grow (loc_name, loc);
+    }
+}
+
+void
+muscle_percent_code_grow (char const *qualifier, location qualifier_loc,
+                          char const *code, location code_loc)
+{
+  char const *name;
+  MUSCLE_USER_NAME_CONVERT (name, "percent_code(", qualifier, ")");
+  muscle_code_grow (name, code, code_loc);
+  muscle_user_name_list_grow ("percent_code_user_qualifiers", qualifier,
+                               qualifier_loc);
+}
+
+
 /*------------------------------------------------.
 | Output the definition of ENTRY as a m4_define.  |
 `------------------------------------------------*/
@@ -278,31 +480,3 @@ muscles_m4_output (FILE *out)
 {
   hash_do_for_each (muscle_table, muscle_m4_output_processor, out);
 }
-
-void
-muscle_boundary_grow (char const *key, boundary bound)
-{
-  char *extension;
-  MUSCLE_OBSTACK_SGROW (&muscle_obstack, bound.file);
-  obstack_1grow (&muscle_obstack, ':');
-  obstack_fgrow1 (&muscle_obstack, "%d", bound.line);
-  obstack_1grow (&muscle_obstack, '.');
-  obstack_fgrow1 (&muscle_obstack, "%d", bound.column);
-  obstack_1grow (&muscle_obstack, '\0');
-  extension = obstack_finish (&muscle_obstack);
-  muscle_grow (key, extension, "");
-  obstack_free (&muscle_obstack, extension);
-}
-
-void
-muscle_grow_user_name_list (char const *key, char const *user_name,
-                            location loc)
-{
-  muscle_grow (key, "[[[[", ",");
-  muscle_grow (key, user_name, "");
-  muscle_grow (key, "]], [[", "");
-  muscle_boundary_grow (key, loc.start);
-  muscle_grow (key, "]], [[", "");
-  muscle_boundary_grow (key, loc.end);
-  muscle_grow (key, "]]]]", "");
-}
