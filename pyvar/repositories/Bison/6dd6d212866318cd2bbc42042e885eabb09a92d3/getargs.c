@@ -1,5 +1,5 @@
 /* Parse command line arguments for bison,
-   Copyright (C) 1984, 1986, 1989 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992 Free Software Foundation, Inc.
 
 This file is part of Bison, the GNU Compiler Compiler.
 
@@ -27,14 +27,17 @@ int verboseflag;
 int definesflag;
 int debugflag;
 int nolinesflag;
+int noparserflag = 0;
+int toknumflag = 0;
+int rawtoknumflag = 0;
 char *spec_name_prefix; /* for -p.  */
 char *spec_file_prefix; /* for -b. */
 extern int fixed_outfiles;/* for -y */
-
+  
 extern char *program_name;
 extern char *version_string;
 
-extern void fatal();
+extern void warns();	/* main.c */
 
 struct option longopts[] =
 {
@@ -43,10 +46,13 @@ struct option longopts[] =
   {"file-prefix", 1, 0, 'b'},
   {"fixed-output-files", 0, &fixed_outfiles, 1},
   {"help", 0, 0, 'h'},
-  {"name-prefix", 1, 0, 'a'},
+  {"name-prefix", 1, 0, 'p'}, /* was 'a';  apparently unused -wjh */
   {"no-lines", 0, &nolinesflag, 1},
+  {"no-parser", 0, &noparserflag, 1},
   {"output", 1, 0, 'o'},
   {"output-file", 1, 0, 'o'},
+  {"raw", 0, &rawtoknumflag, 1},
+  {"token-table", 0, &toknumflag, 1},
   {"verbose", 0, &verboseflag, 1},
   {"version", 0, 0, 'V'},
   {"yacc", 0, &fixed_outfiles, 1},
@@ -58,9 +64,10 @@ usage (stream)
      FILE *stream;
 {
   fprintf (stream, "\
-Usage: %s [-dhltvyV] [-b file-prefix] [-o outfile] [-p name-prefix]\n\
+Usage: %s [-dhklntvyV] [-b file-prefix] [-o outfile] [-p name-prefix]\n\
        [--debug] [--defines] [--fixed-output-files] [--no-lines]\n\
        [--verbose] [--version] [--help] [--yacc]\n\
+       [--no-parser] [--token-table]\n\
        [--file-prefix=prefix] [--name-prefix=prefix]\n\
        [--output=outfile] grammar-file\n",
 	   program_name);
@@ -76,9 +83,12 @@ getargs(argc, argv)
   verboseflag = 0;
   definesflag = 0;
   debugflag = 0;
+  noparserflag = 0;
+  rawtoknumflag = 0;
+  toknumflag = 0;
   fixed_outfiles = 0;
 
-  while ((c = getopt_long (argc, argv, "yvdhltVo:b:p:", longopts, (int *)0))
+  while ((c = getopt_long (argc, argv, "yvdhrltknVo:b:p:", longopts, (int *)0))
 	 != EOF)
     {
       switch (c)
@@ -111,6 +121,18 @@ getargs(argc, argv)
 	  nolinesflag = 1;
 	  break;
 	  
+	case 'k':
+	  toknumflag = 1;
+	  break;
+
+	case 'r':
+	  rawtoknumflag = 1;
+	  break;
+	  
+	case 'n':
+	  noparserflag = 1;
+	  break;
+	  
 	case 't':
 	  debugflag = 1;
 	  break;
@@ -139,7 +161,8 @@ getargs(argc, argv)
       exit(1);
     }
   if (optind < argc - 1)
-    fprintf(stderr, "%s: warning: extra arguments ignored\n", program_name);
+    fprintf(stderr, "%s: extra arguments ignored after '%s'\n", 
+		program_name, argv[optind]);
 
   infile = argv[optind];
 }
