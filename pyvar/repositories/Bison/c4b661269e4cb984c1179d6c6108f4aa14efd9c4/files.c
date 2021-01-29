@@ -349,6 +349,7 @@ open_files (void)
   obstack_init (&defines_obstack);
   obstack_init (&guard_obstack);
   obstack_init (&output_obstack);
+  obstack_init (&graph_obstack);
 }
 
 
@@ -407,4 +408,7 @@ output_files (void)
     /* We used to use just .out if spec_name_prefix (-p) was used, but
        that conflicts with Posix.  */
     obstack_save (&output_obstack, stringappend (short_base_name, EXT_OUTPUT));
+
+  if (graph_flag)
+    obstack_save (&graph_obstack, stringappend (short_base_name, ".vcg"));
 }
