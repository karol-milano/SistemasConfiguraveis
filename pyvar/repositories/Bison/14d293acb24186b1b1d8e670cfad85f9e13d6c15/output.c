@@ -1128,6 +1128,5 @@ output (void)
   obstack_free (&muscle_obstack, NULL);
   obstack_free (&format_obstack, NULL);
   obstack_free (&action_obstack, NULL);
-  obstack_free (&guard_obstack, NULL);
   obstack_free (&attrs_obstack, NULL);
 }
