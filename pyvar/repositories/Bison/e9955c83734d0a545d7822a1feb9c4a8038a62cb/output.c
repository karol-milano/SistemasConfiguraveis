@@ -548,12 +548,8 @@ actions_output (FILE *out)
 		   rules[rule].action_line,
 		   quotearg_style (c_quoting_style,
 				   muscle_find ("filename")));
-	/* As a Bison extension, add the ending semicolon.  Since some
-	   Yacc don't do that, help people using bison as a Yacc
-	   finding their missing semicolons.  */
-	fprintf (out, "{ %s%s }\n    break;\n\n",
-		 rules[rule].action,
-		 yacc_flag ? ";" : "");
+	fprintf (out, "    %s\n    break;\n\n",
+		 rules[rule].action);
       }
 }
 
