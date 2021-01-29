@@ -221,7 +221,7 @@ symbol_check_defined_processor (void *sym, void *null ATTRIBUTE_UNUSED)
 
 /*------------------------------------------------------------------.
 | Declare the new symbol SYM.  Make it an alias of SYMVAL, and type |
-| them with TYPENAME.                                               |
+| SYMVAL with SYM's type.                                           |
 `------------------------------------------------------------------*/
 
 void
@@ -247,6 +247,7 @@ symbol_make_alias (symbol *sym, symbol *symval, location loc)
 	abort ();
       sym->number = symval->number =
 	(symval->number < sym->number) ? symval->number : sym->number;
+      symbol_type_set (symval, sym->type_name, loc);
     }
 }
 
