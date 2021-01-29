@@ -208,8 +208,7 @@ abitset_reverse_list (src, list, num, next)
   bitcnt = bitno % BITSET_WORD_BITS;
   bitoff = windex * BITSET_WORD_BITS;
 
-  for (; windex != ~0U; windex--, bitoff -= BITSET_WORD_BITS,
-	 bitcnt = BITSET_WORD_BITS - 1)
+  do
     {
       word = srcp[windex] << (BITSET_WORD_BITS - 1 - bitcnt);
       for (; word; bitcnt--)
@@ -225,7 +224,10 @@ abitset_reverse_list (src, list, num, next)
 	    }
 	  word <<= 1;
 	}
+      bitoff -= BITSET_WORD_BITS;
+      bitcnt = BITSET_WORD_BITS - 1;
     }
+  while (windex--);
 
   *next = n_bits - (bitoff + 1);
   return count;
@@ -348,7 +350,7 @@ abitset_unused_clear (dst)
   last_bit = ABITSET_N_BITS (dst) % BITSET_WORD_BITS;
   if (last_bit)
     ABITSET_WORDS (dst)[dst->b.csize - 1] &=
-      (bitset_word) ((1 << last_bit) - 1);
+      ((bitset_word) 1 << last_bit) - 1;
 }
 
 
@@ -370,7 +372,7 @@ abitset_op1 (dst, op)
       break;
 
     case BITSET_OP_ONES:
-      memset (dstp, ~0, bytes);
+      memset (dstp, -1, bytes);
       abitset_unused_clear (dst);
       break;
 
