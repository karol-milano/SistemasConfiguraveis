@@ -402,16 +402,18 @@ symbol_destructors_output (FILE *out)
 
 	/* Filename, lineno,
 	   Symbol-name, Symbol-number,
-	   destructor, typename. */
+	   destructor, optional typename.  */
 	fprintf (out, "%s[", sep);
 	sep = ",\n";
 	escaped_file_name_output (out, sym->destructor_location.start.file);
-	fprintf (out, ", [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
+	fprintf (out, ", [[%d]], [[%s]], [[%d]], [[%s]]",
 		 sym->destructor_location.start.line,
 		 sym->tag,
 		 sym->number,
-		 sym->destructor,
-		 sym->type_name);
+		 sym->destructor);
+	if (sym->type_name)
+	  fprintf (out, ", [[%s]]", sym->type_name);
+	fputc (']', out);
       }
   fputs ("])\n\n", out);
 }
@@ -435,16 +437,18 @@ symbol_printers_output (FILE *out)
 
 	/* Filename, lineno,
 	   Symbol-name, Symbol-number,
-	   printer, typename. */
+	   printer, optional typename.  */
 	fprintf (out, "%s[", sep);
 	sep = ",\n";
 	escaped_file_name_output (out, sym->printer_location.start.file);
-	fprintf (out, ", [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
+	fprintf (out, ", [[%d]], [[%s]], [[%d]], [[%s]]",
 		 sym->printer_location.start.line,
 		 sym->tag,
 		 sym->number,
-		 sym->printer,
-		 sym->type_name);
+		 sym->printer);
+	if (sym->type_name)
+	  fprintf (out, ", [[%s]]", sym->type_name);
+	fputc (']', out);
       }
   fputs ("])\n\n", out);
 }
