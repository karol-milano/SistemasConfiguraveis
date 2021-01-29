@@ -456,7 +456,7 @@ packgram (void)
 
   assert (itemno == nritems);
 
-  if (trace_flag)
+  if (trace_flag & trace_sets)
     ritem_print (stderr);
 }
 
