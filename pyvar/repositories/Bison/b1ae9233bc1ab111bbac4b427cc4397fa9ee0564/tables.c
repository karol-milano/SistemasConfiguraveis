@@ -692,8 +692,7 @@ pack_vector (vector_number_t vector)
 	  if (loc > high)
 	    high = loc;
 
-	  if (j < BASE_MIN || BASE_MAX < j)
-	    fatal ("base_t too small to hold %d\n", j);
+	  assert (BASE_MIN <= j && j <= BASE_MAX);
 	  return j;
 	}
     }
@@ -802,9 +801,9 @@ tables_generate (void)
   token_actions ();
 
   goto_actions ();
-  XFREE (goto_map + ntokens);
-  XFREE (from_state);
-  XFREE (to_state);
+  free (goto_map + ntokens);
+  free (from_state);
+  free (to_state);
 
   order = XCALLOC (vector_number_t, nvectors);
   sort_actions ();
@@ -816,8 +815,8 @@ tables_generate (void)
 
   for (i = 0; i < nvectors; i++)
     {
-      XFREE (froms[i]);
-      XFREE (tos[i]);
+      free (froms[i]);
+      free (tos[i]);
       XFREE (conflict_tos[i]);
     }
 
