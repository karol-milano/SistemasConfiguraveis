@@ -1080,10 +1080,14 @@ read_declarations (void)
 | matching `}' into the actions file.  STACK_OFFSET is the number of |
 | values in the current rule so far, which says where to find `$0'   |
 | with respect to the top of the stack.                              |
+|                                                                    |
+| This routine is used both for actions and guards.  Only the        |
+| actions_obstack is used, but this is fine, since we use only       |
+| pointers to relevant portions inside this obstack.                 |
 `-------------------------------------------------------------------*/
 
 static void
-copy_action (symbol_list *rule, int stack_offset)
+parse_braces (symbol_list *rule, int stack_offset)
 {
   int c;
   int count;
@@ -1093,57 +1097,48 @@ copy_action (symbol_list *rule, int stack_offset)
     stack_offset = 0;
 
   count = 1;
-  c = getc (finput);
-
-  rule->action_line = lineno;
-
   while (count > 0)
     {
-      while (c != '}')
-	{
-	  switch (c)
-	    {
-	    case '\n':
-	      obstack_1grow (&action_obstack, c);
-	      lineno++;
-	      break;
-
-	    case '{':
-	      obstack_1grow (&action_obstack, c);
-	      count++;
-	      break;
+      while ((c = getc (finput)) != '}')
+	switch (c)
+	  {
+	  case '\n':
+	    obstack_1grow (&action_obstack, c);
+	    lineno++;
+	    break;
 
-	    case '\'':
-	    case '"':
-	      copy_string (finput, &action_obstack, c);
-	      break;
+	  case '{':
+	    obstack_1grow (&action_obstack, c);
+	    count++;
+	    break;
 
-	    case '/':
-	      copy_comment (finput, &action_obstack);
-	      break;
+	  case '\'':
+	  case '"':
+	    copy_string (finput, &action_obstack, c);
+	    break;
 
-	    case '$':
-	      copy_dollar (finput, &action_obstack,
-			   rule, stack_offset);
-	      break;
+	  case '/':
+	    copy_comment (finput, &action_obstack);
+	    break;
 
-	    case '@':
-	      copy_at (finput, &action_obstack,
-		       stack_offset);
-	      break;
-
-	    case EOF:
-	      fatal (_("unmatched %s"), "`{'");
+	  case '$':
+	    copy_dollar (finput, &action_obstack,
+			 rule, stack_offset);
+	    break;
 
-	    default:
-	      obstack_1grow (&action_obstack, c);
-	    }
+	  case '@':
+	    copy_at (finput, &action_obstack,
+		     stack_offset);
+	    break;
 
-	  c = getc (finput);
-	}
+	  case EOF:
+	    fatal (_("unmatched %s"), "`{'");
 
-      /* above loop exits when c is '}' */
+	  default:
+	    obstack_1grow (&action_obstack, c);
+	  }
 
+      /* Above loop exits when C is '}'.  */
       if (--count)
 	{
 	  obstack_1grow (&action_obstack, c);
@@ -1152,91 +1147,29 @@ copy_action (symbol_list *rule, int stack_offset)
     }
 
   obstack_1grow (&action_obstack, '\0');
-  rule->action = obstack_finish (&action_obstack);
 }
-
-/*-------------------------------------------------------------------.
-| After `%guard' is seen in the input file, copy the actual guard    |
-| into the guards file.  If the guard is followed by an action, copy |
-| that into the actions file.  STACK_OFFSET is the number of values  |
-| in the current rule so far, which says where to find `$0' with     |
-| respect to the top of the stack, for the simple parser in which    |
-| the stack is not popped until after the guard is run.              |
-`-------------------------------------------------------------------*/
+
 
 static void
-copy_guard (symbol_list *rule, int stack_offset)
+parse_action (symbol_list *rule, int stack_offset)
 {
-  int c;
-  int count;
-  int brace_flag = 0;
+  rule->action_line = lineno;
+  parse_braces (rule, stack_offset);
+  rule->action = obstack_finish (&action_obstack);
+}
 
-  /* offset is always 0 if parser has already popped the stack pointer */
-  if (semantic_parser)
-    stack_offset = 0;
 
+static void
+parse_guard (symbol_list *rule, int stack_offset)
+{
+  token_t t = lex ();
+  if (t != tok_left_curly)
+    complain (_("invalid %s declaration"), "%guard");
   rule->guard_line = lineno;
-
-  count = 0;
-  c = getc (finput);
-
-  while (brace_flag ? (count > 0) : (c != ';'))
-    {
-      switch (c)
-	{
-	case '\n':
-	  obstack_1grow (&guard_obstack, c);
-	  lineno++;
-	  break;
-
-	case '{':
-	  obstack_1grow (&guard_obstack, c);
-	  brace_flag = 1;
-	  count++;
-	  break;
-
-	case '}':
-	  obstack_1grow (&guard_obstack, c);
-	  if (count > 0)
-	    count--;
-	  else
-	    {
-	      complain (_("unmatched %s"), "`}'");
-	      c = getc (finput);	/* skip it */
-	    }
-	  break;
-
-	case '\'':
-	case '"':
-	  copy_string (finput, &guard_obstack, c);
-	  break;
-
-	case '/':
-	  copy_comment (finput, &guard_obstack);
-	  break;
-
-	case '$':
-	  copy_dollar (finput, &guard_obstack, rule, stack_offset);
-	  break;
-
-	case '@':
-	  copy_at (finput, &guard_obstack, stack_offset);
-	  break;
-
-	case EOF:
-	  fatal ("%s", _("unterminated %guard clause"));
-
-	default:
-	  obstack_1grow (&guard_obstack, c);
-	}
-
-      if (c != '}' || count != 0)
-	c = getc (finput);
-    }
-
-  obstack_1grow (&guard_obstack, '\0');
-  rule->guard = obstack_finish (&guard_obstack);
+  parse_braces (rule, stack_offset);
+  rule->guard = obstack_finish (&action_obstack);
 }
+
 
 
 /*-------------------------------------------------------------------.
@@ -1439,7 +1372,7 @@ readgram (void)
 	      }
 	    else		/* handle an action.  */
 	      {
-		copy_action (crule, rulelength);
+		parse_action (crule, rulelength);
 		action_flag = 1;
 		xactions++;	/* JF */
 	      }
@@ -1464,7 +1397,7 @@ readgram (void)
 	    if (!semantic_parser)
 	      complain (_("%%guard present but %%semantic_parser not specified"));
 
-	    copy_guard (crule, rulelength);
+	    parse_guard (crule, rulelength);
 	    t = lex ();
 	  }
 
@@ -1473,7 +1406,7 @@ readgram (void)
 	    /* This case never occurs -wjh */
 	    if (action_flag)
 	      complain (_("two actions at end of one rule"));
-	    copy_action (crule, rulelength);
+	    parse_action (crule, rulelength);
 	    action_flag = 1;
 	    xactions++;	/* -wjh */
 	    t = lex ();
@@ -1865,7 +1798,6 @@ reader (void)
   /* Initialize the obstacks. */
   obstack_init (&action_obstack);
   obstack_init (&attrs_obstack);
-  obstack_init (&guard_obstack);
   obstack_init (&output_obstack);
 
   finput = xfopen (infile, "r");
