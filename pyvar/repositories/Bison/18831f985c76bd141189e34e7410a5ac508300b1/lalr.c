@@ -192,7 +192,7 @@ static void
 initialize_goto_follows (void)
 {
   goto_number **reads = xnmalloc (ngotos, sizeof *reads);
-  goto_number *edge = xnmalloc (ngotos + 1, sizeof *edge);
+  goto_number *edge = xnmalloc (ngotos, sizeof *edge);
   goto_number nedges = 0;
 
   goto_follows = bitsetv_create (ngotos, ntokens, BITSET_FIXED);
@@ -211,7 +211,7 @@ initialize_goto_follows (void)
           symbol_number sym = TRANSITION_SYMBOL (trans, j);
           if (nullable[sym - ntokens])
             {
-              assert (nedges < ngotos + 1);
+              assert (nedges < ngotos);
               edge[nedges++] = map_goto (dst, sym);
             }
         }
@@ -309,7 +309,7 @@ add_lookback_edge (state *s, rule const *r, goto_number gotono)
 static void
 build_relations (void)
 {
-  goto_number *edge = xnmalloc (ngotos + 1, sizeof *edge);
+  goto_number *edge = xnmalloc (ngotos, sizeof *edge);
   state_number *path = xnmalloc (ritem_longest_rhs () + 1, sizeof *path);
 
   includes = xnmalloc (ngotos, sizeof *includes);
@@ -361,8 +361,8 @@ build_relations (void)
                   found = edge[j] == g;
                 if (!found)
                   {
-                    assert (nedges < ngotos + 1);
-                    edge[nedges++] = map_goto (path[p], sym);
+                    assert (nedges < ngotos);
+                    edge[nedges++] = g;
                   }
               }
               if (!nullable[sym - ntokens])
