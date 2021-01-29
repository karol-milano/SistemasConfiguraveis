@@ -35,7 +35,7 @@
 static void
 print_token (int extnum, int token)
 {
-  fprintf (foutput, _(" type %d is %s\n"), extnum, tags[token]);
+  obstack_fgrow2 (&output_obstack, _(" type %d is %s\n"), extnum, tags[token]);
 }
 #endif
 
@@ -68,26 +68,26 @@ print_core (int state)
 	sp++;
 
       rule = -(*sp);
-      fprintf (foutput, "    %s  ->  ", tags[rlhs[rule]]);
+      obstack_fgrow1 (&output_obstack, "    %s  ->  ", tags[rlhs[rule]]);
 
       for (sp = ritem + rrhs[rule]; sp < sp1; sp++)
 	{
-	  fprintf (foutput, "%s ", tags[*sp]);
+	  obstack_fgrow1 (&output_obstack, "%s ", tags[*sp]);
 	}
 
-      putc ('.', foutput);
+      obstack_1grow (&output_obstack, '.');
 
       while (*sp > 0)
 	{
-	  fprintf (foutput, " %s", tags[*sp]);
+	  obstack_fgrow1 (&output_obstack, " %s", tags[*sp]);
 	  sp++;
 	}
 
-      fprintf (foutput, _("   (rule %d)"), rule);
-      putc ('\n', foutput);
+      obstack_fgrow1 (&output_obstack, _("   (rule %d)"), rule);
+      obstack_1grow (&output_obstack, '\n');
     }
 
-  putc ('\n', foutput);
+  obstack_1grow (&output_obstack, '\n');
 }
 
 static void
@@ -109,9 +109,9 @@ print_actions (int state)
   if (!shiftp && !redp)
     {
       if (final_state == state)
-	fprintf (foutput, _("    $default\taccept\n"));
+	obstack_sgrow (&output_obstack, _("    $default\taccept\n"));
       else
-	fprintf (foutput, _("    NO ACTIONS\n"));
+	obstack_sgrow (&output_obstack, _("    NO ACTIONS\n"));
       return;
     }
 
@@ -129,14 +129,16 @@ print_actions (int state)
 	  if (ISVAR (symbol))
 	    break;
 	  if (symbol == 0)	/* I.e. strcmp(tags[symbol],"$")==0 */
-	    fprintf (foutput, _("    $   \tgo to state %d\n"), state1);
+	    obstack_fgrow1 (&output_obstack,
+			    _("    $   \tgo to state %d\n"), state1);
 	  else
-	    fprintf (foutput, _("    %-4s\tshift, and go to state %d\n"),
-		     tags[symbol], state1);
+	    obstack_fgrow2 (&output_obstack,
+			    _("    %-4s\tshift, and go to state %d\n"),
+			    tags[symbol], state1);
 	}
 
       if (i > 0)
-	putc ('\n', foutput);
+	obstack_1grow (&output_obstack, '\n');
     }
   else
     {
@@ -155,20 +157,21 @@ print_actions (int state)
 	  if (!errp->errs[j])
 	    continue;
 	  symbol = errp->errs[j];
-	  fprintf (foutput, _("    %-4s\terror (nonassociative)\n"),
+	  obstack_fgrow1 (&output_obstack, _("    %-4s\terror (nonassociative)\n"),
 		   tags[symbol]);
 	}
 
       if (j > 0)
-	putc ('\n', foutput);
+	obstack_1grow (&output_obstack, '\n');
     }
 
   if (consistent[state] && redp)
     {
       rule = redp->rules[0];
       symbol = rlhs[rule];
-      fprintf (foutput, _("    $default\treduce using rule %d (%s)\n\n"),
-	       rule, tags[symbol]);
+      obstack_fgrow2 (&output_obstack,
+		      _("    $default\treduce using rule %d (%s)\n\n"),
+		      rule, tags[symbol]);
     }
   else if (redp)
     {
@@ -183,20 +186,21 @@ print_actions (int state)
 	    continue;
 	  state1 = shiftp->shifts[i];
 	  symbol = accessing_symbol[state1];
-	  fprintf (foutput, _("    %-4s\tgo to state %d\n"), tags[symbol],
-		   state1);
+	  obstack_fgrow2 (&output_obstack,
+			  _("    %-4s\tgo to state %d\n"),
+			  tags[symbol], state1);
 	}
 
-      putc ('\n', foutput);
+      obstack_1grow (&output_obstack, '\n');
     }
 }
 
 static void
 print_state (int state)
 {
-  fputs ("\n\n", foutput);
-  fprintf (foutput, _("state %d"), state);
-  fputs ("\n\n", foutput);
+  obstack_sgrow (&output_obstack, "\n\n");
+  obstack_fgrow1 (&output_obstack, _("state %d"), state);
+  obstack_sgrow (&output_obstack, "\n\n");
   print_core (state);
   print_actions (state);
 }
@@ -205,14 +209,15 @@ print_state (int state)
 | Print information on the whole grammar.  |
 `-----------------------------------------*/
 
-#define END_TEST(end)				\
-  do {						\
-    if (column + strlen(buffer) > (end)) {	\
-      fprintf (foutput, "%s\n   ", buffer);	\
-      column = 3;				\
-      buffer[0] = 0;				\
-    }						\
-  } while (0)
+#define END_TEST(End)						\
+do {								\
+  if (column + strlen(buffer) > (End))				\
+    {								\
+      obstack_fgrow1 (&output_obstack, "%s\n   ", buffer);	\
+      column = 3;						\
+      buffer[0] = 0;						\
+    }								\
+} while (0)
 
 
 static void
@@ -224,28 +229,30 @@ print_grammar (void)
   int column = 0;
 
   /* rule # : LHS -> RHS */
-  putc ('\n', foutput);
-  fputs (_("Grammar"), foutput);
-  putc ('\n', foutput);
+  obstack_1grow (&output_obstack, '\n');
+  obstack_sgrow (&output_obstack, _("Grammar"));
+  obstack_1grow (&output_obstack, '\n');
   for (i = 1; i <= nrules; i++)
     /* Don't print rules disabled in reduce_grammar_tables.  */
     if (rlhs[i] >= 0)
       {
-	fprintf (foutput, _("rule %-4d %s ->"), i, tags[rlhs[i]]);
+	obstack_fgrow2 (&output_obstack,
+			_("rule %-4d %s ->"), i, tags[rlhs[i]]);
 	rule = &ritem[rrhs[i]];
 	if (*rule > 0)
 	  while (*rule > 0)
-	    fprintf (foutput, " %s", tags[*rule++]);
+	    obstack_fgrow1 (&output_obstack, " %s", tags[*rule++]);
 	else
-	  fputs (_("		/* empty */"), foutput);
-	putc ('\n', foutput);
+	  obstack_sgrow (&output_obstack, _("		/* empty */"));
+	obstack_1grow (&output_obstack, '\n');
       }
 
   /* TERMINAL (type #) : rule #s terminal is on RHS */
-  fputs ("\n", foutput);
-  fputs (_("Terminals, with rules where they appear"), foutput);
-  fputs ("\n\n", foutput);
-  fprintf (foutput, "%s (-1)\n", tags[0]);
+  obstack_sgrow (&output_obstack, "\n");
+  obstack_sgrow (&output_obstack,
+		 _("Terminals, with rules where they appear"));
+  obstack_sgrow (&output_obstack, "\n\n");
+  obstack_fgrow1 (&output_obstack, "%s (-1)\n", tags[0]);
   if (translations)
     {
       for (i = 0; i <= max_user_token_number; i++)
@@ -253,34 +260,32 @@ print_grammar (void)
 	  {
 	    buffer[0] = 0;
 	    column = strlen (tags[token_translations[i]]);
-	    fprintf (foutput, "%s", tags[token_translations[i]]);
+	    obstack_sgrow (&output_obstack, tags[token_translations[i]]);
 	    END_TEST (50);
 	    sprintf (buffer, " (%d)", i);
 
 	    for (j = 1; j <= nrules; j++)
-	      {
-		for (rule = &ritem[rrhs[j]]; *rule > 0; rule++)
-		  if (*rule == token_translations[i])
-		    {
-		      END_TEST (65);
-		      sprintf (buffer + strlen (buffer), " %d", j);
-		      break;
-		    }
-	      }
-	    fprintf (foutput, "%s\n", buffer);
+	      for (rule = &ritem[rrhs[j]]; *rule > 0; rule++)
+		if (*rule == token_translations[i])
+		  {
+		    END_TEST (65);
+		    sprintf (buffer + strlen (buffer), " %d", j);
+		    break;
+		  }
+	    obstack_fgrow1 (&output_obstack, "%s\n", buffer);
 	  }
     }
   else
-    for (i = 1; i < ntokens; i++)
-      {
-	buffer[0] = 0;
-	column = strlen (tags[i]);
-	fprintf (foutput, "%s", tags[i]);
-	END_TEST (50);
-	sprintf (buffer, " (%d)", i);
+    {
+      for (i = 1; i < ntokens; i++)
+	{
+	  buffer[0] = 0;
+	  column = strlen (tags[i]);
+	  obstack_sgrow (&output_obstack, tags[i]);
+	  END_TEST (50);
+	  sprintf (buffer, " (%d)", i);
 
-	for (j = 1; j <= nrules; j++)
-	  {
+	  for (j = 1; j <= nrules; j++)
 	    for (rule = &ritem[rrhs[j]]; *rule > 0; rule++)
 	      if (*rule == i)
 		{
@@ -288,13 +293,14 @@ print_grammar (void)
 		  sprintf (buffer + strlen (buffer), " %d", j);
 		  break;
 		}
-	  }
-	fprintf (foutput, "%s\n", buffer);
-      }
+	  obstack_fgrow1 (&output_obstack, "%s\n", buffer);
+	}
+    }
 
-  fputs ("\n", foutput);
-  fputs (_("Nonterminals, with rules where they appear"), foutput);
-  fputs ("\n\n", foutput);
+  obstack_sgrow (&output_obstack, "\n");
+  obstack_sgrow (&output_obstack,
+		 _("Nonterminals, with rules where they appear"));
+  obstack_sgrow (&output_obstack, "\n\n");
   for (i = ntokens; i <= nsyms - 1; i++)
     {
       int left_count = 0, right_count = 0;
@@ -312,7 +318,7 @@ print_grammar (void)
 	}
 
       buffer[0] = 0;
-      fprintf (foutput, "%s", tags[i]);
+      obstack_sgrow (&output_obstack, tags[i]);
       column = strlen (tags[i]);
       sprintf (buffer, " (%d)", i);
       END_TEST (0);
@@ -347,7 +353,7 @@ print_grammar (void)
 		  }
 	    }
 	}
-      fprintf (foutput, "%s\n", buffer);
+      obstack_fgrow1 (&output_obstack, "%s\n", buffer);
     }
 }
 
