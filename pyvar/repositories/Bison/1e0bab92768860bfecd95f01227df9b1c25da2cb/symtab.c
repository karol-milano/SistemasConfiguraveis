@@ -102,12 +102,13 @@ symbol_tag_print (symbol_t *symbol, FILE *out)
 `------------------------------------------------------------------*/
 
 void
-symbol_type_set (symbol_t *symbol, char *type_name)
+symbol_type_set (symbol_t *symbol, location_t location, char *type_name)
 {
   if (type_name)
     {
       if (symbol->type_name)
-	complain (_("type redeclaration for %s"), symbol->tag);
+	complain_at (location,
+		     _("type redeclaration for %s"), symbol->tag);
       symbol->type_name = type_name;
     }
 }
@@ -119,13 +120,14 @@ symbol_type_set (symbol_t *symbol, char *type_name)
 `------------------------------------------------------------------*/
 
 void
-symbol_precedence_set (symbol_t *symbol,
+symbol_precedence_set (symbol_t *symbol, location_t location,
 		       int prec, associativity assoc)
 {
   if (assoc != undef_assoc)
     {
       if (symbol->prec != 0)
-	complain (_("redefining precedence of %s"), symbol->tag);
+	complain_at (location,
+		     _("redefining precedence of %s"), symbol->tag);
       symbol->prec = prec;
       symbol->assoc = assoc;
     }
