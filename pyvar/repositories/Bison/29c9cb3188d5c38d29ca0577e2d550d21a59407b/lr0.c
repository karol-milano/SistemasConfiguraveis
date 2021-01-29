@@ -158,6 +158,14 @@ kernel_print (FILE *out)
       }
 }
 
+/* Make sure the kernel is in sane state. */
+static void
+kernel_check (void)
+{
+  for (symbol_number i = 0; i < nsyms - 1; ++i)
+    assert (kernel_base[i] + kernel_size[i] <= kernel_base[i + 1]);
+}
+
 static void
 allocate_storage (void)
 {
@@ -209,9 +217,21 @@ new_itemsets (state *s)
 
   bitset_zero (shift_symbol);
 
+  if (trace_flag & trace_automaton)
+    {
+      fprintf (stderr, "initial kernel:\n");
+      kernel_print (stderr);
+    }
+
   for (size_t i = 0; i < nitemset; ++i)
     if (item_number_is_symbol_number (ritem[itemset[i]]))
       {
+        if (trace_flag & trace_automaton)
+          {
+            fputs ("working on: ", stderr);
+            item_print (ritem + itemset[i], NULL, stderr);
+            fputc ('\n', stderr);
+          }
         symbol_number sym = item_number_as_symbol_number (ritem[itemset[i]]);
         bitset_set (shift_symbol, sym);
         kernel_base[sym][kernel_size[sym]] = itemset[i] + 1;
@@ -220,9 +240,11 @@ new_itemsets (state *s)
 
   if (trace_flag & trace_automaton)
     {
+      fprintf (stderr, "final kernel:\n");
       kernel_print (stderr);
       fprintf (stderr, "new_itemsets: end: state = %d\n\n", s->number);
     }
+  kernel_check ();
 }
 
 
@@ -309,6 +331,17 @@ save_reductions (state *s)
         }
     }
 
+  if (trace_flag & trace_automaton)
+    {
+      fprintf (stderr, "reduction[%d] = {\n", s->number);
+      for (int i = 0; i < count; ++i)
+        {
+          rule_print (redset[i], NULL, stderr);
+          fputc ('\n', stderr);
+        }
+      fputs ("}\n", stderr);
+    }
+
   /* Make a reductions structure and copy the data into it.  */
   state_reductions_set (s, count, redset);
 }
