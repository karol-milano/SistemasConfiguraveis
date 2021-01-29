@@ -100,11 +100,7 @@ symbol_new (uniqstr tag, location loc)
   return res;
 }
 
-/*-------------------------------------------------------.
-| Name of the code_props type: %destructor or %printer.  |
-`-------------------------------------------------------*/
-
-static char const *
+char const *
 code_props_type_string (code_props_type kind)
 {
   switch (kind)
