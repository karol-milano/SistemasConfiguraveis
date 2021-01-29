@@ -37,7 +37,6 @@ extern int fixed_outfiles;/* for -y */
 extern char *program_name;
 
 extern void warns PARAMS((char *, char *));	/* main.c */
-static void usage PARAMS((FILE *));
 extern void getargs PARAMS((int argc, char *[]));
 
 static struct option longopts[] =
@@ -63,6 +62,7 @@ static struct option longopts[] =
 /*---------------------------.
 | Display the help message.  |
 `---------------------------*/
+
 static void
 usage (FILE *stream)
 {
@@ -112,6 +112,37 @@ Output:\n\
 Report bugs to <bug-bison@gnu.org>.\n"), stream);
 }
 
+
+/*------------------------------.
+| Display the version message.  |
+`------------------------------*/
+
+static void
+version (FILE *stream)
+{
+  /* Some efforts were made to ease the translators' task, please
+     continue.  */
+  fprintf (stream, _("\
+bison (GNU Bison) %s"), VERSION);
+  putc ('\n', stream);
+  putc ('\n', stream);
+
+  fputs (_("\
+Copyright (C) 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.\n"),
+	 stream);
+
+  fputs (_("\
+This is free software; see the source for copying conditions.  There is NO\n\
+warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
+"),
+	 stream);
+}
+
+
+/*----------------------.
+| Process the options.  |
+`----------------------*/
+
 void
 getargs (int argc, char *argv[])
 {
@@ -143,7 +174,7 @@ getargs (int argc, char *argv[])
 	  exit (0);
 
 	case 'V':
-	  printf ("%s\n", VERSION_STRING);
+	  version (stdout);
 	  exit (0);
 
 	case 'v':
@@ -194,12 +225,12 @@ getargs (int argc, char *argv[])
 
   if (optind == argc)
     {
-      fprintf(stderr, _("%s: no grammar file given\n"), program_name);
-      exit(1);
+      fprintf (stderr, _("%s: no grammar file given\n"), program_name);
+      exit (1);
     }
   if (optind < argc - 1)
-    fprintf(stderr, _("%s: extra arguments ignored after `%s'\n"),
-	    program_name, argv[optind]);
+    fprintf (stderr, _("%s: extra arguments ignored after `%s'\n"),
+	     program_name, argv[optind]);
 
   infile = argv[optind];
 }
