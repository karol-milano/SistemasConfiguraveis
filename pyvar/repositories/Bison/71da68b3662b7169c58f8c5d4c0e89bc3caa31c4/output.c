@@ -438,7 +438,7 @@ prepare_symbol_definitions (void)
 
 #define CODE_PROP(PropName)                                             \
       do {                                                              \
-        code_props const *p = symbol_ ## PropName ## _get (sym);        \
+        code_props const *p = symbol_code_props_get (sym, PropName);    \
         SET_KEY("has_" #PropName);                                      \
         MUSCLE_INSERT_INT (key, !!p->code);                             \
                                                                         \
