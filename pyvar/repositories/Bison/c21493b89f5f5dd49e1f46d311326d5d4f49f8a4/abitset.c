@@ -1,5 +1,5 @@
 /* Array bitsets.
-   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2006 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -37,11 +37,11 @@ static bitset_bindex
 abitset_resize (bitset src ATTRIBUTE_UNUSED,
 		bitset_bindex size ATTRIBUTE_UNUSED)
 {
-    if (BITSET_SIZE_ (src) == size)
-	return size;
-
     /* These bitsets have a fixed size.  */
-    abort ();
+    if (BITSET_SIZE_ (src) != size)
+      abort ();
+
+    return size;
 }
 
 /* Find list of up to NUM bits set in BSET starting from and including
