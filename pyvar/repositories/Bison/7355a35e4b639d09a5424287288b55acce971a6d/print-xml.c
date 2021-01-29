@@ -517,7 +517,7 @@ print_xml (void)
   /* print grammar */
   print_grammar (out, level + 1);
 
-  new_closure (nritems);
+  closure_new (nritems);
   no_reduce_set =  bitset_create (ntokens, BITSET_FIXED);
 
   /* print automaton */
@@ -531,7 +531,7 @@ print_xml (void)
   xml_puts (out, level + 1, "</automaton>");
 
   bitset_free (no_reduce_set);
-  free_closure ();
+  closure_free ();
 
   xml_puts (out, 0, "</bison-xml-report>");
 
