@@ -135,7 +135,7 @@ getargs (int argc, char *argv[])
 {
   int c;
 
-  create_long_option_table ();
+  struct option *longopts = long_option_table_new ();
   while ((c = getopt_long (argc, argv, shortopts, longopts, NULL)) != EOF)
     switch (c)
       {
@@ -217,7 +217,8 @@ getargs (int argc, char *argv[])
 	exit (1);
       }
 
-  XFREE (longopts);
+  free (longopts);
+
   if (optind == argc)
     {
       fprintf (stderr, _("%s: no grammar file given\n"), program_name);
