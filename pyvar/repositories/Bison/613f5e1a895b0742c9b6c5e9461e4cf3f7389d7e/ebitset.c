@@ -47,10 +47,7 @@
 
 
 /* Number of words to use for each element.  */
-
-#ifndef EBITSET_ELT_WORDS
 #define EBITSET_ELT_WORDS 2
-#endif
 
 /* Number of bits stored in each element.  */
 #define EBITSET_ELT_BITS \
@@ -197,9 +194,6 @@ ebitset_elt_alloc ()
     }
   else
     {
-      /* We can't use gcc_obstack_init to initialize the obstack since
-	 print-rtl.c now calls bitset functions, and bitset is linked
-	 into the gen* functions.  */
       if (!ebitset_obstack_init)
 	{
 	  ebitset_obstack_init = 1;
@@ -242,7 +236,7 @@ ebitset_elt_alloc ()
 }
 
 
-/* Allocate a ebitset element.  The bits are not cleared.  */
+/* Allocate a ebitset element.  The bits are cleared.  */
 static inline ebitset_elt *
 ebitset_elt_calloc ()
 {
