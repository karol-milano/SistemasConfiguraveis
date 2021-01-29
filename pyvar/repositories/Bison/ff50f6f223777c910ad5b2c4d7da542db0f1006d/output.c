@@ -225,6 +225,11 @@ prepare_symbol_names (char const *muscle_name)
           tag = "\"end of file\"";
           translatable = with_translations;
         }
+      else if (symbols[i]->content == undeftoken->content)
+        {
+          tag = "\"invalid token\"";
+          translatable = with_translations;
+        }
 
       char *cp
         = tag[0] == '"' && !quote
