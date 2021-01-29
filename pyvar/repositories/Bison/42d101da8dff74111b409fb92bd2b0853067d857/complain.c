@@ -196,6 +196,15 @@ warning_severity (warnings flags)
     }
 }
 
+bool
+warning_is_unset (warnings flags)
+{
+  size_t b;
+  for (b = 0; b < warnings_size; ++b)
+    if (flags & 1 << b && warnings_flag[b] != severity_unset)
+      return false;
+  return true;
+}
 
 /** Display a "[-Wyacc]" like message on \a f.  */
 
