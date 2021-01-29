@@ -2793,7 +2793,7 @@ handle_action_dollar (char *text, location_t location)
 	type_name = symbol_list_n_type_name_get (current_rule, location, 0);
       if (!type_name && typed)
 	complain_at (location, _("$$ of `%s' has no declared type"),
-		     symbol_tag_get (current_rule->sym));
+		     current_rule->sym->tag);
       if (!type_name)
 	type_name = "";
       obstack_fgrow1 (&string_obstack,
@@ -2817,7 +2817,7 @@ handle_action_dollar (char *text, location_t location)
 						     n);
 	  if (!type_name && typed)
 	    complain_at (location, _("$%d of `%s' has no declared type"),
-		      n, symbol_tag_get (current_rule->sym));
+		      n, current_rule->sym->tag);
 	  if (!type_name)
 	    type_name = "";
 	  obstack_fgrow3 (&string_obstack,
