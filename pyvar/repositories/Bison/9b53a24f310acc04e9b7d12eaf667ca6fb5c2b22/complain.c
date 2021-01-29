@@ -41,6 +41,9 @@
 void exit ();
 #endif
 
+/* To get error_one_per_line. */
+#include "error.h"
+
 #include "complain.h"
 
 #ifndef HAVE_DECL_STRERROR_R
@@ -106,9 +109,6 @@ unsigned int warn_message_count;
 /* This variable is incremented each time `complain' is called.  */
 unsigned int complain_message_count;
 
-/* Sometimes we want to have at most one error per line.  This
-   variable controls whether this mode is selected or not.  */
-int error_one_per_line;
 
 /*--------------------------------.
 | Report a warning, and proceed.  |
