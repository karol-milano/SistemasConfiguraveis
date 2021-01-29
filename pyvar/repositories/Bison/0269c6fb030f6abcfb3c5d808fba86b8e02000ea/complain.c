@@ -72,7 +72,7 @@ begin_use_class (const char *s, FILE *out)
 {
   if (out == stderr)
     {
-      if (style_debug)
+      if (color_debug)
         fprintf (out, "<%s>", s);
       else
         {
@@ -87,7 +87,7 @@ end_use_class (const char *s, FILE *out)
 {
   if (out == stderr)
     {
-      if (style_debug)
+      if (color_debug)
         fprintf (out, "</%s>", s);
       else
         {
