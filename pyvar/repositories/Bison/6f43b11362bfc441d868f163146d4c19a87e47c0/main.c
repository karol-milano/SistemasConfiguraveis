@@ -51,6 +51,7 @@ main (int argc, char *argv[])
   lineno = 0;
   getargs (argc, argv);
 
+  macro_init ();
   open_files ();
 
   /* Read the input.  Copy some parts of it to FGUARD, FACTION, FTABLE
