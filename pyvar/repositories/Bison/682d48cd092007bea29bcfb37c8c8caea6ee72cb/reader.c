@@ -1201,7 +1201,8 @@ copy_guard (symbol_list *rule, int stack_offset)
   obstack_fgrow1 (&guard_obstack, "\ncase %d:\n", nrules);
   if (!no_lines_flag)
     obstack_fgrow2 (&guard_obstack, "#line %d %s\n",
-		    lineno, quotearg_style (c_quoting_style, infile));
+		    lineno, quotearg_style (c_quoting_style,
+					    macro_find ("filename")));
   obstack_1grow (&guard_obstack, '{');
 
   count = 0;
