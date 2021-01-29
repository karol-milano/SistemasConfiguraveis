@@ -72,8 +72,13 @@ begin_use_class (const char *s, FILE *out)
 {
   if (out == stderr)
     {
-      styled_ostream_begin_use_class (errstream, s);
-      styled_ostream_flush_to_current_style (errstream);
+      if (style_debug)
+        fprintf (out, "<%s>", s);
+      else
+        {
+          styled_ostream_begin_use_class (errstream, s);
+          styled_ostream_flush_to_current_style (errstream);
+        }
     }
 }
 
@@ -82,8 +87,13 @@ end_use_class (const char *s, FILE *out)
 {
   if (out == stderr)
     {
-      styled_ostream_end_use_class (errstream, s);
-      styled_ostream_flush_to_current_style (errstream);
+      if (style_debug)
+        fprintf (out, "</%s>", s);
+      else
+        {
+          styled_ostream_end_use_class (errstream, s);
+          styled_ostream_flush_to_current_style (errstream);
+        }
     }
 }
 
