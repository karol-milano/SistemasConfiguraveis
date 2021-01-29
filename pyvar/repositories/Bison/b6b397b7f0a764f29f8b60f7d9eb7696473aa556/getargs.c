@@ -41,7 +41,7 @@ bool graph_flag = false;
 bool xml_flag = false;
 bool no_lines_flag = false;
 bool token_table_flag = false;
-bool yacc_flag = false; /* for -y */
+location yacc_loc = EMPTY_LOCATION_INIT;
 bool update_flag = false; /* for -u */
 
 bool nondeterministic_parser = false;
@@ -709,7 +709,7 @@ getargs (int argc, char *argv[])
 
       case 'y':
         warning_argmatch ("error=yacc", 0, 6);
-        yacc_flag = true;
+        yacc_loc = command_line_location ();
         break;
 
       case LOCATIONS_OPTION:
