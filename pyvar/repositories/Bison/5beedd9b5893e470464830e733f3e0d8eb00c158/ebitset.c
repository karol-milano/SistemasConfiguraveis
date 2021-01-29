@@ -771,7 +771,7 @@ ebitset_list (bset, list, num, next)
 	  bitset_word *srcp = EBITSET_WORDS (elt);
 
 	  windex = bitno / BITSET_WORD_BITS;
-	  woffset = eindex / EBITSET_ELT_WORDS;
+	  woffset = eindex * EBITSET_ELT_WORDS;
 
 	  for (; (windex - woffset) < EBITSET_ELT_WORDS; windex++)
 	    {
