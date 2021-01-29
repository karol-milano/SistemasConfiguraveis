@@ -606,13 +606,19 @@ getargs (int argc, char *argv[])
         /* Here, the -d and --defines options are differentiated.  */
         defines_flag = true;
         if (optarg)
-          spec_defines_file = xstrdup (AS_FILE_NAME (optarg));
+          {
+            free (spec_defines_file);
+            spec_defines_file = xstrdup (AS_FILE_NAME (optarg));
+          }
         break;
 
       case 'g':
 	graph_flag = true;
 	if (optarg)
-	  spec_graph_file = xstrdup (AS_FILE_NAME (optarg));
+          {
+            free (spec_graph_file);
+            spec_graph_file = xstrdup (AS_FILE_NAME (optarg));
+          }
 	break;
 
       case 'h':
@@ -649,7 +655,10 @@ getargs (int argc, char *argv[])
       case 'x':
 	xml_flag = true;
 	if (optarg)
-	  spec_xml_file = xstrdup (AS_FILE_NAME (optarg));
+          {
+            free (spec_xml_file);
+            spec_xml_file = xstrdup (AS_FILE_NAME (optarg));
+          }
 	break;
 
       case 'y':
@@ -669,6 +678,7 @@ getargs (int argc, char *argv[])
 	exit (EXIT_SUCCESS);
 
       case REPORT_FILE_OPTION:
+        free (spec_verbose_file);
 	spec_verbose_file = xstrdup (AS_FILE_NAME (optarg));
 	break;
 
