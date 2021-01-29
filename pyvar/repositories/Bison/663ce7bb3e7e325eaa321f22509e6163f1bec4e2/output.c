@@ -363,9 +363,11 @@ token_definitions_output (FILE *out)
       if (sym->tag[0] == '\'' || sym->tag[0] == '\"')
 	continue;
 
-      /* Don't #define nonliteral tokens whose names contain periods
-	 or '$' (as does the default value of the EOF token).  */
-      if (strchr (sym->tag, '.') || strchr (sym->tag, '$'))
+      /* Don't #define nonliteral tokens whose names contain periods,
+         dashes or '$' (as does the default value of the EOF token).  */
+      if (strchr (sym->tag, '.')
+          || strchr (sym->tag, '-')
+          || strchr (sym->tag, '$'))
 	continue;
 
       fprintf (out, "%s[[[%s]], %d]",
