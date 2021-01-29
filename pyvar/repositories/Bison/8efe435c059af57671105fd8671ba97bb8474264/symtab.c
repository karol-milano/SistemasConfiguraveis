@@ -34,6 +34,7 @@ symbol_t *undeftoken = NULL;
 symbol_t *eoftoken = NULL;
 symbol_t *axiom = NULL;
 symbol_t *startsymbol = NULL;
+location_t startsymbol_location;
 
 /*---------------------------------.
 | Create a new symbol, named TAG.  |
