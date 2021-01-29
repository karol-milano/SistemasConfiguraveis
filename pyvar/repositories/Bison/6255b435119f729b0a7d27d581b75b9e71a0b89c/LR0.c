@@ -50,7 +50,7 @@ static short *redset = NULL;
 static short *shiftset = NULL;
 
 static short **kernel_base = NULL;
-static size_t *kernel_size = NULL;
+static int *kernel_size = NULL;
 static short *kernel_items = NULL;
 
 /* hash table for states, to recognize equivalent ones.  */
@@ -213,7 +213,6 @@ static int
 get_state (int symbol)
 {
   int key;
-  short *isp2;
   int i;
   core *sp;
 
@@ -236,7 +235,6 @@ get_state (int symbol)
 	{
 	  if (sp->nitems == kernel_size[symbol])
 	    {
-	      int i;
 	      found = 1;
 	      for (i = 0; i < kernel_size[symbol]; ++i)
 		if (kernel_base[symbol][i] != sp->items[i])
