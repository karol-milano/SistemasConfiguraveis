@@ -1,22 +1,22 @@
 /* Print information on generated parser, for bison,
-   Copyright (C) 1984, 1986, 1989 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 2000 Free Software Foundation, Inc.
 
-This file is part of Bison, the GNU Compiler Compiler.
+   This file is part of Bison, the GNU Compiler Compiler.
 
-Bison is free software; you can redistribute it and/or modify
-it under the terms of the GNU General Public License as published by
-the Free Software Foundation; either version 2, or (at your option)
-any later version.
+   Bison is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
 
-Bison is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
+   Bison is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
 
-You should have received a copy of the GNU General Public License
-along with Bison; see the file COPYING.  If not, write to
-the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU General Public License
+   along with Bison; see the file COPYING.  If not, write to
+   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
+   Boston, MA 02111-1307, USA.  */
 
 
 #include "system.h"
@@ -38,54 +38,50 @@ extern char any_conflicts;
 extern char *conflicts;
 extern int final_state;
 
-extern void conflict_log PARAMS((void));
-extern void verbose_conflict_log PARAMS((void));
-extern void print_reductions PARAMS((int));
+extern void conflict_log PARAMS ((void));
+extern void verbose_conflict_log PARAMS ((void));
+extern void print_reductions PARAMS ((int));
 
-extern void terse PARAMS((void));
-extern void verbose PARAMS((void));
+extern void terse PARAMS ((void));
+extern void verbose PARAMS ((void));
 
-#if 0                           /* XXX currently unused.  */
-static void print_token PARAMS((int, int));
+#if 0				/* XXX currently unused.  */
+static void print_token PARAMS ((int, int));
 #endif
 
-static void print_state PARAMS((int));
-static void print_core PARAMS((int));
-static void print_actions PARAMS((int));
-static void print_grammar PARAMS((void));
+static void print_state PARAMS ((int));
+static void print_core PARAMS ((int));
+static void print_actions PARAMS ((int));
+static void print_grammar PARAMS ((void));
 
 void
 terse (void)
 {
   if (any_conflicts)
-    {
-      conflict_log();
-    }
+    conflict_log ();
 }
 
 
 void
 verbose (void)
 {
-  register int i;
+  int i;
 
   if (any_conflicts)
-    verbose_conflict_log();
+    verbose_conflict_log ();
 
-  print_grammar();
+  print_grammar ();
 
   for (i = 0; i < nstates; i++)
-    {
-      print_state(i);
-    }
+    print_state (i);
 }
 
 
-#if 0                           /* XXX currently unused.  */
+#if 0				/* XXX currently unused.  */
 static void
 print_token (int extnum, int token)
 {
-  fprintf(foutput, _(" type %d is %s\n"), extnum, tags[token]);
+  fprintf (foutput, _(" type %d is %s\n"), extnum, tags[token]);
 }
 #endif
 
@@ -93,26 +89,27 @@ print_token (int extnum, int token)
 static void
 print_state (int state)
 {
-  fprintf(foutput, _("\n\nstate %d\n\n"), state);
-  print_core(state);
-  print_actions(state);
+  fprintf (foutput, _("\n\nstate %d\n\n"), state);
+  print_core (state);
+  print_actions (state);
 }
 
 
 static void
 print_core (int state)
 {
-  register int i;
-  register int k;
-  register int rule;
-  register core *statep;
-  register short *sp;
-  register short *sp1;
+  int i;
+  int k;
+  int rule;
+  core *statep;
+  short *sp;
+  short *sp1;
 
   statep = state_table[state];
   k = statep->nitems;
 
-  if (k == 0) return;
+  if (k == 0)
+    return;
 
   for (i = 0; i < k; i++)
     {
@@ -122,40 +119,40 @@ print_core (int state)
 	sp++;
 
       rule = -(*sp);
-      fprintf(foutput, "    %s  ->  ", tags[rlhs[rule]]);
+      fprintf (foutput, "    %s  ->  ", tags[rlhs[rule]]);
 
       for (sp = ritem + rrhs[rule]; sp < sp1; sp++)
 	{
-	  fprintf(foutput, "%s ", tags[*sp]);
+	  fprintf (foutput, "%s ", tags[*sp]);
 	}
 
-      putc('.', foutput);
+      putc ('.', foutput);
 
       while (*sp > 0)
 	{
-	  fprintf(foutput, " %s", tags[*sp]);
+	  fprintf (foutput, " %s", tags[*sp]);
 	  sp++;
 	}
 
       fprintf (foutput, _("   (rule %d)"), rule);
-      putc('\n', foutput);
+      putc ('\n', foutput);
     }
 
-  putc('\n', foutput);
+  putc ('\n', foutput);
 }
 
 
 static void
 print_actions (int state)
 {
-  register int i;
-  register int k;
-  register int state1;
-  register int symbol;
-  register shifts *shiftp;
-  register errs *errp;
-  register reductions *redp;
-  register int rule;
+  int i;
+  int k;
+  int state1;
+  int symbol;
+  shifts *shiftp;
+  errs *errp;
+  reductions *redp;
+  int rule;
 
   shiftp = shift_table[state];
   redp = reduction_table[state];
@@ -164,9 +161,9 @@ print_actions (int state)
   if (!shiftp && !redp)
     {
       if (final_state == state)
-	fprintf(foutput, _("    $default\taccept\n"));
+	fprintf (foutput, _("    $default\taccept\n"));
       else
-	fprintf(foutput, _("    NO ACTIONS\n"));
+	fprintf (foutput, _("    NO ACTIONS\n"));
       return;
     }
 
@@ -176,20 +173,22 @@ print_actions (int state)
 
       for (i = 0; i < k; i++)
 	{
-	  if (! shiftp->shifts[i]) continue;
+	  if (!shiftp->shifts[i])
+	    continue;
 	  state1 = shiftp->shifts[i];
 	  symbol = accessing_symbol[state1];
 	  /* The following line used to be turned off.  */
-	  if (ISVAR(symbol)) break;
-          if (symbol==0)      /* I.e. strcmp(tags[symbol],"$")==0 */
-            fprintf(foutput, _("    $   \tgo to state %d\n"), state1);
-          else
-            fprintf(foutput, _("    %-4s\tshift, and go to state %d\n"),
-                    tags[symbol], state1);
+	  if (ISVAR (symbol))
+	    break;
+	  if (symbol == 0)	/* I.e. strcmp(tags[symbol],"$")==0 */
+	    fprintf (foutput, _("    $   \tgo to state %d\n"), state1);
+	  else
+	    fprintf (foutput, _("    %-4s\tshift, and go to state %d\n"),
+		     tags[symbol], state1);
 	}
 
       if (i > 0)
-	putc('\n', foutput);
+	putc ('\n', foutput);
     }
   else
     {
@@ -205,38 +204,42 @@ print_actions (int state)
 
       for (j = 0; j < nerrs; j++)
 	{
-	  if (! errp->errs[j]) continue;
+	  if (!errp->errs[j])
+	    continue;
 	  symbol = errp->errs[j];
-	  fprintf(foutput, _("    %-4s\terror (nonassociative)\n"), tags[symbol]);
+	  fprintf (foutput, _("    %-4s\terror (nonassociative)\n"),
+		   tags[symbol]);
 	}
 
       if (j > 0)
-	putc('\n', foutput);
+	putc ('\n', foutput);
     }
 
   if (consistent[state] && redp)
     {
       rule = redp->rules[0];
       symbol = rlhs[rule];
-      fprintf(foutput, _("    $default\treduce using rule %d (%s)\n\n"),
-     	        rule, tags[symbol]);
+      fprintf (foutput, _("    $default\treduce using rule %d (%s)\n\n"),
+	       rule, tags[symbol]);
     }
   else if (redp)
     {
-      print_reductions(state);
+      print_reductions (state);
     }
 
   if (i < k)
     {
       for (; i < k; i++)
 	{
-	  if (! shiftp->shifts[i]) continue;
+	  if (!shiftp->shifts[i])
+	    continue;
 	  state1 = shiftp->shifts[i];
 	  symbol = accessing_symbol[state1];
-	  fprintf(foutput, _("    %-4s\tgo to state %d\n"), tags[symbol], state1);
+	  fprintf (foutput, _("    %-4s\tgo to state %d\n"), tags[symbol],
+		   state1);
 	}
 
-      putc('\n', foutput);
+      putc ('\n', foutput);
     }
 }
 
@@ -253,29 +256,29 @@ static void
 print_grammar (void)
 {
   int i, j;
-  short* rule;
+  short *rule;
   char buffer[90];
   int column = 0;
 
   /* rule # : LHS -> RHS */
-  fputs(_("\nGrammar\n"), foutput);
+  fputs (_("\nGrammar\n"), foutput);
   for (i = 1; i <= nrules; i++)
     /* Don't print rules disabled in reduce_grammar_tables.  */
     if (rlhs[i] >= 0)
       {
-	fprintf(foutput, _("rule %-4d %s ->"), i, tags[rlhs[i]]);
+	fprintf (foutput, _("rule %-4d %s ->"), i, tags[rlhs[i]]);
 	rule = &ritem[rrhs[i]];
 	if (*rule > 0)
 	  while (*rule > 0)
-	    fprintf(foutput, " %s", tags[*rule++]);
+	    fprintf (foutput, " %s", tags[*rule++]);
 	else
 	  fputs (_("		/* empty */"), foutput);
-	putc('\n', foutput);
+	putc ('\n', foutput);
       }
 
   /* TERMINAL (type #) : rule #s terminal is on RHS */
-  fputs(_("\nTerminals, with rules where they appear\n\n"), foutput);
-  fprintf(foutput, "%s (-1)\n", tags[0]);
+  fputs (_("\nTerminals, with rules where they appear\n\n"), foutput);
+  fprintf (foutput, "%s (-1)\n", tags[0]);
   if (translations)
     {
       for (i = 0; i <= max_user_token_number; i++)
@@ -283,7 +286,7 @@ print_grammar (void)
 	  {
 	    buffer[0] = 0;
 	    column = strlen (tags[token_translations[i]]);
-	    fprintf(foutput, "%s", tags[token_translations[i]]);
+	    fprintf (foutput, "%s", tags[token_translations[i]]);
 	    END_TEST (50);
 	    sprintf (buffer, " (%d)", i);
 
@@ -293,7 +296,7 @@ print_grammar (void)
 		  if (*rule == token_translations[i])
 		    {
 		      END_TEST (65);
-		      sprintf (buffer + strlen(buffer), " %d", j);
+		      sprintf (buffer + strlen (buffer), " %d", j);
 		      break;
 		    }
 	      }
@@ -305,7 +308,7 @@ print_grammar (void)
       {
 	buffer[0] = 0;
 	column = strlen (tags[i]);
-	fprintf(foutput, "%s", tags[i]);
+	fprintf (foutput, "%s", tags[i]);
 	END_TEST (50);
 	sprintf (buffer, " (%d)", i);
 
@@ -315,14 +318,14 @@ print_grammar (void)
 	      if (*rule == i)
 		{
 		  END_TEST (65);
-		  sprintf (buffer + strlen(buffer), " %d", j);
+		  sprintf (buffer + strlen (buffer), " %d", j);
 		  break;
 		}
 	  }
 	fprintf (foutput, "%s\n", buffer);
       }
 
-  fputs(_("\nNonterminals, with rules where they appear\n\n"), foutput);
+  fputs (_("\nNonterminals, with rules where they appear\n\n"), foutput);
   for (i = ntokens; i <= nsyms - 1; i++)
     {
       int left_count = 0, right_count = 0;
@@ -340,7 +343,7 @@ print_grammar (void)
 	}
 
       buffer[0] = 0;
-      fprintf(foutput, "%s", tags[i]);
+      fprintf (foutput, "%s", tags[i]);
       column = strlen (tags[i]);
       sprintf (buffer, " (%d)", i);
       END_TEST (0);
@@ -348,29 +351,29 @@ print_grammar (void)
       if (left_count > 0)
 	{
 	  END_TEST (50);
-	  sprintf (buffer + strlen(buffer), _(" on left:"));
+	  sprintf (buffer + strlen (buffer), _(" on left:"));
 
 	  for (j = 1; j <= nrules; j++)
 	    {
 	      END_TEST (65);
 	      if (rlhs[j] == i)
-		sprintf (buffer + strlen(buffer), " %d", j);
+		sprintf (buffer + strlen (buffer), " %d", j);
 	    }
 	}
 
       if (right_count > 0)
 	{
 	  if (left_count > 0)
-	    sprintf (buffer + strlen(buffer), ",");
+	    sprintf (buffer + strlen (buffer), ",");
 	  END_TEST (50);
-	  sprintf (buffer + strlen(buffer), _(" on right:"));
+	  sprintf (buffer + strlen (buffer), _(" on right:"));
 	  for (j = 1; j <= nrules; j++)
 	    {
 	      for (rule = &ritem[rrhs[j]]; *rule > 0; rule++)
 		if (*rule == i)
 		  {
 		    END_TEST (65);
-		    sprintf (buffer + strlen(buffer), " %d", j);
+		    sprintf (buffer + strlen (buffer), " %d", j);
 		    break;
 		  }
 	    }
