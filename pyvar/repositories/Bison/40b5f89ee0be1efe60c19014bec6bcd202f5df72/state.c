@@ -51,20 +51,14 @@ transitions_new (int num, state **dst)
 }
 
 
-/*-------------------------------------------------------.
-| Return the state such that SHIFTS contain a shift/goto |
-| to it on SYM.  Abort if none found.                    |
-`-------------------------------------------------------*/
-
 state *
-transitions_to (transitions *shifts, symbol_number sym)
+transitions_to (state *s, symbol_number sym)
 {
-  for (int j = 0; ; j++)
-    {
-      aver (j < shifts->num);
-      if (TRANSITION_SYMBOL (shifts, j) == sym)
-        return shifts->states[j];
-    }
+  transitions *trans = s->transitions;
+  for (int i = 0; i < trans->num; ++i)
+    if (TRANSITION_SYMBOL (trans, i) == sym)
+      return trans->states[i];
+  abort ();
 }
 
 
