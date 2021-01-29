@@ -610,6 +610,15 @@ matching_state (vector_number_t vector)
   t = tally[i];
   w = width[i];
 
+  /* If VECTOR has GLR conflicts, return -1 */
+  if (conflict_tos[i] != NULL)
+    {
+      int j;
+      for (j = 0; j < t; j += 1)
+	if (conflict_tos[i][j] != 0)
+	  return -1;
+    }
+
   for (prev = vector - 1; prev >= 0; prev--)
     {
       vector_number_t j = order[prev];
@@ -622,7 +631,8 @@ matching_state (vector_number_t vector)
 	return -1;
 
       for (k = 0; match && k < t; k++)
-	if (tos[j][k] != tos[i][k] || froms[j][k] != froms[i][k])
+	if (tos[j][k] != tos[i][k] || froms[j][k] != froms[i][k]
+	    || (conflict_tos[j] != NULL && conflict_tos[j][k] != 0))
 	  match = 0;
 
       if (match)
