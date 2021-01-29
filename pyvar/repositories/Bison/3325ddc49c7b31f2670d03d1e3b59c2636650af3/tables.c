@@ -732,7 +732,7 @@ pack_vector (vector_number_t vector)
       for (k = 0; ok && k < t; k++)
 	{
 	  loc = j + state_number_as_int (from[k]);
-	  if (loc > (int) table_size)
+	  if (loc >= (int) table_size)
 	    table_grow (loc);
 
 	  if (table[loc] != 0)
@@ -839,16 +839,6 @@ pack_table (void)
   base_ninf = table_ninf_remap (base, nvectors, BASE_MIN);
   table_ninf = table_ninf_remap (table, high + 1, ACTION_MIN);
 
-  for (i = 0; i < nvectors; i++)
-    {
-      XFREE (froms[i]);
-      XFREE (tos[i]);
-      XFREE (conflict_tos[i]);
-    }
-
-  free (froms);
-  free (tos);
-  free (conflict_tos);
   free (pos);
 }
 
@@ -862,6 +852,8 @@ pack_table (void)
 void
 tables_generate (void)
 {
+  int i;
+
   /* That's a poor way to make sure the sizes are properly corelated,
      in particular the signedness is not taking into account, but it's
      not useless.  */
@@ -877,8 +869,6 @@ tables_generate (void)
   width = XCALLOC (base_t, nvectors);
 
   token_actions ();
-  bitsetv_free (LA);
-  free (LArule);
 
   goto_actions ();
   XFREE (goto_map + ntokens);
@@ -892,6 +882,17 @@ tables_generate (void)
 
   free (tally);
   free (width);
+
+  for (i = 0; i < nvectors; i++)
+    {
+      XFREE (froms[i]);
+      XFREE (tos[i]);
+      XFREE (conflict_tos[i]);
+    }
+
+  free (froms);
+  free (tos);
+  free (conflict_tos);
 }
 
 
