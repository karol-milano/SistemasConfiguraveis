@@ -45,7 +45,7 @@ void scan_skel (FILE *);
 
 static struct obstack format_obstack;
 
-int error_verbose = 0;
+bool error_verbose = false;
 
 
 
@@ -341,7 +341,7 @@ static void
 token_definitions_output (FILE *out)
 {
   int i;
-  int first = 1;
+  char const *sep = "";
 
   fputs ("m4_define([b4_tokens], \n[", out);
   for (i = 0; i < ntokens; ++i)
@@ -376,9 +376,8 @@ token_definitions_output (FILE *out)
 	continue;
 
       fprintf (out, "%s[[[%s]], [%d]]",
-	       first ? "" : ",\n", sym->tag, number);
-
-      first = 0;
+	       sep, sym->tag, number);
+      sep = ",\n";
     }
   fputs ("])\n\n", out);
 }
@@ -392,7 +391,7 @@ static void
 symbol_destructors_output (FILE *out)
 {
   int i;
-  int first = 1;
+  char const *sep = "";
 
   fputs ("m4_define([b4_symbol_destructors], \n[", out);
   for (i = 0; i < nsyms; ++i)
@@ -403,8 +402,8 @@ symbol_destructors_output (FILE *out)
 	/* Filename, lineno,
 	   Symbol-name, Symbol-number,
 	   destructor, typename. */
-	fprintf (out, "%s[",
-		 first ? "" : ",\n");
+	fprintf (out, "%s[", sep);
+	sep = ",\n";
 	escaped_file_name_output (out, sym->destructor_location.start.file);
 	fprintf (out, ", [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
 		 sym->destructor_location.start.line,
@@ -412,8 +411,6 @@ symbol_destructors_output (FILE *out)
 		 sym->number,
 		 sym->destructor,
 		 sym->type_name);
-
-	first = 0;
       }
   fputs ("])\n\n", out);
 }
@@ -427,7 +424,7 @@ static void
 symbol_printers_output (FILE *out)
 {
   int i;
-  int first = 1;
+  char const *sep = "";
 
   fputs ("m4_define([b4_symbol_printers], \n[", out);
   for (i = 0; i < nsyms; ++i)
@@ -438,8 +435,8 @@ symbol_printers_output (FILE *out)
 	/* Filename, lineno,
 	   Symbol-name, Symbol-number,
 	   printer, typename. */
-	fprintf (out, "%s[",
-		 first ? "" : ",\n");
+	fprintf (out, "%s[", sep);
+	sep = ",\n";
 	escaped_file_name_output (out, sym->printer_location.start.file);
 	fprintf (out, ", [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
 		 sym->printer_location.start.line,
@@ -447,8 +444,6 @@ symbol_printers_output (FILE *out)
 		 sym->number,
 		 sym->printer,
 		 sym->type_name);
-
-	first = 0;
       }
   fputs ("])\n\n", out);
 }
@@ -595,12 +590,12 @@ static void
 prepare (void)
 {
   /* Flags. */
-  MUSCLE_INSERT_INT ("debug", debug_flag);
-  MUSCLE_INSERT_INT ("defines_flag", defines_flag);
-  MUSCLE_INSERT_INT ("error_verbose", error_verbose);
-  MUSCLE_INSERT_INT ("locations_flag", locations_flag);
-  MUSCLE_INSERT_INT ("pure", pure_parser);
-  MUSCLE_INSERT_INT ("synclines_flag", !no_lines_flag);
+  MUSCLE_INSERT_BOOL ("debug", debug_flag);
+  MUSCLE_INSERT_BOOL ("defines_flag", defines_flag);
+  MUSCLE_INSERT_BOOL ("error_verbose", error_verbose);
+  MUSCLE_INSERT_BOOL ("locations_flag", locations_flag);
+  MUSCLE_INSERT_BOOL ("pure", pure_parser);
+  MUSCLE_INSERT_BOOL ("synclines_flag", !no_lines_flag);
 
   /* File names.  */
   MUSCLE_INSERT_STRING ("prefix", spec_name_prefix ? spec_name_prefix : "yy");
