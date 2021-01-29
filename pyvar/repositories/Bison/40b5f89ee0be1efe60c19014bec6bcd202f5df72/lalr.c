@@ -153,8 +153,8 @@ initialize_F (void)
 
   for (goto_number i = 0; i < ngotos; ++i)
     {
-      state_number stateno = to_state[i];
-      const transitions *sp = states[stateno]->transitions;
+      state_number dst = to_state[i];
+      const transitions *sp = states[dst]->transitions;
 
       int j;
       FOR_EACH_SHIFT (sp, j)
@@ -164,7 +164,7 @@ initialize_F (void)
         {
           symbol_number sym = TRANSITION_SYMBOL (sp, j);
           if (nullable[sym - ntokens])
-            edge[nedges++] = map_goto (stateno, sym);
+            edge[nedges++] = map_goto (dst, sym);
         }
 
       if (nedges == 0)
@@ -215,15 +215,15 @@ build_relations (void)
 
       for (rule **rulep = derives[symbol1 - ntokens]; *rulep; rulep++)
         {
-          int length = 1;
-          item_number const *rp;
           state *s = states[from_state[i]];
           states1[0] = s->number;
 
-          for (rp = (*rulep)->rhs; ! item_number_is_rule_number (*rp); rp++)
+          int length = 1;
+          item_number const *rp;
+          for (rp = (*rulep)->rhs; 0 <= *rp; rp++)
             {
-              s = transitions_to (s->transitions,
-                                  item_number_as_symbol_number (*rp));
+              symbol_number sym = item_number_as_symbol_number (*rp);
+              s = transitions_to (s, sym);
               states1[length++] = s->number;
             }
 
