@@ -1327,7 +1327,7 @@ readgram (void)
 		symval = ssave;
 		if (t1 == tok_colon)
 		  {
-		    complain (_("previous rule lacks an ending `;'"));
+		    warn (_("previous rule lacks an ending `;'"));
 		    break;
 		  }
 
@@ -1446,7 +1446,7 @@ readgram (void)
 	else if (!xactions && !first_rhs && lhs->type_name != 0)
 	  complain (_("empty rule for typed nonterminal, and no action"));
 	if (t == tok_two_percents || t == tok_eof)
-	  complain (_("previous rule lacks an ending `;'"));
+	  warn (_("previous rule lacks an ending `;'"));
 	if (t == tok_semicolon)
 	  t = lex ();
       }
