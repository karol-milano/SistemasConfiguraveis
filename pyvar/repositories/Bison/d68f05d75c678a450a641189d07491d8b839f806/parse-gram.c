@@ -2705,7 +2705,7 @@ yyreduce:
       if (current_class == nterm_sym)
         {
           gram_error (&(yylsp[0]),
-                      _("character literals cannot be non-terminals"));
+                      _("character literals cannot be nonterminals"));
           YYERROR;
         }
       (yyval.id) = symbol_get (char_name ((yyvsp[0].CHAR)), (yylsp[0]));
