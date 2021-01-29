@@ -247,17 +247,19 @@ grammar_rule_check (const symbol_list *r)
 
   /* Check that typed symbol values are used.  */
   {
-    symbol_list *l = r;
+    symbol_list const *l = r;
     int n = 0;
     for (; l && l->sym; l = l->next, ++n)
       if (! (l->used
 	     || !l->sym->type_name
 	     /* The default action, $$ = $1, `uses' both.  */
-	     || !r->action && (n == 0 || n == 1)))
-	if (n)
-	  warn_at (r->location, _("unused value: $%d"), n);
-	else
-	  warn_at (r->location, _("unset value: $$"));
+	     || (!r->action && (n == 0 || n == 1))))
+	{
+	  if (n)
+	    warn_at (r->location, _("unused value: $%d"), n);
+	  else
+	    warn_at (r->location, _("unset value: $$"));
+	}
   }
 }
 
