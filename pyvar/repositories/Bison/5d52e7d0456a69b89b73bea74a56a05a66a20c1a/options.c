@@ -142,7 +142,14 @@ create_long_option_table ()
 	/* Copy the struct information in the longoptions.  */
 	longopts[j].name = option_table[i].name;
 	longopts[j].has_arg = option_table[i].has_arg;
-	longopts[j].flag = option_table[i].set_flag;
+	/* When an options is declared having 'optional_argument' and
+	   a flag is specified to be set, the option is skipped on 
+	   command line. So we never use a flag when a command line
+	   option is declared 'optional_argument.  */
+	if (longopts[j].has_arg == optional_argument)
+	  longopts[j].flag = NULL;
+	else
+	  longopts[j].flag = option_table[i].set_flag;
 	longopts[j++].val = option_table[i].val;
       }
   longopts[number_options].name = NULL;
