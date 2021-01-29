@@ -622,10 +622,16 @@ symbol_destructors_output (FILE *out)
       {
 	symbol_t *symbol = symbols[i];
 
-	/* Symbol-number, destructor. */
-	fprintf (out, "%s[[[%d]], [[%s]], [[%s]]]",
+	/* Filename, lineno,
+	   Symbol-name, Symbol-number,
+	   destructor, typename. */
+	fprintf (out, "%s[[[%s]], [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
 		 first ? "" : ",\n",
-		 symbol->number, symbol->destructor, symbol->type_name);
+		 infile, symbol->destructor_location.first_line,
+		 symbol_tag_get (symbol),
+		 symbol->number,
+		 symbol->destructor,
+		 symbol->type_name);
 
 	first = 0;
       }
