@@ -20,7 +20,6 @@
 
 
 #include "system.h"
-#include "xalloc.h"
 #include "files.h"
 #include "gram.h"
 #include "LR0.h"
@@ -35,17 +34,17 @@
 static void
 print_token (int extnum, int token)
 {
-  obstack_fgrow2 (&output_obstack, _(" type %d is %s\n"), extnum, tags[token]);
+  fprintf (out, _(" type %d is %s\n"), extnum, tags[token]);
 }
 #endif
 
 
-/*================================\
+/*--------------------------------.
 | Report information on a state.  |
-\================================*/
+`--------------------------------*/
 
 static void
-print_core (int state)
+print_core (FILE *out, int state)
 {
   int i;
   int k;
@@ -68,30 +67,30 @@ print_core (int state)
 	sp++;
 
       rule = -(*sp);
-      obstack_fgrow1 (&output_obstack, "    %s  ->  ", tags[rlhs[rule]]);
+      fprintf (out, "    %s  ->  ", tags[rlhs[rule]]);
 
       for (sp = ritem + rrhs[rule]; sp < sp1; sp++)
 	{
-	  obstack_fgrow1 (&output_obstack, "%s ", tags[*sp]);
+	  fprintf (out, "%s ", tags[*sp]);
 	}
 
-      obstack_1grow (&output_obstack, '.');
+      fputc ('.', out);
 
       while (*sp > 0)
 	{
-	  obstack_fgrow1 (&output_obstack, " %s", tags[*sp]);
+	  fprintf (out, " %s", tags[*sp]);
 	  sp++;
 	}
 
-      obstack_fgrow1 (&output_obstack, _("   (rule %d)"), rule);
-      obstack_1grow (&output_obstack, '\n');
+      fprintf (out, _("   (rule %d)"), rule);
+      fputc ('\n', out);
     }
 
-  obstack_1grow (&output_obstack, '\n');
+  fputc ('\n', out);
 }
 
 static void
-print_actions (int state)
+print_actions (FILE *out, int state)
 {
   int i;
   int k;
@@ -109,9 +108,9 @@ print_actions (int state)
   if (!shiftp && !redp)
     {
       if (final_state == state)
-	obstack_sgrow (&output_obstack, _("    $default\taccept\n"));
+	fprintf (out, _("    $default\taccept\n"));
       else
-	obstack_sgrow (&output_obstack, _("    NO ACTIONS\n"));
+	fprintf (out, _("    NO ACTIONS\n"));
       return;
     }
 
@@ -129,16 +128,16 @@ print_actions (int state)
 	  if (ISVAR (symbol))
 	    break;
 	  if (symbol == 0)	/* I.e. strcmp(tags[symbol],"$")==0 */
-	    obstack_fgrow1 (&output_obstack,
-			    _("    $   \tgo to state %d\n"), state1);
+	    fprintf (out,
+		     _("    $   \tgo to state %d\n"), state1);
 	  else
-	    obstack_fgrow2 (&output_obstack,
-			    _("    %-4s\tshift, and go to state %d\n"),
-			    tags[symbol], state1);
+	    fprintf (out,
+		     _("    %-4s\tshift, and go to state %d\n"),
+		     tags[symbol], state1);
 	}
 
       if (i > 0)
-	obstack_1grow (&output_obstack, '\n');
+	fputc ('\n', out);
     }
   else
     {
@@ -157,21 +156,20 @@ print_actions (int state)
 	  if (!errp->errs[j])
 	    continue;
 	  symbol = errp->errs[j];
-	  obstack_fgrow1 (&output_obstack, _("    %-4s\terror (nonassociative)\n"),
+	  fprintf (out, _("    %-4s\terror (nonassociative)\n"),
 		   tags[symbol]);
 	}
 
       if (j > 0)
-	obstack_1grow (&output_obstack, '\n');
+	fputc ('\n', out);
     }
 
   if (consistent[state] && redp)
     {
       rule = redp->rules[0];
       symbol = rlhs[rule];
-      obstack_fgrow2 (&output_obstack,
-		      _("    $default\treduce using rule %d (%s)\n\n"),
-		      rule, tags[symbol]);
+      fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
+	       rule, tags[symbol]);
     }
   else if (redp)
     {
@@ -186,42 +184,41 @@ print_actions (int state)
 	    continue;
 	  state1 = shiftp->shifts[i];
 	  symbol = accessing_symbol[state1];
-	  obstack_fgrow2 (&output_obstack,
-			  _("    %-4s\tgo to state %d\n"),
-			  tags[symbol], state1);
+	  fprintf (out, _("    %-4s\tgo to state %d\n"),
+		   tags[symbol], state1);
 	}
 
-      obstack_1grow (&output_obstack, '\n');
+      fputc ('\n', out);
     }
 }
 
 static void
-print_state (int state)
+print_state (FILE *out, int state)
 {
-  obstack_sgrow (&output_obstack, "\n\n");
-  obstack_fgrow1 (&output_obstack, _("state %d"), state);
-  obstack_sgrow (&output_obstack, "\n\n");
-  print_core (state);
-  print_actions (state);
+  fputs ("\n\n", out);
+  fprintf (out, _("state %d"), state);
+  fputs ("\n\n", out);
+  print_core (out, state);
+  print_actions (out, state);
 }
 
 /*-----------------------------------------.
 | Print information on the whole grammar.  |
 `-----------------------------------------*/
 
-#define END_TEST(End)						\
-do {								\
-  if (column + strlen(buffer) > (End))				\
-    {								\
-      obstack_fgrow1 (&output_obstack, "%s\n   ", buffer);	\
-      column = 3;						\
-      buffer[0] = 0;						\
-    }								\
+#define END_TEST(End)				\
+do {						\
+  if (column + strlen(buffer) > (End))		\
+    {						\
+      fprintf (out, "%s\n   ", buffer);		\
+      column = 3;				\
+      buffer[0] = 0;				\
+    }						\
 } while (0)
 
 
 static void
-print_grammar (void)
+print_grammar (FILE *out)
 {
   int i, j;
   short *rule;
@@ -229,78 +226,46 @@ print_grammar (void)
   int column = 0;
 
   /* rule # : LHS -> RHS */
-  obstack_1grow (&output_obstack, '\n');
-  obstack_sgrow (&output_obstack, _("Grammar"));
-  obstack_1grow (&output_obstack, '\n');
+  fprintf (out, "\n%s\n", _("Grammar"));
   for (i = 1; i <= nrules; i++)
     /* Don't print rules disabled in reduce_grammar_tables.  */
     if (rlhs[i] >= 0)
       {
-	obstack_fgrow2 (&output_obstack,
-			_("rule %-4d %s ->"), i, tags[rlhs[i]]);
+	fprintf (out, _("rule %-4d %s ->"), i, tags[rlhs[i]]);
 	rule = &ritem[rrhs[i]];
 	if (*rule > 0)
 	  while (*rule > 0)
-	    obstack_fgrow1 (&output_obstack, " %s", tags[*rule++]);
+	    fprintf (out, " %s", tags[*rule++]);
 	else
-	  obstack_sgrow (&output_obstack, _("		/* empty */"));
-	obstack_1grow (&output_obstack, '\n');
+	  fprintf (out, "		/* %s */\n", _("empty"));
       }
 
   /* TERMINAL (type #) : rule #s terminal is on RHS */
-  obstack_sgrow (&output_obstack, "\n");
-  obstack_sgrow (&output_obstack,
-		 _("Terminals, with rules where they appear"));
-  obstack_sgrow (&output_obstack, "\n\n");
-  obstack_fgrow1 (&output_obstack, "%s (-1)\n", tags[0]);
-  if (translations)
-    {
-      for (i = 0; i <= max_user_token_number; i++)
-	if (token_translations[i] != 2)
-	  {
-	    buffer[0] = 0;
-	    column = strlen (tags[token_translations[i]]);
-	    obstack_sgrow (&output_obstack, tags[token_translations[i]]);
-	    END_TEST (50);
-	    sprintf (buffer, " (%d)", i);
-
-	    for (j = 1; j <= nrules; j++)
-	      for (rule = &ritem[rrhs[j]]; *rule > 0; rule++)
-		if (*rule == token_translations[i])
-		  {
-		    END_TEST (65);
-		    sprintf (buffer + strlen (buffer), " %d", j);
-		    break;
-		  }
-	    obstack_fgrow1 (&output_obstack, "%s\n", buffer);
-	  }
-    }
-  else
-    {
-      for (i = 1; i < ntokens; i++)
-	{
-	  buffer[0] = 0;
-	  column = strlen (tags[i]);
-	  obstack_sgrow (&output_obstack, tags[i]);
-	  END_TEST (50);
-	  sprintf (buffer, " (%d)", i);
+  fprintf (out, "\n%s\n\n", _("Terminals, with rules where they appear"));
+  fprintf (out, "%s (-1)\n", tags[0]);
 
-	  for (j = 1; j <= nrules; j++)
-	    for (rule = &ritem[rrhs[j]]; *rule > 0; rule++)
-	      if (*rule == i)
-		{
-		  END_TEST (65);
-		  sprintf (buffer + strlen (buffer), " %d", j);
-		  break;
-		}
-	  obstack_fgrow1 (&output_obstack, "%s\n", buffer);
-	}
-    }
+  for (i = 0; i <= max_user_token_number; i++)
+    if (token_translations[i] != 2)
+      {
+	buffer[0] = 0;
+	column = strlen (tags[token_translations[i]]);
+	fputs (tags[token_translations[i]], out);
+	END_TEST (50);
+	sprintf (buffer, " (%d)", i);
 
-  obstack_sgrow (&output_obstack, "\n");
-  obstack_sgrow (&output_obstack,
-		 _("Nonterminals, with rules where they appear"));
-  obstack_sgrow (&output_obstack, "\n\n");
+	for (j = 1; j <= nrules; j++)
+	  for (rule = &ritem[rrhs[j]]; *rule > 0; rule++)
+	    if (*rule == token_translations[i])
+	      {
+		END_TEST (65);
+		sprintf (buffer + strlen (buffer), " %d", j);
+		break;
+	      }
+	fprintf (out, "%s\n", buffer);
+      }
+
+  fprintf (out, "\n%s\n\n",
+	   _("Nonterminals, with rules where they appear"));
   for (i = ntokens; i <= nsyms - 1; i++)
     {
       int left_count = 0, right_count = 0;
@@ -318,7 +283,7 @@ print_grammar (void)
 	}
 
       buffer[0] = 0;
-      obstack_sgrow (&output_obstack, tags[i]);
+      fputs (tags[i], out);
       column = strlen (tags[i]);
       sprintf (buffer, " (%d)", i);
       END_TEST (0);
@@ -353,22 +318,33 @@ print_grammar (void)
 		  }
 	    }
 	}
-      obstack_fgrow1 (&output_obstack, "%s\n", buffer);
+      fprintf (out, "%s\n", buffer);
     }
 }
 
 void
 print_results (void)
 {
-  int i;
+  if (verbose_flag)
+    {
+      int i;
 
-  if (any_conflicts)
-    print_conflicts ();
+      /* We used to use just .out if spec_name_prefix (-p) was used, but
+	 that conflicts with Posix.  */
+      FILE *out = xfopen (spec_verbose_file, "w");
 
-  if (verbose_flag)
-    print_grammar ();
+      size_t size = obstack_object_size (&output_obstack);
+      fwrite (obstack_finish (&output_obstack), 1, size, out);
 
-  if (verbose_flag)
-    for (i = 0; i < nstates; i++)
-      print_state (i);
+      if (any_conflicts)
+	print_conflicts (out);
+
+      print_grammar (out);
+
+      for (i = 0; i < nstates; i++)
+	print_state (out, i);
+
+      xfclose (out);
+    }
+  obstack_free (&output_obstack, NULL);
 }
