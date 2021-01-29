@@ -35,6 +35,7 @@
 #include "getargs.h"
 #include "gram.h"
 #include "lalr.h"
+#include "ielr.h"
 #include "muscle-tab.h"
 #include "nullable.h"
 #include "output.h"
@@ -102,10 +103,10 @@ main (int argc, char *argv[])
   generate_states ();
   timevar_pop (TV_LR0);
 
-  /* make it deterministic.  In file lalr.  */
-  timevar_push (TV_LALR);
-  lalr ();
-  timevar_pop (TV_LALR);
+  /* Make it deterministic by computing lookahead sets.  Except when LALR(1) is
+     requested, split states to eliminate LR(1)-relative inadequacies.  In file
+     lalr and ielr.  */
+  ielr ();
 
   /* Find and record any conflicts: places where one token of
      lookahead is not enough to disambiguate the parsing.  In file
