@@ -172,14 +172,6 @@ main (int argc, char *argv[])
   scanner_free ();
   muscle_free ();
   uniqstrs_free ();
-  /* If using alloca.c, flush the alloca'ed memory for the benefit of
-     people running Bison as a library in IDEs.  */
-#if C_ALLOCA
-  {
-    extern void *alloca (size_t);
-    alloca (0);
-  }
-#endif
   timevar_pop (TV_FREE);
 
   if (trace_flag & trace_bitsets)
