@@ -182,11 +182,11 @@ symbol_free (void *ptr)
 */
 
 static void
-symbols_sort (symbol **first, symbol **second)
+symbols_sort (const symbol **first, const symbol **second)
 {
   if (0 < location_cmp ((*first)->location, (*second)->location))
     {
-      symbol* tmp = *first;
+      const symbol* tmp = *first;
       *first = *second;
       *second = tmp;
     }
@@ -371,7 +371,7 @@ symbol_from_uniqstr_fuzzy (const uniqstr key)
 }
 
 static void
-complain_symbol_undeclared (symbol *sym)
+complain_symbol_undeclared (const symbol *sym)
 {
   assert (sym->content->status != declared);
   const symbol *best = symbol_from_uniqstr_fuzzy (sym->tag);
@@ -742,7 +742,7 @@ symbol_pack (symbol *sym)
 }
 
 static void
-complain_code_redeclared (int num, symbol *first, symbol *second)
+complain_code_redeclared (int num, const symbol *first, const symbol *second)
 {
   symbols_sort (&first, &second);
   complain (&second->location, complaint,
@@ -758,13 +758,11 @@ complain_code_redeclared (int num, symbol *first, symbol *second)
 `-------------------------------------------------*/
 
 static void
-symbol_translation (symbol *sym)
+symbol_translation (const symbol *sym)
 {
-  /* Nonterminal? */
-  if (sym->content->class == token_sym
-      && !sym->is_alias)
+  if (sym->content->class == token_sym && !sym->is_alias)
     {
-      /* A token which translation has already been set?*/
+      /* A token whose translation has already been set? */
       if (token_translations[sym->content->code]
           != undeftoken->content->number)
         complain_code_redeclared
