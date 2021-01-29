@@ -138,19 +138,16 @@ prologue_augment (const char *prologue, location_t location)
 void
 epilogue_set (const char *epilogue, location_t location)
 {
-  struct obstack el_obstack;
-  obstack_init (&el_obstack);
-
   if (!no_lines_flag)
     {
-      obstack_fgrow2 (&el_obstack, muscle_find ("linef"),
+      obstack_fgrow2 (&muscle_obstack, muscle_find ("linef"),
 		      location.first_line,
 		      quotearg_style (c_quoting_style,
 				      muscle_find ("filename")));
     }
-  obstack_sgrow (&el_obstack, epilogue);
-  obstack_1grow (&el_obstack, 0);
-  muscle_insert ("epilogue", obstack_finish (&el_obstack));
+  obstack_sgrow (&muscle_obstack, epilogue);
+  obstack_1grow (&muscle_obstack, 0);
+  muscle_insert ("epilogue", obstack_finish (&muscle_obstack));
 }
 
 
@@ -450,9 +447,6 @@ reader (void)
   gram_control_t gram_control;
   lineno = 1;
 
-  /* Initialize the muscle obstack.  */
-  obstack_init (&muscle_obstack);
-
   /* Initialize the symbol table.  */
   symbols_new ();
 
@@ -473,8 +467,6 @@ reader (void)
   undeftoken->number = ntokens++;
 
   /* Initialize the obstacks. */
-  obstack_init (&action_obstack);
-  obstack_init (&output_obstack);
   obstack_init (&pre_prologue_obstack);
   obstack_init (&post_prologue_obstack);
 
