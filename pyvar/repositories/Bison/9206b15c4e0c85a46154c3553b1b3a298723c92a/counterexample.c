@@ -561,6 +561,7 @@ search_state_free (search_state *ss)
   free (ss);
 }
 
+/* For debugging traces.  */
 static void
 search_state_print (search_state *ss)
 {
