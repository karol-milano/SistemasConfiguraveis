@@ -534,6 +534,7 @@ user_token_number_redeclaration (int num, symbol *first, symbol *second)
   complain_at_indent (second->location, &i,
                       _("user token number %d redeclaration for %s"),
                       num, second->tag);
+  i += SUB_INDENT;
   complain_at_indent (first->location, &i,
                       _("previous declaration for %s"),
                       first->tag);
