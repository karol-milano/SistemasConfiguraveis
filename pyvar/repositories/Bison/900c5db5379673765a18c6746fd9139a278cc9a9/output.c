@@ -280,7 +280,7 @@ user_actions_output (FILE *out)
 	  fprintf (out, muscle_find ("linef"),
 		   rules[r].action_location.first_line,
 		   quotearg_style (c_quoting_style,
-				   muscle_find ("filename")));
+				   rules[r].action_location.file));
 	fprintf (out, "    %s\n    break;\n\n",
 		 rules[r].action);
       }
@@ -381,7 +381,8 @@ symbol_destructors_output (FILE *out)
 	   destructor, typename. */
 	fprintf (out, "%s[[[%s]], [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
 		 first ? "" : ",\n",
-		 infile, symbol->destructor_location.first_line,
+		 symbol->destructor_location.file,
+		 symbol->destructor_location.first_line,
 		 symbol->tag,
 		 symbol->number,
 		 symbol->destructor,
@@ -414,7 +415,8 @@ symbol_printers_output (FILE *out)
 	   printer, typename. */
 	fprintf (out, "%s[[[%s]], [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
 		 first ? "" : ",\n",
-		 infile, symbol->printer_location.first_line,
+		 symbol->printer_location.file,
+		 symbol->printer_location.first_line,
 		 symbol->tag,
 		 symbol->number,
 		 symbol->printer,
