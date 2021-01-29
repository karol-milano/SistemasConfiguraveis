@@ -674,7 +674,7 @@ getargs (int argc, char *argv[])
         exit (EXIT_SUCCESS);
 
       case PRINT_DATADIR_OPTION:
-        printf ("%s\n", compute_pkgdatadir ());
+        printf ("%s\n", pkgdatadir ());
         exit (EXIT_SUCCESS);
 
       case REPORT_FILE_OPTION:
