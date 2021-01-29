@@ -27,18 +27,17 @@
 
 /* comments for these variables are in gram.h  */
 
-int nitems = 0;
-int nrules = 0;
-int nsyms = 0;
-int ntokens = 1;
-int nvars = 0;
-
 short *ritem = NULL;
 int nritems = 0;
 
 rule_t *rules = NULL;
+int nrules = 0;
 
 symbol_t **symbols = NULL;
+int nsyms = 0;
+int ntokens = 1;
+int nvars = 0;
+
 short *token_translations = NULL;
 
 int start_symbol = 0;
