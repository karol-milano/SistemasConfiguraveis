@@ -56,8 +56,9 @@ main (int argc, char *argv[])
 {
   program_name = argv[0];
   setlocale (LC_ALL, "");
-  (void) bindtextdomain (PACKAGE, LOCALEDIR);
-  (void) textdomain (PACKAGE);
+  bindtextdomain (PACKAGE, LOCALEDIR);
+  bindtextdomain ("bison-runtime", LOCALEDIR);
+  textdomain (PACKAGE);
 
   uniqstrs_new ();
 
