@@ -371,20 +371,9 @@ reduce_output (FILE *out)
   }
 
   if (nuseless_productions > 0)
-    {
-      int i;
-      fprintf (out, "%s\n\n", _("Useless rules:"));
-      for (i = nrules + 1; i < nuseless_productions + nrules + 1; i++)
-	{
-	  item_number_t *r;
-	  fprintf (out, "#%-4d  ", rules[i].user_number - 1);
-	  fprintf (out, "%s:", symbol_tag_get (rules[i].lhs));
-	  for (r = rules[i].rhs; *r >= 0; r++)
-	    fprintf (out, " %s", symbol_tag_get (symbols[*r]));
-	  fputs (";\n", out);
-	}
-      fputs ("\n\n", out);
-    }
+    grammar_rules_partial_print (out, _("Useless rules"),
+				 nrules + 1,
+				 nuseless_productions + nrules + 1);
 }
 
 
