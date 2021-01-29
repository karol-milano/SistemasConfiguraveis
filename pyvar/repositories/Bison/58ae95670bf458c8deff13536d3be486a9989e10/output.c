@@ -679,7 +679,7 @@ prepare (void)
 #define DEFINE(Name) MUSCLE_INSERT_STRING (#Name, Name ? Name : "")
   DEFINE (dir_prefix);
   DEFINE (parser_file_name);
-  DEFINE (spec_defines_file);
+  DEFINE (spec_header_file);
   DEFINE (spec_file_prefix);
   DEFINE (spec_graph_file);
   DEFINE (spec_name_prefix);
