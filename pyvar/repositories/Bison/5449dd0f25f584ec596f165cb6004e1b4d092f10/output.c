@@ -1037,6 +1037,7 @@ prepare (void)
   MUSCLE_INSERT_INT ("locations-flag", locations_flag);
 
   /* We need to save the actions in the muscle %%action.  */
+  obstack_1grow (&action_obstack, 0);
   muscle_insert ("action", obstack_finish (&action_obstack));
 
   if (spec_name_prefix)
@@ -1067,6 +1068,7 @@ output (void)
 #endif
   prepare ();
   /* Copy definitions in directive.  */
+  obstack_1grow (&attrs_obstack, 0);
   muscle_insert ("prologue", obstack_finish (&attrs_obstack));
 
   output_master_parser ();
