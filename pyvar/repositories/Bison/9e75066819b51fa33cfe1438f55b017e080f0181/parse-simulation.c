@@ -157,7 +157,7 @@ parse_state_derivation_completed (const parse_state *ps)
 derivation *
 parse_state_derivation (const parse_state *ps)
 {
-  return (derivation *)ps->derivs.head_elt;
+  return (derivation *) ps->derivs.head_elt;
 }
 
 const state_item *
