@@ -40,7 +40,7 @@
    be zero. 
 
    The bitset cache can be disabled either by setting cindex to
-   some large number or by setting csize to 0.  Here 
+   BITSET_WINDEX_MAX or by setting csize to 0.  Here 
    we use the former approach since cindex needs to be updated whenever
    cdata is changed.   
 */
@@ -71,7 +71,7 @@ typedef ebitset_elt *ebitset_elts;
 /* Head of ebitset linked list.  */
 typedef struct ebitset_struct
 {
-  unsigned int size;		/* Number of elements.  */
+  bitset_windex size;		/* Number of elements.  */
   ebitset_elts *elts;		/* Expanding array of pointers to elements.  */
 }
 *ebitset;
@@ -108,25 +108,25 @@ static struct obstack ebitset_obstack;
 static int ebitset_obstack_init = 0;
 static ebitset_elt *ebitset_free_list;	/* Free list of bitset elements.  */
 
-static void ebitset_elts_grow PARAMS ((bitset, unsigned int));
+static void ebitset_elts_grow PARAMS ((bitset, bitset_windex));
 static ebitset_elt *ebitset_elt_alloc PARAMS ((void));
 static ebitset_elt *ebitset_elt_calloc PARAMS ((void));
-static void ebitset_elt_add PARAMS ((bitset, ebitset_elt *, unsigned int));
-static void ebitset_elt_remove PARAMS ((bitset, unsigned int));
+static void ebitset_elt_add PARAMS ((bitset, ebitset_elt *, bitset_windex));
+static void ebitset_elt_remove PARAMS ((bitset, bitset_windex));
 static void ebitset_elt_free PARAMS ((ebitset_elt *));
 static ebitset_elt *ebitset_elt_find PARAMS ((bitset, bitset_windex,
 					      enum ebitset_find_mode));
 static ebitset_elt *ebitset_elt_last PARAMS ((bitset));
 static int ebitset_elt_zero_p PARAMS ((ebitset_elt *));
 
-static int ebitset_weed PARAMS ((bitset));
+static bitset_windex ebitset_weed PARAMS ((bitset));
 static void ebitset_zero PARAMS ((bitset));
 static void ebitset_copy_ PARAMS ((bitset, bitset));
 static int ebitset_copy_cmp PARAMS ((bitset, bitset));
 static void ebitset_set PARAMS ((bitset, bitset_bindex));
 static void ebitset_reset PARAMS ((bitset, bitset_bindex));
 static int ebitset_test PARAMS ((bitset, bitset_bindex));
-static int ebitset_size PARAMS ((bitset));
+static bitset_bindex ebitset_size PARAMS ((bitset));
 static int ebitset_disjoint_p PARAMS ((bitset, bitset));
 static int ebitset_equal_p PARAMS ((bitset, bitset));
 static void ebitset_not PARAMS ((bitset, bitset));
@@ -136,9 +136,9 @@ static int ebitset_and_cmp PARAMS ((bitset, bitset, bitset));
 static int ebitset_andn_cmp PARAMS ((bitset, bitset, bitset));
 static int ebitset_or_cmp PARAMS ((bitset, bitset, bitset));
 static int ebitset_xor_cmp PARAMS ((bitset, bitset, bitset));
-static int ebitset_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
-				 bitset_bindex *));
-static int ebitset_list_reverse
+static bitset_bindex ebitset_list PARAMS ((bitset, bitset_bindex *,
+					   bitset_bindex, bitset_bindex *));
+static bitset_bindex ebitset_list_reverse
 PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
 static void ebitset_free PARAMS ((bitset));
 
@@ -149,10 +149,10 @@ static void ebitset_free PARAMS ((bitset));
 #define EBITSET_WORDS(ELT) ((ELT)->u.words)
 
 /* Disable bitset cache and mark BSET as being zero.  */
-#define EBITSET_ZERO_SET(BSET) ((BSET)->b.cindex = BITSET_INDEX_MAX, \
+#define EBITSET_ZERO_SET(BSET) ((BSET)->b.cindex = BITSET_WINDEX_MAX, \
         (BSET)->b.cdata = 0)
 
-#define EBITSET_CACHE_DISABLE(BSET)  ((BSET)->b.cindex = BITSET_INDEX_MAX)
+#define EBITSET_CACHE_DISABLE(BSET)  ((BSET)->b.cindex = BITSET_WINDEX_MAX)
 
 /* Disable bitset cache and mark BSET as being possibly non-zero.  */
 #define EBITSET_NONZERO_SET(BSET) \
@@ -173,14 +173,17 @@ static void ebitset_free PARAMS ((bitset));
 static void
 ebitset_elts_grow (bset, size)
      bitset bset;
-     unsigned int size;
+     bitset_windex size;
 {
-  unsigned int oldsize;
-  unsigned int newsize;
+  bitset_windex oldsize;
+  bitset_windex newsize;
 
   oldsize = EBITSET_SIZE (bset);
   newsize = oldsize + size;
 
+  if (BITSET_SIZE_MAX / sizeof (ebitset_elt *) < newsize)
+    xalloc_die ();
+
   EBITSET_ELTS (bset) = xrealloc (EBITSET_ELTS (bset),
 				  newsize * sizeof (ebitset_elt *));
   EBITSET_SIZE (bset) = newsize;
@@ -269,7 +272,7 @@ ebitset_elt_free (elt)
 static inline void
 ebitset_elt_remove (bset, eindex)
      bitset bset;
-     unsigned int eindex;
+     bitset_windex eindex;
 {
   ebitset_elts *elts;
   ebitset_elt *elt;
@@ -288,7 +291,7 @@ static inline void
 ebitset_elt_add (bset, elt, eindex)
      bitset bset;
      ebitset_elt *elt;
-     unsigned int eindex;
+     bitset_windex eindex;
 {
   ebitset_elts *elts;
 
@@ -321,7 +324,7 @@ ebitset_elt_find (bset, windex, mode)
 {
   ebitset_elt *elt;
   bitset_windex size;
-  unsigned int eindex;
+  bitset_windex eindex;
   ebitset_elts *elts;
 
   eindex = windex / EBITSET_ELT_WORDS;
@@ -351,7 +354,7 @@ ebitset_elt_find (bset, windex, mode)
     case EBITSET_CREATE:
       if (eindex >= size)
 	{
-	  unsigned int extra;
+	  bitset_windex extra;
 
 	  extra = eindex - size + 1;
 
@@ -395,13 +398,13 @@ ebitset_elt_last (bset)
 
 
 /* Weed out the zero elements from the elts.  */
-static inline int
+static inline bitset_windex
 ebitset_weed (bset)
      bitset bset;
 {
   ebitset_elts *elts;
   bitset_windex j;
-  int count;
+  bitset_windex count;
 
   if (EBITSET_ZERO_P (bset))
     return 0;
@@ -567,7 +570,7 @@ ebitset_copy_cmp (dst, src)
 
 
 /* Return size in bits of bitset SRC.  */
-static int
+static bitset_bindex
 ebitset_size (src)
      bitset src;
 {
@@ -639,7 +642,7 @@ ebitset_free (bset)
 /* Find list of up to NUM bits set in BSET starting from and including
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
-static int
+static bitset_bindex
 ebitset_list_reverse (bset, list, num, next)
      bitset bset;
      bitset_bindex *list;
@@ -652,7 +655,7 @@ ebitset_list_reverse (bset, list, num, next)
   unsigned int bcount;
   bitset_bindex boffset;
   bitset_windex windex;
-  unsigned int eindex;
+  bitset_windex eindex;
   bitset_windex woffset;
   bitset_bindex count;
   bitset_windex size;
@@ -731,7 +734,7 @@ ebitset_list_reverse (bset, list, num, next)
 /* Find list of up to NUM bits set in BSET starting from and including
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
-static int
+static bitset_bindex
 ebitset_list (bset, list, num, next)
      bitset bset;
      bitset_bindex *list;
@@ -740,7 +743,7 @@ ebitset_list (bset, list, num, next)
 {
   bitset_bindex bitno;
   bitset_windex windex;
-  unsigned int eindex;
+  bitset_windex eindex;
   bitset_bindex count;
   bitset_windex size;
   ebitset_elt *elt;
@@ -1296,7 +1299,7 @@ struct bitset_vtable ebitset_vtable = {
 
 
 /* Return size of initial structure.  */
-int
+size_t
 ebitset_bytes (n_bits)
      bitset_bindex n_bits ATTRIBUTE_UNUSED;
 {
@@ -1311,7 +1314,7 @@ ebitset_init (bset, n_bits)
      bitset bset;
      bitset_bindex n_bits;
 {
-  unsigned int size;
+  bitset_windex size;
 
   bset->b.vtable = &ebitset_vtable;
 
