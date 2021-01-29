@@ -2075,7 +2075,7 @@ yyreduce:
     break;
 
   case 9: /* prologue_declaration: "%defines"  */
-                                   { defines_flag = true; }
+                                   { header_flag = true; }
     break;
 
   case 10: /* prologue_declaration: "%defines" "string"  */
@@ -2938,7 +2938,7 @@ add_param (param_type type, char *decl, location loc)
 static void
 handle_defines (char const *value)
 {
-  defines_flag = true;
+  header_flag = true;
   char *file = unquote (value);
   spec_header_file = xstrdup (file);
   gram_scanner_last_string_free ();
