@@ -91,23 +91,12 @@ print_actions (state_t *state, const char *node_name)
 
   shifts   *shiftp = state->shifts;
   reductions *redp = state->reductions;
-#if 0
-  errs       *errp = state->errs;
-#endif
 
   static char buff[10];
   edge_t edge;
 
   if (!shiftp->nshifts && !redp)
-    {
-#if 0
-      if (final_state == state)
-	obstack_sgrow (node_obstack, "$default: accept");
-      else
-	obstack_sgrow (node_obstack, "NO ACTIONS");
-#endif
-      return;
-    }
+    return;
 
   for (i = 0; i < shiftp->nshifts; i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
@@ -130,43 +119,6 @@ print_actions (state_t *state, const char *node_name)
 	output_edge (&edge, fgraph);
 	close_edge (fgraph);
       }
-
-#if 0
-  if (errp)
-    {
-      int j, nerrs;
-
-      nerrs = errp->nerrs;
-
-      for (j = 0; j < nerrs; j++)
-	{
-	  if (!errp->errs[j])
-	    continue;
-	  symbol = errp->errs[j];
-	  /* If something has been added in the NODE_OBSTACK after
-	     the declaration of the label, then we need a `\n'.
-	  if (obstack_object_size (node_obstack) > node_output_size)
-	    obstack_sgrow (node_obstack, "\n");
-	    */
-	  obstack_fgrow1 (node_obstack, _("%-4s\terror (nonassociative)"),
-			  tags[symbol]);
-	}
-      if (j > 0)
-	obstack_1grow (node_obstack, '\n');
-    }
-
-  if (state->consistent && redp)
-    {
-      rule = redp->rules[0];
-      symbol = rule_table[rule].lhs;
-      /*
-      if (obstack_object_size (node_obstack) > node_output_size)
-	obstack_sgrow (node_obstack, "\n");
-	*/
-      obstack_fgrow2 (node_obstack, _("$default\treduce using rule %d (%s)"),
-		      rule, tags[symbol]);
-    }
-#endif
 }
 
 
