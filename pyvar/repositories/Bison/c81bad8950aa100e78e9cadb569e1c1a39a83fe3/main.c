@@ -51,8 +51,8 @@ main (int argc, char *argv[])
 {
   program_name = argv[0];
   setlocale (LC_ALL, "");
-  bindtextdomain (PACKAGE, LOCALEDIR);
-  textdomain (PACKAGE);
+  (void) bindtextdomain (PACKAGE, LOCALEDIR);
+  (void) textdomain (PACKAGE);
 
   getargs (argc, argv);
 
