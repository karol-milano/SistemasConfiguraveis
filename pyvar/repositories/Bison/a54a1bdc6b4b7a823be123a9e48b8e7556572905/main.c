@@ -1,4 +1,5 @@
-/* Top level entry point of bison,
+/* Top level entry point of Bison.
+
    Copyright (C) 1984, 1986, 1989, 1992, 1995, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
@@ -173,7 +174,10 @@ main (int argc, char *argv[])
   /* If using alloca.c, flush the alloca'ed memory for the benefit of
      people running Bison as a library in IDEs.  */
 #if C_ALLOCA
-  alloca (0);
+  {
+    extern void *alloca (size_t);
+    alloca (0);
+  }
 #endif
   timevar_pop (TV_FREE);
 
