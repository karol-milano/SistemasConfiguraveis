@@ -204,6 +204,7 @@ output_red (state const *s, reductions const *reds, FILE *fout)
     }
   obstack_free (&eout, 0);
   obstack_free (&dout, 0);
+  bitset_free (no_reduce_set);
 }
 
 void
