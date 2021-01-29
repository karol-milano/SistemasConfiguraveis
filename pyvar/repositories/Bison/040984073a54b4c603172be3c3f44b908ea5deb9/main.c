@@ -56,9 +56,9 @@ main (int argc, char *argv[])
 {
   program_name = argv[0];
   setlocale (LC_ALL, "");
-  bindtextdomain (PACKAGE, LOCALEDIR);
-  bindtextdomain ("bison-runtime", LOCALEDIR);
-  textdomain (PACKAGE);
+  (void) bindtextdomain (PACKAGE, LOCALEDIR);
+  (void) bindtextdomain ("bison-runtime", LOCALEDIR);
+  (void) textdomain (PACKAGE);
 
   uniqstrs_new ();
 
