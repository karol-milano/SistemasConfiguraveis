@@ -1265,27 +1265,43 @@ counterexample_report_reduce_reduce (state_item_number itm1, state_item_number i
                                      FILE *out, const char *prefix)
 {
   {
-    fputs (prefix, out);
-    fputs (ngettext ("Reduce/reduce conflict on token",
-                     "Reduce/reduce conflict on tokens",
-                     bitset_count (conflict_syms)), out);
+    struct obstack obstack;
+    obstack_init (&obstack);
     bitset_iterator biter;
     state_item_number sym;
-    const char *sep = " ";
+    const char *sep = "";
     BITSET_FOR_EACH (biter, conflict_syms, sym, 0)
       {
-        fprintf (out, "%s%s", sep, symbols[sym]->tag);
+        obstack_printf (&obstack, "%s%s", sep, symbols[sym]->tag);
         sep = ", ";
       }
-    fputs (_(":\n"), out);
+    char *tokens = obstack_finish0 (&obstack);
+    if (out == stderr)
+      complain (NULL, Wcounterexamples,
+                ngettext ("reduce/reduce conflict on token %s",
+                          "reduce/reduce conflict on tokens %s",
+                          bitset_count (conflict_syms)),
+                tokens);
+    else
+      {
+        fputs (prefix, out);
+        fprintf (out,
+                 ngettext ("reduce/reduce conflict on token %s",
+                           "reduce/reduce conflict on tokens %s",
+                           bitset_count (conflict_syms)),
+                 tokens);
+        fprintf (out, "%s\n", _(":"));
+      }
+    obstack_free (&obstack, NULL);
   }
   // In the report, print the items.
-  if (*prefix || trace_flag & trace_cex)
+  if (out != stderr || trace_flag & trace_cex)
     {
       print_state_item (&state_items[itm1], out, prefix);
       print_state_item (&state_items[itm2], out, prefix);
     }
-  counterexample_report (itm1, itm2, bitset_first (conflict_syms), false, out, prefix);
+  counterexample_report (itm1, itm2, bitset_first (conflict_syms),
+                         false, out, prefix);
 }
 
 static state_item_number
