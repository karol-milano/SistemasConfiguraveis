@@ -25,7 +25,6 @@
 #include "revision.h"
 
 #include <argmatch.h>
-#include <c-strcase.h>
 #include <configmake.h>
 #include <error.h>
 
@@ -367,7 +366,7 @@ language_argmatch (char const *arg, int prio, location const *loc)
     {
       int i;
       for (i = 0; valid_languages[i].language[0]; i++)
-	if (c_strcasecmp (arg, valid_languages[i].language) == 0)
+	if (strcasecmp (arg, valid_languages[i].language) == 0)
 	  {
 	    language_prio = prio;
 	    language = &valid_languages[i];
