@@ -1,5 +1,5 @@
 /* Functions to support expandable bitsets.
-   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -52,7 +52,7 @@
 
 /* Number of bits stored in each element.  */
 #define EBITSET_ELT_BITS \
-  ((unsigned) (EBITSET_ELT_WORDS * BITSET_WORD_BITS))
+  ((unsigned int) (EBITSET_ELT_WORDS * BITSET_WORD_BITS))
 
 /* Ebitset element.  We use an array of bits.  */
 typedef struct ebitset_elt_struct
@@ -216,7 +216,7 @@ ebitset_elt_alloc (void)
 
 	  obstack_specify_allocation (&ebitset_obstack, OBSTACK_CHUNK_SIZE,
 				      __alignof__ (ebitset_elt),
-				      (void *(*)PARAMS ((long)))
+				      (void *(*)PARAMS ((long int)))
 				      OBSTACK_CHUNK_ALLOC,
 				      (void (*)PARAMS ((void *)))
 				      OBSTACK_CHUNK_FREE);
