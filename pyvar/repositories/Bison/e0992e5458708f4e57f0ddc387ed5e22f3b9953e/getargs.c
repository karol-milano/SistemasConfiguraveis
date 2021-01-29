@@ -49,7 +49,7 @@
 #include "quote.h"
 #include "uniqstr.h"
 
-bool debug_flag;
+bool debug;
 bool defines_flag;
 bool graph_flag;
 bool xml_flag;
@@ -664,7 +664,7 @@ getargs (int argc, char *argv[])
 	break;
 
       case 't':
-	debug_flag = true;
+	debug = true;
 	break;
 
       case 'v':
