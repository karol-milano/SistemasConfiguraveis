@@ -72,6 +72,12 @@ static bitsetv LA = NULL;
 size_t nLA;
 
 
+/* "(p, A) includes (p', B)" iff
+   B → βAγ, γ nullable, and p'-- β --> p (i.e., state p' reaches p on label β).
+
+   Definition p.621 [DeRemer 1982].
+
+   INCLUDES[(p, A)] = [(p', B),...] */
 static goto_number **includes;
 
 /* "(q, A → ω) lookback (p, A)" iff state p reaches state q on label ω.
