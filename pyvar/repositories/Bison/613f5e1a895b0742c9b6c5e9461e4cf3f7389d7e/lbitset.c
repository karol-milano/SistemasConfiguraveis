@@ -40,9 +40,7 @@
    but the more memory wasted for sparse bitsets and the longer the time
    to search for set bits.  */
 
-#ifndef LBITSET_ELT_WORDS
 #define LBITSET_ELT_WORDS 2
-#endif
 
 typedef bitset_word lbitset_word;
 
@@ -139,9 +137,6 @@ lbitset_elt_alloc ()
     }
   else
     {
-      /* We can't use gcc_obstack_init to initialize the obstack since
-	 print-rtl.c now calls bitset functions, and bitset is linked
-	 into the gen* functions.  */
       if (!lbitset_obstack_init)
 	{
 	  lbitset_obstack_init = 1;
@@ -184,7 +179,7 @@ lbitset_elt_alloc ()
 }
 
 
-/* Allocate a lbitset element.  The bits are not cleared.  */
+/* Allocate a lbitset element.  The bits are cleared.  */
 static inline lbitset_elt *
 lbitset_elt_calloc ()
 {
