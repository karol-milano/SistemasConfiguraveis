@@ -419,5 +419,5 @@ getargs (int argc, char *argv[])
       usage (EXIT_FAILURE);
     }
 
-  infile = argv[optind];
+  infile = xstrdup (argv[optind]);
 }
