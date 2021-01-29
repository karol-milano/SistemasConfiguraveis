@@ -110,7 +110,7 @@ main (int argc, char *argv[])
   free_nullable ();
   free_derives ();
   grammar_free ();
-
+  muscle_free ();
   /* If using alloca.c, flush the alloca'ed memory for the benefit of
      people running Bison as a library in IDEs.  */
 #if C_ALLOCA
