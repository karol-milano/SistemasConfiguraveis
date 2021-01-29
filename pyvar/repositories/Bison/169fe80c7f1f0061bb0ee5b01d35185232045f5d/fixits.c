@@ -91,6 +91,13 @@ fixits_register (location const *loc, char const* fix)
 }
 
 
+bool
+fixits_empty (void)
+{
+  return !fixits;
+}
+
+
 void
 fixits_run (void)
 {
