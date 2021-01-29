@@ -634,7 +634,7 @@ packgram (void)
       if (lhs != grammar)
         grammar_rule_check_and_complete (lhs);
 
-      rules[ruleno].user_number = ruleno;
+      rules[ruleno].code = ruleno;
       rules[ruleno].number = ruleno;
       rules[ruleno].lhs = lhs->content.sym->content;
       rules[ruleno].rhs = ritem + itemno;
@@ -782,7 +782,7 @@ check_and_convert_grammar (void)
       endtoken->content->class = token_sym;
       endtoken->content->number = 0;
       /* Value specified by POSIX.  */
-      endtoken->content->user_token_number = 0;
+      endtoken->content->code = 0;
       {
         symbol *alias = symbol_get ("$end", empty_loc);
         symbol_class_set (alias, token_sym, empty_loc, false);
