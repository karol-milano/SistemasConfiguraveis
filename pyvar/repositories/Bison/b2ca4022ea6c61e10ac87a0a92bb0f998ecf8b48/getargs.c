@@ -34,14 +34,11 @@ int noparserflag = 0;
 int rawtoknumflag = 0;
 int toknumflag = 0;
 int verboseflag = 0;
-
-extern int fixed_outfiles;/* for -y */
+int statisticsflag = 0;
+int fixed_outfiles = 0;/* for -y */
 
 extern char *program_name;
 
-extern void warns PARAMS((char *, char *));	/* main.c */
-extern void getargs PARAMS((int argc, char *[]));
-
 static struct option longopts[] =
 {
   {"debug", 0, &debugflag, 1},
@@ -59,6 +56,7 @@ static struct option longopts[] =
   {"verbose", 0, &verboseflag, 1},
   {"version", 0, 0, 'V'},
   {"yacc", 0, &fixed_outfiles, 1},
+  {"statistics", 0, &statisticsflag, 1},
   {0, 0, 0, 0}
 };
 
