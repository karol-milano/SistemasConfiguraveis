@@ -194,37 +194,6 @@ set_state_table (void)
 }
 
 
-/*------------------------------------------.
-| Return the size of the longest rule RHS.  |
-`------------------------------------------*/
-
-static size_t
-maxrhs (void)
-{
-  short *itemp;
-  int length;
-  int max;
-
-  length = 0;
-  max = 0;
-  for (itemp = ritem; *itemp; itemp++)
-    {
-      if (*itemp > 0)
-	{
-	  length++;
-	}
-      else
-	{
-	  if (length > max)
-	    max = length;
-	  length = 0;
-	}
-    }
-
-  return max;
-}
-
-
 static void
 initialize_LA (void)
 {
@@ -497,7 +466,7 @@ static void
 build_relations (void)
 {
   short *edge = XCALLOC (short, ngotos + 1);
-  short *states = XCALLOC (short, maxrhs () + 1);
+  short *states = XCALLOC (short, ritem_longest_rhs () + 1);
   int i;
 
   includes = XCALLOC (short *, ngotos);
