@@ -78,7 +78,7 @@ static struct obstack lbitset_obstack;
 static bool lbitset_obstack_init = false;
 static lbitset_elt *lbitset_free_list;	/* Free list of bitset elements.  */
 
-extern void debug_lbitset PARAMS ((bitset));
+extern void debug_lbitset (bitset);
 
 #define LBITSET_CURRENT1(X) \
   ((lbitset_elt *) (void *) ((char *) (X) - offsetof (lbitset_elt, words)))
@@ -127,9 +127,7 @@ lbitset_elt_alloc (void)
 
 	  obstack_specify_allocation (&lbitset_obstack, OBSTACK_CHUNK_SIZE,
 				      __alignof__ (lbitset_elt),
-				      (void *(*)PARAMS ((long int)))
 				      OBSTACK_CHUNK_ALLOC,
-				      (void (*)PARAMS ((void *)))
 				      OBSTACK_CHUNK_FREE);
 	}
 
