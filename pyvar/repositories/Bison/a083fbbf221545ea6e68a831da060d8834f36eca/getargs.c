@@ -63,13 +63,13 @@ void
 usage (stream)
      FILE *stream;
 {
-  fprintf (stream, "\
+  fprintf (stream, _("\
 Usage: %s [-dhklntvyV] [-b file-prefix] [-o outfile] [-p name-prefix]\n\
        [--debug] [--defines] [--fixed-output-files] [--no-lines]\n\
        [--verbose] [--version] [--help] [--yacc]\n\
        [--no-parser] [--token-table]\n\
        [--file-prefix=prefix] [--name-prefix=prefix]\n\
-       [--output=outfile] grammar-file\n",
+       [--output=outfile] grammar-file\n"),
 	   program_name);
 }
 
@@ -157,11 +157,11 @@ getargs(argc, argv)
 
   if (optind == argc)
     {
-      fprintf(stderr, "%s: no grammar file given\n", program_name);
+      fprintf(stderr, _("%s: no grammar file given\n"), program_name);
       exit(1);
     }
   if (optind < argc - 1)
-    fprintf(stderr, "%s: extra arguments ignored after '%s'\n", 
+    fprintf(stderr, _("%s: extra arguments ignored after '%s'\n"),
 		program_name, argv[optind]);
 
   infile = argv[optind];
