@@ -30,6 +30,8 @@
 #include "gram.h"
 #include "derives.h"
 
+short **derives;
+
 #if DEBUG
 
 static void
@@ -55,8 +57,6 @@ print_derives (void)
 
 #endif
 
-short **derives;
-
 void
 set_derives (void)
 {
