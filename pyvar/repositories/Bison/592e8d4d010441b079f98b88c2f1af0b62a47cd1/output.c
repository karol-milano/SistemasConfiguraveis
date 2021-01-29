@@ -132,7 +132,6 @@ static short *check = NULL;
 static int lowzero;
 static int high;
 
-struct obstack muscle_obstack;
 static struct obstack format_obstack;
 
 int error_verbose = 0;
@@ -1087,9 +1086,7 @@ output (void)
   /* Process the selected skeleton file.  */
   output_skeleton ();
 
-  obstack_free (&muscle_obstack, NULL);
   obstack_free (&format_obstack, NULL);
-  obstack_free (&action_obstack, NULL);
   obstack_free (&pre_prologue_obstack, NULL);
   obstack_free (&post_prologue_obstack, NULL);
 }
