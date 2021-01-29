@@ -269,7 +269,6 @@ is_identifier (uniqstr s)
 uniqstr
 symbol_id_get (symbol const *sym)
 {
-  aver (sym->content->user_token_number != USER_NUMBER_HAS_STRING_ALIAS);
   if (sym->alias)
     sym = sym->alias;
   return is_identifier (sym->tag) ? sym->tag : 0;
@@ -559,6 +558,45 @@ semantic_type_check_defined_processor (void *sem_type,
 }
 
 
+/*-------------------------------------------------------------------.
+| Merge the properties (precedence, associativity, etc.) of SYM, and |
+| its string-named alias STR; check consistency.                     |
+`-------------------------------------------------------------------*/
+
+static void
+symbol_merge_properties (symbol *sym, symbol *str)
+{
+  if (str->content->type_name != sym->content->type_name)
+    {
+      if (str->content->type_name)
+        symbol_type_set (sym,
+                         str->content->type_name, str->content->type_location);
+      else
+        symbol_type_set (str,
+                         sym->content->type_name, sym->content->type_location);
+    }
+
+
+  {
+    int i;
+    for (i = 0; i < CODE_PROPS_SIZE; ++i)
+      if (str->content->props[i].code)
+        symbol_code_props_set (sym, i, &str->content->props[i]);
+      else if (sym->content->props[i].code)
+        symbol_code_props_set (str, i, &sym->content->props[i]);
+  }
+
+  if (sym->content->prec || str->content->prec)
+    {
+      if (str->content->prec)
+        symbol_precedence_set (sym, str->content->prec, str->content->assoc,
+                               str->content->prec_location);
+      else
+        symbol_precedence_set (str, sym->content->prec, sym->content->assoc,
+                               sym->content->prec_location);
+    }
+}
+
 void
 symbol_make_alias (symbol *sym, symbol *str, location loc)
 {
@@ -570,6 +608,7 @@ symbol_make_alias (symbol *sym, symbol *str, location loc)
               _("symbol %s given more than one literal string"), sym->tag);
   else
     {
+      symbol_merge_properties (sym, str);
       sym_content_free (str->content);
       str->content = sym->content;
       str->content->symbol = str;
@@ -591,8 +630,6 @@ symbol_pack (symbol *this)
   aver (this->content->number != NUMBER_UNDEFINED);
   if (this->content->class == nterm_sym)
     this->content->number += ntokens;
-  else if (this->content->user_token_number == USER_NUMBER_HAS_STRING_ALIAS)
-    return true;
 
   symbols[this->content->number] = this->content->symbol;
   return true;
