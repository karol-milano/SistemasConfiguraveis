@@ -1,5 +1,5 @@
 /* Functions to support link list bitsets.
-   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -54,7 +54,7 @@ typedef bitset_word lbitset_word;
 
 /* Number of bits stored in each element.  */
 #define LBITSET_ELT_BITS \
-  ((unsigned) (LBITSET_ELT_WORDS * LBITSET_WORD_BITS))
+  ((unsigned int) (LBITSET_ELT_WORDS * LBITSET_WORD_BITS))
 
 /* Lbitset element.   We use an array of bits for each element.
    These are linked together in a doubly-linked list.  */
@@ -127,7 +127,7 @@ lbitset_elt_alloc (void)
 
 	  obstack_specify_allocation (&lbitset_obstack, OBSTACK_CHUNK_SIZE,
 				      __alignof__ (lbitset_elt),
-				      (void *(*)PARAMS ((long)))
+				      (void *(*)PARAMS ((long int)))
 				      OBSTACK_CHUNK_ALLOC,
 				      (void (*)PARAMS ((void *)))
 				      OBSTACK_CHUNK_FREE);
@@ -1390,7 +1390,7 @@ debug_lbitset (bitset bset)
 
   for (elt = LBITSET_HEAD (bset); elt; elt = elt->next)
     {
-      fprintf (stderr, "Elt %lu\n", (unsigned long) elt->index);
+      fprintf (stderr, "Elt %lu\n", (unsigned long int) elt->index);
       for (i = 0; i < LBITSET_ELT_WORDS; i++)
 	{
 	  unsigned int j;
