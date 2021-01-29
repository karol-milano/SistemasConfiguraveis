@@ -199,9 +199,9 @@ inaccessable_symbols (void)
   V = Vp;
 
   /* Tokens 0, 1, and 2 are internal to Bison.  Consider them useful. */
-  bitset_set (V, 0);		/* end-of-input token */
-  bitset_set (V, 1);		/* error token */
-  bitset_set (V, 2);		/* some undefined token */
+  bitset_set (V, eoftoken->number);		/* end-of-input token */
+  bitset_set (V, errtoken->number);		/* error token */
+  bitset_set (V, undeftoken->number);		/* some undefined token */
 
   bitset_free (P);
   P = Pp;
