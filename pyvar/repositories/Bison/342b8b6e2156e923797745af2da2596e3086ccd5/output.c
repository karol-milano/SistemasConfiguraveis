@@ -94,7 +94,6 @@
 #include "obstack.h"
 #include "quotearg.h"
 #include "getargs.h"
-#include "xalloc.h"
 #include "files.h"
 #include "gram.h"
 #include "LR0.h"
@@ -109,17 +108,17 @@ extern void berror PARAMS((const char *));
 
 static int nvectors;
 static int nentries;
-static short **froms;
-static short **tos;
-static short *tally;
-static short *width;
-static short *actrow;
-static short *state_count;
-static short *order;
-static short *base;
-static short *pos;
-static short *table;
-static short *check;
+static short **froms = NULL;
+static short **tos = NULL;
+static short *tally = NULL;
+static short *width = NULL;
+static short *actrow = NULL;
+static short *state_count = NULL;
+static short *order = NULL;
+static short *base = NULL;
+static short *pos = NULL;
+static short *table = NULL;
+static short *check = NULL;
 static int lowzero;
 static int high;
 
@@ -129,15 +128,15 @@ struct obstack output_obstack;
 /* FIXME. */
 
 static inline void
-output_table_data (struct obstack *oout, 
-		   short *table_data, 
-		   short first, 
-		   short begin, 
+output_table_data (struct obstack *oout,
+		   short *table_data,
+		   short first,
+		   short begin,
 		   short end)
 {
   int i;
   int j = 1;
-  
+
   obstack_fgrow1 (oout, "%6d", first);
   for (i = begin; i < end; ++i)
     {
@@ -158,19 +157,20 @@ output_table_data (struct obstack *oout,
 static void
 output_token_translations (void)
 {
-  output_table_data (&output_obstack, token_translations, 
+  output_table_data (&output_obstack, token_translations,
 		     0, 1, max_user_token_number + 1);
   muscle_insert ("translate", obstack_finish (&output_obstack));
+  XFREE (token_translations);
 }
 
 
 static void
 output_gram (void)
 {
-  output_table_data (&output_obstack, rrhs, 
+  output_table_data (&output_obstack, rrhs,
 		     0, 1, nrules + 1);
   muscle_insert ("prhs", obstack_finish (&output_obstack));
-  
+
   {
     size_t yyrhs_size = 1;
     short *yyrhs, *sp;
@@ -183,7 +183,7 @@ output_gram (void)
     for (sp = ritem + 1, i = 1; *sp; ++sp, ++i)
       yyrhs[i] = *sp > 0 ? *sp : 0;
 
-    output_table_data (&output_obstack, yyrhs, 
+    output_table_data (&output_obstack, yyrhs,
 		       ritem[0], 1, yyrhs_size);
     muscle_insert ("rhs", obstack_finish (&output_obstack));
 
@@ -200,7 +200,7 @@ output_gram (void)
 static void
 output_stos (void)
 {
-  output_table_data (&output_obstack, accessing_symbol, 
+  output_table_data (&output_obstack, accessing_symbol,
 		     0, 1, nstates);
   muscle_insert ("stos", obstack_finish (&output_obstack));
 }
@@ -275,7 +275,7 @@ output_rule_data (void)
   muscle_insert ("toknum", obstack_finish (&output_obstack));
 
   /* Output YYR1. */
-  output_table_data (&output_obstack, rlhs, 
+  output_table_data (&output_obstack, rlhs,
 		     0, 1, nrules + 1);
   muscle_insert ("r1", obstack_finish (&output_obstack));
   XFREE (rlhs + 1);
@@ -285,7 +285,7 @@ output_rule_data (void)
   for (i = 1; i < nrules; i++)
     short_tab[i] = rrhs[i + 1] - rrhs[i] - 1;
   short_tab[nrules] = nitems - rrhs[nrules] - 1;
-  output_table_data (&output_obstack, short_tab, 
+  output_table_data (&output_obstack, short_tab,
 		     0, 1, nrules + 1);
   muscle_insert ("r2", obstack_finish (&output_obstack));
   XFREE (short_tab);
@@ -534,10 +534,10 @@ token_actions (void)
       save_row (i);
     }
 
-  output_table_data (&output_obstack, yydefact, 
+  output_table_data (&output_obstack, yydefact,
 		     yydefact[0], 1, nstates);
   muscle_insert ("defact", obstack_finish (&output_obstack));
-  
+
   XFREE (actrow);
   XFREE (yydefact);
 }
@@ -675,7 +675,7 @@ goto_actions (void)
       yydefgoto[i - ntokens] = default_state;
     }
 
-  output_table_data (&output_obstack, yydefgoto, 
+  output_table_data (&output_obstack, yydefgoto,
 		     yydefgoto[0], 1, nsyms - ntokens);
   muscle_insert ("defgoto", obstack_finish (&output_obstack));
 
@@ -880,12 +880,12 @@ static void
 output_base (void)
 {
   /* Output pact. */
-  output_table_data (&output_obstack, base, 
+  output_table_data (&output_obstack, base,
 		     base[0], 1, nstates);
   muscle_insert ("pact", obstack_finish (&output_obstack));
 
   /* Output pgoto. */
-  output_table_data (&output_obstack, base, 
+  output_table_data (&output_obstack, base,
 		     base[nstates], nstates + 1, nvectors);
   muscle_insert ("pgoto", obstack_finish (&output_obstack));
 
@@ -896,7 +896,7 @@ output_base (void)
 static void
 output_table (void)
 {
-  output_table_data (&output_obstack, table, 
+  output_table_data (&output_obstack, table,
 		     table[0], 1, high + 1);
   muscle_insert ("table", obstack_finish (&output_obstack));
   XFREE (table);
@@ -906,7 +906,7 @@ output_table (void)
 static void
 output_check (void)
 {
-  output_table_data (&output_obstack, check, 
+  output_table_data (&output_obstack, check,
 		     check[0], 1, high + 1);
   muscle_insert ("check", obstack_finish (&output_obstack));
   XFREE (check);
@@ -1109,7 +1109,7 @@ output (void)
     output_stos ();
   output_rule_data ();
   output_actions ();
-  
+
 #if 0
   if (!no_parser_flag) */
 #endif
