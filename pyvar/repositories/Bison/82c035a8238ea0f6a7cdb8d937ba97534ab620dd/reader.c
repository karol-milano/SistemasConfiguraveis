@@ -1357,6 +1357,11 @@ readgram (void)
 		p = symbol_list_new (sdummy);
 		/* Attach its lineno to that of the host rule. */
 		p->line = crule->line;
+		/* Move the action from the host rule to this one. */
+		p->action = crule->action;
+		p->action_line = crule->action_line;
+		crule->action = NULL;
+
 		if (crule1)
 		  crule1->next = p;
 		else
