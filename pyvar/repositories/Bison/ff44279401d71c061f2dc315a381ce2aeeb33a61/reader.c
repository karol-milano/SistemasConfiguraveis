@@ -1451,10 +1451,12 @@ readgram (void)
 	t = lex ();
       }
 
-  /* Insert the initial rule:
+  /* Insert the initial rule, which line is that of the first rule
+     (not that of the start symbol):
 
      axiom: %start EOF.  */
   p = symbol_list_new (axiom);
+  p->line = grammar->line;
   p->next = symbol_list_new (startval);
   p->next->next = symbol_list_new (eoftoken);
   p->next->next->next = symbol_list_new (NULL);
