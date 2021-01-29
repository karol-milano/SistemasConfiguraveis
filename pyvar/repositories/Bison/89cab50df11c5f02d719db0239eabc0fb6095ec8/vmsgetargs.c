@@ -27,14 +27,14 @@ Boston, MA 02111-1307, USA.  */
  *	VMS version of getargs: Uses DCL command parsing
  *		(argc and argv are ignored)
  */
-int verboseflag;
-int definesflag;
-int debugflag;
-int nolinesflag;
-extern int noparserflag;
-extern int toknumflag;
-extern int rawtoknumflag;
-extern int yaccflag;
+int verbose_flag;
+int defines_flag;
+int debug_flag;
+int no_lines_flag;
+extern int no_parser_flag;
+extern int token_table_flag;
+extern int raw_flag;
+extern int yacc_flag;
 extern char * version_string;
 
 /* Allocate storgate and initialize, since bison uses them elsewhere.  */
@@ -50,27 +50,27 @@ getargs(argc,argv)
   static char output_spec[256], name_prefix_spec[256], file_prefix_spec[256];
   extern char *infile;
 
-  verboseflag = 0;
-  definesflag = 0;
-  debugflag = 0;
-  yaccflag = 0;
-  nolinesflag = 0;
-  noparserflag = 0;
-  toknumflag = 0;
-  rawtoknumflag = 0;
+  verbose_flag = 0;
+  defines_flag = 0;
+  debug_flag = 0;
+  yacc_flag = 0;
+  no_lines_flag = 0;
+  no_parser_flag = 0;
+  token_table_flag = 0;
+  raw_flag = 0;
   /*
    *	Check for /VERBOSE qualifier
    */
-  if (cli_present("BISON$VERBOSE")) verboseflag = 1;
+  if (cli_present("BISON$VERBOSE")) verbose_flag = 1;
   /*
    *	Check for /DEFINES qualifier
    */
-  if (cli_present("BISON$DEFINES")) definesflag = 1;
+  if (cli_present("BISON$DEFINES")) defines_flag = 1;
   /*
    *	Check for /FIXED_OUTFILES qualifier
    */
-  if (cli_present("BISON$FIXED_OUTFILES")) yaccflag = 1;
-  if (cli_present("BISON$YACC")) yaccflag = 1;
+  if (cli_present("BISON$FIXED_OUTFILES")) yacc_flag = 1;
+  if (cli_present("BISON$YACC")) yacc_flag = 1;
   /*
    *	Check for /VERSION qualifier
    */
@@ -78,23 +78,23 @@ getargs(argc,argv)
   /*
    *	Check for /NOLINES qualifier
    */
-  if (cli_present("BISON$NOLINES")) nolinesflag = 1;
+  if (cli_present("BISON$NOLINES")) no_lines_flag = 1;
   /*
    *	Check for /NOPARSER qualifier
    */
-  if (cli_present("BISON$NOPARSER")) noparserflag = 1;
+  if (cli_present("BISON$NOPARSER")) no_parser_flag = 1;
   /*
    *	Check for /RAW qualifier
    */
-  if (cli_present("BISON$RAW")) rawtoknumflag = 1;
+  if (cli_present("BISON$RAW")) raw_flag = 1;
   /*
    *	Check for /TOKEN_TABLE qualifier
    */
-  if (cli_present("BISON$TOKEN_TABLE")) toknumflag = 1;
+  if (cli_present("BISON$TOKEN_TABLE")) token_table_flag = 1;
   /*
    *	Check for /DEBUG qualifier
    */
-  if (cli_present("BISON$DEBUG")) debugflag = 1;
+  if (cli_present("BISON$DEBUG")) debug_flag = 1;
   /*
    *	Get the filename
    */
