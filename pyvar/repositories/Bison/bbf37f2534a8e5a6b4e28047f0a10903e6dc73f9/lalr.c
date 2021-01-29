@@ -271,7 +271,7 @@ build_relations (void)
       int nedges = 0;
       for (rule **rulep = derives[var - ntokens]; *rulep; ++rulep)
         {
-          rule const* r = *rulep;
+          rule const *r = *rulep;
           state *s = states[src];
           path[0] = s->number;
 
@@ -295,7 +295,19 @@ build_relations (void)
           for (int p = length - 2; 0 <= p && ISVAR (r->rhs[p]); --p)
             {
               symbol_number sym = item_number_as_symbol_number (r->rhs[p]);
-              edge[nedges++] = map_goto (path[p], sym);
+              goto_number g = map_goto (path[p], sym);
+              /* Insert G if not already in EDGE.
+                 FIXME: linear search.  A bitset instead?  */
+              {
+                bool found = false;
+                for (int j = 0; !found && j < nedges; ++j)
+                  found = edge[j] == g;
+                if (!found)
+                  {
+                    assert (nedges < ngotos + 1);
+                    edge[nedges++] = map_goto (path[p], sym);
+                  }
+              }
               if (!nullable[sym - ntokens])
                 break;
             }
