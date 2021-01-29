@@ -158,7 +158,7 @@ symbol_printer_set (symbol *sym, const char *printer, location loc)
   if (printer)
     {
       if (sym->printer)
-	redeclaration (sym, "%printer", sym->destructor_location, loc);
+	redeclaration (sym, "%printer", sym->printer_location, loc);
       sym->printer = printer;
       sym->printer_location = loc;
     }
