@@ -54,6 +54,10 @@ int yacc_flag = 0;	/* for -y */
 int graph_flag = 0;
 int trace_flag = trace_none;
 
+bool nondeterministic_parser = false;
+bool glr_parser = false;
+bool pure_parser = false;
+
 const char *skeleton = NULL;
 const char *include = NULL;
 
