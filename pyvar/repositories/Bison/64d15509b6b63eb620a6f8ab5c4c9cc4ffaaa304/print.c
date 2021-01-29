@@ -307,35 +307,33 @@ print_grammar (FILE *out)
 void
 print_results (void)
 {
-  if (verbose_flag)
-    {
-      int i;
+  int i;
 
-      /* We used to use just .out if SPEC_NAME_PREFIX (-p) was used, but
-	 that conflicts with Posix.  */
-      FILE *out = xfopen (spec_verbose_file, "w");
+  /* We used to use just .out if SPEC_NAME_PREFIX (-p) was used, but
+     that conflicts with Posix.  */
+  FILE *out = xfopen (spec_verbose_file, "w");
 
-      size_t size = obstack_object_size (&output_obstack);
-      fwrite (obstack_finish (&output_obstack), 1, size, out);
-      if (size)
-	fputs ("\n\n", out);
+  size_t size = obstack_object_size (&output_obstack);
+  fwrite (obstack_finish (&output_obstack), 1, size, out);
+  obstack_free (&output_obstack, NULL);
 
-      reduce_output (out);
-      conflicts_output (out);
+  if (size)
+    fputs ("\n\n", out);
 
-      print_grammar (out);
+  reduce_output (out);
+  conflicts_output (out);
 
-      /* New experimental feature: output all the items of a state,
-	 not only its kernel.  Requires to run closure, which need
-	 memory allocation/deallocation.  */
-      if (trace_flag)
-	new_closure (nitems);
-      for (i = 0; i < nstates; i++)
-	print_state (out, i);
-      if (trace_flag)
-	free_closure ();
+  print_grammar (out);
 
-      xfclose (out);
-    }
-  obstack_free (&output_obstack, NULL);
+  /* New experimental feature: output all the items of a state,
+     not only its kernel.  Requires to run closure, which need
+     memory allocation/deallocation.  */
+  if (trace_flag)
+    new_closure (nitems);
+  for (i = 0; i < nstates; i++)
+    print_state (out, i);
+  if (trace_flag)
+    free_closure ();
+
+  xfclose (out);
 }
