@@ -90,7 +90,7 @@ stringappend (const char *string1, const char *string2)
 |  header of the parser and store it in header_macro_name.       |
 `---------------------------------------------------------------*/
 
-static const char *
+static char *
 compute_header_macro (void)
 {
   int ite;
