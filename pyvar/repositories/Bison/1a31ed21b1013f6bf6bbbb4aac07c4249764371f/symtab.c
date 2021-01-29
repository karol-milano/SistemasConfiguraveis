@@ -105,7 +105,7 @@ symbol_tag_print (symbol_t *symbol, FILE *out)
 `------------------------------------------------------------------*/
 
 void
-symbol_type_set (symbol_t *symbol, location_t location, char *type_name)
+symbol_type_set (symbol_t *symbol, char *type_name, location_t location)
 {
   if (type_name)
     {
@@ -122,7 +122,7 @@ symbol_type_set (symbol_t *symbol, location_t location, char *type_name)
 `-------------------------------------------------------------------*/
 
 void
-symbol_destructor_set (symbol_t *symbol, location_t location, char *destructor)
+symbol_destructor_set (symbol_t *symbol, char *destructor, location_t location)
 {
   if (destructor)
     {
@@ -161,8 +161,8 @@ symbol_printer_set (symbol_t *symbol, char *printer, location_t location)
 `------------------------------------------------------------------*/
 
 void
-symbol_precedence_set (symbol_t *symbol, location_t location,
-		       int prec, associativity assoc)
+symbol_precedence_set (symbol_t *symbol,
+		       int prec, associativity assoc, location_t location)
 {
   if (assoc != undef_assoc)
     {
