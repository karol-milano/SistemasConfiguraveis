@@ -40,6 +40,8 @@
 # undef HACK_FOR___GNU_LIBRARY___PROTOTYPE
 #endif
 
+#include <progname.h>
+
 #include "complain.h"
 #include "files.h"
 #include "getargs.h"
@@ -75,8 +77,6 @@ int language_prio = default_prio;
 struct bison_language const *language = &valid_languages[0];
 const char *include = NULL;
 
-char *program_name;
-
 
 /** Decode an option's set of keys.
  *
