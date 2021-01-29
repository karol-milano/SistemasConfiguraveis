@@ -229,7 +229,7 @@ prepare_rules (void)
       /* Separator in RHS. */
       rhs[i++] = -1;
       /* Line where rule was defined. */
-      rline[r] = rules[r].location.first_line;
+      rline[r] = rules[r].location.start.line;
       /* Dynamic precedence (GLR).  */
       dprec[r] = rules[r].dprec;
       /* Merger-function index (GLR).  */
@@ -295,8 +295,8 @@ user_actions_output (FILE *out)
 	fprintf (out, "  case %d:\n", r + 1);
 
 	fprintf (out, "]b4_syncline([[%d]], ",
-		 rules[r].action_location.first_line);
-	escaped_file_name_output (out, rules[r].action_location.file);
+		 rules[r].action_location.start.line);
+	escaped_file_name_output (out, rules[r].action_location.start.file);
 	fprintf (out, ")[\n");
 	fprintf (out, "    %s\n    break;\n\n",
 		 rules[r].action);
@@ -399,9 +399,9 @@ symbol_destructors_output (FILE *out)
 	   destructor, typename. */
 	fprintf (out, "%s[",
 		 first ? "" : ",\n");
-	escaped_file_name_output (out, symbol->destructor_location.file);
+	escaped_file_name_output (out, symbol->destructor_location.start.file);
 	fprintf (out, ", [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
-		 symbol->destructor_location.first_line,
+		 symbol->destructor_location.start.line,
 		 symbol->tag,
 		 symbol->number,
 		 symbol->destructor,
@@ -434,9 +434,9 @@ symbol_printers_output (FILE *out)
 	   printer, typename. */
 	fprintf (out, "%s[",
 		 first ? "" : ",\n");
-	escaped_file_name_output (out, symbol->printer_location.file);
+	escaped_file_name_output (out, symbol->printer_location.start.file);
 	fprintf (out, ", [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
-		 symbol->printer_location.first_line,
+		 symbol->printer_location.start.line,
 		 symbol->tag,
 		 symbol->number,
 		 symbol->printer,
