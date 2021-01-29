@@ -677,6 +677,7 @@ report_state_counterexamples (const state *s)
                     }
                 }
             }
+          bitset_free (conf);
         }
     }
 }
