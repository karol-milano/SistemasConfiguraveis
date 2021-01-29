@@ -1,7 +1,6 @@
 /* Functions to support link list bitsets.
 
-   Copyright (C) 2002-2004, 2006, 2009-2012 Free Software Foundation,
-   Inc.
+   Copyright (C) 2002-2004, 2006, 2009-2012 Free Software Foundation, Inc.
 
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
@@ -352,7 +351,7 @@ lbitset_elt_find (bitset bset, bitset_windex windex,
 
       /* ELT is the nearest to the one we want.  If it's not the one
          we want, the one we want does not exist.  */
-      if (elt && (windex - elt->index) < LBITSET_ELT_WORDS)
+      if (windex - elt->index < LBITSET_ELT_WORDS)
         {
           bset->b.cindex = elt->index;
           bset->b.csize = LBITSET_ELT_WORDS;
