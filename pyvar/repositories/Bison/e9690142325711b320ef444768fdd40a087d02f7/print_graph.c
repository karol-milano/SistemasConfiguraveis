@@ -66,43 +66,43 @@ print_core (struct obstack *oout, state *s)
       sp1 = sp = ritem + sitems[i];
 
       while (*sp >= 0)
-	sp++;
+        sp++;
 
       r = item_number_as_rule_number (*sp);
 
       obstack_fgrow1 (oout, "\n%s -> ", rules[r].lhs->tag);
 
       for (sp = rules[r].rhs; sp < sp1; sp++)
-	obstack_fgrow1 (oout, "%s ", symbols[*sp]->tag);
+        obstack_fgrow1 (oout, "%s ", symbols[*sp]->tag);
 
       obstack_1grow (oout, '.');
 
       for (/* Nothing */; *sp >= 0; ++sp)
-	obstack_fgrow1 (oout, " %s", symbols[*sp]->tag);
+        obstack_fgrow1 (oout, " %s", symbols[*sp]->tag);
 
       /* Experimental feature: display the lookahead tokens. */
       if (report_flag & report_lookahead_tokens
           && item_number_is_rule_number (*sp1))
-	{
-	  /* Find the reduction we are handling.  */
-	  reductions *reds = s->reductions;
-	  int redno = state_reduction_find (s, &rules[r]);
-
-	  /* Print them if there are.  */
-	  if (reds->lookahead_tokens && redno != -1)
-	    {
-	      bitset_iterator biter;
-	      int k;
-	      char const *sep = "";
-	      obstack_sgrow (oout, "[");
-	      BITSET_FOR_EACH (biter, reds->lookahead_tokens[redno], k, 0)
-		{
-		  obstack_fgrow2 (oout, "%s%s", sep, symbols[k]->tag);
-		  sep = ", ";
-		}
-	      obstack_sgrow (oout, "]");
-	    }
-	}
+        {
+          /* Find the reduction we are handling.  */
+          reductions *reds = s->reductions;
+          int redno = state_reduction_find (s, &rules[r]);
+
+          /* Print them if there are.  */
+          if (reds->lookahead_tokens && redno != -1)
+            {
+              bitset_iterator biter;
+              int k;
+              char const *sep = "";
+              obstack_sgrow (oout, "[");
+              BITSET_FOR_EACH (biter, reds->lookahead_tokens[redno], k, 0)
+                {
+                  obstack_fgrow2 (oout, "%s%s", sep, symbols[k]->tag);
+                  sep = ", ";
+                }
+              obstack_sgrow (oout, "]");
+            }
+        }
     }
 }
 
@@ -125,21 +125,21 @@ print_actions (state const *s, FILE *fgraph)
   for (i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i))
       {
-	state *s1 = trans->states[i];
-	symbol_number sym = s1->accessing_symbol;
-
-	/* Shifts are solid, gotos are dashed, and error is dotted.  */
-	char const *style =
-	  (TRANSITION_IS_ERROR (trans, i) ? "dotted"
-	   : TRANSITION_IS_SHIFT (trans, i) ? "solid"
-	   : "dashed");
-
-	if (TRANSITION_IS_ERROR (trans, i)
-	    && strcmp (symbols[sym]->tag, "error") != 0)
-	  abort ();
-	output_edge (s->number, s1->number,
-		     TRANSITION_IS_ERROR (trans, i) ? NULL : symbols[sym]->tag,
-		     style, fgraph);
+        state *s1 = trans->states[i];
+        symbol_number sym = s1->accessing_symbol;
+
+        /* Shifts are solid, gotos are dashed, and error is dotted.  */
+        char const *style =
+          (TRANSITION_IS_ERROR (trans, i) ? "dotted"
+           : TRANSITION_IS_SHIFT (trans, i) ? "solid"
+           : "dashed");
+
+        if (TRANSITION_IS_ERROR (trans, i)
+            && strcmp (symbols[sym]->tag, "error") != 0)
+          abort ();
+        output_edge (s->number, s1->number,
+                     TRANSITION_IS_ERROR (trans, i) ? NULL : symbols[sym]->tag,
+                     style, fgraph);
       }
 }
 
