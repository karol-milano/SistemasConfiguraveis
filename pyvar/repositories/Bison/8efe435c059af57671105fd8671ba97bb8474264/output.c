@@ -307,7 +307,7 @@ prepare_rules (void)
       /* Separator in RHS. */
       rhs[i++] = -1;
       /* Line where rule was defined. */
-      rline[r] = rules[r].line;
+      rline[r] = rules[r].location.first_line;
     }
   assert (i == nritems);
 
@@ -544,7 +544,7 @@ actions_output (FILE *out)
 
 	if (!no_lines_flag)
 	  fprintf (out, muscle_find ("linef"),
-		   rules[rule].action_line,
+		   rules[rule].action_location.first_line,
 		   quotearg_style (c_quoting_style,
 				   muscle_find ("filename")));
 	fprintf (out, "    %s\n    break;\n\n",
