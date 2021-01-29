@@ -601,6 +601,16 @@ prepare (void)
 
   /* File names.  */
   MUSCLE_INSERT_STRING ("prefix", spec_name_prefix ? spec_name_prefix : "yy");
+#define DEFINE(Name) MUSCLE_INSERT_STRING (#Name, Name ? Name : "")
+  DEFINE (dir_prefix);
+  DEFINE (parser_file_name);
+  DEFINE (spec_defines_file);
+  DEFINE (spec_file_prefix);
+  DEFINE (spec_graph_file);
+  DEFINE (spec_name_prefix);
+  DEFINE (spec_outfile);
+  DEFINE (spec_verbose_file);
+#undef DEFINE
 
   /* User Code.  */
   obstack_1grow (&pre_prologue_obstack, 0);
