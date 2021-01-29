@@ -90,6 +90,7 @@ main (int argc, char *argv[])
   uniqstrs_new ();
   muscle_init ();
   complain_init ();
+  code_scanner_init ();
 
   getargs (argc, argv);
 
