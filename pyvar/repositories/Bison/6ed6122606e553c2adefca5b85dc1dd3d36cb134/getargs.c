@@ -39,7 +39,6 @@ void usage PARAMS((FILE *));
 void getargs PARAMS((int, char *[]));
 
 extern char *program_name;
-extern char *version_string;
 
 extern void warns PARAMS((char *, char *));	/* main.c */
 
@@ -108,7 +107,7 @@ getargs (int argc, char *argv[])
 	  exit (0);
 
 	case 'V':
-	  printf ("%s", version_string);
+	  printf ("%s\n", VERSION_STRING);
 	  exit (0);
 	  
 	case 'v':
