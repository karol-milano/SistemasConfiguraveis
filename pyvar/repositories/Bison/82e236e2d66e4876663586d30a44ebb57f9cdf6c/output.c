@@ -1103,7 +1103,6 @@ prepare (void)
 void
 output (void)
 {
-  obstack_init (&macro_obstack);
   obstack_init (&output_obstack);
 
 #if 0
