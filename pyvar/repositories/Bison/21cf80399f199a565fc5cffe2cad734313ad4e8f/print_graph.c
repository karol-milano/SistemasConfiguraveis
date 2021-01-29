@@ -84,8 +84,11 @@ print_core (struct obstack *oout, state *s)
 
       obstack_1grow (oout, '.');
 
-      for (/* Nothing */; *sp >= 0; ++sp)
-        obstack_printf (oout, " %s", escape (symbols[*sp]->tag));
+      if (0 <= *r->rhs)
+        for (/* Nothing */; *sp >= 0; ++sp)
+          obstack_printf (oout, " %s", escape (symbols[*sp]->tag));
+      else
+        obstack_printf (oout, " %%empty");
 
       /* Experimental feature: display the lookahead tokens. */
       if (report_flag & report_lookahead_tokens
