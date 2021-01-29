@@ -835,7 +835,7 @@ tables_generate (void)
     {
       free (froms[i]);
       free (tos[i]);
-      XFREE (conflict_tos[i]);
+      free (conflict_tos[i]);
     }
 
   free (froms);
