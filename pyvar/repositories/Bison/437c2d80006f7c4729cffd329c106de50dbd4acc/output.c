@@ -276,11 +276,10 @@ user_actions_output (FILE *out)
       {
 	fprintf (out, "  case %d:\n", r + 1);
 
-	if (!no_lines_flag)
-	  fprintf (out, muscle_find ("linef"),
-		   rules[r].action_location.first_line,
-		   quotearg_style (c_quoting_style,
-				   rules[r].action_location.file));
+	fprintf (out, "]b4_syncline([[%d]], [[%s]])[\n",
+		 rules[r].action_location.first_line,
+		 quotearg_style (escape_quoting_style,
+				 rules[r].action_location.file));
 	fprintf (out, "    %s\n    break;\n\n",
 		 rules[r].action);
       }
@@ -566,11 +565,12 @@ static void
 prepare (void)
 {
   /* Flags. */
-  MUSCLE_INSERT_INT ("locations_flag", locations_flag);
+  MUSCLE_INSERT_INT ("debug", debug_flag);
   MUSCLE_INSERT_INT ("defines_flag", defines_flag);
   MUSCLE_INSERT_INT ("error_verbose", error_verbose);
+  MUSCLE_INSERT_INT ("locations_flag", locations_flag);
   MUSCLE_INSERT_INT ("pure", pure_parser);
-  MUSCLE_INSERT_INT ("debug", debug_flag);
+  MUSCLE_INSERT_INT ("synclines_flag", !no_lines_flag);
 
   /* FIXME: This is wrong: the muscles should decide whether they hold
      a copy or not, but the situation is too obscure currently.  */
