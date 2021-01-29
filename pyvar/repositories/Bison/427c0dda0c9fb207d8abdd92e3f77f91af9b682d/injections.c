@@ -101,10 +101,10 @@ injections_compute (void)
       }
 
   if (trace_flag & trace_sets)
-    injections_print (_("syntactic direct injections"));
+    injections_print ("syntactic direct injections");
   bitsetv_transitive_closure (injects);
   if (trace_flag & trace_sets)
-    injections_print (_("syntactic injections"));
+    injections_print ("syntactic injections");
 }
 
 
