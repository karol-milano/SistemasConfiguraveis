@@ -25,6 +25,7 @@
 #include <dirname.h>
 #include <get-errno.h>
 #include <quote.h>
+#include <quotearg.h>
 #include <stdio-safer.h>
 #include <xstrndup.h>
 
@@ -109,7 +110,8 @@ xfopen (const char *name, const char *mode)
 
   ptr = fopen_safer (name, mode);
   if (!ptr)
-    error (EXIT_FAILURE, get_errno (), _("cannot open file '%s'"), name);
+    error (EXIT_FAILURE, get_errno (),
+           _("%s: cannot open"), quotearg_colon (name));
 
   return ptr;
 }
