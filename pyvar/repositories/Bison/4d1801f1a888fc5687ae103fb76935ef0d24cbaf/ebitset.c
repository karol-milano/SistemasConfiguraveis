@@ -1,5 +1,5 @@
 /* Functions to support expandable bitsets.
-   Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -115,11 +115,11 @@ static ebitset_elt *ebitset_free_list;	/* Free list of bitset elements.  */
  ((BSET)->b.cindex = (EINDEX) * EBITSET_ELT_WORDS, \
   (BSET)->b.cdata = EBITSET_WORDS (EBITSET_ELTS (BSET) [EINDEX]))
 
-
+#undef min
+#undef max
 #define min(a, b) ((a) > (b) ? (b) : (a))
 #define max(a, b) ((a) > (b) ? (a) : (b))
 
-
 static bitset_bindex
 ebitset_resize (bitset src, bitset_bindex n_bits)
 {
@@ -136,7 +136,7 @@ ebitset_resize (bitset src, bitset_bindex n_bits)
     {
       bitset_windex size;
 
-      /* The bitset needs to grow.  If we already have enough memory 
+      /* The bitset needs to grow.  If we already have enough memory
 	 allocated, then just zero what we need.  */
       if (newsize > EBITSET_ASIZE (src))
 	{
@@ -149,13 +149,13 @@ ebitset_resize (bitset src, bitset_bindex n_bits)
 	    size = newsize;
 	  else
 	    size = newsize + newsize / 4;
-	  
+
 	  EBITSET_ELTS (src)
 	    = realloc (EBITSET_ELTS (src), size * sizeof (ebitset_elt *));
 	  EBITSET_ASIZE (src) = size;
 	}
 
-      memset (EBITSET_ELTS (src) + oldsize, 0, 
+      memset (EBITSET_ELTS (src) + oldsize, 0,
 	      (newsize - oldsize) * sizeof (ebitset_elt *));
     }
   else
@@ -838,10 +838,10 @@ ebitset_unused_clear (bitset dst)
 {
   unsigned int last_bit;
   bitset_bindex n_bits;
-  
+
   n_bits = BITSET_NBITS_ (dst);
   last_bit = n_bits % EBITSET_ELT_BITS;
-  
+
   if (last_bit)
     {
       bitset_windex eindex;
@@ -849,20 +849,20 @@ ebitset_unused_clear (bitset dst)
       ebitset_elt *elt;
 
       elts = EBITSET_ELTS (dst);
-      
+
       eindex = n_bits / EBITSET_ELT_BITS;
-      
+
       elt = elts[eindex];
       if (elt)
 	{
 	  bitset_windex windex;
 	  bitset_windex woffset;
 	  bitset_word *srcp = EBITSET_WORDS (elt);
-	  
+
 	  windex = n_bits / BITSET_WORD_BITS;
 	  woffset = eindex * EBITSET_ELT_WORDS;
-	  
-	  srcp[windex - woffset] &= ((bitset_word) 1 << last_bit) - 1;	  
+
+	  srcp[windex - woffset] &= ((bitset_word) 1 << last_bit) - 1;
 	  windex++;
 	  for (; (windex - woffset) < EBITSET_ELT_WORDS; windex++)
 	    srcp[windex - woffset] = 0;
