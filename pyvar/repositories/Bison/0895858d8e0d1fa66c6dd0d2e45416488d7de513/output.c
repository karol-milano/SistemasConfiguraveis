@@ -277,7 +277,7 @@ static void
 prepare_symbols (void)
 {
   MUSCLE_INSERT_INT ("tokens_number", ntokens);
-  MUSCLE_INSERT_INT ("nterms_number", nvars);
+  MUSCLE_INSERT_INT ("nterms_number", nnterms);
   MUSCLE_INSERT_INT ("symbols_number", nsyms);
   MUSCLE_INSERT_INT ("code_max", max_code);
 
