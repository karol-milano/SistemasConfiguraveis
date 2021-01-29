@@ -207,8 +207,8 @@ table_grow (size_t desired)
     table_size *= 2;
 
   if (trace_flag & trace_resource)
-    fprintf (stderr, "growing table and check from: %d to %d\n",
-	     old_size, table_size);
+    fprintf (stderr, _("growing table and check from: %lu to %lu\n"),
+	     (unsigned long) old_size, (unsigned long) table_size);
 
   table = XREALLOC (table, base_t, table_size);
   check = XREALLOC (check, base_t, table_size);
@@ -754,7 +754,7 @@ pack_vector (vector_number_t vector)
 	    high = loc;
 
 	  if (j < BASE_MIN || BASE_MAX < j)
-	    fatal ("base_t too small to hold %d\n", j);
+	    fatal (_("base_t too small to hold %d\n"), j);
 	  return j;
 	}
     }
