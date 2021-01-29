@@ -993,11 +993,6 @@ output_parser (const char *skel_filename, struct obstack *oout)
 	    obstack_fgrow1 (oout, "%d", line + 1);
 	  else if (!strcmp (muscle_key, "input_line"))
 	    obstack_fgrow1 (oout, "%d", lineno);
-	  else if (!strcmp (muscle_key, "action"))
-	    {
-	      size_t size = obstack_object_size (&action_obstack);
-	      obstack_grow (oout, obstack_base (&action_obstack), size);
-	    }
 	  /* FIXME: Insert the code to recognize %%sub-skeleton for exemple.  */
 	  else
 	    {
@@ -1027,8 +1022,6 @@ output_master_parser (void)
       else
 	skeleton = skeleton_find ("BISON_SIMPLE", BISON_SIMPLE);
     }
-  
-  obstack_finish (&action_obstack);
   output_parser (skeleton, &table_obstack);
 }
 
@@ -1090,6 +1083,9 @@ prepare (void)
 
   MUSCLE_INSERT_INT ("locations_flag", locations_flag);
 
+  /* We need to save the actions in the muscle %%action.  */
+  muscle_insert ("action", obstack_finish (&action_obstack));
+
   if (spec_name_prefix)
     MUSCLE_INSERT_STRING ("prefix", spec_name_prefix);
 }
@@ -1125,4 +1121,5 @@ output (void)
 
   obstack_free (&muscle_obstack, 0);
   obstack_free (&output_obstack, 0);
+  obstack_free (&action_obstack, 0);
 }
