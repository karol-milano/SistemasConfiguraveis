@@ -158,6 +158,8 @@ main (int argc, char *argv[])
   reduce_free ();
   conflicts_free ();
   grammar_free ();
+  /* FIXME: We are leaking all the other file names.  */
+  free (infile);
 
   /* The scanner memory cannot be released right after parsing, as it
      contains things such as user actions, prologue, epilogue etc.  */
