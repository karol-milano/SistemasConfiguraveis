@@ -52,7 +52,6 @@ bool defines_flag;
 bool graph_flag;
 bool locations_flag;
 bool no_lines_flag;
-bool no_parser_flag;
 bool token_table_flag;
 bool yacc_flag;	/* for -y */
 
@@ -276,7 +275,6 @@ Parser:\n\
       --locations            enable locations computation\n\
   -p, --name-prefix=PREFIX   prepend PREFIX to the external symbols\n\
   -l, --no-lines             don't generate `#line' directives\n\
-  -n, --no-parser            generate the tables only\n\
   -k, --token-table          include a table of token names\n\
 \n\
 "), stdout);
@@ -434,7 +432,6 @@ static struct option const long_options[] =
   { "debug",	      no_argument,               0,   't' },
   { "locations",      no_argument,		 0, LOCATIONS_OPTION },
   { "no-lines",       no_argument,               0,   'l' },
-  { "no-parser",      no_argument,               0,   'n' },
   { "raw",            no_argument,               0,     0 },
   { "skeleton",       required_argument,         0,   'S' },
   { "language",       required_argument,         0,   'L' },
@@ -505,10 +502,6 @@ getargs (int argc, char *argv[])
 	no_lines_flag = true;
 	break;
 
-      case 'n':
-	no_parser_flag = true;
-	break;
-
       case 'o':
 	spec_outfile = AS_FILE_NAME (optarg);
 	break;
