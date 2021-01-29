@@ -153,33 +153,39 @@ muscle_insert (char const *key, char const *value)
 }
 
 
-/*-------------------------------------------------------------------.
-| Append VALUE to the current value of KEY.  If KEY did not already  |
-| exist, create it.  Use MUSCLE_OBSTACK.  De-allocate the previously |
-| associated value.  Copy VALUE and SEPARATOR.                       |
-`-------------------------------------------------------------------*/
+/* Append VALUE to the current value of KEY.  If KEY did not already
+   exist, create it.  Use MUSCLE_OBSTACK.  De-allocate the previously
+   associated value.  Copy VALUE and SEPARATOR.  If VALUE does not end
+   with TERMINATOR, append one.  */
 
-void
-muscle_grow (const char *key, const char *val, const char *separator)
+static void
+muscle_grow (const char *key, const char *val,
+             const char *separator, const char *terminator)
 {
   muscle_entry *entry = muscle_lookup (key);
+  size_t vals = strlen (val);
+  size_t terms = strlen (terminator);
 
   if (entry)
     {
-      /* Grow the current value. */
-      char *new_val;
-      obstack_printf (&muscle_obstack, "%s%s%s", entry->value, separator, val);
+      obstack_sgrow (&muscle_obstack, entry->value);
+      obstack_sgrow (&muscle_obstack, separator);
       free (entry->storage);
-      new_val = obstack_finish0 (&muscle_obstack);
-      entry->value = entry->storage = xstrdup (new_val);
-      obstack_free (&muscle_obstack, new_val);
     }
   else
-    {
-      /* First insertion in the hash. */
-      entry = muscle_entry_new (key);
-      entry->value = entry->storage = xstrdup (val);
-    }
+    entry = muscle_entry_new (key);
+
+  obstack_sgrow (&muscle_obstack, val);
+
+  if (terms <= vals
+      && STRNEQ (val + vals - terms, terminator))
+    obstack_sgrow (&muscle_obstack, terminator);
+
+  {
+    char *new_val = obstack_finish0 (&muscle_obstack);
+    entry->value = entry->storage = xstrdup (new_val);
+    obstack_free (&muscle_obstack, new_val);
+  }
 }
 
 /*------------------------------------------------------------------.
@@ -196,7 +202,7 @@ muscle_syncline_grow (char const *key, location loc)
                  quotearg_style (c_quoting_style, loc.start.file));
   obstack_sgrow (&muscle_obstack, ")[");
   extension = obstack_finish0 (&muscle_obstack);
-  muscle_grow (key, extension, "");
+  muscle_grow (key, extension, "", "");
   obstack_free (&muscle_obstack, extension);
 }
 
@@ -210,7 +216,7 @@ void
 muscle_code_grow (const char *key, const char *val, location loc)
 {
   muscle_syncline_grow (key, loc);
-  muscle_grow (key, val, "\n");
+  muscle_grow (key, val, "\n", "\n");
 }
 
 
@@ -225,7 +231,7 @@ muscle_pair_list_grow (const char *muscle,
   obstack_quote (&muscle_obstack, a2);
   obstack_sgrow (&muscle_obstack, "]");
   pair = obstack_finish0 (&muscle_obstack);
-  muscle_grow (muscle, pair, ",\n");
+  muscle_grow (muscle, pair, ",\n", "");
   obstack_free (&muscle_obstack, pair);
 }
 
@@ -262,7 +268,7 @@ muscle_boundary_grow (char const *key, boundary bound)
   obstack_escape (&muscle_obstack, bound.file);
   obstack_printf (&muscle_obstack, ":%d.%d]]", bound.line, bound.column);
   extension = obstack_finish0 (&muscle_obstack);
-  muscle_grow (key, extension, "");
+  muscle_grow (key, extension, "", "");
   obstack_free (&muscle_obstack, extension);
 }
 
@@ -275,7 +281,7 @@ static void
 muscle_location_grow (char const *key, location loc)
 {
   muscle_boundary_grow (key, loc.start);
-  muscle_grow (key, "", ", ");
+  muscle_grow (key, "", ", ", "");
   muscle_boundary_grow (key, loc.end);
 }
 
@@ -374,11 +380,11 @@ void
 muscle_user_name_list_grow (char const *key, char const *user_name,
                             location loc)
 {
-  muscle_grow (key, "[[[[", ",");
-  muscle_grow (key, user_name, "");
-  muscle_grow (key, "]], ", "");
+  muscle_grow (key, "[[[[", ",", "");
+  muscle_grow (key, user_name, "", "");
+  muscle_grow (key, "]], ", "", "");
   muscle_location_grow (key, loc);
-  muscle_grow (key, "]]", "");
+  muscle_grow (key, "]]", "", "");
 }
 
 
