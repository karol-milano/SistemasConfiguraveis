@@ -214,7 +214,8 @@ getargs (int argc, char *argv[])
 	  break;
 
 	default:
-	  usage (stderr);
+	  fprintf (stderr, _("Try `%s --help' for more information.\n"),
+		   program_name);
 	  exit (1);
 	}
     }
