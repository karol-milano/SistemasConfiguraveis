@@ -1,6 +1,6 @@
 /* Output the generated parsing program for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004
+   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004, 2005
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -113,17 +113,17 @@ GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_item_number_table, item_number)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_state_number_table, state_number)
 
 
-/*----------------------------------------------------------------------.
-| Print to OUT a representation of FILENAME escaped both for C and M4.  |
-`----------------------------------------------------------------------*/
+/*--------------------------------------------------------------------.
+| Print to OUT a representation of STRING escaped both for C and M4.  |
+`--------------------------------------------------------------------*/
 
 static void
-escaped_file_name_output (FILE *out, char const *filename)
+escaped_output (FILE *out, char const *string)
 {
   char const *p;
   fprintf (out, "[[");
 
-  for (p = quotearg_style (c_quoting_style, filename); *p; p++)
+  for (p = quotearg_style (c_quoting_style, string); *p; p++)
     switch (*p)
       {
       case '$': fputs ("$][", out); break;
@@ -300,9 +300,9 @@ user_actions_output (FILE *out)
       {
 	fprintf (out, "  case %d:\n", r + 1);
 
-	fprintf (out, "]b4_syncline([[%d]], ",
+	fprintf (out, "]b4_syncline(%d, ",
 		 rules[r].action_location.start.line);
-	escaped_file_name_output (out, rules[r].action_location.start.file);
+	escaped_output (out, rules[r].action_location.start.file);
 	fprintf (out, ")[\n");
 	fprintf (out, "    %s\n    break;\n\n",
 		 rules[r].action);
@@ -375,7 +375,7 @@ token_definitions_output (FILE *out)
       if (strchr (sym->tag, '.') || strchr (sym->tag, '$'))
 	continue;
 
-      fprintf (out, "%s[[[%s]], [%d]]",
+      fprintf (out, "%s[[[%s]], %d]",
 	       sep, sym->tag, number);
       sep = ",\n";
     }
@@ -404,12 +404,10 @@ symbol_destructors_output (FILE *out)
 	   destructor, optional typename.  */
 	fprintf (out, "%s[", sep);
 	sep = ",\n";
-	escaped_file_name_output (out, sym->destructor_location.start.file);
-	fprintf (out, ", [[%d]], [[%s]], [[%d]], [[%s]]",
-		 sym->destructor_location.start.line,
-		 sym->tag,
-		 sym->number,
-		 sym->destructor);
+	escaped_output (out, sym->destructor_location.start.file);
+	fprintf (out, ", %d, ", sym->destructor_location.start.line);
+	escaped_output (out, sym->tag);
+	fprintf (out, ", %d, [[%s]]", sym->number, sym->destructor);
 	if (sym->type_name)
 	  fprintf (out, ", [[%s]]", sym->type_name);
 	fputc (']', out);
@@ -439,12 +437,10 @@ symbol_printers_output (FILE *out)
 	   printer, optional typename.  */
 	fprintf (out, "%s[", sep);
 	sep = ",\n";
-	escaped_file_name_output (out, sym->printer_location.start.file);
-	fprintf (out, ", [[%d]], [[%s]], [[%d]], [[%s]]",
-		 sym->printer_location.start.line,
-		 sym->tag,
-		 sym->number,
-		 sym->printer);
+	escaped_output (out, sym->printer_location.start.file);
+	fprintf (out, ", %d, ", sym->printer_location.start.line);
+	escaped_output (out, sym->tag);
+	fprintf (out, ", %d, [[%s]]", sym->number, sym->printer);
 	if (sym->type_name)
 	  fprintf (out, ", [[%s]]", sym->type_name);
 	fputc (']', out);
