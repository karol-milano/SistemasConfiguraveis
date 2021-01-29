@@ -34,11 +34,12 @@ int token_table_flag = 0;
 int verbose_flag = 0;
 int statistics_flag = 0;
 int yacc_flag = 0;	/* for -y */
+int graph_flag = 0;
 
 const char *skeleton = NULL;
 
 extern char *program_name;
-const char *shortopts = "yvdhrltknVo:b:p:S:";
+const char *shortopts = "yvgdhrltknVo:b:p:S:";
 static struct option longopts[] =
 {
   /* Operation modes. */
@@ -63,6 +64,7 @@ static struct option longopts[] =
   {"verbose",		no_argument,		0, 'v'},
   {"file-prefix",	required_argument, 	0, 'b'},
   {"output-file",	required_argument, 	0, 'o'},
+  {"graph",		no_argument,		0, 'g'},
 
   /* Hidden. */
   {"statistics",	no_argument, 	&statistics_flag, 1},
@@ -178,6 +180,10 @@ getargs (int argc, char *argv[])
 	version (stdout);
 	exit (0);
 
+      case 'g':
+	graph_flag = 1;
+	break;
+
       case 'v':
 	verbose_flag = 1;
 	break;
