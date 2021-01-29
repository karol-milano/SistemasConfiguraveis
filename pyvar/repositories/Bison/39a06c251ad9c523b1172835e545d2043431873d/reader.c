@@ -41,6 +41,9 @@ merger_list *merge_functions;
 
 /* Has %union been seen?  */
 bool typed = false;
+
+/* Should rules have a default precedence?  */
+bool default_prec = true;
 
 /*-----------------------.
 | Set the start symbol.  |
@@ -409,7 +412,7 @@ packgram (void)
 	  ritem[itemno++] = symbol_number_as_item_number (p->sym->number);
 	  /* A rule gets by default the precedence and associativity
 	     of the last token in it.  */
-	  if (p->sym->class == token_sym)
+	  if (p->sym->class == token_sym && default_prec)
 	    rules[ruleno].prec = p->sym;
 	  if (p)
 	    p = p->next;
