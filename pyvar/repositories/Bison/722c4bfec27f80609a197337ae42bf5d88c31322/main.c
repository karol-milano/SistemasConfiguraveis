@@ -119,6 +119,12 @@ main (int argc, char *argv[])
 
   output_files ();
 
+  /* If using alloca.c, flush the alloca'ed memory for the benefit of
+     people running Bison as a library in IDEs.  */
+#if C_ALLOCA
+    alloca (0);
+#endif
+
   return complain_message_count ? EXIT_FAILURE : EXIT_SUCCESS;
 }
 
