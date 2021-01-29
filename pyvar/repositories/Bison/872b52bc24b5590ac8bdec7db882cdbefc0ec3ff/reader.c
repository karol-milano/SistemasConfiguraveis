@@ -190,6 +190,23 @@ grammar_symbol_append (symbol *sym, location loc)
   return p;
 }
 
+static void
+assign_named_ref (symbol_list *p, named_ref *named_ref)
+{
+  symbol *sym = p->content.sym;
+
+  if (named_ref->id == sym->tag)
+    {
+      warn_at (named_ref->loc,
+	       _("duplicated symbol name for %s ignored"),
+	       quote (sym->tag));
+      named_ref_free (named_ref);
+    }
+  else
+    p->named_ref = named_ref;
+}
+
+
 /* The rule currently being defined, and the previous rule.
    CURRENT_RULE points to the first LHS of the current rule, while
    PREVIOUS_RULE_END points to the *end* of the previous rule (NULL).  */
@@ -213,17 +230,7 @@ grammar_current_rule_begin (symbol *lhs, location loc,
 
   p = grammar_symbol_append (lhs, loc);
   if (lhs_named_ref)
-    {
-      if (lhs_named_ref->id == lhs->tag)
-	{
-	  warn_at (lhs_named_ref->loc,
-		   _("duplicated symbol name for %s ignored"),
-		   quote (lhs->tag));
-	  named_ref_free (lhs_named_ref);
-	}
-      else
-	p->named_ref = lhs_named_ref;
-    }
+    assign_named_ref(p, lhs_named_ref);
 
   current_rule = grammar_end;
 
@@ -348,7 +355,7 @@ grammar_midrule_action (void)
   symbol *dummy = dummy_symbol_get (dummy_location);
   symbol_list *midrule = symbol_list_sym_new (dummy, dummy_location);
 
-  /* Remember named_ref of previous action */
+  /* Remember named_ref of previous action. */
   named_ref *named_ref = current_rule->action_props.named_ref;
 
   /* Make a new rule, whose body is empty, before the current one, so
@@ -432,19 +439,8 @@ grammar_current_rule_symbol_append (symbol *sym, location loc,
   if (current_rule->action_props.code)
     grammar_midrule_action ();
   p = grammar_symbol_append (sym, loc);
-
   if (named_ref)
-    {
-       if (named_ref->id == sym->tag)
-	{
-	  warn_at (named_ref->loc,
-		   _("duplicated symbol name for %s ignored"),
-		   quote (sym->tag));
-	  named_ref_free (named_ref);
-	}
-       else
-	 p->named_ref = named_ref;
-    }
+    assign_named_ref(p, named_ref);
 }
 
 /* Attach an ACTION to the current rule.  */
