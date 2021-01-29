@@ -1002,8 +1002,6 @@ read_declarations (void)
 	      break;
 
 	    case SEMANTIC_PARSER:
-	      if (!semantic_parser)
-		fguard = xfopen (guardfile, "w");
 	      semantic_parser = 1;
 	      break;
 
@@ -1140,11 +1138,11 @@ copy_guard (symbol_list *rule, int stack_offset)
   if (semantic_parser)
     stack_offset = 0;
 
-  fprintf (fguard, "\ncase %d:\n", nrules);
+  obstack_fgrow1 (&guard_obstack, "\ncase %d:\n", nrules);
   if (!no_lines_flag)
-    fprintf (fguard, "#line %d %s\n",
-	     lineno, quotearg_style (c_quoting_style, infile));
-  putc ('{', fguard);
+    obstack_fgrow2 (&guard_obstack, "#line %d %s\n",
+		    lineno, quotearg_style (c_quoting_style, infile));
+  obstack_1grow (&guard_obstack, '{');
 
   count = 0;
   c = getc (finput);
@@ -1154,18 +1152,18 @@ copy_guard (symbol_list *rule, int stack_offset)
       switch (c)
 	{
 	case '\n':
-	  putc (c, fguard);
+	  obstack_1grow (&guard_obstack, c);
 	  lineno++;
 	  break;
 
 	case '{':
-	  putc (c, fguard);
+	  obstack_1grow (&guard_obstack, c);
 	  brace_flag = 1;
 	  count++;
 	  break;
 
 	case '}':
-	  putc (c, fguard);
+	  obstack_1grow (&guard_obstack, c);
 	  if (count > 0)
 	    count--;
 	  else
@@ -1177,26 +1175,26 @@ copy_guard (symbol_list *rule, int stack_offset)
 
 	case '\'':
 	case '"':
-	  copy_string (finput, fguard, 0, c);
+	  copy_string (finput, 0, &guard_obstack, c);
 	  break;
 
 	case '/':
-	  copy_comment (finput, fguard, 0);
+	  copy_comment (finput, 0, &guard_obstack);
 	  break;
 
 	case '$':
-	  copy_dollar (finput, fguard, 0, rule, stack_offset);
+	  copy_dollar (finput, 0, &guard_obstack, rule, stack_offset);
 	  break;
 
 	case '@':
-	  copy_at (finput, fguard, 0, stack_offset);
+	  copy_at (finput, 0, &guard_obstack, stack_offset);
 	  break;
 
 	case EOF:
 	  fatal ("%s", _("unterminated %guard clause"));
 
 	default:
-	  putc (c, fguard);
+	  obstack_1grow (&guard_obstack, c);
 	}
 
       if (c != '}' || count != 0)
@@ -1205,7 +1203,7 @@ copy_guard (symbol_list *rule, int stack_offset)
 
   c = skip_white_space ();
 
-  fprintf (fguard, ";\n    break;}");
+  obstack_grow_string (&guard_obstack, ";\n    break;}");
   if (c == '{')
     copy_action (rule, stack_offset);
   else if (c == '=')
@@ -1898,7 +1896,7 @@ packgram (void)
 
 /*-------------------------------------------------------------------.
 | Read in the grammar specification and record it in the format      |
-| described in gram.h.  All guards are copied into the FGUARD file   |
+| described in gram.h.  All guards are copied into the GUARD_OBSTACK |
 | and all actions into ACTION_OBSTACK, in each case forming the body |
 | of a C function (YYGUARD or YYACTION) which contains a switch      |
 | statement to decide which guard or action to execute.              |
