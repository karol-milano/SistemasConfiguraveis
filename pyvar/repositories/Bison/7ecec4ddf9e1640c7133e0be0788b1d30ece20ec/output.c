@@ -595,12 +595,6 @@ prepare (void)
   DEFINE (spec_verbose_file);
 #undef DEFINE
 
-  /* User Code.  */
-  obstack_1grow (&pre_prologue_obstack, 0);
-  obstack_1grow (&post_prologue_obstack, 0);
-  muscle_insert ("pre_prologue", obstack_finish (&pre_prologue_obstack));
-  muscle_insert ("post_prologue", obstack_finish (&post_prologue_obstack));
-
   /* Find the right skeleton file, and add muscles about the skeletons.  */
   if (skeleton)
     MUSCLE_INSERT_C_STRING ("skeleton", skeleton);
@@ -639,6 +633,4 @@ output (void)
   output_skeleton ();
 
   obstack_free (&format_obstack, NULL);
-  obstack_free (&pre_prologue_obstack, NULL);
-  obstack_free (&post_prologue_obstack, NULL);
 }
