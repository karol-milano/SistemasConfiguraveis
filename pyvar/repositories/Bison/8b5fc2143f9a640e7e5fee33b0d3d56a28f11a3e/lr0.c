@@ -47,6 +47,16 @@ typedef struct state_list
 static state_list *first_state = NULL;
 static state_list *last_state = NULL;
 
+/* Print CORE for debugging. */
+static void
+core_print (size_t core_size, item_number *core, FILE *out)
+{
+  for (int i = 0; i < core_size; ++i)
+    {
+      item_print (ritem + core[i], NULL, out);
+      fputc ('\n', out);
+    }
+}
 
 /*------------------------------------------------------------------.
 | A state was just discovered from another state.  Queue it for     |
@@ -86,8 +96,14 @@ static rule **redset;
    itself.  */
 static state **shiftset;
 
+
+/* KERNEL_BASE[symbol-number] -> list of item numbers (offsets inside
+   RITEM) of lenngth KERNEL_SIZE[symbol-number]. */
 static item_number **kernel_base;
 static int *kernel_size;
+
+/* A single dimension array that serves as storage for
+   KERNEL_BASE.  */
 static item_number *kernel_items;
 
 
@@ -103,10 +119,11 @@ allocate_itemsets (void)
                                   sizeof *symbol_count);
 
   for (rule_number r = 0; r < nrules; ++r)
-    for (item_number *rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
+    for (item_number *rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
       {
-        count++;
-        symbol_count[*rhsp]++;
+        symbol_number sym = item_number_as_symbol_number (*rhsp);
+        count += 1;
+        symbol_count[sym] += 1;
       }
 
   /* See comments before new_itemsets.  All the vectors of items
@@ -129,6 +146,17 @@ allocate_itemsets (void)
   kernel_size = xnmalloc (nsyms, sizeof *kernel_size);
 }
 
+/* Print the current kernel (in KERNEL_BASE). */
+static void
+kernel_print (FILE *out)
+{
+  for (symbol_number i = 0; i < nsyms; ++i)
+    if (kernel_size[i])
+      {
+        fprintf (out, "kernel[%s] =\n", symbols[i]->tag);
+        core_print (kernel_size[i], kernel_base[i], out);
+      }
+}
 
 static void
 allocate_storage (void)
@@ -175,7 +203,7 @@ static void
 new_itemsets (state *s)
 {
   if (trace_flag & trace_automaton)
-    fprintf (stderr, "Entering new_itemsets, state = %d\n", s->number);
+    fprintf (stderr, "new_itemsets: begin: state = %d\n", s->number);
 
   memset (kernel_size, 0, nsyms * sizeof *kernel_size);
 
@@ -189,6 +217,12 @@ new_itemsets (state *s)
         kernel_base[sym][kernel_size[sym]] = itemset[i] + 1;
         kernel_size[sym]++;
       }
+
+  if (trace_flag & trace_automaton)
+    {
+      kernel_print (stderr);
+      fprintf (stderr, "new_itemsets: end: state = %d\n\n", s->number);
+    }
 }
 
 
@@ -203,8 +237,12 @@ static state *
 get_state (symbol_number sym, size_t core_size, item_number *core)
 {
   if (trace_flag & trace_automaton)
-    fprintf (stderr, "Entering get_state, symbol = %d (%s)\n",
-             sym, symbols[sym]->tag);
+    {
+      fprintf (stderr, "Entering get_state, symbol = %d (%s), core:\n",
+               sym, symbols[sym]->tag);
+      core_print (core_size, core, stderr);
+      fputc ('\n', stderr);
+    }
 
   state *s = state_hash_lookup (core_size, core);
   if (!s)
@@ -227,7 +265,7 @@ static void
 append_states (state *s)
 {
   if (trace_flag & trace_automaton)
-    fprintf (stderr, "Entering append_states, state = %d\n", s->number);
+    fprintf (stderr, "append_states: begin: state = %d\n", s->number);
 
   bitset_iterator iter;
   symbol_number sym;
@@ -237,6 +275,9 @@ append_states (state *s)
       shiftset[i] = get_state (sym, kernel_size[sym], kernel_base[sym]);
       ++i;
     }
+
+  if (trace_flag & trace_automaton)
+    fprintf (stderr, "append_states: end: state = %d\n", s->number);
 }
 
 
