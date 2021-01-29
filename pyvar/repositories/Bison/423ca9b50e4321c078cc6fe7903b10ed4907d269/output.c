@@ -447,7 +447,8 @@ prepare_symbol_definitions (void)
         int j;
         for (j = 0; j < CODE_PROPS_SIZE; ++j)
           {
-            char const *pname = code_props_type_string (j);
+            /* "printer", not "%printer".  */
+            char const *pname = code_props_type_string (j) + 1;
             code_props const *p = symbol_code_props_get (sym, j);
             SET_KEY2("has", pname);
             MUSCLE_INSERT_INT (key, !!p->code);
