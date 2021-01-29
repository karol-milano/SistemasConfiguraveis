@@ -26,7 +26,6 @@
 #include <c-strcase.h>
 #include <configmake.h>
 #include <error.h>
-#include <quotearg.h>
 
 /* Hack to get <getopt.h> to declare getopt with a prototype.  */
 #if lint && ! defined __GNU_LIBRARY__
@@ -45,6 +44,7 @@
 #include "files.h"
 #include "getargs.h"
 #include "muscle-tab.h"
+#include "quote.h"
 #include "uniqstr.h"
 
 bool defines_flag;
@@ -421,14 +421,14 @@ language_argmatch (char const *arg, int prio, location loc)
             language = &valid_languages[i];
             return;
           }
-      msg = _("invalid language '%s'");
+      msg = _("%s: invalid language");
     }
   else if (language_prio == prio)
     msg = _("multiple language declarations are invalid");
   else
     return;
 
-  complain_at (loc, msg, arg);
+  complain_at (loc, msg, quotearg_colon (arg));
 }
 
 /*----------------------.
@@ -679,9 +679,9 @@ getargs (int argc, char *argv[])
   if (argc - optind != 1)
     {
       if (argc - optind < 1)
-        error (0, 0, _("missing operand after '%s'"), argv[argc - 1]);
+        error (0, 0, _("%s: missing operand"), quotearg_colon (argv[argc - 1]));
       else
-        error (0, 0, _("extra operand '%s'"), argv[optind + 1]);
+        error (0, 0, _("extra operand %s"), quote (argv[optind + 1]));
       usage (EXIT_FAILURE);
     }
 
