@@ -578,7 +578,8 @@ ebitset_set (dst, bitno)
 
   ebitset_elt_find (dst, windex, EBITSET_CREATE);
 
-  dst->b.cdata[windex - dst->b.cindex] |= (1 << (bitno % BITSET_WORD_BITS));
+  dst->b.cdata[windex - dst->b.cindex] |=
+    (bitset_word) 1 << (bitno % BITSET_WORD_BITS);
 }
 
 
@@ -593,7 +594,8 @@ ebitset_reset (dst, bitno)
   if (!ebitset_elt_find (dst, windex, EBITSET_FIND))
     return;
 
-  dst->b.cdata[windex - dst->b.cindex] &= ~(1 << (bitno % BITSET_WORD_BITS));
+  dst->b.cdata[windex - dst->b.cindex] &=
+    ~((bitset_word) 1 << (bitno % BITSET_WORD_BITS));
 
   /* If all the data is zero, perhaps we should remove it now... 
      However, there is a good chance that the element will be needed
@@ -646,7 +648,6 @@ ebitset_reverse_list (bset, list, num, next)
   bitset_windex woffset;
   bitset_bindex count;
   bitset_windex size;
-  bitset_word word;
   ebitset_elts *elts;
 
   if (EBITSET_OP_ZERO_P (bset))
@@ -674,40 +675,48 @@ ebitset_reverse_list (bset, list, num, next)
   bcount = bitno % BITSET_WORD_BITS;
   boffset = windex * BITSET_WORD_BITS;
 
-  for (; eindex != ~0U; 
-       boffset = eindex * EBITSET_ELT_BITS - BITSET_WORD_BITS, eindex--) 
+  do
     {
       ebitset_elt *elt;
-      bitset_word *srcp;
 
       elt = elts[eindex];
-      if (!elt)
-	continue;
-
-      srcp = EBITSET_WORDS (elt);
-
-      for (; woffset != ~0U; woffset--, boffset -= BITSET_WORD_BITS,
-	     bcount = BITSET_WORD_BITS - 1)
+      if (elt)
 	{
-	  word = srcp[woffset] << (BITSET_WORD_BITS - 1 - bcount);
+	  bitset_word *srcp;
+
+	  srcp = EBITSET_WORDS (elt);
 
-	  for (; word; bcount--)
+	  do
 	    {
-	      if (word & BITSET_MSB)
+	      bitset_word word;
+
+	      word = srcp[woffset] << (BITSET_WORD_BITS - 1 - bcount);
+
+	      for (; word; bcount--)
 		{
-		  list[count++] = boffset + bcount;
-		  if (count >= num)
+		  if (word & BITSET_MSB)
 		    {
-		      *next = n_bits - (boffset + bcount);
-		      return count;
+		      list[count++] = boffset + bcount;
+		      if (count >= num)
+			{
+			  *next = n_bits - (boffset + bcount);
+			  return count;
+			}
 		    }
+		  word <<= 1;
 		}
-	      word <<= 1;
+
+	      boffset -= BITSET_WORD_BITS;
+	      bcount = BITSET_WORD_BITS - 1;
 	    }
+	  while (woffset--);
+
+	  woffset = EBITSET_ELT_WORDS;
 	}
 
-      woffset = EBITSET_ELT_WORDS;
+      boffset = eindex * EBITSET_ELT_BITS - BITSET_WORD_BITS;
     }
+  while (eindex--);
 
   *next = n_bits - (boffset + 1);
   return count;
@@ -878,7 +887,7 @@ ebitset_op1 (dst, op)
 	     we should just add pointers to a ones element.  */
 	  elt =
 	    ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_CREATE);
-	  memset (EBITSET_WORDS (elt), ~0, sizeof (EBITSET_WORDS (elt)));
+	  memset (EBITSET_WORDS (elt), -1, sizeof (EBITSET_WORDS (elt)));
 	}
       break;
 
