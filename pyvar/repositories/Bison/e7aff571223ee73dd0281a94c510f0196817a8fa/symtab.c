@@ -33,6 +33,13 @@
 #include "gram.h"
 #include "intprops.h"
 
+/** Undefined token code.  */
+#define CODE_UNDEFINED (-1)
+
+/* Undefined symbol number.  */
+#define NUMBER_UNDEFINED (-1)
+
+
 static struct hash_table *symbol_table = NULL;
 static struct hash_table *semantic_type_table = NULL;
 
@@ -99,7 +106,7 @@ sym_content_new (symbol *s)
   res->prec_loc = empty_loc;
   res->prec = 0;
   res->assoc = undef_assoc;
-  res->user_token_number = USER_NUMBER_UNDEFINED;
+  res->code = CODE_UNDEFINED;
 
   res->class = unknown_sym;
   res->status = undeclared;
@@ -571,24 +578,24 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
 `------------------------------------------------*/
 
 void
-symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
+symbol_code_set (symbol *sym, int code, location loc)
 {
-  int *user_token_numberp = &sym->content->user_token_number;
+  int *codep = &sym->content->code;
   if (sym->content->class != token_sym)
     complain (&loc, complaint,
               _("nonterminals cannot be given a token code"));
-  else if (*user_token_numberp != USER_NUMBER_UNDEFINED
-           && *user_token_numberp != user_token_number)
+  else if (*codep != CODE_UNDEFINED
+           && *codep != code)
     complain (&loc, complaint, _("redefining code of token %s"),
               sym->tag);
-  else if (user_token_number == INT_MAX)
+  else if (code == INT_MAX)
     complain (&loc, complaint, _("code of token %s too large"),
               sym->tag);
   else
     {
-      *user_token_numberp = user_token_number;
+      *codep = code;
       /* User defined $end token? */
-      if (user_token_number == 0 && !endtoken)
+      if (code == 0 && !endtoken)
         {
           endtoken = sym->content->symbol;
           /* It is always mapped to 0, so it was already counted in
@@ -735,7 +742,7 @@ symbol_pack (symbol *sym)
 }
 
 static void
-complain_user_token_number_redeclared (int num, symbol *first, symbol *second)
+complain_code_redeclared (int num, symbol *first, symbol *second)
 {
   symbols_sort (&first, &second);
   complain (&second->location, complaint,
@@ -758,13 +765,13 @@ symbol_translation (symbol *sym)
       && !sym->is_alias)
     {
       /* A token which translation has already been set?*/
-      if (token_translations[sym->content->user_token_number]
+      if (token_translations[sym->content->code]
           != undeftoken->content->number)
-        complain_user_token_number_redeclared
-          (sym->content->user_token_number,
-           symbols[token_translations[sym->content->user_token_number]], sym);
+        complain_code_redeclared
+          (sym->content->code,
+           symbols[token_translations[sym->content->code]], sym);
       else
-        token_translations[sym->content->user_token_number]
+        token_translations[sym->content->code]
           = sym->content->number;
     }
 }
@@ -1040,53 +1047,53 @@ symbols_check_defined (void)
 static void
 symbols_token_translations_init (void)
 {
-  bool num_256_available_p = true;
+  bool code_256_available_p = true;
 
   /* Find the highest token code, and whether 256, the POSIX preferred
      token code for the error token, is used.  */
-  max_user_token_number = 0;
+  max_code = 0;
   for (int i = 0; i < ntokens; ++i)
     {
       sym_content *sym = symbols[i]->content;
-      if (sym->user_token_number != USER_NUMBER_UNDEFINED)
+      if (sym->code != CODE_UNDEFINED)
         {
-          if (sym->user_token_number > max_user_token_number)
-            max_user_token_number = sym->user_token_number;
-          if (sym->user_token_number == 256)
-            num_256_available_p = false;
+          if (sym->code > max_code)
+            max_code = sym->code;
+          if (sym->code == 256)
+            code_256_available_p = false;
         }
     }
 
   /* If 256 is not used, assign it to error, to follow POSIX.  */
-  if (num_256_available_p
-      && errtoken->content->user_token_number == USER_NUMBER_UNDEFINED)
-    errtoken->content->user_token_number = 256;
+  if (code_256_available_p
+      && errtoken->content->code == CODE_UNDEFINED)
+    errtoken->content->code = 256;
 
-  /* Set the missing user numbers. */
-  if (max_user_token_number < 256)
-    max_user_token_number = 256;
+  /* Set the missing codes. */
+  if (max_code < 256)
+    max_code = 256;
 
   for (int i = 0; i < ntokens; ++i)
     {
       sym_content *sym = symbols[i]->content;
-      if (sym->user_token_number == USER_NUMBER_UNDEFINED)
+      if (sym->code == CODE_UNDEFINED)
         {
           IGNORE_TYPE_LIMITS_BEGIN
-          if (INT_ADD_WRAPV (max_user_token_number, 1, &max_user_token_number))
+          if (INT_ADD_WRAPV (max_code, 1, &max_code))
             complain (NULL, fatal, _("token number too large"));
           IGNORE_TYPE_LIMITS_END
-          sym->user_token_number = max_user_token_number;
+          sym->code = max_code;
         }
-      if (sym->user_token_number > max_user_token_number)
-        max_user_token_number = sym->user_token_number;
+      if (sym->code > max_code)
+        max_code = sym->code;
     }
 
-  token_translations = xnmalloc (max_user_token_number + 1,
+  token_translations = xnmalloc (max_code + 1,
                                  sizeof *token_translations);
 
   /* Initialize all entries for literal tokens to the internal token
      number for $undefined, which represents all invalid inputs.  */
-  for (int i = 0; i < max_user_token_number + 1; ++i)
+  for (int i = 0; i < max_code + 1; ++i)
     token_translations[i] = undeftoken->content->number;
   for (int i = 0; symbols_sorted[i]; ++i)
     symbol_translation (symbols_sorted[i]);
