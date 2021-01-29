@@ -126,7 +126,7 @@ get_merge_function (const char* name, const char* type)
     type = "";
 
   head.next = merge_functions;
-  for (syms = &head, n = 1; syms->next != NULL; syms = syms->next, n += 1) 
+  for (syms = &head, n = 1; syms->next != NULL; syms = syms->next, n += 1)
     if (strcmp (name, syms->next->name) == 0)
       break;
   if (syms->next == NULL) {
@@ -136,7 +136,7 @@ get_merge_function (const char* name, const char* type)
     syms->next->next = NULL;
     merge_functions = head.next;
   } else if (strcmp (type, syms->next->type) != 0)
-    warn (_("result type clash on merge function %s: `%s' vs. `%s'"), 
+    warn (_("result type clash on merge function %s: `%s' vs. `%s'"),
 	  name, type, syms->next->type);
   return n;
 }
@@ -160,26 +160,6 @@ free_merger_functions (void)
     }
 }
 
-/*-------------------------------------------------------------------.
-| Generate a dummy symbol, a nonterminal, whose name cannot conflict |
-| with the user's names.                                             |
-`-------------------------------------------------------------------*/
-
-static symbol_t *
-gensym (location_t location)
-{
-  /* Incremented for each generated symbol */
-  static int gensym_count = 0;
-  static char buf[256];
-
-  symbol_t *sym;
-
-  sprintf (buf, "@%d", ++gensym_count);
-  sym = getsym (buf, location);
-  sym->class = nterm_sym;
-  sym->number = nvars++;
-  return sym;
-}
 
 /*-------------------------------------------------------------------.
 | Parse the input grammar into a one symbol_list_t structure.  Each    |
@@ -323,7 +303,7 @@ grammar_midrule_action (void)
   /* Make a DUMMY nonterminal, whose location is that of the midrule
      action.  Create the MIDRULE.  */
   location_t dummy_location = current_rule->action_location;
-  symbol_t *dummy = gensym (dummy_location);
+  symbol_t *dummy = dummy_symbol_get (dummy_location);
   symbol_list_t *midrule = symbol_list_new (dummy, dummy_location);
 
   /* Make a new rule, whose body is empty, before the current one, so
@@ -371,7 +351,7 @@ grammar_current_rule_dprec_set (int dprec, location_t location)
     warn_at (location, _("%%dprec affects only GLR parsers"));
   if (dprec <= 0)
     complain_at (location, _("%%dprec must be followed by positive number"));
-  else if (current_rule->dprec != 0) 
+  else if (current_rule->dprec != 0)
     complain_at (location, _("only one %%dprec allowed per rule"));
   current_rule->dprec = dprec;
 }
@@ -384,9 +364,9 @@ grammar_current_rule_merge_set (const char* name, location_t location)
 {
   if (! glr_parser)
     warn_at (location, _("%%merge affects only GLR parsers"));
-  if (current_rule->merger != 0) 
+  if (current_rule->merger != 0)
     complain_at (location, _("only one %%merge allowed per rule"));
-  current_rule->merger = 
+  current_rule->merger =
     get_merge_function (name, current_rule->sym->type_name);
 }
 
@@ -499,18 +479,18 @@ reader (void)
   symbols_new ();
 
   /* Construct the axiom symbol. */
-  axiom = getsym ("$axiom", empty_location);
+  axiom = symbol_get ("$axiom", empty_location);
   axiom->class = nterm_sym;
   axiom->number = nvars++;
 
   /* Construct the error token */
-  errtoken = getsym ("error", empty_location);
+  errtoken = symbol_get ("error", empty_location);
   errtoken->class = token_sym;
   errtoken->number = ntokens++;
 
   /* Construct a token that represents all undefined literal tokens.
      It is always token number 2.  */
-  undeftoken = getsym ("$undefined.", empty_location);
+  undeftoken = symbol_get ("$undefined.", empty_location);
   undeftoken->class = token_sym;
   undeftoken->number = ntokens++;
 
@@ -536,7 +516,7 @@ reader (void)
   /* If the user did not define her EOFTOKEN, do it now. */
   if (!eoftoken)
     {
-      eoftoken = getsym ("$", empty_location);
+      eoftoken = symbol_get ("$", empty_location);
       eoftoken->class = token_sym;
       eoftoken->number = 0;
       /* Value specified by POSIX.  */
