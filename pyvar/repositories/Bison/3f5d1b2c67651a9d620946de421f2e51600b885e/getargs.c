@@ -646,7 +646,7 @@ getargs (int argc, char *argv[])
 	exit (EXIT_SUCCESS);
 
       case 'f':
-        FLAGS_ARGMATCH (flag, optarg);
+        FLAGS_ARGMATCH (feature, optarg);
         break;
 
       case 'W':
