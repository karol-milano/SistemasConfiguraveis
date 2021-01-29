@@ -23,6 +23,7 @@
 
 #include <filename.h> /* IS_PATH_WITH_DIR */
 #include <get-errno.h>
+#include <mbswidth.h>
 #include <path-join.h>
 #include <quotearg.h>
 #include <spawn-pipe.h>
@@ -236,7 +237,7 @@ prepare_symbol_names (char const *muscle_name)
       /* Width of the next token, including the two quotes, the
          comma and the space.  */
       int width
-        = strlen (cp) + 2
+        = mbswidth (cp, 0) + 2
         + (translatable ? strlen ("N_()") : 0);
 
       if (col + width > 75)
