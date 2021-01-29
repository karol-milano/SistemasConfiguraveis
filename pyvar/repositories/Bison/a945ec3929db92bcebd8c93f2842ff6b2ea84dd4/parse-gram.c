@@ -105,7 +105,7 @@ symbol_class current_class = unknown_sym;
 char *current_type = 0;
 symbol_t *current_lhs;
 location_t current_lhs_location;
-associativity current_assoc;
+assoc_t current_assoc;
 int current_prec = 0;
 braced_code_t current_braced_code = action_braced_code;
 
@@ -231,7 +231,7 @@ typedef union {
   symbol_list_t *list;
   int integer;
   char *string;
-  associativity assoc;
+  assoc_t assoc;
 } yystype;
 /* Line 187 of /usr/local/share/bison/yacc.c.  */
 #line 238 "parse-gram.c"
