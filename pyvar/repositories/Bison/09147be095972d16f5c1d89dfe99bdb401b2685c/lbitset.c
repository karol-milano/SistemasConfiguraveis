@@ -1439,7 +1439,7 @@ debug_lbitset (bset)
 	  
 	  fprintf (stderr, "  Word %u:", i);
 	  for (j = 0; j < LBITSET_WORD_BITS; j++)
-	    if ((word & (1 << j)))
+	    if ((word & ((bitset_word) 1 << j)))
 	      fprintf (stderr, " %u", j);
 	  fprintf (stderr, "\n");
 	}
