@@ -1910,7 +1910,7 @@ yyreduce:
       strcpy (name + sizeof name_prefix - 1, (yyvsp[(2) - (3)].chars));
       if (muscle_find_const (name))
         warn_at ((yylsp[(2) - (3)]), _("%s `%s' redefined"), "%define variable", (yyvsp[(2) - (3)].chars));
-      muscle_insert (uniqstr_new (name), (yyvsp[(3) - (3)].chars));
+      MUSCLE_INSERT_STRING (uniqstr_new (name), (yyvsp[(3) - (3)].chars));
       free (name);
       muscle_grow_user_name_list ("user_percent_define_variables", (yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
     }
