@@ -355,7 +355,8 @@ getargs (int argc, char *argv[])
       case 'g':
 	/* Here, the -g and --graph=FILE options are differentiated.  */
 	graph_flag = 1;
-	spec_graph_file = AS_FILE_NAME (optarg);
+	if (optarg)
+	  spec_graph_file = AS_FILE_NAME (optarg);
 	break;
 
       case 'v':
