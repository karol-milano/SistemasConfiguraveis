@@ -355,9 +355,9 @@ merger_output (FILE *out)
   fputs ("]])\n\n", out);
 }
 
-/*---------------------------------------.
-| Output the tokens definition to OOUT.  |
-`---------------------------------------*/
+/*--------------------------------------.
+| Output the tokens definition to OUT.  |
+`--------------------------------------*/
 
 static void
 token_definitions_output (FILE *out)
@@ -405,9 +405,9 @@ token_definitions_output (FILE *out)
 }
 
 
-/*----------------------------------------.
-| Output the symbol destructors to OOUT.  |
-`----------------------------------------*/
+/*---------------------------------------.
+| Output the symbol destructors to OUT.  |
+`---------------------------------------*/
 
 static void
 symbol_destructors_output (FILE *out)
@@ -438,9 +438,9 @@ symbol_destructors_output (FILE *out)
 }
 
 
-/*-------------------------------------.
-| Output the symbol printers to OOUT.  |
-`-------------------------------------*/
+/*------------------------------------.
+| Output the symbol printers to OUT.  |
+`------------------------------------*/
 
 static void
 symbol_printers_output (FILE *out)
@@ -456,7 +456,7 @@ symbol_printers_output (FILE *out)
 
 	/* Filename, lineno,
 	   Symbol-name, Symbol-number,
-	   destructor, typename. */
+	   printer, typename. */
 	fprintf (out, "%s[[[%s]], [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
 		 first ? "" : ",\n",
 		 infile, symbol->printer_location.first_line,
