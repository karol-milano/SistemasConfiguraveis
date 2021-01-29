@@ -71,6 +71,7 @@ static int lastprec;
 static bucket *errtoken = NULL;
 static bucket *undeftoken = NULL;
 static bucket *eoftoken = NULL;
+static bucket *axiom = NULL;
 
 static symbol_list *
 symbol_list_new (bucket *sym)
@@ -1450,6 +1451,18 @@ readgram (void)
 	t = lex ();
       }
 
+  /* Insert the initial rule:
+
+     axiom: %start EOF.  */
+  p = symbol_list_new (axiom);
+  p->next = symbol_list_new (startval);
+  p->next->next = symbol_list_new (eoftoken);
+  p->next->next->next = symbol_list_new (NULL);
+  p->next->next->next->next = grammar;
+  nrules += 1;
+  nitems += 3;
+  grammar = p;
+  startval = axiom;
 
   /* grammar has been read.  Do some checking */
 
@@ -1807,6 +1820,11 @@ reader (void)
   /* Initialize the symbol table.  */
   tabinit ();
 
+  /* Construct the axiom symbol. */
+  axiom = getsym ("$axiom");
+  axiom->class = nterm_sym;
+  axiom->value = nvars++;
+
   /* Construct the error token */
   errtoken = getsym ("error");
   errtoken->class = token_sym;
