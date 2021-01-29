@@ -209,6 +209,26 @@ void muscle_pair_list_grow (const char *muscle,
   obstack_free (&muscle_obstack, pair);
 }
 
+
+/*----------------------------------------------------------------------------.
+| Find the value of muscle KEY.  Unlike MUSCLE_FIND, this is always reliable  |
+| to determine whether KEY has a value.                                       |
+`----------------------------------------------------------------------------*/
+
+char const *
+muscle_find_const (char const *key)
+{
+  muscle_entry probe;
+  muscle_entry *result = NULL;
+
+  probe.key = key;
+  result = hash_lookup (muscle_table, &probe);
+  if (result)
+    return result->value;
+  return NULL;
+}
+
+
 /*----------------------------------------------------------------------------.
 | Find the value of muscle KEY.  Abort if muscle_insert was invoked more      |
 | recently than muscle_grow for KEY since muscle_find can't return a          |
@@ -216,7 +236,7 @@ void muscle_pair_list_grow (const char *muscle,
 `----------------------------------------------------------------------------*/
 
 char *
-muscle_find (const char *key)
+muscle_find (char const *key)
 {
   muscle_entry probe;
   muscle_entry *result = NULL;
@@ -276,3 +296,16 @@ muscle_boundary_grow (char const *key, boundary bound)
   muscle_grow (key, extension, "");
   obstack_free (&muscle_obstack, extension);
 }
+
+void
+muscle_grow_used_name_list (char const *key, char const *used_name,
+                            location loc)
+{
+  muscle_grow (key, "[[[[", ",");
+  muscle_grow (key, used_name, "");
+  muscle_grow (key, "]], [[", "");
+  muscle_boundary_grow (key, loc.start);
+  muscle_grow (key, "]], [[", "");
+  muscle_boundary_grow (key, loc.end);
+  muscle_grow (key, "]]]]", "");
+}
