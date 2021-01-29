@@ -778,11 +778,16 @@ check_and_convert_grammar (void)
   /* If the user did not define her ENDTOKEN, do it now. */
   if (!endtoken)
     {
-      endtoken = symbol_get ("$end", empty_loc);
+      endtoken = symbol_get ("YYEOF", empty_loc);
       endtoken->content->class = token_sym;
       endtoken->content->number = 0;
       /* Value specified by POSIX.  */
       endtoken->content->user_token_number = 0;
+      {
+        symbol *alias = symbol_get ("$end", empty_loc);
+        symbol_class_set (alias, token_sym, empty_loc, false);
+        symbol_make_alias (endtoken, alias, empty_loc);
+      }
     }
 
   /* Report any undefined symbols and consider them nonterminals.  */
