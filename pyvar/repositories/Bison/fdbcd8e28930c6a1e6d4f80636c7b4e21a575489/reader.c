@@ -45,9 +45,6 @@ typedef struct symbol_list
   const char *action;
   int action_line;
 
-  /* The guard is attached to the LHS of a rule. */
-  const char *guard;
-  int guard_line;
   symbol_t *ruleprec;
 } symbol_list;
 
@@ -80,8 +77,6 @@ symbol_list_new (symbol_t *sym)
   res->line = lineno;
   res->action = NULL;
   res->action_line = 0;
-  res->guard = NULL;
-  res->guard_line = 0;
   res->ruleprec = NULL;
   return res;
 }
@@ -1273,9 +1268,7 @@ read_declarations (void)
 | values in the current rule so far, which says where to find `$0'  |
 | with respect to the top of the stack.                             |
 |                                                                   |
-| This routine is used both for actions and guards.  Only           |
-| ACTION_OBSTACK is used, but this is fine, since we use only       |
-| pointers to relevant portions inside this obstack.                |
+| This routine is used for actions.                                 |
 `------------------------------------------------------------------*/
 
 static void
@@ -1341,18 +1334,6 @@ parse_action (symbol_list *rule, int rule_length)
   rule->action = obstack_finish (&action_obstack);
 }
 
-
-static void
-parse_guard (symbol_list *rule, int rule_length)
-{
-  token_t t = lex ();
-  if (t != tok_left_curly)
-    complain (_("invalid %s declaration"), "%guard");
-  rule->guard_line = lineno;
-  parse_braces (rule, rule_length);
-  rule->guard = obstack_finish (&action_obstack);
-}
-
 
 
 /*-------------------------------------------------------------------.
@@ -1384,8 +1365,8 @@ gensym (void)
 | null pointer instead of a symbol to terminate the rule.  The next  |
 | symbol is the lhs of the following rule.                           |
 |                                                                    |
-| All guards and actions are copied out to the appropriate files,    |
-| labelled by the rule number they apply to.                         |
+| All actions are copied out, labelled by the rule number they apply |
+| to.                                                                |
 |                                                                    |
 | Bison used to allow some %directives in the rules sections, but    |
 | this is no longer consider appropriate: (i) the documented grammar |
@@ -1582,15 +1563,6 @@ readgram (void)
 	    t = lex ();
 	  }
 
-	if (t == tok_guard)
-	  {
-	    if (!semantic_parser)
-	      complain (_("%%guard present but %%semantic_parser not specified"));
-
-	    parse_guard (crule, rulelength);
-	    t = lex ();
-	  }
-
 	if (t == tok_left_curly)
 	  {
 	    /* This case never occurs -wjh */
@@ -1791,8 +1763,6 @@ packgram (void)
       rules[ruleno].useful = TRUE;
       rules[ruleno].action = p->action;
       rules[ruleno].action_line = p->action_line;
-      rules[ruleno].guard = p->guard;
-      rules[ruleno].guard_line = p->guard_line;
 
       p = p->next;
       while (p && p->sym)
@@ -1829,13 +1799,12 @@ packgram (void)
     ritem_print (stderr);
 }
 
-/*-------------------------------------------------------------------.
-| Read in the grammar specification and record it in the format      |
-| described in gram.h.  All guards are copied into the GUARD_OBSTACK |
-| and all actions into ACTION_OBSTACK, in each case forming the body |
-| of a C function (YYGUARD or YYACTION) which contains a switch      |
-| statement to decide which guard or action to execute.              |
-`-------------------------------------------------------------------*/
+/*------------------------------------------------------------------.
+| Read in the grammar specification and record it in the format     |
+| described in gram.h.  All actions are copied into ACTION_OBSTACK, |
+| in each case forming the body of a C function (YYACTION) which    |
+| contains a switch statement to decide which action to execute.    |
+`------------------------------------------------------------------*/
 
 void
 reader (void)
@@ -1889,7 +1858,7 @@ reader (void)
     }
 
   /* Read in the grammar, build grammar in list form.  Write out
-     guards and actions.  */
+     actions.  */
   readgram ();
   /* Some C code is given at the end of the grammar file. */
   read_additionnal_code ();
