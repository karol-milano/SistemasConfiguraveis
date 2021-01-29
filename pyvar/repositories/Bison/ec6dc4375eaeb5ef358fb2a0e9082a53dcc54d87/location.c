@@ -96,8 +96,6 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
 }
 
 
-/* Output to OUT the location LOC.
-   Warning: it uses quotearg's slot 3.  */
 unsigned
 location_print (location loc, FILE *out)
 {
