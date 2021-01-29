@@ -102,15 +102,16 @@ append_lssi (lssi *sn, Hash_table *visited, lssi_list queue)
 static void
 lssi_print (lssi *l)
 {
-  print_state_item (&state_items[l->si], stdout);
+  FILE *out = stderr;
+  print_state_item (&state_items[l->si], out);
   if (l->lookahead)
     {
-      printf ("FOLLOWL = { ");
+      fprintf (out, "FOLLOWL = { ");
       bitset_iterator biter;
       symbol_number sin;
       BITSET_FOR_EACH (biter, l->lookahead, sin, 0)
-        printf ("%s, \n", symbols[sin]->tag);
-      puts ("}");
+        fprintf (out, "%s, \n", symbols[sin]->tag);
+      fprintf (out, "}");
     }
 }
 #endif
@@ -252,11 +253,11 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
 
   if (trace_flag & trace_cex)
     {
-      puts ("REDUCE ITEM PATH:");
+      fputs ("REDUCE ITEM PATH:", stderr);
       gl_list_iterator_t it = gl_list_iterator (res);
       const void *sip;
       while (gl_list_iterator_next (&it, &sip, NULL))
-        state_item_print ((state_item *) sip, stdout, "");
+        state_item_print ((state_item *) sip, stderr, "");
     }
   return res;
 }
