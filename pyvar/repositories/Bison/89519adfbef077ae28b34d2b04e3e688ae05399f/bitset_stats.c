@@ -698,25 +698,25 @@ bitset_stats_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
     {
     case BITSET_ARRAY:
       bytes = abitset_bytes (n_bits);
-      sbset = (bitset) xcalloc (1, bytes);
+      sbset = xcalloc (1, bytes);
       abitset_init (sbset, n_bits);
       break;
 
     case BITSET_LIST:
       bytes = lbitset_bytes (n_bits);
-      sbset = (bitset) xcalloc (1, bytes);
+      sbset = xcalloc (1, bytes);
       lbitset_init (sbset, n_bits);
       break;
 
     case BITSET_TABLE:
       bytes = ebitset_bytes (n_bits);
-      sbset = (bitset) xcalloc (1, bytes);
+      sbset = xcalloc (1, bytes);
       ebitset_init (sbset, n_bits);
       break;
 
     case BITSET_VARRAY:
       bytes = vbitset_bytes (n_bits);
-      sbset = (bitset) xcalloc (1, bytes);
+      sbset = xcalloc (1, bytes);
       vbitset_init (sbset, n_bits);
       break;
 
