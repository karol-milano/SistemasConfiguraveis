@@ -23,7 +23,7 @@
 #include "system.h"
 
 #include <argmatch.h>
-#include <ctype.h>
+#include <c-ctype.h>
 #include <progname.h>
 #include <stdarg.h>
 #include <sys/stat.h>
@@ -609,7 +609,7 @@ syntax_error (location loc,
 
   while (*format)
     if (format[0] == '%'
-        && isdigit (format[1])
+        && c_isdigit (format[1])
         && format[2] == '$'
         && format[3] == 's'
         && (format[1] - '0') < argc)
