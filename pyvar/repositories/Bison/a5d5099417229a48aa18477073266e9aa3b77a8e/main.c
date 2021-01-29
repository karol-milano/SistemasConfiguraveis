@@ -51,7 +51,6 @@ main (int argc, char *argv[])
   bindtextdomain (PACKAGE, LOCALEDIR);
   textdomain (PACKAGE);
 
-  lineno = 0;
   getargs (argc, argv);
 
   if (trace_flag)
