@@ -44,7 +44,7 @@ static bitsetv firsts = NULL;
 
 /* Retrieve the FDERIVES/FIRSTS sets of the nonterminals numbered Var.  */
 #define FDERIVES(Var)   fderives[(Var) - ntokens]
-#define   FIRSTS(Var)   firsts[(Var) - ntokens]
+#define FIRSTS(Var)   firsts[(Var) - ntokens]
 
 
 /*-----------------.
