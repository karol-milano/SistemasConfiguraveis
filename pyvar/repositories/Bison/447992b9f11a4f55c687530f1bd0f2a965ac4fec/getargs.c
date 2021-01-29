@@ -36,26 +36,33 @@ int statistics_flag = 0;
 int yacc_flag = 0;	/* for -y */
 
 extern char *program_name;
-
+const char *shortopts = "yvdhrltknVo:b:p:";
 static struct option longopts[] =
 {
-  {"debug", 0, &debug_flag, 1},
-  {"defines", 0, &defines_flag, 1},
-  {"file-prefix", 1, 0, 'b'},
-  {"fixed-output-files", 0, &yacc_flag, 1},
-  {"help", 0, 0, 'h'},
-  {"name-prefix", 1, 0, 'p'}, /* was 'a';  apparently unused -wjh */
-  {"locations", 0, &locations_flag, 1},
-  {"no-lines", 0, &no_lines_flag, 1},
-  {"no-parser", 0, &no_parser_flag, 1},
-  {"output", 1, 0, 'o'},
-  {"output-file", 1, 0, 'o'},
-  {"raw", 0, &raw_flag, 1},
-  {"statistics", 0, &statistics_flag, 1},
-  {"token-table", 0, &token_table_flag, 1},
-  {"verbose", 0, &verbose_flag, 1},
-  {"version", 0, 0, 'V'},
-  {"yacc", 0, &yacc_flag, 1},
+  /* Operation modes. */
+  {"help",		no_argument,	0, 'h'},
+  {"version",		no_argument, 	0, 'V'},
+  {"yacc",		no_argument,	0, 'y'},
+  {"fixed-output-files",no_argument,	0, 'y'},
+
+  /* Parser. */
+  {"locations",		no_argument, 	&locations_flag, 1},
+  /* was 'a';  apparently unused -wjh */
+  {"name-prefix",	required_argument, 	0, 'p'},
+  {"no-lines",		no_argument,		0, 'l'},
+  {"no-parser",		no_argument,		0, 'n'},
+  {"raw",		no_argument,		0, 'r'},
+  {"token-table",	no_argument,		0, 'k'},
+  {"debug",		no_argument,		0, 'd'},
+
+  /* Output. */
+  {"defines",		no_argument,		0, 'd'},
+  {"verbose",		no_argument,		0, 'v'},
+  {"file-prefix",	required_argument, 	0, 'b'},
+  {"output-file",	required_argument, 	0, 'o'},
+
+  /* Hidden. */
+  {"statistics",	no_argument, 	&statistics_flag, 1},
   {0, 0, 0, 0}
 };
 
