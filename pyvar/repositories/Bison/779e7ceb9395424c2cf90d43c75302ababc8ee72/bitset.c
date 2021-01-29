@@ -1,5 +1,5 @@
 /* General bitsets.
-   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -296,7 +296,7 @@ bitset_print (FILE *file, bitset bset, bool verbose)
 
   if (verbose)
     fprintf (file, "n_bits = %lu, set = {",
-	     (unsigned long) bitset_size (bset));
+	     (unsigned long int) bitset_size (bset));
 
   pos = 30;
   BITSET_FOR_EACH (iter, bset, i, 0)
