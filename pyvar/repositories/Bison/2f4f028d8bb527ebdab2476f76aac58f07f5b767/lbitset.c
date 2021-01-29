@@ -1400,7 +1400,7 @@ debug_lbitset (bitset bset)
 	  for (j = 0; j < LBITSET_WORD_BITS; j++)
 	    if ((word & ((bitset_word) 1 << j)))
 	      fprintf (stderr, " %u", j);
-	  fputc ('\n', stderr);
+	  fprintf (stderr, "\n");
 	}
     }
 }
