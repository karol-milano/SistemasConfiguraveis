@@ -34,7 +34,7 @@ int nolinesflag;
 extern int noparserflag;
 extern int toknumflag;
 extern int rawtoknumflag;
-extern int fixed_outfiles;
+extern int yaccflag;
 extern char * version_string;
 
 /* Allocate storgate and initialize, since bison uses them elsewhere.  */
@@ -53,7 +53,7 @@ getargs(argc,argv)
   verboseflag = 0;
   definesflag = 0;
   debugflag = 0;
-  fixed_outfiles = 0;
+  yaccflag = 0;
   nolinesflag = 0;
   noparserflag = 0;
   toknumflag = 0;
@@ -69,8 +69,8 @@ getargs(argc,argv)
   /*
    *	Check for /FIXED_OUTFILES qualifier
    */
-  if (cli_present("BISON$FIXED_OUTFILES")) fixed_outfiles = 1;
-  if (cli_present("BISON$YACC")) fixed_outfiles = 1;
+  if (cli_present("BISON$FIXED_OUTFILES")) yaccflag = 1;
+  if (cli_present("BISON$YACC")) yaccflag = 1;
   /*
    *	Check for /VERSION qualifier
    */
