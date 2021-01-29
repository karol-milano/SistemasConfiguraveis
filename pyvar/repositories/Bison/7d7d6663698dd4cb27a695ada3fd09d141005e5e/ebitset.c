@@ -216,9 +216,7 @@ ebitset_elt_alloc (void)
 
 	  obstack_specify_allocation (&ebitset_obstack, OBSTACK_CHUNK_SIZE,
 				      __alignof__ (ebitset_elt),
-				      (void *(*)PARAMS ((long int)))
 				      OBSTACK_CHUNK_ALLOC,
-				      (void (*)PARAMS ((void *)))
 				      OBSTACK_CHUNK_FREE);
 	}
 
