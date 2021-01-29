@@ -34,8 +34,7 @@
 
 
 static bitset_bindex
-abitset_resize (bitset src ATTRIBUTE_UNUSED,
-		bitset_bindex size ATTRIBUTE_UNUSED)
+abitset_resize (bitset src, bitset_bindex size)
 {
     /* These bitsets have a fixed size.  */
     if (BITSET_SIZE_ (src) != size)
