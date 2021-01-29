@@ -27,29 +27,29 @@
 
 /* comments for these variables are in gram.h  */
 
-int nitems;
-int nrules;
-int nsyms;
-int ntokens;
-int nvars;
+int nitems = 0;
+int nrules = 0;
+int nsyms = 0;
+int ntokens = 0;
+int nvars = 0;
 
 short *ritem = NULL;
-int nritems;
+int nritems = 0;
 
 rule_t *rules = NULL;
 
 struct bucket **symbols = NULL;
 short *token_translations = NULL;
 
-int start_symbol;
+int start_symbol = 0;
 
-int max_user_token_number;
+int max_user_token_number = 256;
 
-int semantic_parser;
+int semantic_parser = 0;
 
-int pure_parser;
+int pure_parser = 0;
 
-int error_token_number;
+int error_token_number = 0;
 
 
 /*--------------------------------------.
