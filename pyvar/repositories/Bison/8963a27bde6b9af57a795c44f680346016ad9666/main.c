@@ -41,7 +41,6 @@ extern void berror PARAMS((const char *));
 
 extern char *printable_version PARAMS ((int));
 
-extern void openfiles PARAMS ((void));
 extern void reduce_grammar PARAMS ((void));
 extern void set_nullable PARAMS ((void));
 extern void free_nullable PARAMS ((void));
@@ -68,7 +67,7 @@ main (int argc, char *argv[])
   /* Be ready to clean up if we exit. */
   atexit (done);
 
-  openfiles ();
+  open_files ();
 
   /* Read the input.  Copy some parts of it to FGUARD, FACTION, FTABLE
      and FATTRS.  In file reader.c.  The other parts are recorded in
