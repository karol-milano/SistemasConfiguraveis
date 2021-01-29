@@ -1264,22 +1264,24 @@ read_declarations (void)
 
 /*------------------------------------------------------------------.
 | Assuming that a `{' has just been seen, copy everything up to the |
-| matching `}' into the actions file.  RULE_LENGTH is the number of |
-| values in the current rule so far, which says where to find `$0'  |
-| with respect to the top of the stack.                             |
+| matching `}' into ACTION_OBSTACK.                                 |
+|                                                                   |
+| RULE_LENGTH is the number of values in the current rule so far,   |
+| which says where to find `$0' with respect to the top of the      |
+| stack.  It is not the same as the rule->length in the case of mid |
+| rule actions.                                                     |
 |                                                                   |
 | This routine is used for actions.                                 |
 `------------------------------------------------------------------*/
 
 static void
-parse_braces (symbol_list *rule, int rule_length)
+parse_action (symbol_list *rule, int rule_length)
 {
-  int c;
-  int count;
-
-  count = 1;
+  int count = 1;
+  rule->action_line = lineno;
   while (count > 0)
     {
+      int c;
       while ((c = getc (finput)) != '}')
 	switch (c)
 	  {
@@ -1323,14 +1325,6 @@ parse_braces (symbol_list *rule, int rule_length)
     }
 
   obstack_1grow (&action_obstack, '\0');
-}
-
-
-static void
-parse_action (symbol_list *rule, int rule_length)
-{
-  rule->action_line = lineno;
-  parse_braces (rule, rule_length);
   rule->action = obstack_finish (&action_obstack);
 }
 
