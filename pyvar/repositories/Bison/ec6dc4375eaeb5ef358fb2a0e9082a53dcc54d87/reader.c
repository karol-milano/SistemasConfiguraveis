@@ -712,7 +712,7 @@ check_and_convert_grammar (void)
   /* Insert the initial rule, whose line is that of the first rule
      (not that of the start symbol):
 
-     accept: %start EOF.  */
+     $accept: %start $end.  */
   {
     symbol_list *p = symbol_list_sym_new (accept, empty_location);
     p->location = grammar->location;
@@ -725,7 +725,8 @@ check_and_convert_grammar (void)
     grammar = p;
   }
 
-  aver (nsyms <= SYMBOL_NUMBER_MAXIMUM && nsyms == ntokens + nvars);
+  aver (nsyms <= SYMBOL_NUMBER_MAXIMUM);
+  aver (nsyms == ntokens + nvars);
 
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
