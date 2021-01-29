@@ -58,7 +58,7 @@ static semantic_type **semantic_types_sorted = NULL;
 
 symbol *errtoken = NULL;
 symbol *undeftoken = NULL;
-symbol *endtoken = NULL;
+symbol *eoftoken = NULL;
 symbol *accept = NULL;
 symbol *startsymbol = NULL;
 location startsymbol_loc;
@@ -78,9 +78,9 @@ static bool
 symbol_is_user_defined (symbol *sym)
 {
   const bool eof_is_user_defined
-    = !endtoken->alias || STRNEQ (endtoken->alias->tag, "$end");
+    = !eoftoken->alias || STRNEQ (eoftoken->alias->tag, "$end");
   return sym->tag[0] != '$'
-    && (eof_is_user_defined || (sym != endtoken && sym->alias != errtoken))
+    && (eof_is_user_defined || (sym != eoftoken && sym->alias != errtoken))
     && sym != errtoken && sym->alias != errtoken
     && sym != undeftoken && sym->alias != undeftoken;
 }
@@ -595,14 +595,14 @@ symbol_code_set (symbol *sym, int code, location loc)
     {
       *codep = code;
       /* User defined $end token? */
-      if (code == 0 && !endtoken)
+      if (code == 0 && !eoftoken)
         {
-          endtoken = sym->content->symbol;
+          eoftoken = sym->content->symbol;
           /* It is always mapped to 0, so it was already counted in
              NTOKENS.  */
-          if (endtoken->content->number != NUMBER_UNDEFINED)
+          if (eoftoken->content->number != NUMBER_UNDEFINED)
             --ntokens;
-          endtoken->content->number = 0;
+          eoftoken->content->number = 0;
         }
     }
 }
@@ -1163,9 +1163,9 @@ symbols_pack (void)
   if (has_translations ())
     {
       const bool eof_is_user_defined
-        = !endtoken->alias || STRNEQ (endtoken->alias->tag, "$end");
+        = !eoftoken->alias || STRNEQ (eoftoken->alias->tag, "$end");
       if (!eof_is_user_defined)
-        endtoken->alias->translatable = true;
+        eoftoken->alias->translatable = true;
       undeftoken->alias->translatable = true;
       errtoken->alias->translatable = true;
     }
