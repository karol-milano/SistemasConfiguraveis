@@ -104,7 +104,6 @@
 #include "conflicts.h"
 #include "muscle_tab.h"
 
-extern void berror PARAMS((const char *));
 
 static int nvectors;
 static int nentries;
@@ -789,8 +788,8 @@ pack_vector (int vector)
 	}
     }
 
-  berror ("pack_vector");
-  return 0;			/* JF keep lint happy */
+  assert (!"pack_vector");
+  return 0;
 }
 
 
@@ -988,7 +987,7 @@ output_master_parser (void)
       else
 	skeleton = skeleton_find ("BISON_SIMPLE", BISON_SIMPLE);
     }
-  muscle_insert ("skeleton", skeleton);    
+  muscle_insert ("skeleton", skeleton);
   output_parser (skeleton, &table_obstack);
 }
 
