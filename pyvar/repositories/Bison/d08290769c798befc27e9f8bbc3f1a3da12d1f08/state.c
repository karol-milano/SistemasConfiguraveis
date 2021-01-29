@@ -236,12 +236,13 @@ state_rule_lookaheads_print (state *s, rule *r, FILE *out)
     {
       bitset_iterator biter;
       int k;
-      int not_first = 0;
+      char const *sep = "";
       fprintf (out, "  [");
       BITSET_FOR_EACH (biter, reds->lookaheads[red], k, 0)
-	fprintf (out, "%s%s",
-		 not_first++ ? ", " : "",
-		 symbols[k]->tag);
+	{
+	  fprintf (out, "%s%s", sep, symbols[k]->tag);
+	  sep = ", ";
+	}
       fprintf (out, "]");
     }
 }
