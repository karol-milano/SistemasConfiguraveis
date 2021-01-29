@@ -34,7 +34,32 @@ warnings warnings_flag = Wconflicts_sr | Wconflicts_rr | Wother;
 bool complaint_issued;
 static unsigned *indent_ptr = 0;
 
-
+void
+warnings_print_categories (warnings warn_flags)
+{
+  if (! (warn_flags & silent))
+    {
+      char const *warn_names[] =
+        {
+          "midrule-values",
+          "yacc",
+          "conflicts-sr",
+          "conflicts-rr",
+          "other"
+        };
+
+      bool any = false;
+      int i;
+      for (i = 0; i < ARRAY_CARDINALITY (warn_names); ++i)
+        if (warn_flags & 1 << i)
+          {
+            fprintf (stderr, "%s-W%s", any ? ", " : " [", warn_names[i]);
+            any = true;
+          }
+      if (any)
+        fprintf (stderr, "]");
+    }
+}
 
 /** Report an error message.
  *
