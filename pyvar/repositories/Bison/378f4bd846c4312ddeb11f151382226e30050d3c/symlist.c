@@ -56,11 +56,12 @@ symbol_list_new (symbol *sym, location loc)
 `------------------*/
 
 void
-symbol_list_print (symbol_list *l, FILE *f)
+symbol_list_print (const symbol_list *l, FILE *f)
 {
   for (/* Nothing. */; l && l->sym; l = l->next)
     {
       symbol_print (l->sym, f);
+      fprintf (stderr, l->used ? " used" : " unused");
       if (l && l->sym)
 	fprintf (f, ", ");
     }
@@ -96,7 +97,7 @@ symbol_list_free (symbol_list *list)
 `--------------------*/
 
 unsigned int
-symbol_list_length (symbol_list *l)
+symbol_list_length (const symbol_list *l)
 {
   int res = 0;
   for (/* Nothing. */; l; l = l->next)
