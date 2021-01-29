@@ -50,7 +50,6 @@
 bool defines_flag;
 bool graph_flag;
 bool xml_flag;
-bool locations_flag;
 bool no_lines_flag;
 bool token_table_flag;
 bool yacc_flag;	/* for -y */
@@ -635,7 +634,8 @@ getargs (int argc, char *argv[])
 	break;
 
       case LOCATIONS_OPTION:
-	locations_flag = true;
+        muscle_percent_define_ensure ("locations",
+                                      command_line_location (), true);
 	break;
 
       case PRINT_LOCALEDIR_OPTION:
