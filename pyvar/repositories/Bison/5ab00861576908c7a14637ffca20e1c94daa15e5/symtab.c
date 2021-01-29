@@ -1095,6 +1095,21 @@ symbols_token_translations_init (void)
 }
 
 
+/* Whether some symbol requires internationalization.  */
+static bool
+has_translations (void)
+{
+  for (const void *entry = hash_get_first (symbol_table);
+       entry;
+       entry = hash_get_next (symbol_table, entry))
+    {
+      const symbol *sym = (const symbol *) entry;
+      if (sym->translatable)
+        return true;
+    }
+  return false;
+}
+
 /*----------------------------------------------------------------.
 | Assign symbol numbers, and write definition of token names into |
 | FDEFINES.  Set up vectors SYMBOL_TABLE, TAGS of symbols.        |
@@ -1137,6 +1152,18 @@ symbols_pack (void)
     complain (&startsymbol_loc, fatal,
               _("the start symbol %s is a token"),
               startsymbol->tag);
+
+  // If some user tokens are internationalized, the internal ones
+  // should be too.
+  if (has_translations ())
+    {
+      const bool eof_is_user_defined
+        = !endtoken->alias || STRNEQ (endtoken->alias->tag, "$end");
+      if (!eof_is_user_defined)
+        endtoken->alias->translatable = true;
+      undeftoken->alias->translatable = true;
+      errtoken->alias->translatable = true;
+    }
 }
 
 /*---------------------------------.
