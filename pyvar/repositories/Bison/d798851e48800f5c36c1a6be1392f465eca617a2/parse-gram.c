@@ -2189,7 +2189,7 @@ yyreduce:
 
   case 34: /* grammar_declaration: "%start" symbols.1  */
     {
-      grammar_start_symbols_set ((yyvsp[0].yykind_90));
+      grammar_start_symbols_add ((yyvsp[0].yykind_90));
     }
     break;
 
