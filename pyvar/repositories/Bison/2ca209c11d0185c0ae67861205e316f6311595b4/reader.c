@@ -1474,12 +1474,14 @@ readgram (void)
 		  /* Make a dummy nonterminal, a gensym.  */
 		  bucket *sdummy = gensym ();
 
-		  /* Make a new rule, whose body is empty,
-		     before the current one, so that the action
-		     just read can belong to it.  */
+		  /* Make a new rule, whose body is empty, before the
+		     current one, so that the action just read can
+		     belong to it.  */
 		  nrules++;
 		  nitems++;
 		  p = symbol_list_new (sdummy);
+		  /* Attach its lineno to that of the host rule. */
+		  p->line = crule->line;
 		  if (crule1)
 		    crule1->next = p;
 		  else
