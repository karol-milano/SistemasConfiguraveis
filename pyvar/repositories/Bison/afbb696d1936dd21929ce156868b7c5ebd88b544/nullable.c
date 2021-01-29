@@ -126,10 +126,10 @@ nullable_compute (void)
 	    }
       }
 
-  XFREE (squeue);
-  XFREE (rcount);
-  XFREE (rsets);
-  XFREE (relts);
+  free (squeue);
+  free (rcount);
+  free (rsets);
+  free (relts);
 
   if (trace_flag & trace_sets)
     nullable_print (stderr);
@@ -139,5 +139,5 @@ nullable_compute (void)
 void
 nullable_free (void)
 {
-  XFREE (nullable);
+  free (nullable);
 }
