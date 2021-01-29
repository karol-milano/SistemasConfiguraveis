@@ -46,19 +46,22 @@
 
 bool debug_flag;
 bool defines_flag;
+bool graph_flag;
 bool locations_flag;
 bool no_lines_flag;
 bool no_parser_flag;
-int report_flag = report_none;
 bool token_table_flag;
 bool yacc_flag;	/* for -y */
-bool graph_flag;
-int trace_flag = trace_none;
+
+bool error_verbose = false;
 
 bool nondeterministic_parser = false;
 bool glr_parser = false;
 bool pure_parser = false;
 
+int report_flag = report_none;
+int trace_flag = trace_none;
+
 const char *skeleton = NULL;
 const char *include = NULL;
 
