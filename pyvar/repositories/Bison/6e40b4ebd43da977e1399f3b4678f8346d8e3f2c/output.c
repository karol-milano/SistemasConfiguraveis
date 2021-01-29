@@ -380,7 +380,8 @@ symbol_destructors_output (FILE *out)
 	   destructor, typename. */
 	fprintf (out, "%s[[[%s]], [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
 		 first ? "" : ",\n",
-		 symbol->destructor_location.file,
+		 quotearg_style (escape_quoting_style,
+				 symbol->destructor_location.file),
 		 symbol->destructor_location.first_line,
 		 symbol->tag,
 		 symbol->number,
@@ -414,7 +415,8 @@ symbol_printers_output (FILE *out)
 	   printer, typename. */
 	fprintf (out, "%s[[[%s]], [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
 		 first ? "" : ",\n",
-		 symbol->printer_location.file,
+		 quotearg_style (escape_quoting_style,
+				 symbol->printer_location.file),
 		 symbol->printer_location.first_line,
 		 symbol->tag,
 		 symbol->number,
