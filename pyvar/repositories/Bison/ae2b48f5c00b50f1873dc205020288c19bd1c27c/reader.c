@@ -333,6 +333,12 @@ grammar_rule_check (const symbol_list *r)
       }
   }
 
+  /* Check that %empty => empty rule.  */
+  if (r->percent_empty_loc.start.file
+      && r->next && r->next->content.sym)
+    complain (&r->percent_empty_loc, complaint,
+              _("%%empty on non-empty rule"));
+
   /* See comments in grammar_current_rule_prec_set for how POSIX
      mandates this complaint.  It's only for identifiers, so skip
      it for char literals and strings, which are always tokens.  */
@@ -434,6 +440,17 @@ grammar_current_rule_prec_set (symbol *precsym, location loc)
   current_rule->ruleprec = precsym;
 }
 
+/* Set %empty for the current rule. */
+
+void
+grammar_current_rule_empty_set (location loc)
+{
+  if (current_rule->percent_empty_loc.start.file)
+    complain (&loc, complaint, _("only one %s allowed per rule"), "%empty");
+  else
+    current_rule->percent_empty_loc = loc;
+}
+
 /* Attach dynamic precedence DPREC to the current rule. */
 
 void
