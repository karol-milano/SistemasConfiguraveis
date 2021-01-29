@@ -50,6 +50,8 @@ main (int argc, char *argv[])
   bindtextdomain (PACKAGE, LOCALEDIR);
   textdomain (PACKAGE);
 
+  bitset_stats_init ();
+
   lineno = 0;
   getargs (argc, argv);
 
