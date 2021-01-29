@@ -130,6 +130,14 @@ warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
 | Process the options.  |
 `----------------------*/
 
+/* Under DOS, there is no difference on the case.  This can be
+   troublesome when looking for `.tab' etc.  */
+#ifdef MSDOS
+# define AS_FILE_NAME(File) (strlwr (File), (File))
+#else
+# define AS_FILE_NAME(File) (File)
+#endif
+
 void
 getargs (int argc, char *argv[])
 {
@@ -158,7 +166,7 @@ getargs (int argc, char *argv[])
       case 'g':
 	/* Here, the -g and --graph=FILE options are differentiated.  */
 	graph_flag = 1;
-	spec_graph_file = optarg;
+	spec_graph_file = AS_FILE_NAME (optarg);
 	break;
 
       case 'v':
@@ -166,17 +174,18 @@ getargs (int argc, char *argv[])
 	break;
 
       case 'S':
-	skeleton = optarg;
+	skeleton = AS_FILE_NAME (optarg);
 	break;
 
       case 'I':
-	include = optarg;
+	include = AS_FILE_NAME (optarg);
 	break;
 
       case 'd':
 	/* Here, the -d and --defines options are differentiated.  */
 	defines_flag = 1;
-	spec_defines_file = optarg;
+	if (optarg)
+	  spec_defines_file = AS_FILE_NAME (optarg);
 	break;
 
       case 'l':
@@ -200,11 +209,11 @@ getargs (int argc, char *argv[])
 	break;
 
       case 'o':
-	spec_outfile = optarg;
+	spec_outfile = AS_FILE_NAME (optarg);
 	break;
 
       case 'b':
-	spec_file_prefix = optarg;
+	spec_file_prefix = AS_FILE_NAME (optarg);
 	break;
 
       case 'p':
