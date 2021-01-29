@@ -155,6 +155,8 @@ report_argmatch (char *args)
 | Display the help message and exit STATUS.  |
 `-------------------------------------------*/
 
+static void usage (int) ATTRIBUTE_NORETURN;
+
 static void
 usage (int status)
 {
@@ -337,11 +339,11 @@ getargs (int argc, char *argv[])
 	break;
 
       case 'h':
-	usage (0);
+	usage (EXIT_SUCCESS);
 
       case 'V':
 	version ();
-	exit (0);
+	exit (EXIT_SUCCESS);
 
       case 'g':
 	/* Here, the -g and --graph=FILE options are differentiated.  */
@@ -405,9 +407,7 @@ getargs (int argc, char *argv[])
 	break;
 
       default:
-	fprintf (stderr, _("Try `%s --help' for more information.\n"),
-		 program_name);
-	exit (1);
+	usage (EXIT_FAILURE);
       }
 
   if (argc - optind != 1)
