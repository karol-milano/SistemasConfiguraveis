@@ -90,7 +90,7 @@ warn (message, va_alist)
   if (error_one_per_line)
     {
       static const char *old_infile;
-      static unsigned int old_lineno;
+      static int old_lineno;
 
       if (old_lineno == lineno &&
 	  (infile == old_infile || !strcmp (old_infile, infile)))
@@ -142,7 +142,7 @@ complain (message, va_alist)
   if (error_one_per_line)
     {
       static const char *old_infile;
-      static unsigned int old_lineno;
+      static int old_lineno;
 
       if (old_lineno == lineno &&
 	  (infile == old_infile || !strcmp (old_infile, infile)))
