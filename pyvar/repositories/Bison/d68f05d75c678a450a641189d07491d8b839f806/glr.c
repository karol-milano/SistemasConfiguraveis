@@ -639,7 +639,7 @@ struct yyGLRState {
   size_t yyposn;
   union {
     /** First in a chain of alternative reductions producing the
-     *  non-terminal corresponding to this state, threaded through
+     *  nonterminal corresponding to this state, threaded through
      *  yynext.  */
     yySemanticOption* yyfirstVal;
     /** Semantic value for this state.  */
