@@ -1764,6 +1764,8 @@ packgram (void)
     }
 
   ritem[itemno] = 0;
+  nritems = itemno;
+  assert (nritems == nitems);
 
   if (trace_flag)
     ritem_print (stderr);
