@@ -1,5 +1,5 @@
 /* Functions to support link list bitsets.
-   Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004, 2006 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -363,6 +363,9 @@ lbitset_elt_find (bitset bset, bitset_windex windex,
 
   switch (mode)
     {
+    default:
+      abort ();
+
     case LBITSET_FIND:
       return 0;
 
@@ -376,9 +379,6 @@ lbitset_elt_find (bitset bset, bitset_windex windex,
 
     case LBITSET_SUBST:
       return &lbitset_zero_elts[0];
-
-    default:
-      abort ();
     }
 }
 
@@ -1117,6 +1117,9 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
       dstp = dtmp->words;
       switch (op)
 	{
+	default:
+	  abort ();
+
 	case BITSET_OP_OR:
 	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
 	    {
@@ -1168,9 +1171,6 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 		}
 	    }
 	  break;
-
-	default:
-	  abort ();
 	}
 
       if (!lbitset_elt_zero_p (dtmp))
