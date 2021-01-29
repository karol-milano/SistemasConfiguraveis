@@ -130,7 +130,7 @@ symbol_type_set (symbol *sym, uniqstr type_name, location loc)
 `------------------------------------------------------------------*/
 
 void
-symbol_destructor_set (symbol *sym, char *destructor, location loc)
+symbol_destructor_set (symbol *sym, const char *destructor, location loc)
 {
   if (destructor)
     {
@@ -147,7 +147,7 @@ symbol_destructor_set (symbol *sym, char *destructor, location loc)
 `---------------------------------------------------------------*/
 
 void
-symbol_printer_set (symbol *sym, char *printer, location loc)
+symbol_printer_set (symbol *sym, const char *printer, location loc)
 {
   if (printer)
     {
