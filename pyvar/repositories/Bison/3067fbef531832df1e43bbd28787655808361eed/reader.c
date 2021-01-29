@@ -2005,6 +2005,9 @@ packgram (void)
     }
 
   ritem[itemno] = 0;
+
+  if (trace_flag)
+    ritem_print (stderr);
 }
 
 /*-------------------------------------------------------------------.
