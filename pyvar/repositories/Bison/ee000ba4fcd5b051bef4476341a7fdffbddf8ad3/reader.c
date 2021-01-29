@@ -159,7 +159,7 @@ epilogue_set (const char *epilogue, location_t location)
 `-------------------------------------------------------------------*/
 
 static symbol_t *
-gensym (void)
+gensym (location_t location)
 {
   /* Incremented for each generated symbol */
   static int gensym_count = 0;
@@ -168,7 +168,7 @@ gensym (void)
   symbol_t *sym;
 
   sprintf (buf, "@%d", ++gensym_count);
-  sym = getsym (buf);
+  sym = getsym (buf, location);
   sym->class = nterm_sym;
   sym->number = nvars++;
   return sym;
@@ -313,8 +313,8 @@ grammar_midrule_action (void)
 
   /* Make a DUMMY nonterminal, whose location is that of the midrule
      action.  Create the MIDRULE.  */
-  symbol_t *dummy = gensym ();
   location_t dummy_location = current_rule->action_location;
+  symbol_t *dummy = gensym (dummy_location);
   symbol_list *midrule = symbol_list_new (dummy, dummy_location);
 
   /* Make a new rule, whose body is empty, before the current one, so
@@ -461,18 +461,18 @@ reader (void)
   symbols_new ();
 
   /* Construct the axiom symbol. */
-  axiom = getsym ("$axiom");
+  axiom = getsym ("$axiom", empty_location);
   axiom->class = nterm_sym;
   axiom->number = nvars++;
 
   /* Construct the error token */
-  errtoken = getsym ("error");
+  errtoken = getsym ("error", empty_location);
   errtoken->class = token_sym;
   errtoken->number = ntokens++;
 
   /* Construct a token that represents all undefined literal tokens.
      It is always token number 2.  */
-  undeftoken = getsym ("$undefined.");
+  undeftoken = getsym ("$undefined.", empty_location);
   undeftoken->class = token_sym;
   undeftoken->number = ntokens++;
 
@@ -498,7 +498,7 @@ reader (void)
   /* If the user did not define her EOFTOKEN, do it now. */
   if (!eoftoken)
     {
-      eoftoken = getsym ("$");
+      eoftoken = getsym ("$", empty_location);
       eoftoken->class = token_sym;
       eoftoken->number = 0;
       /* Value specified by POSIX.  */
