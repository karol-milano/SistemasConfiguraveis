@@ -274,12 +274,12 @@ prepare_symbols (void)
   MUSCLE_INSERT_INT ("tokens_number", ntokens);
   MUSCLE_INSERT_INT ("nterms_number", nvars);
   MUSCLE_INSERT_INT ("symbols_number", nsyms);
-  MUSCLE_INSERT_INT ("user_token_number_max", max_user_token_number);
+  MUSCLE_INSERT_INT ("code_max", max_code);
 
   muscle_insert_symbol_number_table ("translate",
                                      token_translations,
                                      token_translations[0],
-                                     1, max_user_token_number + 1);
+                                     1, max_code + 1);
 
   /* tname -- token names.  */
   prepare_symbol_names ("tname");
@@ -309,7 +309,7 @@ prepare_symbols (void)
   {
     int *values = xnmalloc (ntokens, sizeof *values);
     for (int i = 0; i < ntokens; ++i)
-      values[i] = symbols[i]->content->user_token_number;
+      values[i] = symbols[i]->content->code;
     muscle_insert_int_table ("toknum", values,
                              values[0], 1, ntokens);
     free (values);
@@ -565,8 +565,8 @@ prepare_symbol_definitions (void)
       SET_KEY ("tag");
       MUSCLE_INSERT_STRING (key, symbol_tag (sym));
 
-      SET_KEY ("user_number");
-      MUSCLE_INSERT_INT (key, sym->content->user_token_number);
+      SET_KEY ("code");
+      MUSCLE_INSERT_INT (key, sym->content->code);
 
       SET_KEY ("is_token");
       MUSCLE_INSERT_INT (key, i < ntokens);
