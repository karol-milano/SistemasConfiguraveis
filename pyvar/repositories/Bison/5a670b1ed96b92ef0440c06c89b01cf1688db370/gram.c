@@ -38,11 +38,9 @@ int nritems;
 rule_t *rule_table = NULL;
 short *rprec = NULL;
 short *rprecsym = NULL;
+short *rassoc = NULL;
 
 struct bucket **symbols = NULL;
-short *sprec = NULL;
-short *rassoc = NULL;
-short *sassoc = NULL;
 short *token_translations = NULL;
 
 int start_symbol;
