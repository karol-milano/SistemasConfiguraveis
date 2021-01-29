@@ -382,39 +382,34 @@ static void
 save_row (state_number s)
 {
   symbol_number i;
-  size_t count;
-  base_number *sp;
-  base_number *sp1;
-  base_number *sp2;
-  unsigned int *sp3;
 
   /* Number of non default actions in S.  */
-  count = 0;
+  size_t count = 0;
   for (i = 0; i < ntokens; i++)
     if (actrow[i] != 0)
       count++;
 
-  if (count == 0)
-    return;
-
-  /* Allocate non defaulted actions.  */
-  froms[s] = sp = sp1 = xnmalloc (count, sizeof *sp1);
-  tos[s] = sp2 = xnmalloc (count, sizeof *sp2);
-  conflict_tos[s] = sp3 =
-    nondeterministic_parser ? xnmalloc (count, sizeof *sp3) : NULL;
-
-  /* Store non defaulted actions.  */
-  for (i = 0; i < ntokens; i++)
-    if (actrow[i] != 0)
-      {
-        *sp1++ = i;
-        *sp2++ = actrow[i];
-        if (nondeterministic_parser)
-          *sp3++ = conflrow[i];
-      }
+  if (count)
+    {
+      /* Allocate non defaulted actions.  */
+      base_number *sp1 = froms[s] = xnmalloc (count, sizeof *sp1);
+      base_number *sp2 = tos[s] = xnmalloc (count, sizeof *sp2);
+      unsigned int *sp3 = conflict_tos[s] =
+        nondeterministic_parser ? xnmalloc (count, sizeof *sp3) : NULL;;
+
+      /* Store non defaulted actions.  */
+      for (i = 0; i < ntokens; i++)
+        if (actrow[i] != 0)
+          {
+            *sp1++ = i;
+            *sp2++ = actrow[i];
+            if (nondeterministic_parser)
+              *sp3++ = conflrow[i];
+          }
 
-  tally[s] = count;
-  width[s] = sp1[-1] - sp[0] + 1;
+      tally[s] = count;
+      width[s] = sp1[-1] - froms[s][0] + 1;
+    }
 }
 
 
