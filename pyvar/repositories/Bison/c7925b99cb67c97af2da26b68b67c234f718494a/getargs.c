@@ -34,7 +34,6 @@ int no_lines_flag = 0;
 int no_parser_flag = 0;
 int token_table_flag = 0;
 int verbose_flag = 0;
-int error_verbose_flag = 0;
 int yacc_flag = 0;	/* for -y */
 int graph_flag = 0;
 int trace_flag = 0;
@@ -166,10 +165,6 @@ getargs (int argc, char *argv[])
 	verbose_flag = 1;
 	break;
 
-      case 'e':
-	error_verbose_flag = 1;
-	break;
-
       case 'S':
 	skeleton = optarg;
 	break;
