@@ -603,7 +603,7 @@ token_definitions_output (FILE *out)
       if (strchr (symbol->tag, '.') || strchr (symbol->tag, '$'))
 	continue;
 
-      fprintf (out, "%s  [[[%s]], [%d]]",
+      fprintf (out, "%s[[[%s]], [%d]]",
 	       first ? "" : ",\n", symbol->tag, number);
       first = 0;
     }
