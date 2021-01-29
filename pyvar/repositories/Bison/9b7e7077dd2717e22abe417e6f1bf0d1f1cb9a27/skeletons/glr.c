@@ -622,7 +622,7 @@ yysymbol_name (yysymbol_kind_t yysymbol)
   {
   ]b4_symbol_names[
   };]m4_ifdef([b4_translatable], [[
-  /* YYTRANSLATABLE[SYMBOL-NUM] -- Whether YYTNAME[SYMBOL-NUM] is
+  /* YYTRANSLATABLE[SYMBOL-NUM] -- Whether YY_SNAME[SYMBOL-NUM] is
      internationalizable.  */
   static ]b4_int_type_for([b4_translatable])[ yytranslatable[] =
   {
