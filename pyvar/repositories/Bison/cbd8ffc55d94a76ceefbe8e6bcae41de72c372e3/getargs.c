@@ -31,6 +31,9 @@ char *spec_name_prefix; /* for -p.  */
 char *spec_file_prefix; /* for -b. */
 extern int fixed_outfiles;/* for -y */
 
+extern char *program_name;
+extern char *version_string;
+
 extern void fatal();
 
 struct option longopts[] =
@@ -39,6 +42,7 @@ struct option longopts[] =
   {"defines", 0, &definesflag, 1},
   {"file-prefix", 1, 0, 'b'},
   {"fixed-output-files", 0, &fixed_outfiles, 1},
+  {"help", 0, 0, 'h'},
   {"name-prefix", 1, 0, 'a'},
   {"no-lines", 0, &nolinesflag, 1},
   {"output", 1, 0, 'o'},
@@ -49,26 +53,34 @@ struct option longopts[] =
   {0, 0, 0, 0}
 };
 
+void
+usage (stream)
+     FILE *stream;
+{
+  fprintf (stream, "\
+Usage: %s [-dhltvyV] [-b file-prefix] [-o outfile] [-p name-prefix]\n\
+       [--debug] [--defines] [--fixed-output-files] [--no-lines]\n\
+       [--verbose] [--version] [--help] [--yacc]\n\
+       [--file-prefix=prefix] [--name-prefix=prefix]\n\
+       [--output=outfile] grammar-file\n",
+	   program_name);
+}
+
 void
 getargs(argc, argv)
      int argc;
      char *argv[];
 {
   register int c;
-  int longind;
-  extern char *program_name;
-  extern char *version_string;
 
   verboseflag = 0;
   definesflag = 0;
   debugflag = 0;
   fixed_outfiles = 0;
 
-  while ((c = getopt_long (argc, argv, "yvdltVo:b:p:", longopts, &longind))
+  while ((c = getopt_long (argc, argv, "yvdhltVo:b:p:", longopts, (int *)0))
 	 != EOF)
     {
-      if (c == 0 && longopts[longind].flag == 0)
-	c = longopts[longind].val;
       switch (c)
 	{
 	case 0:
@@ -79,9 +91,13 @@ getargs(argc, argv)
 	  fixed_outfiles = 1;
 	  break;
 	  
+	case 'h':
+	  usage (stdout);
+	  exit (0);
+
 	case 'V':
-	  printf("%s", version_string);
-	  break;
+	  printf ("%s", version_string);
+	  exit (0);
 	  
 	case 'v':
 	  verboseflag = 1;
@@ -112,13 +128,7 @@ getargs(argc, argv)
 	  break;
 	  
 	default:
-	  fprintf (stderr, "\
-Usage: %s [-dltvyV] [-b file-prefix] [-o outfile] [-p name-prefix]\n\
-       [--debug] [--defines] [--fixed-output-files] [--no-lines]\n\
-       [--verbose] [--version] [--yacc]\n\
-       [--file-prefix=prefix] [--name-prefix=prefix]\n\
-       [--output=outfile] grammar-file\n",
-		   program_name);
+	  usage (stderr);
 	  exit (1);
 	}
     }
