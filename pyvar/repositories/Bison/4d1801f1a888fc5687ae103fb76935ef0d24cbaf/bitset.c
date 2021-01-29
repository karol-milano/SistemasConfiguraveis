@@ -1,5 +1,5 @@
 /* General bitsets.
-   Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -111,7 +111,7 @@ bitset_type_choose (bitset_bindex n_bits ATTRIBUTE_UNUSED, unsigned int attr)
   /* Choose the type of bitset.  Note that sometimes we will be asked
   for a zero length fixed size bitset.  */
 
-  
+
   /* If no attributes selected, choose a good compromise.  */
   if (!attr)
     return BITSET_VARRAY;
@@ -307,7 +307,7 @@ bitset_print (FILE *file, bitset bset, bool verbose)
 	pos = 0;
       }
 
-    fprintf (file, "%d ", i);
+    fprintf (file, "%lu ", (unsigned long int) i);
     pos += 1 + (i >= 10) + (i >= 100);
   };
 
