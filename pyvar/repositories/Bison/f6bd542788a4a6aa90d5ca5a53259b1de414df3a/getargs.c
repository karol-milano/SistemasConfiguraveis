@@ -39,6 +39,7 @@ int graph_flag = 0;
 int trace_flag = 0;
 
 const char *skeleton = NULL;
+const char *include = NULL;
 
 extern char *program_name;
 
@@ -168,6 +169,10 @@ getargs (int argc, char *argv[])
 	skeleton = optarg;
 	break;
 
+      case 'I':
+	include = optarg;
+	break;
+
       case 'd':
 	/* Here, the -d and --defines options are differentiated.  */
 	defines_flag = 1;
