@@ -98,7 +98,7 @@ flags_argmatch (const char *option,
 	    *flags = 0;
 	  else
 	    *flags |= value;
-          args = strtok (NULL, ",");
+	  args = strtok (NULL, ",");
 	}
     }
   else
@@ -408,7 +408,7 @@ getargs (int argc, char *argv[])
 	/* Here, the -g and --graph=FILE options are differentiated.  */
 	graph_flag = true;
 	if (optarg)
-	  spec_graph_file = AS_FILE_NAME (optarg);
+	  spec_graph_file = xstrdup (AS_FILE_NAME (optarg));
 	break;
 
       case 'h':
@@ -426,7 +426,7 @@ getargs (int argc, char *argv[])
 	/* Here, the -d and --defines options are differentiated.  */
 	defines_flag = true;
 	if (optarg)
-	  spec_defines_file = AS_FILE_NAME (optarg);
+	  spec_defines_file = xstrdup (AS_FILE_NAME (optarg));
 	break;
 
       case 'k':
