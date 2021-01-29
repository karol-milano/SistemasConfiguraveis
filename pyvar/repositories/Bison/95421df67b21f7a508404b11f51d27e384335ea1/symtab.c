@@ -65,6 +65,17 @@ static bool *used_assoc = NULL;
 bool tag_seen = false;
 
 
+/* Whether SYM was defined by the user.  */
+
+static bool
+symbol_is_user_defined (symbol *sym)
+{
+  return sym->tag[0] != '$'
+    && sym != errtoken && sym->alias != errtoken
+    && sym != undeftoken  && sym->alias != undeftoken;
+}
+
+
 /*--------------------------.
 | Create a new sym_content. |
 `--------------------------*/
@@ -279,6 +290,7 @@ is_identifier (uniqstr s)
 /*-----------------------------------------------.
 | Get the identifier associated to this symbol.  |
 `-----------------------------------------------*/
+
 uniqstr
 symbol_id_get (symbol const *sym)
 {
@@ -419,6 +431,7 @@ symbol_code_props_set (symbol *sym, code_props_type kind,
     sym->content->props[kind] = *code;
 }
 
+
 /*-----------------------------------------------------.
 | Set the DESTRUCTOR or PRINTER associated with TYPE.  |
 `-----------------------------------------------------*/
@@ -457,7 +470,7 @@ symbol_code_props_get (symbol *sym, code_props_type kind)
     }
 
   /* Apply default code props's only to user-defined symbols.  */
-  if (sym->tag[0] != '$' && sym != errtoken)
+  if (symbol_is_user_defined (sym))
     {
       code_props *code = &semantic_type_get (sym->content->type_name ? "*" : "",
                                              NULL)->props[kind];
@@ -831,16 +844,26 @@ symbols_new (void)
   accept->content->class = nterm_sym;
   accept->content->number = nvars++;
 
-  /* Construct the error token */
-  errtoken = symbol_get ("error", empty_loc);
+  /* Construct the YYERRCODE/"error" token */
+  errtoken = symbol_get ("YYERRCODE", empty_loc);
   errtoken->content->class = token_sym;
   errtoken->content->number = ntokens++;
+  {
+    symbol *alias = symbol_get ("error", empty_loc);
+    symbol_class_set (alias, token_sym, empty_loc, false);
+    symbol_make_alias (errtoken, alias, empty_loc);
+  }
 
-  /* Construct a token that represents all undefined literal tokens.
-     It is always token number 2.  */
-  undeftoken = symbol_get ("$undefined", empty_loc);
+  /* Construct the YYUNDEF/"$undefined" token that represents all
+     undefined literal tokens.  It is always symbol number 2.  */
+  undeftoken = symbol_get ("YYUNDEF", empty_loc);
   undeftoken->content->class = token_sym;
   undeftoken->content->number = ntokens++;
+  {
+    symbol *alias = symbol_get ("$undefined", empty_loc);
+    symbol_class_set (alias, token_sym, empty_loc, false);
+    symbol_make_alias (undeftoken, alias, empty_loc);
+  }
 
   semantic_type_table = hash_xinitialize (HT_INITIAL_CAPACITY,
                                           NULL,
