@@ -254,7 +254,7 @@ muscle_find (char const *key)
 }
 
 
-/* In the format `file_name:line.column', append BOUND to MUSCLE.  Use
+/* In the format 'file_name:line.column', append BOUND to MUSCLE.  Use
    digraphs for special characters in the file name.  */
 
 static void
@@ -270,7 +270,7 @@ muscle_boundary_grow (char const *key, boundary bound)
 }
 
 
-/* In the format `[[file_name:line.column]], [[file_name:line.column]]',
+/* In the format '[[file_name:line.column]], [[file_name:line.column]]',
    append LOC to MUSCLE.  Use digraphs for special characters in each
    file name.  */
 
@@ -523,8 +523,8 @@ muscle_percent_define_ensure (char const *variable, location loc,
   char const *val = value ? "" : "false";
   char const *name = UNIQSTR_CONCAT ("percent_define(", variable, ")");
 
-  /* %pure-parser is deprecated in favor of `%define api.pure', so use
-     `%define api.pure' in a backward-compatible manner here.  First,
+  /* %pure-parser is deprecated in favor of '%define api.pure', so use
+     '%define api.pure' in a backward-compatible manner here.  First,
      don't complain if %pure-parser is specified multiple times.  */
   if (!muscle_find_const (name))
     muscle_percent_define_insert (variable, loc, val,
