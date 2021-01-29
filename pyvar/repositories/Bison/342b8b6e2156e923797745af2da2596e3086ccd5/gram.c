@@ -31,21 +31,19 @@ int nsyms;
 int ntokens;
 int nvars;
 
-short *ritem;
-short *rlhs;
-short *rrhs;
-short *rprec;
-short *rprecsym;
-short *sprec;
-short *rassoc;
-short *sassoc;
-short *token_translations;
-short *rline;
+short *ritem = NULL;
+short *rlhs = NULL;
+short *rrhs = NULL;
+short *rprec = NULL;
+short *rprecsym = NULL;
+short *sprec = NULL;
+short *rassoc = NULL;
+short *sassoc = NULL;
+short *token_translations = NULL;
+short *rline = NULL;
 
 int start_symbol;
 
-int translations;
-
 int max_user_token_number;
 
 int semantic_parser;
