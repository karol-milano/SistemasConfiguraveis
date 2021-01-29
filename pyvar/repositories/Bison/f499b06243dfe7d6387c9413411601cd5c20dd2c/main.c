@@ -110,8 +110,6 @@ main (int argc, char *argv[])
   free_nullable ();
   free_derives ();
 
-  output_files ();
-
   /* If using alloca.c, flush the alloca'ed memory for the benefit of
      people running Bison as a library in IDEs.  */
 #if C_ALLOCA
