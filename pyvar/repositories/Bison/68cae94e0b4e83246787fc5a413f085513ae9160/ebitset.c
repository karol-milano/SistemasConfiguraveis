@@ -1,5 +1,5 @@
 /* Functions to support expandable bitsets.
-   Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -322,6 +322,9 @@ ebitset_elt_find (bitset bset, bitset_bindex bindex,
 
   switch (mode)
     {
+    default:
+      abort ();
+
     case EBITSET_FIND:
       return 0;
 
@@ -337,9 +340,6 @@ ebitset_elt_find (bitset bset, bitset_bindex bindex,
 
     case EBITSET_SUBST:
       return &ebitset_zero_elts[0];
-
-    default:
-      abort ();
     }
 }
 
@@ -1090,6 +1090,9 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
       dstp = EBITSET_WORDS (delt);
       switch (op)
 	{
+	default:
+	  abort ();
+
 	case BITSET_OP_OR:
 	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
 	    {
@@ -1141,9 +1144,6 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 		}
 	    }
 	  break;
-
-	default:
-	  abort ();
 	}
 
       if (!ebitset_elt_zero_p (delt))
