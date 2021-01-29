@@ -1084,7 +1084,6 @@ output (void)
   output_token_translations ();
   output_gram ();
 
-  XFREE (ritem);
   if (semantic_parser)
     output_stos ();
   output_rule_data ();
@@ -1095,7 +1094,6 @@ output (void)
   /* Process the selected skeleton file.  */
   output_skeleton ();
 
-  free (rules + 1);
   obstack_free (&muscle_obstack, NULL);
   obstack_free (&format_obstack, NULL);
   obstack_free (&action_obstack, NULL);
