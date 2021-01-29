@@ -40,18 +40,6 @@
 
 location const empty_loc = EMPTY_LOCATION_INIT;
 
-static int
-min_int (int a, int b)
-{
-  return a < b ? a : b;
-}
-
-static int
-max_int (int a, int b)
-{
-  return a >= b ? a : b;
-}
-
 /* The terminal width.  Not less than 40.  */
 static int
 columns (void)
