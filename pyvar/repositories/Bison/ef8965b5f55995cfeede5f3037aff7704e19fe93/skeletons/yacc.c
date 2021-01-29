@@ -674,7 +674,7 @@ yysymbol_name (int yysymbol)
   };]m4_ifdef([b4_translatable], [[
   /* YYTRANSLATABLE[SYMBOL-NUM] -- Whether YYTNAME[SYMBOL-NUM] is
      internationalizable.  */
-  static ]b4_int_type_for([b4_translate])[ yytranslatable[] =
+  static ]b4_int_type_for([b4_translatable])[ yytranslatable[] =
   {
   ]b4_translatable[
   };
