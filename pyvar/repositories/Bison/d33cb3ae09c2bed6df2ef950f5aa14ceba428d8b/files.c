@@ -28,7 +28,7 @@
 #include "complain.h"
 
 /* From basename.c.  Almost a lie, as it returns a char *. */
-const char *base_name PARAMS ((char const *name));
+const char *base_name (char const *name);
 
 FILE *finput = NULL;
 
