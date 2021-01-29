@@ -26,20 +26,7 @@
 #include <c-strcase.h>
 #include <configmake.h>
 #include <error.h>
-
-/* Hack to get <getopt.h> to declare getopt with a prototype.  */
-#if lint && ! defined __GNU_LIBRARY__
-# define __GNU_LIBRARY__
-# define HACK_FOR___GNU_LIBRARY___PROTOTYPE 1
-#endif
-
 #include <getopt.h>
-
-#ifdef HACK_FOR___GNU_LIBRARY___PROTOTYPE
-# undef __GNU_LIBRARY__
-# undef HACK_FOR___GNU_LIBRARY___PROTOTYPE
-#endif
-
 #include <progname.h>
 
 #include "complain.h"
