@@ -19,21 +19,22 @@
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.  */
 
-
 #include "system.h"
-#include "quotearg.h"
-#include "getargs.h"
+
+#include <quotearg.h>
+
+#include "complain.h"
+#include "conflicts.h"
 #include "files.h"
-#include "symtab.h"
-#include "symlist.h"
+#include "getargs.h"
 #include "gram.h"
-#include "complain.h"
+#include "muscle_tab.h"
 #include "output.h"
 #include "reader.h"
-#include "conflicts.h"
-#include "muscle_tab.h"
+#include "symlist.h"
+#include "symtab.h"
 
-static symbol_list_t *grammar = NULL;
+static symbol_list *grammar = NULL;
 static int start_flag = 0;
 merger_list *merge_functions;
 
@@ -45,15 +46,15 @@ int typed = 0;
 `-----------------------*/
 
 void
-grammar_start_symbol_set (symbol_t *s, location_t l)
+grammar_start_symbol_set (symbol *s, location loc)
 {
   if (start_flag)
-    complain_at (l, _("multiple %s declarations"), "%start");
+    complain_at (loc, _("multiple %s declarations"), "%start");
   else
     {
       start_flag = 1;
       startsymbol = s;
-      startsymbol_location = l;
+      startsymbol_location = loc;
     }
 }
 
@@ -64,15 +65,14 @@ grammar_start_symbol_set (symbol_t *s, location_t l)
 `----------------------------------------------------------------*/
 
 void
-prologue_augment (const char *prologue, location_t location)
+prologue_augment (const char *prologue, location loc)
 {
   struct obstack *oout =
     !typed ? &pre_prologue_obstack : &post_prologue_obstack;
 
-  obstack_fgrow1 (oout, "]b4_syncline([[%d]], [[",
-		  location.start.line);
-  MUSCLE_OBSTACK_SGROW (oout, quotearg_style (c_quoting_style,
-					      location.start.file));
+  obstack_fgrow1 (oout, "]b4_syncline([[%d]], [[", loc.start.line);
+  MUSCLE_OBSTACK_SGROW (oout,
+			quotearg_style (c_quoting_style, loc.start.file));
   obstack_sgrow (oout, "]])[\n");
   obstack_sgrow (oout, prologue);
 }
@@ -85,13 +85,12 @@ prologue_augment (const char *prologue, location_t location)
 `----------------------*/
 
 void
-epilogue_augment (const char *epilogue, location_t location)
+epilogue_augment (const char *epilogue, location loc)
 {
   char *extension = NULL;
-  obstack_fgrow1 (&muscle_obstack, "]b4_syncline([[%d]], [[",
-		  location.start.line);
+  obstack_fgrow1 (&muscle_obstack, "]b4_syncline([[%d]], [[", loc.start.line);
   MUSCLE_OBSTACK_SGROW (&muscle_obstack,
-			quotearg_style (c_quoting_style, location.start.file));
+			quotearg_style (c_quoting_style, loc.start.file));
   obstack_sgrow (&muscle_obstack, "]])[\n");
   obstack_sgrow (&muscle_obstack, epilogue);
   obstack_1grow (&muscle_obstack, 0);
@@ -110,7 +109,7 @@ epilogue_augment (const char *epilogue, location_t location)
 `-------------------------------------------------------------------*/
 
 static int
-get_merge_function (struniq_t name, struniq_t type, location_t loc)
+get_merge_function (uniqstr name, uniqstr type, location loc)
 {
   merger_list *syms;
   merger_list head;
@@ -120,21 +119,21 @@ get_merge_function (struniq_t name, struniq_t type, location_t loc)
     return 0;
 
   if (type == NULL)
-    type = struniq_new ("");
+    type = uniqstr_new ("");
 
   head.next = merge_functions;
   for (syms = &head, n = 1; syms->next != NULL; syms = syms->next, n += 1)
-    if (STRUNIQ_EQ (name, syms->next->name))
+    if (UNIQSTR_EQ (name, syms->next->name))
       break;
   if (syms->next == NULL)
     {
       syms->next = XMALLOC (merger_list, 1);
-      syms->next->name = struniq_new (name);
-      syms->next->type = struniq_new (type);
+      syms->next->name = uniqstr_new (name);
+      syms->next->type = uniqstr_new (type);
       syms->next->next = NULL;
       merge_functions = head.next;
     }
-  else if (!STRUNIQ_EQ (type, syms->next->type))
+  else if (!UNIQSTR_EQ (type, syms->next->type))
     warn_at (loc, _("result type clash on merge function %s: <%s> != <%s>"),
 	     name, type, syms->next->type);
   return n;
@@ -161,7 +160,7 @@ free_merger_functions (void)
 
 
 /*-------------------------------------------------------------------.
-| Parse the input grammar into a one symbol_list_t structure.  Each  |
+| Parse the input grammar into a one symbol_list structure.  Each    |
 | rule is represented by a sequence of symbols: the left hand side   |
 | followed by the contents of the right hand side, followed by a     |
 | null pointer instead of a symbol to terminate the rule.  The next  |
@@ -179,13 +178,13 @@ free_merger_functions (void)
 `-------------------------------------------------------------------*/
 
 /* The (currently) last symbol of GRAMMAR. */
-symbol_list_t *grammar_end = NULL;
+symbol_list *grammar_end = NULL;
 
 /* Append S to the GRAMMAR. */
 void
-grammar_symbol_append (symbol_t *symbol, location_t location)
+grammar_symbol_append (symbol *sym, location loc)
 {
-  symbol_list_t *p = symbol_list_new (symbol, location);
+  symbol_list *p = symbol_list_new (sym, loc);
 
   if (grammar_end)
     grammar_end->next = p;
@@ -198,8 +197,8 @@ grammar_symbol_append (symbol_t *symbol, location_t location)
 /* The rule currently being defined, and the previous rule.
    CURRENT_RULE points to the first LHS of the current rule, while
    PREVIOUS_RULE_END points to the *end* of the previous rule (NULL).  */
-symbol_list_t *current_rule = NULL;
-symbol_list_t *previous_rule_end = NULL;
+symbol_list *current_rule = NULL;
+symbol_list *previous_rule_end = NULL;
 
 
 /*----------------------------------------------.
@@ -207,12 +206,12 @@ symbol_list_t *previous_rule_end = NULL;
 `----------------------------------------------*/
 
 void
-grammar_rule_begin (symbol_t *lhs, location_t location)
+grammar_rule_begin (symbol *lhs, location loc)
 {
   if (!start_flag)
     {
       startsymbol = lhs;
-      startsymbol_location = location;
+      startsymbol_location = loc;
       start_flag = 1;
     }
 
@@ -221,7 +220,7 @@ grammar_rule_begin (symbol_t *lhs, location_t location)
   ++nritems;
 
   previous_rule_end = grammar_end;
-  grammar_symbol_append (lhs, location);
+  grammar_symbol_append (lhs, loc);
   current_rule = grammar_end;
 
   /* Mark the rule's lhs as a nonterminal if not already so.  */
@@ -233,7 +232,7 @@ grammar_rule_begin (symbol_t *lhs, location_t location)
       ++nvars;
     }
   else if (lhs->class == token_sym)
-    complain_at (location, _("rule given for %s, which is a token"), lhs->tag);
+    complain_at (loc, _("rule given for %s, which is a token"), lhs->tag);
 }
 
 /* Check that the last rule (CURRENT_RULE) is properly defined.  For
@@ -242,9 +241,9 @@ grammar_rule_begin (symbol_t *lhs, location_t location)
 static void
 grammar_current_rule_check (void)
 {
-  symbol_t *lhs = current_rule->sym;
+  symbol *lhs = current_rule->sym;
   char const *lhs_type = lhs->type_name;
-  symbol_t *first_rhs = current_rule->next->sym;
+  symbol *first_rhs = current_rule->next->sym;
 
   /* If there is an action, then there is nothing we can do: the user
      is allowed to shoot herself in the foot.  */
@@ -260,7 +259,7 @@ grammar_current_rule_check (void)
   if (first_rhs)
     {
       const char *rhs_type = first_rhs->type_name ? first_rhs->type_name : "";
-      if (!STRUNIQ_EQ (lhs_type, rhs_type))
+      if (!UNIQSTR_EQ (lhs_type, rhs_type))
 	warn_at (current_rule->location,
 		 _("type clash on default action: <%s> != <%s>"),
 		 lhs_type, rhs_type);
@@ -277,11 +276,11 @@ grammar_current_rule_check (void)
 `-------------------------------------*/
 
 void
-grammar_rule_end (location_t location)
+grammar_rule_end (location loc)
 {
   /* Put an empty link in the list to mark the end of this rule  */
   grammar_symbol_append (NULL, grammar_end->location);
-  current_rule->location = location;
+  current_rule->location = loc;
   grammar_current_rule_check ();
 }
 
@@ -302,9 +301,9 @@ grammar_midrule_action (void)
 
   /* Make a DUMMY nonterminal, whose location is that of the midrule
      action.  Create the MIDRULE.  */
-  location_t dummy_location = current_rule->action_location;
-  symbol_t *dummy = dummy_symbol_get (dummy_location);
-  symbol_list_t *midrule = symbol_list_new (dummy, dummy_location);
+  location dummy_location = current_rule->action_location;
+  symbol *dummy = dummy_symbol_get (dummy_location);
+  symbol_list *midrule = symbol_list_new (dummy, dummy_location);
 
   /* Make a new rule, whose body is empty, before the current one, so
      that the action just read can belong to it.  */
@@ -335,25 +334,24 @@ grammar_midrule_action (void)
 /* Set the precedence symbol of the current rule to PRECSYM. */
 
 void
-grammar_current_rule_prec_set (symbol_t *precsym, location_t location)
+grammar_current_rule_prec_set (symbol *precsym, location loc)
 {
   if (current_rule->ruleprec)
-    complain_at (location, _("only one %s allowed per rule"), "%prec");
+    complain_at (loc, _("only one %s allowed per rule"), "%prec");
   current_rule->ruleprec = precsym;
 }
 
 /* Attach dynamic precedence DPREC to the current rule. */
 
 void
-grammar_current_rule_dprec_set (int dprec, location_t location)
+grammar_current_rule_dprec_set (int dprec, location loc)
 {
   if (! glr_parser)
-    warn_at (location, _("%s affects only GLR parsers"), "%dprec");
+    warn_at (loc, _("%s affects only GLR parsers"), "%dprec");
   if (dprec <= 0)
-    complain_at (location,
-		 _("%s must be followed by positive number"), "%dprec");
+    complain_at (loc, _("%s must be followed by positive number"), "%dprec");
   else if (current_rule->dprec != 0)
-    complain_at (location, _("only one %s allowed per rule"), "%dprec");
+    complain_at (loc, _("only one %s allowed per rule"), "%dprec");
   current_rule->dprec = dprec;
 }
 
@@ -361,38 +359,38 @@ grammar_current_rule_dprec_set (int dprec, location_t location)
    rule. */
 
 void
-grammar_current_rule_merge_set (struniq_t name, location_t location)
+grammar_current_rule_merge_set (uniqstr name, location loc)
 {
   if (! glr_parser)
-    warn_at (location, _("%s affects only GLR parsers"), "%merge");
+    warn_at (loc, _("%s affects only GLR parsers"), "%merge");
   if (current_rule->merger != 0)
-    complain_at (location, _("only one %s allowed per rule"), "%merge");
+    complain_at (loc, _("only one %s allowed per rule"), "%merge");
   current_rule->merger =
-    get_merge_function (name, current_rule->sym->type_name, location);
+    get_merge_function (name, current_rule->sym->type_name, loc);
 }
 
-/* Attach a SYMBOL to the current rule.  If needed, move the previous
+/* Attach SYM to the current rule.  If needed, move the previous
    action as a mid-rule action.  */
 
 void
-grammar_current_rule_symbol_append (symbol_t *symbol, location_t location)
+grammar_current_rule_symbol_append (symbol *sym, location loc)
 {
   if (current_rule->action)
     grammar_midrule_action ();
   ++nritems;
-  grammar_symbol_append (symbol, location);
+  grammar_symbol_append (sym, loc);
 }
 
 /* Attach an ACTION to the current rule.  If needed, move the previous
    action as a mid-rule action.  */
 
 void
-grammar_current_rule_action_append (const char *action, location_t location)
+grammar_current_rule_action_append (const char *action, location loc)
 {
   if (current_rule->action)
     grammar_midrule_action ();
   current_rule->action = action;
-  current_rule->action_location = location;
+  current_rule->action_location = loc;
 }
 
 
@@ -405,15 +403,15 @@ static void
 packgram (void)
 {
   unsigned int itemno = 0;
-  rule_number_t ruleno = 0;
-  symbol_list_t *p = grammar;
+  rule_number ruleno = 0;
+  symbol_list *p = grammar;
 
-  ritem = XCALLOC (item_number_t, nritems);
-  rules = XCALLOC (rule_t, nrules);
+  ritem = XCALLOC (item_number, nritems);
+  rules = XCALLOC (rule, nrules);
 
   while (p)
     {
-      symbol_t *ruleprec = p->ruleprec;
+      symbol *ruleprec = p->ruleprec;
       rules[ruleno].user_number = ruleno;
       rules[ruleno].number = ruleno;
       rules[ruleno].lhs = p->sym;
@@ -428,7 +426,7 @@ packgram (void)
       p = p->next;
       while (p && p->sym)
 	{
-	  /* item_number_t = symbol_number_t.
+	  /* item_number = symbol_number.
 	     But the former needs to contain more: negative rule numbers. */
 	  ritem[itemno++] = symbol_number_as_item_number (p->sym->number);
 	  /* A rule gets by default the precedence and associativity
@@ -528,7 +526,7 @@ reader (void)
 
      accept: %start EOF.  */
   {
-    symbol_list_t *p = symbol_list_new (accept, empty_location);
+    symbol_list *p = symbol_list_new (accept, empty_location);
     p->location = grammar->location;
     p->next = symbol_list_new (startsymbol, empty_location);
     p->next->next = symbol_list_new (endtoken, empty_location);
@@ -539,7 +537,7 @@ reader (void)
     grammar = p;
   }
 
-  if (! (nsyms <= SYMBOL_NUMBER_MAX && nsyms == ntokens + nvars))
+  if (! (nsyms <= SYMBOL_NUMBER_MAXIMUM && nsyms == ntokens + nvars))
     abort ();
 
   xfclose (finput);
@@ -551,6 +549,6 @@ reader (void)
   /* Convert the grammar into the format described in gram.h.  */
   packgram ();
 
-  /* The grammar as a symbol_list_t is no longer needed. */
-  LIST_FREE (symbol_list_t, grammar);
+  /* The grammar as a symbol_list is no longer needed. */
+  LIST_FREE (symbol_list, grammar);
 }
