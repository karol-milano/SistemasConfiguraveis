@@ -45,6 +45,7 @@ extern void reduce_grammar PARAMS((void));
 extern void set_derives PARAMS((void));
 extern void free_derives PARAMS((void));
 extern void set_nullable PARAMS((void));
+extern void free_nullable PARAMS((void));
 extern void generate_states PARAMS((void));
 extern void lalr PARAMS((void));
 extern void initialize_conflicts PARAMS((void));
@@ -109,6 +110,7 @@ main (int argc, char *argv[])
   output();
 
   finalize_conflicts();
+  free_nullable();
   free_derives();
 
   exit (complain_message_count ? 1 : 0);
