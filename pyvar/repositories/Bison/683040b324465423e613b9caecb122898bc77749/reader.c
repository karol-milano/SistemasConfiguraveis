@@ -322,7 +322,8 @@ grammar_rule_check_and_complete (symbol_list *r)
       const symbol *start = r->next->next->content.sym;
       if (start->content->type_name)
         obstack_printf (obstack_for_actions,
-                        "{ ]b4_accept([orig %d])[; }",
+                        "{ ]b4_accept([%s%d])[; }",
+                        start->content->class == nterm_sym ? "orig " : "",
                         start->content->number);
       else
         obstack_printf (obstack_for_actions,
@@ -827,9 +828,7 @@ switching_token (const symbol *start)
 {
   char buf[100];
   size_t len = sizeof buf;
-  char *name
-    = asnprintf (buf, &len,
-                 "YY_PARSE_%s", start->alias ? start->alias->tag : start->tag);
+  char *name = asnprintf (buf, &len, "YY_PARSE_%s", symbol_id_get (start));
   if (!name)
     xalloc_die ();
   // Setting the location ensures deterministic symbol numbers.
@@ -881,6 +880,7 @@ create_start_rules (void)
 static void
 check_start_symbols (void)
 {
+  const bool multistart = start_symbols && start_symbols->next;
   // Sanity checks on the start symbols.
   for (symbol_list *list = start_symbols; list; list = list->next)
     {
@@ -895,7 +895,8 @@ check_start_symbols (void)
           // defined as a token and has no rules".
           abort ();
         }
-      if (start->content->class == token_sym)
+      // If your only start symbol is a token, you're weird.
+      if (!multistart && start->content->class == token_sym)
         complain (&start->location, complaint,
                   _("the start symbol %s is a token"),
                   start->tag);
