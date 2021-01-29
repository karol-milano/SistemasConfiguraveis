@@ -170,9 +170,9 @@ free_storage (void)
 | points to a vector of item numbers activated if that symbol is |
 | shifted, and kernel_size[symbol] is their numbers.             |
 |                                                                |
-| itemset is sorted on item number from ritem, which is sorted   |
-| on rule number.  Compute each kernel_base[symbol] with the     |
-| same sort.                                                     |
+| itemset is sorted on item index in ritem, which is sorted on   |
+| rule number.  Compute each kernel_base[symbol] with the same   |
+| sort.                                                          |
 `---------------------------------------------------------------*/
 
 static void
