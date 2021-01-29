@@ -805,8 +805,10 @@ prepare (void)
 
 #define DEFINE(Name) MUSCLE_INSERT_STRING (#Name, Name ? Name : "")
   DEFINE (dir_prefix);
+  DEFINE (mapped_dir_prefix);
   DEFINE (parser_file_name);
   DEFINE (spec_header_file);
+  DEFINE (spec_mapped_header_file);
   DEFINE (spec_file_prefix);
   DEFINE (spec_graph_file);
   DEFINE (spec_name_prefix);
