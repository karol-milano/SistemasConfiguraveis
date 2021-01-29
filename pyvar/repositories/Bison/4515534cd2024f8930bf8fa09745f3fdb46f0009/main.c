@@ -110,6 +110,10 @@ main (int argc, char *argv[])
   free_nullable ();
   free_derives ();
   grammar_free ();
+
+  /* The scanner memory cannot be released right after parsing, as it
+     contains things such as user actions, prologue, epilogue etc.  */
+  scanner_free ();
   muscle_free ();
   /* If using alloca.c, flush the alloca'ed memory for the benefit of
      people running Bison as a library in IDEs.  */
