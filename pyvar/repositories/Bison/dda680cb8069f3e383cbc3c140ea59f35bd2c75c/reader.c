@@ -749,7 +749,8 @@ parse_union_decl (void)
 
   if (!no_lines_flag)
     obstack_fgrow2 (&attrs_obstack, "\n#line %d %s\n",
-		    lineno, quotearg_style (c_quoting_style, infile));
+		    lineno, quotearg_style (c_quoting_style, 
+					    macro_find("filename")));
   else
     obstack_1grow (&attrs_obstack, '\n');
 
@@ -1111,7 +1112,8 @@ copy_action (symbol_list *rule, int stack_offset)
   if (!no_lines_flag)
     {
       sprintf (buf, "#line %d %s\n",
-	       lineno, quotearg_style (c_quoting_style, infile));
+	       lineno, quotearg_style (c_quoting_style, 
+				       macro_find ("filename")));
       obstack_grow (&action_obstack, buf, strlen (buf));
     }
   obstack_1grow (&action_obstack, '{');
