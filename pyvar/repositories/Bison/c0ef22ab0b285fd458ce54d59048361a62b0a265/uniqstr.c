@@ -105,7 +105,7 @@ uniqstr_print_processor (void *ustr, void *null ATTRIBUTE_UNUSED)
 
 
 int
-uniqstr_cmp(uniqstr l, uniqstr r)
+uniqstr_cmp (uniqstr l, uniqstr r)
 {
   return (l == r ? 0
           : !l ? -1
