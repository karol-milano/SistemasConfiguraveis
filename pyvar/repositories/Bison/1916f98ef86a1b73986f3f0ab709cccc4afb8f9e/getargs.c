@@ -35,7 +35,7 @@ int rawtoknumflag = 0;
 int toknumflag = 0;
 int verboseflag = 0;
 int statisticsflag = 0;
-int fixed_outfiles = 0;/* for -y */
+int yaccflag = 0;	/* for -y */
 
 extern char *program_name;
 
@@ -44,7 +44,7 @@ static struct option longopts[] =
   {"debug", 0, &debugflag, 1},
   {"defines", 0, &definesflag, 1},
   {"file-prefix", 1, 0, 'b'},
-  {"fixed-output-files", 0, &fixed_outfiles, 1},
+  {"fixed-output-files", 0, &yaccflag, 1},
   {"help", 0, 0, 'h'},
   {"name-prefix", 1, 0, 'p'}, /* was 'a';  apparently unused -wjh */
   {"no-lines", 0, &nolinesflag, 1},
@@ -55,7 +55,7 @@ static struct option longopts[] =
   {"token-table", 0, &toknumflag, 1},
   {"verbose", 0, &verboseflag, 1},
   {"version", 0, 0, 'V'},
-  {"yacc", 0, &fixed_outfiles, 1},
+  {"yacc", 0, &yaccflag, 1},
   {"statistics", 0, &statisticsflag, 1},
   {0, 0, 0, 0}
 };
@@ -147,15 +147,7 @@ warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
 void
 getargs (int argc, char *argv[])
 {
-  register int c;
-
-  verboseflag = 0;
-  definesflag = 0;
-  debugflag = 0;
-  noparserflag = 0;
-  rawtoknumflag = 0;
-  toknumflag = 0;
-  fixed_outfiles = 0;
+  int c;
 
   while ((c = getopt_long (argc, argv, "yvdhrltknVo:b:p:", longopts, (int *)0))
 	 != EOF)
@@ -167,7 +159,7 @@ getargs (int argc, char *argv[])
 	  break;
 
 	case 'y':
-	  fixed_outfiles = 1;
+	  yaccflag = 1;
 	  break;
 
 	case 'h':
