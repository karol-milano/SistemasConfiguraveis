@@ -30,6 +30,7 @@
 #include <getopt.h>
 #include <progname.h>
 #include <quote.h>
+#include <stdnoreturn.h>
 #include <textstyle.h>
 
 #include "complain.h"
@@ -151,8 +152,8 @@ flags_argmatch (const char *opt,
  */
 #define FLAGS_ARGMATCH(FlagName, Args, All)                             \
   flags_argmatch ("--" #FlagName,                                       \
-                  (xargmatch_fn*) argmatch_## FlagName ## _value,        \
-                  argmatch_## FlagName ## _usage,                       \
+                  (xargmatch_fn*) argmatch_## FlagName ## _value,       \
+                  argmatch_ ## FlagName ## _usage,                      \
                   All, &FlagName ## _flag, Args)
 
 /*---------------------.
@@ -337,7 +338,8 @@ const argmatch_feature_group_type argmatch_feature_group =
 | Display the help message and exit STATUS.  |
 `-------------------------------------------*/
 
-static void usage (int) ATTRIBUTE_NORETURN;
+ _Noreturn
+static void usage (int);
 
 static void
 usage (int status)
@@ -860,7 +862,7 @@ getargs (int argc, char *argv[])
 void
 tr (char *s, char from, char to)
 {
-  for (; *s; s++)
+  for (; *s; ++s)
     if (*s == from)
       *s = to;
 }
