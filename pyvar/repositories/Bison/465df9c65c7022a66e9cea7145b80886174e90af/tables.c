@@ -620,47 +620,43 @@ static state_number
 matching_state (vector_number vector)
 {
   vector_number i = order[vector];
-  size_t t;
-  int w;
-  int prev;
-
   /* If VECTOR is a nterm, return -1.  */
-  if (nstates <= i)
-    return -1;
-
-  t = tally[i];
-  w = width[i];
-
-  /* If VECTOR has GLR conflicts, return -1 */
-  if (conflict_tos[i] != NULL)
+  if (i < nstates)
     {
-      int j;
-      for (j = 0; j < t; j += 1)
-        if (conflict_tos[i][j] != 0)
-          return -1;
-    }
+      size_t t = tally[i];
+      int w = width[i];
+      int prev;
 
-  for (prev = vector - 1; prev >= 0; prev--)
-    {
-      vector_number j = order[prev];
-      int k;
-      int match = 1;
-
-      /* Given how ORDER was computed, if the WIDTH or TALLY is
-         different, there cannot be a matching state.  */
-      if (width[j] != w || tally[j] != t)
-        return -1;
-
-      for (k = 0; match && k < t; k++)
-        if (tos[j][k] != tos[i][k]
-            || froms[j][k] != froms[i][k]
-            || (conflict_tos[j] != NULL && conflict_tos[j][k] != 0))
-          match = 0;
-
-      if (match)
-        return j;
-    }
+      /* If VECTOR has GLR conflicts, return -1 */
+      if (conflict_tos[i] != NULL)
+        {
+          int j;
+          for (j = 0; j < t; j += 1)
+            if (conflict_tos[i][j] != 0)
+              return -1;
+        }
 
+      for (prev = vector - 1; 0 <= prev; prev--)
+        {
+          vector_number j = order[prev];
+          /* Given how ORDER was computed, if the WIDTH or TALLY is
+             different, there cannot be a matching state.  */
+          if (width[j] != w || tally[j] != t)
+            return -1;
+          else
+            {
+              bool match = true;
+              int k;
+              for (k = 0; match && k < t; k++)
+                if (tos[j][k] != tos[i][k]
+                    || froms[j][k] != froms[i][k]
+                    || (conflict_tos[j] != NULL && conflict_tos[j][k] != 0))
+                  match = false;
+              if (match)
+                return j;
+            }
+        }
+    }
   return -1;
 }
 
