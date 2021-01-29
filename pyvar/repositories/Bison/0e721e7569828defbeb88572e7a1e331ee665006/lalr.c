@@ -39,7 +39,6 @@
 /* All the decorated states, indexed by the state number.  */
 state_t **states = NULL;
 
-int tokensetsize;
 short *LAruleno = NULL;
 bitset *LA = NULL;
 size_t nLA;
@@ -581,8 +580,6 @@ lookaheads_print (FILE *out)
 void
 lalr (void)
 {
-  tokensetsize = WORDSIZE (ntokens);
-
   initialize_lookaheads ();
   initialize_LA ();
   set_goto_map ();
