@@ -46,17 +46,14 @@ symbol *accept = NULL;
 symbol *startsymbol = NULL;
 location startsymbol_location;
 
-/*---------------------------.
-| Precedence relation graph. |
-`---------------------------*/
-
+/* Precedence relation graph. */
 static symgraph **prec_nodes;
 
-/*-----------------------------------.
-| Store which associativity is used. |
-`-----------------------------------*/
+/* Store which associativity is used.  */
+static bool *used_assoc = NULL;
+
+bool tag_seen = false;
 
-bool *used_assoc = NULL;
 
 /*--------------------------.
 | Create a new sym_content. |
@@ -334,6 +331,7 @@ symbol_type_set (symbol *sym, uniqstr type_name, location loc)
 {
   if (type_name)
     {
+      tag_seen = true;
       if (sym->content->type_name)
         complain_symbol_redeclared (sym, "%type",
                                     sym->content->type_location, loc);
