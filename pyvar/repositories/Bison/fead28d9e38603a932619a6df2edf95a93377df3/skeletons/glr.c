@@ -623,16 +623,16 @@ yytnamerr (char *yyres, const char *yystr)
 
 #endif /* !YYERROR_VERBOSE */
 
-/** State numbers, as in LALR(1) machine */
+/** State numbers. */
 typedef int yyStateNum;
 
-/** Rule numbers, as in LALR(1) machine */
+/** Rule numbers. */
 typedef int yyRuleNum;
 
-/** Grammar symbol */
+/** Grammar symbol. */
 typedef int yySymbol;
 
-/** Item references, as in LALR(1) machine */
+/** Item references. */
 typedef short yyItemNum;
 
 typedef struct yyGLRState yyGLRState;
