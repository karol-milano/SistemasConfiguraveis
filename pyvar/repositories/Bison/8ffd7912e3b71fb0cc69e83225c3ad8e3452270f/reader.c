@@ -250,22 +250,25 @@ grammar_current_rule_begin (symbol *lhs, location loc,
 /*----------------------------------------------------------------------.
 | A symbol should be used if either:                                    |
 |   1. It has a destructor.                                             |
-|   2. --warnings=midrule-values and the symbol is a mid-rule symbol    |
-|      (i.e., the generated LHS replacing a mid-rule action) that was   |
-|      assigned to or used, as in "exp: { $$ = 1; } { $$ = $1; }".      |
+|   2. The symbol is a mid-rule symbol (i.e., the generated LHS         |
+|      replacing a mid-rule action) that was assigned to or used, as in |
+|      "exp: { $$ = 1; } { $$ = $1; }".                                 |
 `----------------------------------------------------------------------*/
 
 static bool
-symbol_should_be_used (symbol_list const *s)
+symbol_should_be_used (symbol_list const *s, bool *midrule_warning)
 {
   if (symbol_destructor_get (s->content.sym)->code)
     return true;
-  if (warnings_flag & warnings_midrule_values)
-    return ((s->midrule && s->midrule->action_props.is_value_used)
-	    || (s->midrule_parent_rule
-		&& symbol_list_n_get (s->midrule_parent_rule,
-				      s->midrule_parent_rhs_index)
-                     ->action_props.is_value_used));
+  if ((s->midrule && s->midrule->action_props.is_value_used)
+      || (s->midrule_parent_rule
+          && symbol_list_n_get (s->midrule_parent_rule,
+                                s->midrule_parent_rhs_index)
+               ->action_props.is_value_used))
+    {
+      *midrule_warning = true;
+      return true;
+    }
   return false;
 }
 
@@ -309,16 +312,21 @@ grammar_rule_check (const symbol_list *r)
     symbol_list const *l = r;
     int n = 0;
     for (; l && l->content.sym; l = l->next, ++n)
-      if (! (l->action_props.is_value_used
-	     || !symbol_should_be_used (l)
-	     /* The default action, $$ = $1, `uses' both.  */
-	     || (!r->action_props.code && (n == 0 || n == 1))))
-	{
-	  if (n)
-	    warn_at (r->location, _("unused value: $%d"), n);
-	  else
-	    warn_at (r->location, _("unset value: $$"));
-	}
+      {
+        bool midrule_warning = false;
+        if (!l->action_props.is_value_used
+            && symbol_should_be_used (l, &midrule_warning)
+            /* The default action, $$ = $1, `uses' both.  */
+            && (r->action_props.code || (n != 0 && n != 1)))
+          {
+            void (*warn_at_ptr)(location, char const*, ...) =
+              midrule_warning ? midrule_value_at : warn_at;
+            if (n)
+              warn_at_ptr (r->location, _("unused value: $%d"), n);
+            else
+              warn_at_ptr (r->location, _("unset value: $$"));
+          }
+      }
   }
 
   /* See comments in grammar_current_rule_prec_set for how POSIX
