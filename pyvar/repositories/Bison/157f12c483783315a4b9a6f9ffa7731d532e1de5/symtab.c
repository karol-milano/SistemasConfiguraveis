@@ -463,21 +463,26 @@ void
 symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
 {
   int *user_token_numberp = &sym->content->user_token_number;
-  if (*user_token_numberp != USER_NUMBER_UNDEFINED
-      && *user_token_numberp != user_token_number)
+  if (sym->content->class != token_sym)
+    complain (&loc, complaint,
+              _("non-terminals cannot be given an explicit number"));
+  else if (*user_token_numberp != USER_NUMBER_UNDEFINED
+           && *user_token_numberp != user_token_number)
     complain (&loc, complaint, _("redefining user token number of %s"),
               sym->tag);
-
-  *user_token_numberp = user_token_number;
-  /* User defined $end token? */
-  if (user_token_number == 0)
+  else
     {
-      endtoken = sym->content->symbol;
-      /* It is always mapped to 0, so it was already counted in
-         NTOKENS.  */
-      if (endtoken->content->number != NUMBER_UNDEFINED)
-        --ntokens;
-      endtoken->content->number = 0;
+      *user_token_numberp = user_token_number;
+      /* User defined $end token? */
+      if (user_token_number == 0)
+        {
+          endtoken = sym->content->symbol;
+          /* It is always mapped to 0, so it was already counted in
+             NTOKENS.  */
+          if (endtoken->content->number != NUMBER_UNDEFINED)
+            --ntokens;
+          endtoken->content->number = 0;
+        }
     }
 }
 
@@ -594,7 +599,10 @@ symbol_merge_properties (symbol *sym, symbol *str)
 void
 symbol_make_alias (symbol *sym, symbol *str, location loc)
 {
-  if (str->alias)
+  if (sym->content->class != token_sym)
+    complain (&loc, complaint,
+              _("non-terminals cannot be given a string alias"));
+  else if (str->alias)
     complain (&loc, Wother,
               _("symbol %s used more than once as a literal string"), str->tag);
   else if (sym->alias)
