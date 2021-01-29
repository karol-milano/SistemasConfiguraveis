@@ -188,7 +188,7 @@ inaccessable_symbols (void)
 
   /* These tokens (numbered 0, 1, and 2) are internal to Bison.
      Consider them useful. */
-  bitset_set (V, endtoken->content->number);   /* end-of-input token */
+  bitset_set (V, eoftoken->content->number);   /* end-of-input token */
   bitset_set (V, errtoken->content->number);   /* error token */
   bitset_set (V, undeftoken->content->number); /* some undefined token */
 
