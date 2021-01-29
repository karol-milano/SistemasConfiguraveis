@@ -475,10 +475,10 @@ reader (void)
   /* Initialize the symbol table.  */
   symbols_new ();
 
-  /* Construct the axiom symbol. */
-  axiom = symbol_get ("$axiom", empty_location);
-  axiom->class = nterm_sym;
-  axiom->number = nvars++;
+  /* Construct the accept symbol. */
+  accept = symbol_get ("$accept", empty_location);
+  accept->class = nterm_sym;
+  accept->number = nvars++;
 
   /* Construct the error token */
   errtoken = symbol_get ("error", empty_location);
@@ -487,7 +487,7 @@ reader (void)
 
   /* Construct a token that represents all undefined literal tokens.
      It is always token number 2.  */
-  undeftoken = symbol_get ("$undefined.", empty_location);
+  undeftoken = symbol_get ("$undefined", empty_location);
   undeftoken->class = token_sym;
   undeftoken->number = ntokens++;
 
@@ -515,25 +515,25 @@ reader (void)
   /* Report any undefined symbols and consider them nonterminals.  */
   symbols_check_defined ();
 
-  /* If the user did not define her EOFTOKEN, do it now. */
-  if (!eoftoken)
+  /* If the user did not define her ENDTOKEN, do it now. */
+  if (!endtoken)
     {
-      eoftoken = symbol_get ("$", empty_location);
-      eoftoken->class = token_sym;
-      eoftoken->number = 0;
+      endtoken = symbol_get ("$end", empty_location);
+      endtoken->class = token_sym;
+      endtoken->number = 0;
       /* Value specified by POSIX.  */
-      eoftoken->user_token_number = 0;
+      endtoken->user_token_number = 0;
     }
 
   /* Insert the initial rule, which line is that of the first rule
      (not that of the start symbol):
 
-     axiom: %start EOF.  */
+     accept: %start EOF.  */
   {
-    symbol_list_t *p = symbol_list_new (axiom, empty_location);
+    symbol_list_t *p = symbol_list_new (accept, empty_location);
     p->location = grammar->location;
     p->next = symbol_list_new (startsymbol, empty_location);
-    p->next->next = symbol_list_new (eoftoken, empty_location);
+    p->next->next = symbol_list_new (endtoken, empty_location);
     p->next->next->next = symbol_list_new (NULL, empty_location);
     p->next->next->next->next = grammar;
     nrules += 1;
