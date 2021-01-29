@@ -38,35 +38,20 @@ warnings errors_flag;
 err_status complaint_status = status_none;
 static unsigned *indent_ptr = 0;
 
-void
-warnings_print_categories (warnings warn_flags)
+/** Display a "[-Wyacc]" like message on \a f.  */
+
+static void
+warnings_print_categories (warnings warn_flags, FILE *f)
 {
-  if (! (warn_flags & silent))
-    {
-      char const *warn_names[] =
-        {
-          "midrule-values",
-          "yacc",
-          "conflicts-sr",
-          "conflicts-rr",
-          "deprecated",
-          "precedence",
-          "other"
-        };
-
-      bool any = false;
-      int i;
-      for (i = 0; i < ARRAY_CARDINALITY (warn_names); ++i)
-        if (warn_flags & 1 << i)
-          {
-            bool err = warn_flags & errors_flag;
-            fprintf (stderr, "%s-W", any ? ", " : " [");
-            fprintf (stderr, "%s%s", err ? "error=" : "" , warn_names[i]);
-            any = true;
-          }
-      if (any)
-        fprintf (stderr, "]");
-    }
+  /* Display only the first match, the second is "-Wall".  */
+  int i;
+  for (i = 0; warnings_args[i]; ++i)
+    if (warn_flags & warnings_types[i])
+      {
+        bool err = warn_flags & errors_flag;
+        fprintf (f, " [-W%s%s]", err ? "error=" : "" , warnings_args[i]);
+        break;
+      }
 }
 
 /** Report an error message.
@@ -109,7 +94,8 @@ error_message (const location *loc, warnings flags, const char *prefix,
     fprintf (stderr, "%s: ", prefix);
 
   vfprintf (stderr, message, args);
-  warnings_print_categories (flags);
+  if (! (flags & silent))
+    warnings_print_categories (flags, stderr);
   {
     size_t l = strlen (message);
     if (l < 2 || message[l - 2] != ':' || message[l - 1] != ' ')
