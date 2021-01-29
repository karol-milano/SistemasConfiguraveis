@@ -352,7 +352,7 @@ lbitset_elt_find (bitset bset, bitset_windex windex,
 
       /* ELT is the nearest to the one we want.  If it's not the one
 	 we want, the one we want does not exist.  */
-      if (elt && (windex - elt->index) < LBITSET_ELT_WORDS)
+      if (windex - elt->index < LBITSET_ELT_WORDS)
 	{
 	  bset->b.cindex = elt->index;
 	  bset->b.csize = LBITSET_ELT_WORDS;
