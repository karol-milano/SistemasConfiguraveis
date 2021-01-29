@@ -21,6 +21,7 @@
 #include <config.h>
 #include "system.h"
 
+#include <quote.h>
 #include <quotearg.h>
 
 #include "complain.h"
@@ -169,7 +170,7 @@ free_merger_functions (void)
 static symbol_list *grammar_end = NULL;
 
 /* Append SYM to the grammar.  */
-static void
+static symbol_list *
 grammar_symbol_append (symbol *sym, location loc)
 {
   symbol_list *p = symbol_list_sym_new (sym, loc);
@@ -185,6 +186,8 @@ grammar_symbol_append (symbol *sym, location loc)
      part of it.  */
   if (sym)
     ++nritems;
+
+  return p;
 }
 
 /* The rule currently being defined, and the previous rule.
@@ -199,12 +202,29 @@ static symbol_list *previous_rule_end = NULL;
 `----------------------------------------------*/
 
 void
-grammar_current_rule_begin (symbol *lhs, location loc)
+grammar_current_rule_begin (symbol *lhs, location loc,
+			    named_ref *lhs_named_ref)
 {
+  symbol_list* p;
+
   /* Start a new rule and record its lhs.  */
   ++nrules;
   previous_rule_end = grammar_end;
-  grammar_symbol_append (lhs, loc);
+
+  p = grammar_symbol_append (lhs, loc);
+  if (lhs_named_ref)
+    {
+      if (lhs_named_ref->id == lhs->tag)
+	{
+	  warn_at (lhs_named_ref->loc,
+		   _("duplicated symbol name for %s ignored"),
+		   quote (lhs->tag));
+	  named_ref_free (lhs_named_ref);
+	}
+      else
+	p->named_ref = lhs_named_ref;
+    }
+
   current_rule = grammar_end;
 
   /* Mark the rule's lhs as a nonterminal if not already so.  */
@@ -328,6 +348,9 @@ grammar_midrule_action (void)
   symbol *dummy = dummy_symbol_get (dummy_location);
   symbol_list *midrule = symbol_list_sym_new (dummy, dummy_location);
 
+  /* Remember named_ref of previous action */
+  named_ref *named_ref = current_rule->action_props.named_ref;
+
   /* Make a new rule, whose body is empty, before the current one, so
      that the action just read can belong to it.  */
   ++nrules;
@@ -337,7 +360,7 @@ grammar_midrule_action (void)
   code_props_rule_action_init (&midrule->action_props,
                                current_rule->action_props.code,
                                current_rule->action_props.location,
-                               midrule);
+                               midrule, 0);
   code_props_none_init (&current_rule->action_props);
 
   if (previous_rule_end)
@@ -353,7 +376,7 @@ grammar_midrule_action (void)
 
   /* Insert the dummy nonterminal replacing the midrule action into
      the current rule.  Bind it to its dedicated rule.  */
-  grammar_current_rule_symbol_append (dummy, dummy_location);
+  grammar_current_rule_symbol_append (dummy, dummy_location, named_ref);
   grammar_end->midrule = midrule;
   midrule->midrule_parent_rule = current_rule;
   midrule->midrule_parent_rhs_index = symbol_list_length (current_rule->next);
@@ -402,24 +425,40 @@ grammar_current_rule_merge_set (uniqstr name, location loc)
    action as a mid-rule action.  */
 
 void
-grammar_current_rule_symbol_append (symbol *sym, location loc)
+grammar_current_rule_symbol_append (symbol *sym, location loc,
+				    named_ref *named_ref)
 {
+  symbol_list *p;
   if (current_rule->action_props.code)
     grammar_midrule_action ();
-  grammar_symbol_append (sym, loc);
+  p = grammar_symbol_append (sym, loc);
+
+  if (named_ref)
+    {
+       if (named_ref->id == sym->tag)
+	{
+	  warn_at (named_ref->loc,
+		   _("duplicated symbol name for %s ignored"),
+		   quote (sym->tag));
+	  named_ref_free (named_ref);
+	}
+       else
+	 p->named_ref = named_ref;
+    }
 }
 
 /* Attach an ACTION to the current rule.  */
 
 void
-grammar_current_rule_action_append (const char *action, location loc)
+grammar_current_rule_action_append (const char *action, location loc,
+				    named_ref *named_ref)
 {
   if (current_rule->action_props.code)
     grammar_midrule_action ();
   /* After all symbol declarations have been parsed, packgram invokes
      code_props_translate_code.  */
   code_props_rule_action_init (&current_rule->action_props, action, loc,
-                               current_rule);
+                               current_rule, named_ref);
 }
 
 
