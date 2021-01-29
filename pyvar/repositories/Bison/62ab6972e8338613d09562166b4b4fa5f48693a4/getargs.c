@@ -29,7 +29,6 @@ int defines_flag = 0;
 int locations_flag = 0;
 int no_lines_flag = 0;
 int no_parser_flag = 0;
-int raw_flag = 0;
 char *skeleton = 0;
 int token_table_flag = 0;
 int verbose_flag = 0;
@@ -106,7 +105,6 @@ Parser:\n\
   -p, --name-prefix=PREFIX   prepend PREFIX to the external symbols\n\
   -l, --no-lines             don't generate `#line' directives\n\
   -n, --no-parser            generate the tables only\n\
-  -r, --raw                  number the tokens from 3\n\
   -k, --token-table          include a table of token names\n\
 "), stream);
   putc ('\n', stream);
@@ -199,7 +197,7 @@ getargs (int argc, char *argv[])
 	break;
 
       case 'r':
-	raw_flag = 1;
+	fatal (_("`%s' is no longer supported"), "--raw");
 	break;
 
       case 'n':
