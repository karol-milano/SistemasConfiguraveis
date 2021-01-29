@@ -92,7 +92,7 @@
 
 #include "system.h"
 #include "getargs.h"
-#include "alloc.h"
+#include "xalloc.h"
 #include "files.h"
 #include "gram.h"
 #include "LR0.h"
@@ -452,7 +452,7 @@ output_rule_data (void)
 
   output_short_table (ftable, "yyr1", rlhs,
 		      0, 1, nrules + 1);
-  FREE (rlhs + 1);
+  XFREE (rlhs + 1);
 
   putc ('\n', ftable);
 
@@ -483,7 +483,7 @@ static const short yyr2[] = {     0", ftable);
     putc ('\n', ftable);
 
   fprintf (ftable, "%6d\n};\n", nitems - rrhs[nrules] - 1);
-  FREE (rrhs + 1);
+  XFREE (rrhs + 1);
 }
 
 
@@ -699,8 +699,8 @@ save_row (int state)
   if (count == 0)
     return;
 
-  froms[state] = sp1 = sp = NEW2 (count, short);
-  tos[state] = sp2 = NEW2 (count, short);
+  froms[state] = sp1 = sp = XCALLOC (short, count);
+  tos[state] = sp2 = XCALLOC (short, count);
 
   for (i = 0; i < ntokens; i++)
     {
@@ -728,19 +728,19 @@ static void
 token_actions (void)
 {
   int i;
-  short *yydefact = NEW2 (nstates, short);
+  short *yydefact = XCALLOC (short, nstates);
 
-  actrow = NEW2 (ntokens, short);
+  actrow = XCALLOC (short, ntokens);
   for (i = 0; i < nstates; ++i)
     {
       yydefact[i] = action_row (i);
       save_row (i);
     }
-  FREE (actrow);
+  XFREE (actrow);
 
   output_short_table (ftable, "yydefact", yydefact,
 		      yydefact[0], 1, nstates);
-  FREE (yydefact);
+  XFREE (yydefact);
 }
 
 
@@ -749,12 +749,12 @@ free_shifts (void)
 {
   shifts *sp, *sptmp;	/* JF derefrenced freed ptr */
 
-  FREE (shift_table);
+  XFREE (shift_table);
 
   for (sp = first_shift; sp; sp = sptmp)
     {
       sptmp = sp->next;
-      FREE (sp);
+      XFREE (sp);
     }
 }
 
@@ -764,12 +764,12 @@ free_reductions (void)
 {
   reductions *rp, *rptmp;	/* JF fixed freed ptr */
 
-  FREE (reduction_table);
+  XFREE (reduction_table);
 
   for (rp = first_reduction; rp; rp = rptmp)
     {
       rptmp = rp->next;
-      FREE (rp);
+      XFREE (rp);
     }
 }
 
@@ -802,8 +802,8 @@ save_column (int symbol, int default_state)
 
   symno = symbol - ntokens + nstates;
 
-  froms[symno] = sp1 = sp = NEW2 (count, short);
-  tos[symno] = sp2 = NEW2 (count, short);
+  froms[symno] = sp1 = sp = XCALLOC (short, count);
+  tos[symno] = sp2 = XCALLOC (short, count);
 
   for (i = m; i < n; i++)
     {
@@ -869,7 +869,7 @@ goto_actions (void)
 {
   int i, j, k;
 
-  state_count = NEW2 (nstates, short);
+  state_count = XCALLOC (short, nstates);
 
   k = default_goto (ntokens);
   fprintf (ftable, "\nstatic const short yydefgoto[] = {%6d", k);
@@ -896,7 +896,7 @@ goto_actions (void)
     }
 
   fprintf (ftable, "\n};\n");
-  FREE (state_count);
+  XFREE (state_count);
 }
 
 
@@ -912,7 +912,7 @@ sort_actions (void)
   int t;
   int w;
 
-  order = NEW2 (nvectors, short);
+  order = XCALLOC (short, nvectors);
   nentries = 0;
 
   for (i = 0; i < nvectors; i++)
@@ -1049,10 +1049,10 @@ pack_table (void)
   int place;
   int state;
 
-  base = NEW2 (nvectors, short);
-  pos = NEW2 (nentries, short);
-  table = NEW2 (MAXTABLE, short);
-  check = NEW2 (MAXTABLE, short);
+  base = XCALLOC (short, nvectors);
+  pos = XCALLOC (short, nentries);
+  table = XCALLOC (short, MAXTABLE);
+  check = XCALLOC (short, MAXTABLE);
 
   lowzero = 0;
   high = 0;
@@ -1079,14 +1079,14 @@ pack_table (void)
   for (i = 0; i < nvectors; i++)
     {
       if (froms[i])
-	FREE (froms[i]);
+	XFREE (froms[i]);
       if (tos[i])
-	FREE (tos[i]);
+	XFREE (tos[i]);
     }
 
-  FREE (froms);
-  FREE (tos);
-  FREE (pos);
+  XFREE (froms);
+  XFREE (tos);
+  XFREE (pos);
 }
 
 /* the following functions output yytable, yycheck
@@ -1103,7 +1103,7 @@ output_base (void)
   output_short_table (ftable, "yypgoto", base,
 		      base[nstates], nstates + 1, nvectors);
 
-  FREE (base);
+  XFREE (base);
 }
 
 
@@ -1113,7 +1113,7 @@ output_table (void)
   fprintf (ftable, "\n\n#define\tYYLAST\t\t%d\n\n\n", high);
   output_short_table (ftable, "yytable", table,
 		      table[0], 1, high + 1);
-  FREE (table);
+  XFREE (table);
 }
 
 
@@ -1122,7 +1122,7 @@ output_check (void)
 {
   output_short_table (ftable, "yycheck", check,
 		      check[0], 1, high + 1);
-  FREE (check);
+  XFREE (check);
 }
 
 /* compute and output yydefact, yydefgoto, yypact, yypgoto, yytable
@@ -1133,23 +1133,23 @@ output_actions (void)
 {
   nvectors = nstates + nvars;
 
-  froms = NEW2 (nvectors, short *);
-  tos = NEW2 (nvectors, short *);
-  tally = NEW2 (nvectors, short);
-  width = NEW2 (nvectors, short);
+  froms = XCALLOC (short *, nvectors);
+  tos = XCALLOC (short *, nvectors);
+  tally = XCALLOC (short, nvectors);
+  width = XCALLOC (short, nvectors);
 
   token_actions ();
   free_shifts ();
   free_reductions ();
-  FREE (lookaheads);
-  FREE (LA);
-  FREE (LAruleno);
-  FREE (accessing_symbol);
+  XFREE (lookaheads);
+  XFREE (LA);
+  XFREE (LAruleno);
+  XFREE (accessing_symbol);
 
   goto_actions ();
-  FREE (goto_map + ntokens);
-  FREE (from_state);
-  FREE (to_state);
+  XFREE (goto_map + ntokens);
+  XFREE (from_state);
+  XFREE (to_state);
 
   sort_actions ();
   pack_table ();
@@ -1264,12 +1264,12 @@ free_itemsets (void)
 {
   core *cp, *cptmp;
 
-  FREE (state_table);
+  XFREE (state_table);
 
   for (cp = first_state; cp; cp = cptmp)
     {
       cptmp = cp->next;
-      FREE (cp);
+      XFREE (cp);
     }
 }
 
@@ -1321,7 +1321,7 @@ output (void)
 /*   if (semantic_parser) */
   /* This is now unconditional because debugging printouts can use it.  */
   output_gram ();
-  FREE (ritem);
+  XFREE (ritem);
   if (semantic_parser)
     output_stos ();
   output_rule_data ();
