@@ -559,6 +559,13 @@ search_state_free (search_state *ss)
   free (ss);
 }
 
+static inline void
+search_state_retain_derivs (search_state *ss)
+{
+  parse_state_retain_deriv (ss->states[0]);
+  parse_state_retain_deriv (ss->states[1]);
+}
+
 static void
 search_state_print (search_state *ss)
 {
@@ -1057,12 +1064,11 @@ unifying_example (state_item_number itm1,
                       // we've found a unifying counterexample.
                       cex = new_counterexample (d1, d2, true, false);
                       // prevent d1/d2 from being freed.
-                      parse_state_retain_deriv (ps1);
-                      parse_state_retain_deriv (ps2);
+                      search_state_retain_derivs (ss);
                       goto cex_search_end;
                     }
                   if (!stage3result)
-                    stage3result = ss;
+                    stage3result = copy_search_state (ss);
                 }
             }
           if (TIME_LIMIT_ENFORCED)
@@ -1094,7 +1100,11 @@ cex_search_end:;
       // If a search state from Stage 3 is available, use it
       // to construct a more compact nonunifying counterexample.
       if (stage3result)
-        cex = complete_diverging_examples (stage3result, next_sym);
+        {
+          cex = complete_diverging_examples (stage3result, next_sym);
+          search_state_retain_derivs (stage3result);
+          search_state_free (stage3result);
+        }
       // Otherwise, construct a nonunifying counterexample that
       // begins from the start state using the shortest
       // lookahead-sensitive path to the reduce item.
