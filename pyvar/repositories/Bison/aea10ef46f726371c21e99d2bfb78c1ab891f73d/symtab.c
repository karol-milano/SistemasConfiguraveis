@@ -128,6 +128,41 @@ symbol_print (symbol *s, FILE *f)
 #undef SYMBOL_ATTR_PRINT
 #undef SYMBOL_CODE_PRINT
 
+
+/*----------------------------------.
+| Whether S is a valid identifier.  |
+`----------------------------------*/
+
+static bool
+is_identifier (uniqstr s)
+{
+  static char const alphanum[26 + 26 + 1 + 10] =
+    "abcdefghijklmnopqrstuvwxyz"
+    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
+    "_"
+    "0123456789";
+  if (!s || ! memchr (alphanum, *s, sizeof alphanum - 10))
+    return false;
+  for (++s; *s; ++s)
+    if (! memchr (alphanum, *s, sizeof alphanum))
+      return false;
+  return true;
+}
+
+
+/*-----------------------------------------------.
+| Get the identifier associated to this symbol.  |
+`-----------------------------------------------*/
+uniqstr
+symbol_id_get (symbol const *sym)
+{
+  aver (sym->user_token_number != USER_NUMBER_ALIAS);
+  if (sym->alias)
+    sym = sym->alias;
+  return is_identifier (sym->tag) ? sym->tag : 0;
+}
+
+
 /*------------------------------------------------------------------.
 | Complain that S's WHAT is redeclared at SECOND, and was first set |
 | at FIRST.                                                         |
