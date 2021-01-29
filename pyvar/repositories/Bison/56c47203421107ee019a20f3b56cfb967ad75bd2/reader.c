@@ -26,6 +26,7 @@
 #include "getargs.h"
 #include "files.h"
 #include "symtab.h"
+#include "symlist.h"
 #include "options.h"
 #include "gram.h"
 #include "complain.h"
@@ -35,68 +36,12 @@
 #include "muscle_tab.h"
 
 int lineno;
-static symbol_list *grammar = NULL;
+static symbol_list_t *grammar = NULL;
 static int start_flag = 0;
 
 /* Nonzero if %union has been seen.  */
 int typed = 0;
-
-symbol_list *
-symbol_list_new (symbol_t *sym, location_t location)
-{
-  symbol_list *res = XMALLOC (symbol_list, 1);
-  res->next = NULL;
-  res->sym = sym;
-  res->location = location;
-  res->action = NULL;
-  res->ruleprec = NULL;
-  return res;
-}
-
-symbol_list *
-symbol_list_prepend (symbol_list *list, symbol_t *symbol, location_t location)
-{
-  symbol_list *res = symbol_list_new (symbol, location);
-  res->next = list;
-  return res;
-}
-
 
-/*--------------------------------------------------------------.
-| Get the data type (alternative in the union) of the value for |
-| symbol N in rule RULE.                                        |
-`--------------------------------------------------------------*/
-
-char *
-get_type_name (int n, symbol_list *rule)
-{
-  int i;
-  symbol_list *rp;
-
-  if (n < 0)
-    {
-      complain (_("invalid $ value"));
-      return NULL;
-    }
-
-  rp = rule;
-  i = 0;
-
-  while (i < n)
-    {
-      rp = rp->next;
-      if (rp == NULL || rp->sym == NULL)
-	{
-	  complain (_("invalid $ value"));
-	  return NULL;
-	}
-      ++i;
-    }
-
-  return rp->sym->type_name;
-}
-
-
 /*-----------------------.
 | Set the start symbol.  |
 `-----------------------*/
@@ -183,7 +128,7 @@ gensym (location_t location)
 }
 
 /*-------------------------------------------------------------------.
-| Parse the input grammar into a one symbol_list structure.  Each    |
+| Parse the input grammar into a one symbol_list_t structure.  Each    |
 | rule is represented by a sequence of symbols: the left hand side   |
 | followed by the contents of the right hand side, followed by a     |
 | null pointer instead of a symbol to terminate the rule.  The next  |
@@ -201,13 +146,13 @@ gensym (location_t location)
 `-------------------------------------------------------------------*/
 
 /* The (currently) last symbol of GRAMMAR. */
-symbol_list *grammar_end = NULL;
+symbol_list_t *grammar_end = NULL;
 
 /* Append S to the GRAMMAR. */
 void
 grammar_symbol_append (symbol_t *symbol, location_t location)
 {
-  symbol_list *p = symbol_list_new (symbol, location);
+  symbol_list_t *p = symbol_list_new (symbol, location);
 
   if (grammar_end)
     grammar_end->next = p;
@@ -220,8 +165,8 @@ grammar_symbol_append (symbol_t *symbol, location_t location)
 /* The rule currently being defined, and the previous rule.
    CURRENT_RULE points to the first LHS of the current rule, while
    PREVIOUS_RULE_END points to the *end* of the previous rule (NULL).  */
-symbol_list *current_rule = NULL;
-symbol_list *previous_rule_end = NULL;
+symbol_list_t *current_rule = NULL;
+symbol_list_t *previous_rule_end = NULL;
 
 
 /*----------------------------------------------.
@@ -323,7 +268,7 @@ grammar_midrule_action (void)
      action.  Create the MIDRULE.  */
   location_t dummy_location = current_rule->action_location;
   symbol_t *dummy = gensym (dummy_location);
-  symbol_list *midrule = symbol_list_new (dummy, dummy_location);
+  symbol_list_t *midrule = symbol_list_new (dummy, dummy_location);
 
   /* Make a new rule, whose body is empty, before the current one, so
      that the action just read can belong to it.  */
@@ -397,7 +342,7 @@ packgram (void)
 {
   unsigned int itemno;
   int ruleno;
-  symbol_list *p;
+  symbol_list_t *p;
 
   ritem = XCALLOC (item_number_t, nritems);
   rules = XCALLOC (rule_t, nrules) - 1;
@@ -518,7 +463,7 @@ reader (void)
 
      axiom: %start EOF.  */
   {
-    symbol_list *p = symbol_list_new (axiom, empty_location);
+    symbol_list_t *p = symbol_list_new (axiom, empty_location);
     p->location = grammar->location;
     p->next = symbol_list_new (startsymbol, empty_location);
     p->next->next = symbol_list_new (eoftoken, empty_location);
@@ -544,6 +489,6 @@ reader (void)
   /* Convert the grammar into the format described in gram.h.  */
   packgram ();
 
-  /* The grammar as a symbol_list is no longer needed. */
-  LIST_FREE (symbol_list, grammar);
+  /* The grammar as a symbol_list_t is no longer needed. */
+  LIST_FREE (symbol_list_t, grammar);
 }
