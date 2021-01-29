@@ -3410,24 +3410,33 @@ static void
 handle_name_prefix (location const *loc,
                     char const *directive, char const *value)
 {
-  spec_name_prefix = value;
+  bison_directive (loc, directive);
 
   char buf1[1024];
   size_t len1 = sizeof (buf1);
   char *old = asnprintf (buf1, &len1, "%s\"%s\"", directive, value);
   if (!old)
     xalloc_die ();
-  char buf2[1024];
-  size_t len2 = sizeof (buf2);
-  char *new = asnprintf (buf2, &len2, "%%define api.prefix {%s}", value);
-  if (!new)
-    xalloc_die ();
-  bison_directive (loc, old);
-  deprecated_directive (loc, old, new);
+
+  if (location_empty (spec_name_prefix_loc))
+    {
+      spec_name_prefix = value;
+      spec_name_prefix_loc = *loc;
+
+      char buf2[1024];
+      size_t len2 = sizeof (buf2);
+      char *new = asnprintf (buf2, &len2, "%%define api.prefix {%s}", value);
+      if (!new)
+        xalloc_die ();
+      deprecated_directive (loc, old, new);
+      if (new != buf2)
+        free (new);
+    }
+  else
+    duplicate_directive (old, spec_file_prefix_loc, *loc);
+
   if (old != buf1)
     free (old);
-  if (new != buf2)
-    free (new);
 }
 
 
