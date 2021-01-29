@@ -54,7 +54,7 @@ print_core (struct obstack *oout, state *s)
       snritems = nitemset;
     }
 
-  obstack_fgrow1 (oout, "%d", s->number);
+  obstack_printf (oout, "%d", s->number);
   for (i = 0; i < snritems; i++)
     {
       item_number *sp;
@@ -68,15 +68,15 @@ print_core (struct obstack *oout, state *s)
 
       r = item_number_as_rule_number (*sp);
 
-      obstack_fgrow1 (oout, "\n%s -> ", rules[r].lhs->tag);
+      obstack_printf (oout, "\n%s -> ", rules[r].lhs->tag);
 
       for (sp = rules[r].rhs; sp < sp1; sp++)
-	obstack_fgrow1 (oout, "%s ", symbols[*sp]->tag);
+	obstack_printf (oout, "%s ", symbols[*sp]->tag);
 
       obstack_1grow (oout, '.');
 
       for (/* Nothing */; *sp >= 0; ++sp)
-	obstack_fgrow1 (oout, " %s", symbols[*sp]->tag);
+	obstack_printf (oout, " %s", symbols[*sp]->tag);
 
       /* Experimental feature: display the lookahead tokens. */
       if (report_flag & report_lookahead_tokens
@@ -95,7 +95,7 @@ print_core (struct obstack *oout, state *s)
 	      obstack_sgrow (oout, "[");
 	      BITSET_FOR_EACH (biter, reds->lookahead_tokens[redno], k, 0)
 		{
-		  obstack_fgrow2 (oout, "%s%s", sep, symbols[k]->tag);
+		  obstack_printf (oout, "%s%s", sep, symbols[k]->tag);
 		  sep = ", ";
 		}
 	      obstack_sgrow (oout, "]");
