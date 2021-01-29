@@ -124,10 +124,11 @@ fixits_run (void)
   FILE *out = xfopen (input, "w");
   size_t line = 1;
   size_t offset = 1;
-  fixit const *f = NULL;
+  void const *p = NULL;
   gl_list_iterator_t iter = gl_list_iterator (fixits);
-  while (gl_list_iterator_next (&iter, (const void**) &f, NULL))
+  while (gl_list_iterator_next (&iter, &p, NULL))
     {
+      fixit const *f = p;
       /* Look for the correct line. */
       while (line < f->location.start.line)
         {
