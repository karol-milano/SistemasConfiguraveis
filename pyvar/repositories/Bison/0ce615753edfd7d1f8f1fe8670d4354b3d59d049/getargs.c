@@ -47,7 +47,6 @@
 #include "muscle_tab.h"
 #include "uniqstr.h"
 
-bool debug_flag;
 bool defines_flag;
 bool graph_flag;
 bool xml_flag;
@@ -618,7 +617,7 @@ getargs (int argc, char *argv[])
 	break;
 
       case 't':
-	debug_flag = true;
+        muscle_percent_define_insert ("debug", command_line_location (), "");
 	break;
 
       case 'v':
