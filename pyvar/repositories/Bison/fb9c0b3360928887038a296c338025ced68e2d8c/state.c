@@ -237,13 +237,13 @@ state_rule_look_ahead_tokens_print (state *s, rule *r, FILE *out)
       bitset_iterator biter;
       int k;
       char const *sep = "";
-      fprintf (out, "  [");
+      fputs ("  [", out);
       BITSET_FOR_EACH (biter, reds->look_ahead_tokens[red], k, 0)
 	{
 	  fprintf (out, "%s%s", sep, symbols[k]->tag);
 	  sep = ", ";
 	}
-      fprintf (out, "]");
+      fputc (']', out);
     }
 }
 
