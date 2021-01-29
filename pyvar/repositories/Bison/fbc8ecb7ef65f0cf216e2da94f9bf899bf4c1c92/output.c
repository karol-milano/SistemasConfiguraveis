@@ -556,8 +556,11 @@ actions_output (FILE *out, size_t *line)
 		 rule_table[rule].action,
 		 yacc_flag ? ";" : "");
 
-	/* We always output 5 '\n' per action.  */
-	*line += 5;
+	/* We always output 4 '\n' per action.  */
+	*line += 4;
+	/* Plus one if !no_lines_flag.  */
+	if (!no_lines_flag)
+	  ++*line;
 	/* Get the number of lines written by the user.  */
 	*line += get_lines_number (rule_table[rule].action);
       }
