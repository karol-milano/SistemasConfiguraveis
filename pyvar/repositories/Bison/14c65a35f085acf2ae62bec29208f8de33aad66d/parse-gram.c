@@ -3032,11 +3032,9 @@ handle_pure_parser (location const *loc, char const *directive)
 }
 
 
-/* Convert VERSION into an int (MAJOR * 100 + MINOR).  Return -1 on
-   errors.
-
-   Changes of behavior are only on minor version changes, so "3.0.5"
-   is the same as "3.0": 300. */
+/* Convert VERSION into an int (MAJOR * 10000 + MINOR * 100 + MICRO).
+   E.g., "3.7.4" => 30704, "3.8" => 30800.
+   Return -1 on errors. */
 static int
 str_to_version (char const *version)
 {
@@ -3044,18 +3042,35 @@ str_to_version (char const *version)
   int res = 0;
   errno = 0;
   char *cp = NULL;
-  long major = strtol (version, &cp, 10);
-  if (errno || cp == version || *cp != '.' || major < 0
-      || INT_MULTIPLY_WRAPV (major, 100, &res))
-    return -1;
 
-  ++cp;
-  char *cp1 = NULL;
-  long minor = strtol (cp, &cp1, 10);
-  if (errno || cp1 == cp || (*cp1 != '\0' && *cp1 != '.')
-      || ! (0 <= minor && minor < 100)
-      || INT_ADD_WRAPV (minor, res, &res))
-    return -1;
+  {
+    long major = strtol (version, &cp, 10);
+    if (errno || cp == version || *cp != '.' || major < 0
+        || INT_MULTIPLY_WRAPV (major, 10000, &res))
+      return -1;
+  }
+
+  {
+    ++cp;
+    char *prev = cp;
+    long minor = strtol (cp, &cp, 10);
+    if (errno || cp == prev || (*cp != '\0' && *cp != '.')
+        || ! (0 <= minor && minor < 100)
+        || INT_MULTIPLY_WRAPV (minor, 100, &minor)
+        || INT_ADD_WRAPV (minor, res, &res))
+      return -1;
+  }
+
+  if (*cp == '.')
+    {
+      ++cp;
+      char *prev = cp;
+      long micro = strtol (cp, &cp, 10);
+      if (errno || cp == prev || (*cp != '\0' && *cp != '.')
+          || ! (0 <= micro && micro < 100)
+          || INT_ADD_WRAPV (micro, res, &res))
+        return -1;
+    }
 
   IGNORE_TYPE_LIMITS_END
   return res;
