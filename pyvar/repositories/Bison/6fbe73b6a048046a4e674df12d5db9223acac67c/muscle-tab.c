@@ -157,12 +157,9 @@ muscle_grow (const char *key, const char *val, const char *separator)
     {
       /* Grow the current value. */
       char *new_val;
-      obstack_sgrow (&muscle_obstack, entry->value);
+      obstack_printf (&muscle_obstack, "%s%s%s", entry->value, separator, val);
       free (entry->storage);
-      obstack_sgrow (&muscle_obstack, separator);
-      obstack_sgrow (&muscle_obstack, val);
-      obstack_1grow (&muscle_obstack, 0);
-      new_val = obstack_finish (&muscle_obstack);
+      new_val = obstack_finish0 (&muscle_obstack);
       entry->value = entry->storage = xstrdup (new_val);
       obstack_free (&muscle_obstack, new_val);
     }
@@ -181,8 +178,7 @@ muscle_syncline_grow (char const *key, location loc)
   obstack_quote (&muscle_obstack,
                  quotearg_style (c_quoting_style, loc.start.file));
   obstack_sgrow (&muscle_obstack, ")[");
-  obstack_1grow (&muscle_obstack, 0);
-  extension = obstack_finish (&muscle_obstack);
+  extension = obstack_finish0 (&muscle_obstack);
   muscle_grow (key, extension, "");
   obstack_free (&muscle_obstack, extension);
 }
@@ -210,8 +206,7 @@ void muscle_pair_list_grow (const char *muscle,
   obstack_sgrow (&muscle_obstack, ", ");
   obstack_quote (&muscle_obstack, a2);
   obstack_sgrow (&muscle_obstack, "]");
-  obstack_1grow (&muscle_obstack, 0);
-  pair = obstack_finish (&muscle_obstack);
+  pair = obstack_finish0 (&muscle_obstack);
   muscle_grow (muscle, pair, ",\n");
   obstack_free (&muscle_obstack, pair);
 }
@@ -268,13 +263,8 @@ muscle_boundary_grow (char const *key, boundary bound)
   char *extension;
   obstack_sgrow  (&muscle_obstack, "[[");
   obstack_escape (&muscle_obstack, bound.file);
-  obstack_1grow (&muscle_obstack, ':');
-  obstack_printf (&muscle_obstack, "%d", bound.line);
-  obstack_1grow (&muscle_obstack, '.');
-  obstack_printf (&muscle_obstack, "%d", bound.column);
-  obstack_sgrow  (&muscle_obstack, "]]");
-  obstack_1grow (&muscle_obstack, '\0');
-  extension = obstack_finish (&muscle_obstack);
+  obstack_printf (&muscle_obstack, ":%d.%d]]", bound.line, bound.column);
+  extension = obstack_finish0 (&muscle_obstack);
   muscle_grow (key, extension, "");
   obstack_free (&muscle_obstack, extension);
 }
@@ -358,8 +348,7 @@ location_decode (char const *key)
           {
             char *boundary_str;
             aver (*++value == ']');
-            obstack_1grow (&muscle_obstack, '\0');
-            boundary_str = obstack_finish (&muscle_obstack);
+            boundary_str = obstack_finish0 (&muscle_obstack);
             switch (*++value)
               {
                 case ',':
