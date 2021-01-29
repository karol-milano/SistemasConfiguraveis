@@ -22,6 +22,7 @@
 
 #include <config.h>
 #include "system.h"
+#include <assert.h>
 
 #include <quotearg.h>
 
@@ -34,6 +35,8 @@
 #include "reader.h"
 #include "symlist.h"
 #include "symtab.h"
+#include "scan-gram.h"
+#include "scan-code.h"
 
 static void check_and_convert_grammar (void);
 
@@ -77,6 +80,8 @@ prologue_augment (const char *prologue, location loc)
     !typed ? &pre_prologue_obstack : &post_prologue_obstack;
 
   obstack_fgrow1 (oout, "]b4_syncline(%d, [[", loc.start.line);
+  /* FIXME: Protection of M4 characters missing here.  See
+     output.c:escaped_output.  */
   MUSCLE_OBSTACK_SGROW (oout,
 			quotearg_style (c_quoting_style, loc.start.file));
   obstack_sgrow (oout, "]])[\n");
@@ -398,9 +403,7 @@ grammar_current_rule_symbol_append (symbol *sym, location loc)
 void
 grammar_current_rule_action_append (const char *action, location loc)
 {
-  /* There's no need to invoke grammar_midrule_action here, since the
-     scanner already did it if necessary.  */
-  current_rule->action = action;
+  current_rule->action = translate_rule_action (current_rule, action, loc);
   current_rule->action_location = loc;
 }
 
@@ -426,6 +429,7 @@ packgram (void)
 
   while (p)
     {
+      int rule_length = 0;
       symbol *ruleprec = p->ruleprec;
       rules[ruleno].user_number = ruleno;
       rules[ruleno].number = ruleno;
@@ -440,18 +444,22 @@ packgram (void)
       rules[ruleno].action = p->action;
       rules[ruleno].action_location = p->action_location;
 
-      p = p->next;
-      while (p && p->sym)
+      for (p = p->next; p && p->sym; p = p->next)
 	{
+	  ++rule_length;
+
+	  /* Don't allow rule_length == INT_MAX, since that might
+	     cause confusion with strtol if INT_MAX == LONG_MAX.  */
+	  if (rule_length == INT_MAX)
+	      fatal_at (rules[ruleno].location, _("rule is too long"));
+
 	  /* item_number = symbol_number.
 	     But the former needs to contain more: negative rule numbers. */
 	  ritem[itemno++] = symbol_number_as_item_number (p->sym->number);
 	  /* A rule gets by default the precedence and associativity
-	     of the last token in it.  */
+	     of its last token.  */
 	  if (p->sym->class == token_sym && default_prec)
 	    rules[ruleno].prec = p->sym;
-	  if (p)
-	    p = p->next;
 	}
 
       /* If this rule has a %prec,
@@ -461,8 +469,11 @@ packgram (void)
 	  rules[ruleno].precsym = ruleprec;
 	  rules[ruleno].prec = ruleprec;
 	}
+      /* An item ends by the rule number (negated).  */
       ritem[itemno++] = rule_number_as_item_number (ruleno);
+      assert (itemno < ITEM_NUMBER_MAX);
       ++ruleno;
+      assert (ruleno < RULE_NUMBER_MAX);
 
       if (p)
 	p = p->next;
@@ -511,7 +522,7 @@ reader (void)
 
   gram__flex_debug = trace_flag & trace_scan;
   gram_debug = trace_flag & trace_parse;
-  scanner_initialize ();
+  gram_scanner_initialize ();
   gram_parse ();
 
   if (! complaint_issued)
