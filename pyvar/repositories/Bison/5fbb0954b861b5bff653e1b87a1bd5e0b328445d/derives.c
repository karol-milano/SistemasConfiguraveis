@@ -69,7 +69,7 @@ set_derives (void)
   p = delts;
   for (i = nrules; i > 0; i--)
     {
-      int lhs = rules[i].lhs->number;
+      token_number_t lhs = rules[i].lhs->number;
       p->next = dset[lhs];
       p->value = i;
       dset[lhs] = p;
