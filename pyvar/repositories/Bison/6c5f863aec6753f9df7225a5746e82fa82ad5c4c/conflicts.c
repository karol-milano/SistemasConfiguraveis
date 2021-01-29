@@ -545,7 +545,7 @@ conflicts_print (void)
 void
 conflicts_free (void)
 {
-  free (conflicts);
+  XFREE (conflicts);
   bitset_free (shiftset);
   bitset_free (lookaheadset);
   obstack_free (&solved_conflicts_obstack, NULL);
