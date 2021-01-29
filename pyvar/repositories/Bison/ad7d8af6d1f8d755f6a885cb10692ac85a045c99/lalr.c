@@ -241,7 +241,6 @@ build_relations (void)
               rp--;
               if (ISVAR (*rp))
                 {
-                  /* Downcasting from item_number to symbol_number.  */
                   edge[nedges++] = map_goto (states1[--length],
                                              item_number_as_symbol_number (*rp));
                   if (nullable[*rp - ntokens])
