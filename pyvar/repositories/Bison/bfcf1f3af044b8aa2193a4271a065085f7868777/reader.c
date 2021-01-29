@@ -1445,6 +1445,8 @@ readgram (void)
 	/* Warn if there is no default for $$ but we need one.  */
 	else if (!xactions && !first_rhs && lhs->type_name != 0)
 	  complain (_("empty rule for typed nonterminal, and no action"));
+	if (t == tok_two_percents || t == tok_eof)
+	  complain (_("previous rule lacks an ending `;'"));
 	if (t == tok_semicolon)
 	  t = lex ();
       }
