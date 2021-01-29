@@ -94,6 +94,7 @@
 #include <config.h>
 #include "system.h"
 
+#include "c-ctype.h"
 #include "complain.h"
 #include "conflicts.h"
 #include "files.h"
@@ -3170,11 +3171,11 @@ add_param (char const *type, char *decl, location loc)
   /* Strip the surrounding '{' and '}', and any blanks just inside
      the braces.  */
   --p;
-  while (isspace ((unsigned char) *p))
+  while (c_isspace ((unsigned char) *p))
     --p;
   p[1] = '\0';
   ++decl;
-  while (isspace ((unsigned char) *decl))
+  while (c_isspace ((unsigned char) *decl))
     ++decl;
 
   if (! name_start)
