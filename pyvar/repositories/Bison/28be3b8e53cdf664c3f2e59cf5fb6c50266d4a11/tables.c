@@ -486,11 +486,6 @@ static void
 save_column (symbol_number sym, state_number default_state)
 {
   goto_number i;
-  base_number *sp;
-  base_number *sp1;
-  base_number *sp2;
-  vector_number symno = symbol_number_to_vector_number (sym);
-
   goto_number begin = goto_map[sym - ntokens];
   goto_number end = goto_map[sym - ntokens + 1];
 
@@ -500,23 +495,24 @@ save_column (symbol_number sym, state_number default_state)
     if (to_state[i] != default_state)
       count++;
 
-  if (count == 0)
-    return;
-
-  /* Allocate room for non defaulted gotos.  */
-  froms[symno] = sp = sp1 = xnmalloc (count, sizeof *sp1);
-  tos[symno] = sp2 = xnmalloc (count, sizeof *sp2);
-
-  /* Store the state numbers of the non defaulted gotos.  */
-  for (i = begin; i < end; i++)
-    if (to_state[i] != default_state)
-      {
-        *sp1++ = from_state[i];
-        *sp2++ = to_state[i];
-      }
-
-  tally[symno] = count;
-  width[symno] = sp1[-1] - sp[0] + 1;
+  if (count)
+    {
+      /* Allocate room for non defaulted gotos.  */
+      vector_number symno = symbol_number_to_vector_number (sym);
+      base_number *sp1 = froms[symno] = xnmalloc (count, sizeof *sp1);
+      base_number *sp2 = tos[symno] = xnmalloc (count, sizeof *sp2);
+
+      /* Store the state numbers of the non defaulted gotos.  */
+      for (i = begin; i < end; i++)
+        if (to_state[i] != default_state)
+          {
+            *sp1++ = from_state[i];
+            *sp2++ = to_state[i];
+          }
+
+      tally[symno] = count;
+      width[symno] = sp1[-1] - froms[symno][0] + 1;
+    }
 }
 
 
@@ -675,42 +671,44 @@ matching_state (vector_number vector)
 static base_number
 pack_vector (vector_number vector)
 {
+  base_number res;
   vector_number i = order[vector];
   size_t t = tally[i];
-  int j;
-  int loc = 0;
   base_number *from = froms[i];
   base_number *to = tos[i];
   unsigned int *conflict_to = conflict_tos[i];
 
   aver (t != 0);
 
-  for (j = lowzero - from[0]; ; j++)
+  for (res = lowzero - from[0]; ; res++)
     {
-      int k;
       bool ok = true;
-
-      aver (j < table_size);
-
-      for (k = 0; ok && k < t; k++)
-        {
-          loc = j + state_number_as_int (from[k]);
-          if (table_size <= loc)
-            table_grow (loc);
-
-          if (table[loc] != 0)
-            ok = false;
-        }
-
-      for (k = 0; ok && k < vector; k++)
-        if (pos[k] == j)
-          ok = false;
+      aver (res < table_size);
+      {
+        int k;
+        for (k = 0; ok && k < t; k++)
+          {
+            int loc = res + state_number_as_int (from[k]);
+            if (table_size <= loc)
+              table_grow (loc);
+
+            if (table[loc] != 0)
+              ok = false;
+          }
+
+        if (ok)
+          for (k = 0; k < vector; k++)
+            if (pos[k] == res)
+              ok = false;
+      }
 
       if (ok)
         {
+          int loc;
+          int k;
           for (k = 0; k < t; k++)
             {
-              loc = j + from[k];
+              loc = res + state_number_as_int (from[k]);
               table[loc] = to[k];
               if (nondeterministic_parser && conflict_to != NULL)
                 conflict_table[loc] = conflict_to[k];
@@ -723,8 +721,8 @@ pack_vector (vector_number vector)
           if (high < loc)
             high = loc;
 
-          aver (BASE_MINIMUM <= j && j <= BASE_MAXIMUM);
-          return j;
+          aver (BASE_MINIMUM <= res && res <= BASE_MAXIMUM);
+          return res;
         }
     }
 }
