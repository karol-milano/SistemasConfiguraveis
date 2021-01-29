@@ -19,88 +19,75 @@
    02111-1307, USA.  */
 
 
-/* functions to output parsing data to various files.  Entries are:
+/* The parser tables consist of these tables.
+   Starred ones needed only for the semantic parser.
+   Double starred are output only if switches are set.
 
-  output_headers ()
+   yytranslate = vector mapping yylex's token numbers into bison's token
+   numbers.
 
-Output constant strings to the beginning of certain files.
+   ** yytname = vector of string-names indexed by bison token number
 
-  output_trailers()
+   ** yytoknum = vector of yylex token numbers corresponding to entries
+   in yytname
 
-Output constant strings to the ends of certain files.
+   yyrline = vector of line-numbers of all rules.  For yydebug printouts.
 
-  output ()
+   yyrhs = vector of items of all rules.
+   This is exactly what ritems contains.  For yydebug and for semantic
+   parser.
 
-Output the parsing tables and the parser code to ftable.
+   yyprhs[r] = index in yyrhs of first item for rule r.
 
-The parser tables consist of these tables.
-Starred ones needed only for the semantic parser.
-Double starred are output only if switches are set.
+   yyr1[r] = symbol number of symbol that rule r derives.
 
-yytranslate = vector mapping yylex's token numbers into bison's token numbers.
+   yyr2[r] = number of symbols composing right hand side of rule r.
 
-** yytname = vector of string-names indexed by bison token number
+   * yystos[s] = the symbol number of the symbol that leads to state s.
 
-** yytoknum = vector of yylex token numbers corresponding to entries in yytname
+   yydefact[s] = default rule to reduce with in state s,
+   when yytable doesn't specify something else to do.
+   Zero means the default is an error.
 
-yyrline = vector of line-numbers of all rules.  For yydebug printouts.
+   yydefgoto[i] = default state to go to after a reduction of a rule that
+   generates variable ntokens + i, except when yytable
+   specifies something else to do.
 
-yyrhs = vector of items of all rules.
-        This is exactly what ritems contains.  For yydebug and for semantic
-	parser.
+   yypact[s] = index in yytable of the portion describing state s.
+   The lookahead token's type is used to index that portion
+   to find out what to do.
 
-yyprhs[r] = index in yyrhs of first item for rule r.
+   If the value in yytable is positive,
+   we shift the token and go to that state.
 
-yyr1[r] = symbol number of symbol that rule r derives.
+   If the value is negative, it is minus a rule number to reduce by.
 
-yyr2[r] = number of symbols composing right hand side of rule r.
+   If the value is zero, the default action from yydefact[s] is used.
 
-* yystos[s] = the symbol number of the symbol that leads to state s.
+   yypgoto[i] = the index in yytable of the portion describing
+   what to do after reducing a rule that derives variable i + ntokens.
+   This portion is indexed by the parser state number, s,
+   as of before the text for this nonterminal was read.
+   The value from yytable is the state to go to if
+   the corresponding value in yycheck is s.
 
-yydefact[s] = default rule to reduce with in state s,
-	      when yytable doesn't specify something else to do.
-	      Zero means the default is an error.
+   yytable = a vector filled with portions for different uses,
+   found via yypact and yypgoto.
 
-yydefgoto[i] = default state to go to after a reduction of a rule that
-	       generates variable ntokens + i, except when yytable
-	       specifies something else to do.
+   yycheck = a vector indexed in parallel with yytable.
+   It indicates, in a roundabout way, the bounds of the
+   portion you are trying to examine.
 
-yypact[s] = index in yytable of the portion describing state s.
-            The lookahead token's type is used to index that portion
-            to find out what to do.
-
-	    If the value in yytable is positive,
-	    we shift the token and go to that state.
-
-	    If the value is negative, it is minus a rule number to reduce by.
-
-	    If the value is zero, the default action from yydefact[s] is used.
-
-yypgoto[i] = the index in yytable of the portion describing
-             what to do after reducing a rule that derives variable i + ntokens.
-             This portion is indexed by the parser state number, s,
-	     as of before the text for this nonterminal was read.
-	     The value from yytable is the state to go to if
-             the corresponding value in yycheck is s.
-
-yytable = a vector filled with portions for different uses,
-          found via yypact and yypgoto.
-
-yycheck = a vector indexed in parallel with yytable.
-	  It indicates, in a roundabout way, the bounds of the
-	  portion you are trying to examine.
-
-	  Suppose that the portion of yytable starts at index p
-	  and the index to be examined within the portion is i.
-	  Then if yycheck[p+i] != i, i is outside the bounds
-	  of what is actually allocated, and the default
-	  (from yydefact or yydefgoto) should be used.
-	  Otherwise, yytable[p+i] should be used.
-
-YYFINAL = the state number of the termination state.
-YYFLAG = most negative short int.  Used to flag ??
-YYNTBASE = ntokens.
+   Suppose that the portion of yytable starts at index p
+   and the index to be examined within the portion is i.
+   Then if yycheck[p+i] != i, i is outside the bounds
+   of what is actually allocated, and the default
+   (from yydefact or yydefgoto) should be used.
+   Otherwise, yytable[p+i] should be used.
 
+   YYFINAL = the state number of the termination state.
+   YYFLAG = most negative short int.  Used to flag ??
+   YYNTBASE = ntokens.
 */
 
 #include "system.h"
@@ -110,7 +97,7 @@ YYNTBASE = ntokens.
 #include "gram.h"
 #include "state.h"
 #include "complain.h"
-
+#include "output.h"
 
 extern char **tags;
 extern int *user_toknums;
@@ -129,36 +116,6 @@ extern short *goto_map;
 extern short *from_state;
 extern short *to_state;
 
-extern void output_headers PARAMS ((void));
-extern void output_trailers PARAMS ((void));
-extern void output PARAMS ((void));
-
-static void output_token_translations PARAMS ((void));
-static void output_gram PARAMS ((void));
-static void output_stos PARAMS ((void));
-static void output_rule_data PARAMS ((void));
-static void output_defines PARAMS ((void));
-static void output_actions PARAMS ((void));
-static void token_actions PARAMS ((void));
-static void save_row PARAMS ((int));
-static void goto_actions PARAMS ((void));
-static void save_column PARAMS ((int, int));
-static void sort_actions PARAMS ((void));
-static void pack_table PARAMS ((void));
-static void output_base PARAMS ((void));
-static void output_table PARAMS ((void));
-static void output_check PARAMS ((void));
-static void output_parser PARAMS ((void));
-static void output_program PARAMS ((void));
-static void free_shifts PARAMS ((void));
-static void free_reductions PARAMS ((void));
-static void free_itemsets PARAMS ((void));
-static int action_row PARAMS ((int));
-static int default_goto PARAMS ((int));
-static int matching_state PARAMS ((int));
-static int pack_vector PARAMS ((int));
-
-extern void berror PARAMS ((const char *));
 extern void reader_output_yylsp PARAMS ((FILE *));
 
 static int nvectors;
@@ -215,6 +172,10 @@ register YYLTYPE *yylsp;\n\
 #define	ACTSTR_SIMPLE	"\n  switch (yyn) {\n"
 
 
+/*------------------------------------------------------------.
+| Output constant strings to the beginning of certain files.  |
+`------------------------------------------------------------*/
+
 void
 output_headers (void)
 {
@@ -244,6 +205,10 @@ output_headers (void)
 }
 
 
+/*-------------------------------------------------------.
+| Output constant strings to the ends of certain files.  |
+`-------------------------------------------------------*/
+
 void
 output_trailers (void)
 {
@@ -261,65 +226,12 @@ output_trailers (void)
 }
 
 
-void
-output (void)
-{
-  int c;
-
-  /* output_token_defines(ftable);      / * JF put out token defines FIRST */
-  if (!semantic_parser)		/* JF Put out other stuff */
-    {
-      rewind (fattrs);
-      while ((c = getc (fattrs)) != EOF)
-	putc (c, ftable);
-    }
-  reader_output_yylsp (ftable);
-  if (debugflag)
-    fputs ("\
-#ifndef YYDEBUG\n\
-#define YYDEBUG 1\n\
-#endif\n\
-\n",
-	   ftable);
-
-  if (semantic_parser)
-    fprintf (ftable, "#include \"%s\"\n", attrsfile);
-
-  if (!noparserflag)
-    fprintf (ftable, "#include <stdio.h>\n\n");
-
-  /* Make "const" do nothing if not in ANSI C.  */
-  fputs ("\
-#ifndef __cplusplus\n\
-# ifndef __STDC__\n\
-#  define const\n\
-# endif\n\
-#endif\n\
-\n",
-	 ftable);
-
-  free_itemsets ();
-  output_defines ();
-  output_token_translations ();
-/*   if (semantic_parser) */
-  /* This is now unconditional because debugging printouts can use it.  */
-  output_gram ();
-  FREE (ritem);
-  if (semantic_parser)
-    output_stos ();
-  output_rule_data ();
-  output_actions ();
-  if (!noparserflag)
-    output_parser ();
-  output_program ();
-}
-
 
 static void
 output_token_translations (void)
 {
-  register int i, j;
-/*   register short *sp; JF unused */
+  int i, j;
+/*   short *sp; JF unused */
 
   if (translations)
     {
@@ -362,9 +274,9 @@ output_token_translations (void)
 static void
 output_gram (void)
 {
-  register int i;
-  register int j;
-  register short *sp;
+  int i;
+  int j;
+  short *sp;
 
   /* With the ordinary parser,
      yyprhs and yyrhs are needed only for yydebug. */
@@ -427,8 +339,8 @@ output_gram (void)
 static void
 output_stos (void)
 {
-  register int i;
-  register int j;
+  int i;
+  int j;
 
   fprintf (ftable, "\nstatic const short yystos[] = {     0");
 
@@ -457,8 +369,8 @@ output_stos (void)
 static void
 output_rule_data (void)
 {
-  register int i;
-  register int j;
+  int i;
+  int j;
 
   fputs ("\n\
 #if YYDEBUG != 0\n\
@@ -506,7 +418,7 @@ static const short yyrline[] = { 0", ftable);
     /* this used to be i<=nsyms, but that output a final "" symbol
        almost by accident */
     {
-      register char *p;
+      char *p;
       putc (',', ftable);
       j++;
 
@@ -649,118 +561,40 @@ output_defines (void)
 }
 
 
-
-/* compute and output yydefact, yydefgoto, yypact, yypgoto, yytable and yycheck.  */
-
-static void
-output_actions (void)
-{
-  nvectors = nstates + nvars;
-
-  froms = NEW2 (nvectors, short *);
-  tos = NEW2 (nvectors, short *);
-  tally = NEW2 (nvectors, short);
-  width = NEW2 (nvectors, short);
-
-  token_actions ();
-  free_shifts ();
-  free_reductions ();
-  FREE (lookaheads);
-  FREE (LA);
-  FREE (LAruleno);
-  FREE (accessing_symbol);
-
-  goto_actions ();
-  FREE (goto_map + ntokens);
-  FREE (from_state);
-  FREE (to_state);
-
-  sort_actions ();
-  pack_table ();
-  output_base ();
-  output_table ();
-  output_check ();
-}
-
-
-
-/* Figure out the actions for the specified state, indexed by
-   lookahead token type.
-
-   The yydefact table is output now.  The detailed info is saved for
-   putting into yytable later.  */
-
-static void
-token_actions (void)
-{
-  register int i;
-  register int j;
-  register int k;
-
-  actrow = NEW2 (ntokens, short);
-
-  k = action_row (0);
-  fprintf (ftable, "\nstatic const short yydefact[] = {%6d", k);
-  save_row (0);
-
-  j = 10;
-  for (i = 1; i < nstates; i++)
-    {
-      putc (',', ftable);
-
-      if (j >= 10)
-	{
-	  putc ('\n', ftable);
-	  j = 1;
-	}
-      else
-	{
-	  j++;
-	}
-
-      k = action_row (i);
-      fprintf (ftable, "%6d", k);
-      save_row (i);
-    }
-
-  fprintf (ftable, "\n};\n");
-  FREE (actrow);
-}
-
-
-
-/* Decide what to do for each type of token if seen as the lookahead
-   token in specified state.  The value returned is used as the
-   default action (yydefact) for the state.  In addition, actrow is
-   filled with what to do for each kind of token, index by symbol
-   number, with zero meaning do the default action.  The value
-   MINSHORT, a very negative number, means this situation is an error.
-   The parser recognizes this value specially.
-
-   This is where conflicts are resolved.  The loop over lookahead
-   rules considered lower-numbered rules last, and the last rule
-   considered that likes a token gets to handle it.  */
+/*------------------------------------------------------------------.
+| Decide what to do for each type of token if seen as the lookahead |
+| token in specified state.  The value returned is used as the      |
+| default action (yydefact) for the state.  In addition, actrow is  |
+| filled with what to do for each kind of token, index by symbol    |
+| number, with zero meaning do the default action.  The value       |
+| MINSHORT, a very negative number, means this situation is an      |
+| error.  The parser recognizes this value specially.               |
+|                                                                   |
+| This is where conflicts are resolved.  The loop over lookahead    |
+| rules considered lower-numbered rules last, and the last rule     |
+| considered that likes a token gets to handle it.                  |
+`------------------------------------------------------------------*/
 
 static int
 action_row (int state)
 {
-  register int i;
-  register int j;
-  register int k;
-  register int m = 0;
-  register int n = 0;
-  register int count;
-  register int default_rule;
-  register int nreds;
-  register int max;
-  register int rule;
-  register int shift_state;
-  register int symbol;
-  register unsigned mask;
-  register unsigned *wordp;
-  register reductions *redp;
-  register shifts *shiftp;
-  register errs *errp;
+  int i;
+  int j;
+  int k;
+  int m = 0;
+  int n = 0;
+  int count;
+  int default_rule;
+  int nreds;
+  int max;
+  int rule;
+  int shift_state;
+  int symbol;
+  unsigned mask;
+  unsigned *wordp;
+  reductions *redp;
+  shifts *shiftp;
+  errs *errp;
   int nodefault = 0;		/* set nonzero to inhibit having any default reduction */
 
   for (i = 0; i < ntokens; i++)
@@ -914,11 +748,11 @@ action_row (int state)
 static void
 save_row (int state)
 {
-  register int i;
-  register int count;
-  register short *sp;
-  register short *sp1;
-  register short *sp2;
+  int i;
+  int count;
+  short *sp;
+  short *sp1;
+  short *sp2;
 
   count = 0;
   for (i = 0; i < ntokens; i++)
@@ -947,29 +781,29 @@ save_row (int state)
 }
 
 
-
-/* figure out what to do after reducing with each rule,
-   depending on the saved state from before the beginning
-   of parsing the data that matched this rule.
-
-   The yydefgoto table is output now.  The detailed info
-   is saved for putting into yytable later.  */
+/*------------------------------------------------------------------.
+| Figure out the actions for the specified state, indexed by        |
+| lookahead token type.                                             |
+|                                                                   |
+| The yydefact table is output now.  The detailed info is saved for |
+| putting into yytable later.                                       |
+`------------------------------------------------------------------*/
 
 static void
-goto_actions (void)
+token_actions (void)
 {
-  register int i;
-  register int j;
-  register int k;
+  int i;
+  int j;
+  int k;
 
-  state_count = NEW2 (nstates, short);
+  actrow = NEW2 (ntokens, short);
 
-  k = default_goto (ntokens);
-  fprintf (ftable, "\nstatic const short yydefgoto[] = {%6d", k);
-  save_column (ntokens, k);
+  k = action_row (0);
+  fprintf (ftable, "\nstatic const short yydefact[] = {%6d", k);
+  save_row (0);
 
   j = 10;
-  for (i = ntokens + 1; i < nsyms; i++)
+  for (i = 1; i < nstates; i++)
     {
       putc (',', ftable);
 
@@ -983,65 +817,58 @@ goto_actions (void)
 	  j++;
 	}
 
-      k = default_goto (i);
+      k = action_row (i);
       fprintf (ftable, "%6d", k);
-      save_column (i, k);
+      save_row (i);
     }
 
   fprintf (ftable, "\n};\n");
-  FREE (state_count);
+  FREE (actrow);
 }
 
 
-
-static int
-default_goto (int symbol)
+static void
+free_shifts (void)
 {
-  register int i;
-  register int m;
-  register int n;
-  register int default_state;
-  register int max;
+  shifts *sp, *sptmp;	/* JF derefrenced freed ptr */
 
-  m = goto_map[symbol];
-  n = goto_map[symbol + 1];
+  FREE (shift_table);
 
-  if (m == n)
-    return -1;
+  for (sp = first_shift; sp; sp = sptmp)
+    {
+      sptmp = sp->next;
+      FREE (sp);
+    }
+}
 
-  for (i = 0; i < nstates; i++)
-    state_count[i] = 0;
 
-  for (i = m; i < n; i++)
-    state_count[to_state[i]]++;
+static void
+free_reductions (void)
+{
+  reductions *rp, *rptmp;	/* JF fixed freed ptr */
 
-  max = 0;
-  default_state = -1;
+  FREE (reduction_table);
 
-  for (i = 0; i < nstates; i++)
+  for (rp = first_reduction; rp; rp = rptmp)
     {
-      if (state_count[i] > max)
-	{
-	  max = state_count[i];
-	  default_state = i;
-	}
+      rptmp = rp->next;
+      FREE (rp);
     }
-
-  return default_state;
 }
 
 
+
 static void
 save_column (int symbol, int default_state)
 {
-  register int i;
-  register int m;
-  register int n;
-  register short *sp;
-  register short *sp1;
-  register short *sp2;
-  register int count;
-  register int symno;
+  int i;
+  int m;
+  int n;
+  short *sp;
+  short *sp1;
+  short *sp2;
+  int count;
+  int symno;
 
   m = goto_map[symbol];
   n = goto_map[symbol + 1];
@@ -1074,6 +901,86 @@ save_column (int symbol, int default_state)
   width[symno] = sp1[-1] - sp[0] + 1;
 }
 
+static int
+default_goto (int symbol)
+{
+  int i;
+  int m;
+  int n;
+  int default_state;
+  int max;
+
+  m = goto_map[symbol];
+  n = goto_map[symbol + 1];
+
+  if (m == n)
+    return -1;
+
+  for (i = 0; i < nstates; i++)
+    state_count[i] = 0;
+
+  for (i = m; i < n; i++)
+    state_count[to_state[i]]++;
+
+  max = 0;
+  default_state = -1;
+
+  for (i = 0; i < nstates; i++)
+    {
+      if (state_count[i] > max)
+	{
+	  max = state_count[i];
+	  default_state = i;
+	}
+    }
+
+  return default_state;
+}
+
+
+/*-------------------------------------------------------------------.
+| Figure out what to do after reducing with each rule, depending on  |
+| the saved state from before the beginning of parsing the data that |
+| matched this rule.                                                 |
+|                                                                    |
+| The YYDEFGOTO table is output now.  The detailed info is saved for |
+| putting into YYTABLE later.                                        |
+`-------------------------------------------------------------------*/
+
+static void
+goto_actions (void)
+{
+  int i, j, k;
+
+  state_count = NEW2 (nstates, short);
+
+  k = default_goto (ntokens);
+  fprintf (ftable, "\nstatic const short yydefgoto[] = {%6d", k);
+  save_column (ntokens, k);
+
+  j = 10;
+  for (i = ntokens + 1; i < nsyms; i++)
+    {
+      putc (',', ftable);
+
+      if (j >= 10)
+	{
+	  putc ('\n', ftable);
+	  j = 1;
+	}
+      else
+	{
+	  j++;
+	}
+
+      k = default_goto (i);
+      fprintf (ftable, "%6d", k);
+      save_column (i, k);
+    }
+
+  fprintf (ftable, "\n};\n");
+  FREE (state_count);
+}
 
 
 /* The next few functions decide how to pack the actions and gotos
@@ -1082,11 +989,11 @@ save_column (int symbol, int default_state)
 static void
 sort_actions (void)
 {
-  register int i;
-  register int j;
-  register int k;
-  register int t;
-  register int w;
+  int i;
+  int j;
+  int k;
+  int t;
+  int w;
 
   order = NEW2 (nvectors, short);
   nentries = 0;
@@ -1115,65 +1022,16 @@ sort_actions (void)
 }
 
 
-static void
-pack_table (void)
-{
-  register int i;
-  register int place;
-  register int state;
-
-  base = NEW2 (nvectors, short);
-  pos = NEW2 (nentries, short);
-  table = NEW2 (MAXTABLE, short);
-  check = NEW2 (MAXTABLE, short);
-
-  lowzero = 0;
-  high = 0;
-
-  for (i = 0; i < nvectors; i++)
-    base[i] = MINSHORT;
-
-  for (i = 0; i < MAXTABLE; i++)
-    check[i] = -1;
-
-  for (i = 0; i < nentries; i++)
-    {
-      state = matching_state (i);
-
-      if (state < 0)
-	place = pack_vector (i);
-      else
-	place = base[state];
-
-      pos[i] = place;
-      base[order[i]] = place;
-    }
-
-  for (i = 0; i < nvectors; i++)
-    {
-      if (froms[i])
-	FREE (froms[i]);
-      if (tos[i])
-	FREE (tos[i]);
-    }
-
-  FREE (froms);
-  FREE (tos);
-  FREE (pos);
-}
-
-
-
 static int
 matching_state (int vector)
 {
-  register int i;
-  register int j;
-  register int k;
-  register int t;
-  register int w;
-  register int match;
-  register int prev;
+  int i;
+  int j;
+  int k;
+  int t;
+  int w;
+  int match;
+  int prev;
 
   i = order[vector];
   if (i >= nstates)
@@ -1203,18 +1061,17 @@ matching_state (int vector)
 }
 
 
-
 static int
 pack_vector (int vector)
 {
-  register int i;
-  register int j;
-  register int k;
-  register int t;
-  register int loc = 0;
-  register int ok;
-  register short *from;
-  register short *to;
+  int i;
+  int j;
+  int k;
+  int t;
+  int loc = 0;
+  int ok;
+  short *from;
+  short *to;
 
   i = order[vector];
   t = tally[i];
@@ -1269,6 +1126,52 @@ pack_vector (int vector)
 }
 
 
+static void
+pack_table (void)
+{
+  int i;
+  int place;
+  int state;
+
+  base = NEW2 (nvectors, short);
+  pos = NEW2 (nentries, short);
+  table = NEW2 (MAXTABLE, short);
+  check = NEW2 (MAXTABLE, short);
+
+  lowzero = 0;
+  high = 0;
+
+  for (i = 0; i < nvectors; i++)
+    base[i] = MINSHORT;
+
+  for (i = 0; i < MAXTABLE; i++)
+    check[i] = -1;
+
+  for (i = 0; i < nentries; i++)
+    {
+      state = matching_state (i);
+
+      if (state < 0)
+	place = pack_vector (i);
+      else
+	place = base[state];
+
+      pos[i] = place;
+      base[order[i]] = place;
+    }
+
+  for (i = 0; i < nvectors; i++)
+    {
+      if (froms[i])
+	FREE (froms[i]);
+      if (tos[i])
+	FREE (tos[i]);
+    }
+
+  FREE (froms);
+  FREE (tos);
+  FREE (pos);
+}
 
 /* the following functions output yytable, yycheck
    and the vectors whose elements index the portion starts */
@@ -1276,8 +1179,8 @@ pack_vector (int vector)
 static void
 output_base (void)
 {
-  register int i;
-  register int j;
+  int i;
+  int j;
 
   fprintf (ftable, "\nstatic const short yypact[] = {%6d", base[0]);
 
@@ -1328,8 +1231,8 @@ output_base (void)
 static void
 output_table (void)
 {
-  register int i;
-  register int j;
+  int i;
+  int j;
 
   fprintf (ftable, "\n\n#define\tYYLAST\t\t%d\n\n", high);
   fprintf (ftable, "\nstatic const short yytable[] = {%6d", table[0]);
@@ -1360,8 +1263,8 @@ output_table (void)
 static void
 output_check (void)
 {
-  register int i;
-  register int j;
+  int i;
+  int j;
 
   fprintf (ftable, "\nstatic const short yycheck[] = {%6d", check[0]);
 
@@ -1387,14 +1290,45 @@ output_check (void)
   FREE (check);
 }
 
+/* compute and output yydefact, yydefgoto, yypact, yypgoto, yytable
+   and yycheck.  */
+
+static void
+output_actions (void)
+{
+  nvectors = nstates + nvars;
 
+  froms = NEW2 (nvectors, short *);
+  tos = NEW2 (nvectors, short *);
+  tally = NEW2 (nvectors, short);
+  width = NEW2 (nvectors, short);
+
+  token_actions ();
+  free_shifts ();
+  free_reductions ();
+  FREE (lookaheads);
+  FREE (LA);
+  FREE (LAruleno);
+  FREE (accessing_symbol);
+
+  goto_actions ();
+  FREE (goto_map + ntokens);
+  FREE (from_state);
+  FREE (to_state);
+
+  sort_actions ();
+  pack_table ();
+  output_base ();
+  output_table ();
+  output_check ();
+}
 
 /* copy the parser code into the ftable file at the end.  */
 
 static void
 output_parser (void)
 {
-  register int c;
+  int c;
 #ifdef DONTDEF
   FILE *fpars;
 #else
@@ -1474,7 +1408,7 @@ output_parser (void)
 static void
 output_program (void)
 {
-  register int c;
+  int c;
 
   if (!nolinesflag)
     fprintf (ftable, "#line %d \"%s\"\n", lineno, infile);
@@ -1491,7 +1425,7 @@ output_program (void)
 static void
 free_itemsets (void)
 {
-  register core *cp, *cptmp;
+  core *cp, *cptmp;
 
   FREE (state_table);
 
@@ -1503,31 +1437,59 @@ free_itemsets (void)
 }
 
 
-static void
-free_shifts (void)
-{
-  register shifts *sp, *sptmp;	/* JF derefrenced freed ptr */
+/*----------------------------------------------------------.
+| Output the parsing tables and the parser code to ftable.  |
+`----------------------------------------------------------*/
 
-  FREE (shift_table);
+void
+output (void)
+{
+  int c;
 
-  for (sp = first_shift; sp; sp = sptmp)
+  /* output_token_defines(ftable);      / * JF put out token defines FIRST */
+  if (!semantic_parser)		/* JF Put out other stuff */
     {
-      sptmp = sp->next;
-      FREE (sp);
+      rewind (fattrs);
+      while ((c = getc (fattrs)) != EOF)
+	putc (c, ftable);
     }
-}
+  reader_output_yylsp (ftable);
+  if (debugflag)
+    fputs ("\
+#ifndef YYDEBUG\n\
+#define YYDEBUG 1\n\
+#endif\n\
+\n",
+	   ftable);
 
+  if (semantic_parser)
+    fprintf (ftable, "#include \"%s\"\n", attrsfile);
 
-static void
-free_reductions (void)
-{
-  register reductions *rp, *rptmp;	/* JF fixed freed ptr */
+  if (!noparserflag)
+    fprintf (ftable, "#include <stdio.h>\n\n");
 
-  FREE (reduction_table);
+  /* Make "const" do nothing if not in ANSI C.  */
+  fputs ("\
+#ifndef __cplusplus\n\
+# ifndef __STDC__\n\
+#  define const\n\
+# endif\n\
+#endif\n\
+\n",
+	 ftable);
 
-  for (rp = first_reduction; rp; rp = rptmp)
-    {
-      rptmp = rp->next;
-      FREE (rp);
-    }
+  free_itemsets ();
+  output_defines ();
+  output_token_translations ();
+/*   if (semantic_parser) */
+  /* This is now unconditional because debugging printouts can use it.  */
+  output_gram ();
+  FREE (ritem);
+  if (semantic_parser)
+    output_stos ();
+  output_rule_data ();
+  output_actions ();
+  if (!noparserflag)
+    output_parser ();
+  output_program ();
 }
