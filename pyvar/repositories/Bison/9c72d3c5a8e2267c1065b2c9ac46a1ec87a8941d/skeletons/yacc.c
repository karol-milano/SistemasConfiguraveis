@@ -681,7 +681,7 @@ yysymbol_name (yysymbol_kind_t yysymbol)
   static const char *const yy_sname[] =
   {
   ]b4_symbol_names[
-  };]m4_ifdef([b4_translatable], [[
+  };]b4_has_translations_if([[
   /* YYTRANSLATABLE[SYMBOL-NUM] -- Whether YY_SNAME[SYMBOL-NUM] is
      internationalizable.  */
   static ]b4_int_type_for([b4_translatable])[ yytranslatable[] =
