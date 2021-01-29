@@ -29,7 +29,8 @@
 #include "files.h"
 #include "getargs.h"
 
-warnings warnings_flag = Wconflicts_sr | Wconflicts_rr | Wother;
+warnings warnings_flag =
+  Wconflicts_sr | Wconflicts_rr | Wdeprecated  | Wother;
 
 bool complaint_issued;
 static unsigned *indent_ptr = 0;
@@ -45,6 +46,7 @@ warnings_print_categories (warnings warn_flags)
           "yacc",
           "conflicts-sr",
           "conflicts-rr",
+          "deprecated",
           "other"
         };
 
