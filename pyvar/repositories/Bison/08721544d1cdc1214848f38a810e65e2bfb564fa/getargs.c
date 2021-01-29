@@ -1,4 +1,5 @@
-/* Parse command line arguments for bison.
+/* Parse command line arguments for Bison.
+
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
@@ -320,7 +321,8 @@ getargs (int argc, char *argv[])
 {
   int c;
 
-  while ((c = getopt_long (argc, argv, short_options, long_options, NULL)) != EOF)
+  while ((c = getopt_long (argc, argv, short_options, long_options, NULL))
+	 != -1)
     switch (c)
       {
       case 0:
