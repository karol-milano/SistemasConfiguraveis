@@ -1,5 +1,5 @@
 /* Bitset statistics.
-   Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -696,6 +696,9 @@ bitset_stats_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
      we are a wrapper over.  */
   switch (type)
     {
+    default:
+      abort ();
+
     case BITSET_ARRAY:
       bytes = abitset_bytes (n_bits);
       sbset = xcalloc (1, bytes);
@@ -719,9 +722,6 @@ bitset_stats_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
       sbset = xcalloc (1, bytes);
       vbitset_init (sbset, n_bits);
       break;
-
-    default:
-      abort ();
     }
 
   bset->s.bset = sbset;
