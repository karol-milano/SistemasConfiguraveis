@@ -337,6 +337,7 @@ print_results (void)
       size_t size = obstack_object_size (&output_obstack);
       fwrite (obstack_finish (&output_obstack), 1, size, out);
 
+      reduce_output (out);
       conflicts_output (out);
 
       print_grammar (out);
