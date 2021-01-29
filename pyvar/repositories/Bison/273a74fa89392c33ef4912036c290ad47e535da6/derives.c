@@ -101,7 +101,7 @@ set_derives (void)
       *q++ = -1;
     }
 
-  if (trace_flag)
+  if (trace_flag & trace_sets)
     print_derives ();
 
   free (dset + ntokens);
