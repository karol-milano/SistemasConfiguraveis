@@ -66,7 +66,7 @@ print_core (state_t *state, struct obstack *node_obstack)
 
       sp1 = sp = ritem + sitems[i];
 
-      while (*sp > 0)
+      while (*sp >= 0)
 	sp++;
 
       rule = -(*sp);
@@ -81,7 +81,7 @@ print_core (state_t *state, struct obstack *node_obstack)
 
       obstack_1grow (node_obstack, '.');
 
-      for (/* Nothing */; *sp > 0; ++sp)
+      for (/* Nothing */; *sp >= 0; ++sp)
 	obstack_fgrow1 (node_obstack, " %s", escape (tags[*sp]));
     }
 }
