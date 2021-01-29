@@ -1433,7 +1433,7 @@ readgram (void)
 	/* start a new rule and record its lhs.  */
 
 	++nrules;
-	++nitems;
+	++nritems;
 
 	p = symbol_list_new (lhs);
 
@@ -1511,7 +1511,7 @@ readgram (void)
 		   current one, so that the action just read can
 		   belong to it.  */
 		++nrules;
-		++nitems;
+		++nritems;
 		p = symbol_list_new (sdummy);
 		/* Attach its lineno to that of the host rule. */
 		p->line = crule->line;
@@ -1532,7 +1532,7 @@ readgram (void)
 
 		/* Insert the dummy generated by that rule into this
 		   rule.  */
-		++nitems;
+		++nritems;
 		p = symbol_list_new (sdummy);
 		p1->next = p;
 		p1 = p;
@@ -1542,7 +1542,7 @@ readgram (void)
 
 	    if (t == tok_identifier)
 	      {
-		++nitems;
+		++nritems;
 		p = symbol_list_new (symval);
 		p1->next = p;
 		p1 = p;
@@ -1633,7 +1633,7 @@ readgram (void)
   p->next->next->next = symbol_list_new (NULL);
   p->next->next->next->next = grammar;
   nrules += 1;
-  nitems += 3;
+  nritems += 3;
   grammar = p;
   startval = axiom;
 
@@ -1742,10 +1742,10 @@ packgram (void)
   symbol_list *p;
 
   /* We use short to index items.  */
-  if (nitems >= MAXSHORT)
+  if (nritems >= MAXSHORT)
     fatal (_("too many items (max %d)"), MAXSHORT);
 
-  ritem = XCALLOC (short, nitems + 1);
+  ritem = XCALLOC (short, nritems + 1);
   rules = XCALLOC (rule_t, nrules) - 1;
 
   itemno = 0;
@@ -1793,8 +1793,7 @@ packgram (void)
     }
 
   ritem[itemno] = 0;
-  nritems = itemno;
-  assert (nritems == nitems);
+  assert (itemno == nritems);
 
   if (trace_flag)
     ritem_print (stderr);
