@@ -37,9 +37,6 @@
 #include "getargs.h"
 #include "bitset.h"
 
-typedef short *rule;
-
-
 /* Set of all nonterminals which are not useless.  */
 static bitset N;
 
@@ -67,7 +64,7 @@ int nuseless_nonterminals;
 static bool
 useful_production (int i, bitset N0)
 {
-  rule r;
+  item_number_t *r;
   short n;
 
   /* A production is useful if all of the nonterminals in its appear
@@ -139,7 +136,7 @@ inaccessable_symbols (void)
   bitset Vp, Vs, Pp;
   int i;
   short t;
-  rule r;
+  item_number_t *r;
 
   /* Find out which productions are reachable and which symbols are
      used.  Starting with an empty set of productions and a set of
@@ -252,7 +249,7 @@ reduce_grammar_tables (void)
     /* Renumber the rules markers in RITEMS.  */
     for (i = 1; i < nrules + 1; ++i)
       {
-	short *rhsp = rules[i].rhs;
+	item_number_t *rhsp = rules[i].rhs;
 	for (/* Nothing. */; *rhsp >= 0; ++rhsp)
 	  /* Nothing. */;
 	*rhsp = -i;
@@ -361,7 +358,7 @@ reduce_output (FILE *out)
       fprintf (out, "%s\n\n", _("Useless rules:"));
       for (i = nrules + 1; i < nuseless_productions + nrules + 1; i++)
 	{
-	  rule r;
+	  item_number_t *r;
 	  fprintf (out, "#%-4d  ", rules[i].user_number - 1);
 	  fprintf (out, "%s:", quotearg_style (escape_quoting_style,
 					       rules[i].lhs->tag));
@@ -378,7 +375,7 @@ static void
 dump_grammar (FILE *out)
 {
   int i;
-  rule r;
+  item_number_t *r;
 
   fprintf (out, "REDUCED GRAMMAR\n\n");
   fprintf (out,
