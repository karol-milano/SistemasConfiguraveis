@@ -985,7 +985,6 @@ output_parser (const char *skel_filename, struct obstack *oout)
 	    obstack_fgrow1 (oout, "%d", line + 1);
 	  else if (!strcmp (muscle_key, "input_line"))
 	    obstack_fgrow1 (oout, "%d", lineno);
-	  /* FIXME: Insert the code to recognize %%sub-skeleton for exemple.  */
 	  else
 	    {
 	      obstack_sgrow (oout, "%%");
@@ -1014,6 +1013,7 @@ output_master_parser (void)
       else
 	skeleton = skeleton_find ("BISON_SIMPLE", BISON_SIMPLE);
     }
+  muscle_insert ("skeleton", skeleton);    
   output_parser (skeleton, &table_obstack);
 }
 
