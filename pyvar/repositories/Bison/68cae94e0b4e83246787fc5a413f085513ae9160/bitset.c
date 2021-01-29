@@ -1,5 +1,5 @@
 /* General bitsets.
-   Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -45,6 +45,9 @@ bitset_bytes (enum bitset_type type, bitset_bindex n_bits)
 
   switch (type)
     {
+    default:
+      abort ();
+
     case BITSET_ARRAY:
       bytes = abitset_bytes (n_bits);
       break;
@@ -60,9 +63,6 @@ bitset_bytes (enum bitset_type type, bitset_bindex n_bits)
     case BITSET_VARRAY:
       bytes = vbitset_bytes (n_bits);
       break;
-
-    default:
-      abort ();
     }
 
   return bytes;
@@ -78,6 +78,9 @@ bitset_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
 
   switch (type)
     {
+    default:
+      abort ();
+
     case BITSET_ARRAY:
       return abitset_init (bset, n_bits);
 
@@ -89,9 +92,6 @@ bitset_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
 
     case BITSET_VARRAY:
       return vbitset_init (bset, n_bits);
-
-    default:
-      abort ();
     }
 }
 
@@ -421,6 +421,9 @@ bitset_op4_cmp (bitset dst, bitset src1, bitset src2, bitset src3,
 
   switch (op)
     {
+    default:
+      abort ();
+
     case BITSET_OP_OR_AND:
       bitset_or (tmp, src1, src2);
       changed = bitset_and_cmp (dst, src3, tmp);
@@ -435,9 +438,6 @@ bitset_op4_cmp (bitset dst, bitset src1, bitset src2, bitset src3,
       bitset_andn (tmp, src1, src2);
       changed = bitset_or_cmp (dst, src3, tmp);
       break;
-
-    default:
-      abort ();
     }
 
   bitset_free (tmp);
