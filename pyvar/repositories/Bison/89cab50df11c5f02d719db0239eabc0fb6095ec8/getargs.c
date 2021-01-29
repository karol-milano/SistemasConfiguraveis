@@ -27,36 +27,38 @@
 char *spec_file_prefix; /* for -b. */
 char *spec_name_prefix; /* for -p.  */
 
-int debugflag = 0;
-int definesflag = 0;
-int nolinesflag = 0;
-int noparserflag = 0;
-int rawtoknumflag = 0;
-int toknumflag = 0;
-int verboseflag = 0;
-int statisticsflag = 0;
-int yaccflag = 0;	/* for -y */
+int debug_flag = 0;
+int defines_flag = 0;
+int locations_flag = 0;
+int no_lines_flag = 0;
+int no_parser_flag = 0;
+int raw_flag = 0;
+int token_table_flag = 0;
+int verbose_flag = 0;
+int statistics_flag = 0;
+int yacc_flag = 0;	/* for -y */
 
 extern char *program_name;
 
 static struct option longopts[] =
 {
-  {"debug", 0, &debugflag, 1},
-  {"defines", 0, &definesflag, 1},
+  {"debug", 0, &debug_flag, 1},
+  {"defines", 0, &defines_flag, 1},
   {"file-prefix", 1, 0, 'b'},
-  {"fixed-output-files", 0, &yaccflag, 1},
+  {"fixed-output-files", 0, &yacc_flag, 1},
   {"help", 0, 0, 'h'},
   {"name-prefix", 1, 0, 'p'}, /* was 'a';  apparently unused -wjh */
-  {"no-lines", 0, &nolinesflag, 1},
-  {"no-parser", 0, &noparserflag, 1},
+  {"locations", 0, &locations_flag, 1},
+  {"no-lines", 0, &no_lines_flag, 1},
+  {"no-parser", 0, &no_parser_flag, 1},
   {"output", 1, 0, 'o'},
   {"output-file", 1, 0, 'o'},
-  {"raw", 0, &rawtoknumflag, 1},
-  {"token-table", 0, &toknumflag, 1},
-  {"verbose", 0, &verboseflag, 1},
+  {"raw", 0, &raw_flag, 1},
+  {"statistics", 0, &statistics_flag, 1},
+  {"token-table", 0, &token_table_flag, 1},
+  {"verbose", 0, &verbose_flag, 1},
   {"version", 0, 0, 'V'},
-  {"yacc", 0, &yaccflag, 1},
-  {"statistics", 0, &statisticsflag, 1},
+  {"yacc", 0, &yacc_flag, 1},
   {0, 0, 0, 0}
 };
 
@@ -93,6 +95,7 @@ Operation modes:\n\
   fputs (_("\
 Parser:\n\
   -t, --debug                instrument the parser for debugging\n\
+      --locations            enable locations computation\n\
   -p, --name-prefix=PREFIX   prepend PREFIX to the external symbols\n\
   -l, --no-lines             don't generate `#line' directives\n\
   -n, --no-parser            generate the tables only\n\
@@ -159,7 +162,7 @@ getargs (int argc, char *argv[])
 	  break;
 
 	case 'y':
-	  yaccflag = 1;
+	  yacc_flag = 1;
 	  break;
 
 	case 'h':
@@ -171,31 +174,31 @@ getargs (int argc, char *argv[])
 	  exit (0);
 
 	case 'v':
-	  verboseflag = 1;
+	  verbose_flag = 1;
 	  break;
 
 	case 'd':
-	  definesflag = 1;
+	  defines_flag = 1;
 	  break;
 
 	case 'l':
-	  nolinesflag = 1;
+	  no_lines_flag = 1;
 	  break;
 
 	case 'k':
-	  toknumflag = 1;
+	  token_table_flag = 1;
 	  break;
 
 	case 'r':
-	  rawtoknumflag = 1;
+	  raw_flag = 1;
 	  break;
 
 	case 'n':
-	  noparserflag = 1;
+	  no_parser_flag = 1;
 	  break;
 
 	case 't':
-	  debugflag = 1;
+	  debug_flag = 1;
 	  break;
 
 	case 'o':
