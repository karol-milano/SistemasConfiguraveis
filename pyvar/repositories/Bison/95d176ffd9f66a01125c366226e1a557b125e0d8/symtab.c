@@ -158,6 +158,7 @@ semantic_type_redeclaration (semantic_type *s, const char *what, location first,
 }
 
 
+
 /*-----------------------------------------------------------------.
 | Set the TYPE_NAME associated with SYM.  Does nothing if passed 0 |
 | as TYPE_NAME.                                                    |
@@ -547,7 +548,26 @@ symbol_pack_processor (void *this, void *null ATTRIBUTE_UNUSED)
 }
 
 
+static void
+user_token_number_redeclaration (int num, symbol *first, symbol *second)
+{
+  /* User token numbers are not assigned during the parsing, but in a
+     second step, via a (nondeterministic) traversal of the symbol
+     hash table.
 
+     Make errors deterministic: keep the first declaration first.  */
+  if (location_cmp (first->location, second->location) > 0)
+    {
+      symbol* tmp = first;
+      first = second;
+      second = tmp;
+    }
+  complain_at (second->location,
+               _("user token number %d redeclaration for %s"),
+               num, second->tag);
+  complain_at (first->location, _("previous declaration for %s"),
+               first->tag);
+}
 
 /*--------------------------------------------------.
 | Put THIS in TOKEN_TRANSLATIONS if it is a token.  |
@@ -562,10 +582,10 @@ symbol_translation (symbol *this)
     {
       /* A token which translation has already been set? */
       if (token_translations[this->user_token_number] != undeftoken->number)
-	complain_at (this->location,
-		     _("tokens %s and %s both assigned number %d"),
-		     symbols[token_translations[this->user_token_number]]->tag,
-		     this->tag, this->user_token_number);
+	user_token_number_redeclaration
+          (this->user_token_number,
+           symbols[token_translations[this->user_token_number]],
+           this);
 
       token_translations[this->user_token_number] = this->number;
     }
