@@ -54,51 +54,51 @@ static struct obstack format_obstack;
 `-------------------------------------------------------------------*/
 
 
-#define GENERATE_MUSCLE_INSERT_TABLE(Name, Type)			\
-									\
-static void								\
-Name (char const *name,							\
-      Type *table_data,							\
-      Type first,							\
-      int begin,							\
-      int end)								\
-{									\
-  Type min = first;							\
-  Type max = first;							\
-  long int lmin;							\
-  long int lmax;							\
-  int i;								\
-  int j = 1;								\
-									\
-  obstack_fgrow1 (&format_obstack, "%6d", first);			\
-  for (i = begin; i < end; ++i)						\
-    {									\
-      obstack_1grow (&format_obstack, ',');				\
-      if (j >= 10)							\
-	{								\
-	  obstack_sgrow (&format_obstack, "\n  ");			\
-	  j = 1;							\
-	}								\
-      else								\
-	++j;								\
-      obstack_fgrow1 (&format_obstack, "%6d", table_data[i]);		\
-      if (table_data[i] < min)						\
-	min = table_data[i];						\
-      if (max < table_data[i])						\
-	max = table_data[i];						\
-    }									\
-  obstack_1grow (&format_obstack, 0);					\
-  muscle_insert (name, obstack_finish (&format_obstack));		\
-									\
-  lmin = min;								\
-  lmax = max;								\
-  /* Build `NAME_min' and `NAME_max' in the obstack. */			\
-  obstack_fgrow1 (&format_obstack, "%s_min", name);			\
-  obstack_1grow (&format_obstack, 0);					\
-  MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack), lmin);	\
-  obstack_fgrow1 (&format_obstack, "%s_max", name);			\
-  obstack_1grow (&format_obstack, 0);					\
-  MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack), lmax);	\
+#define GENERATE_MUSCLE_INSERT_TABLE(Name, Type)                        \
+                                                                        \
+static void                                                             \
+Name (char const *name,                                                 \
+      Type *table_data,                                                 \
+      Type first,                                                       \
+      int begin,                                                        \
+      int end)                                                          \
+{                                                                       \
+  Type min = first;                                                     \
+  Type max = first;                                                     \
+  long int lmin;                                                        \
+  long int lmax;                                                        \
+  int i;                                                                \
+  int j = 1;                                                            \
+                                                                        \
+  obstack_fgrow1 (&format_obstack, "%6d", first);                       \
+  for (i = begin; i < end; ++i)                                         \
+    {                                                                   \
+      obstack_1grow (&format_obstack, ',');                             \
+      if (j >= 10)                                                      \
+        {                                                               \
+          obstack_sgrow (&format_obstack, "\n  ");                      \
+          j = 1;                                                        \
+        }                                                               \
+      else                                                              \
+        ++j;                                                            \
+      obstack_fgrow1 (&format_obstack, "%6d", table_data[i]);           \
+      if (table_data[i] < min)                                          \
+        min = table_data[i];                                            \
+      if (max < table_data[i])                                          \
+        max = table_data[i];                                            \
+    }                                                                   \
+  obstack_1grow (&format_obstack, 0);                                   \
+  muscle_insert (name, obstack_finish (&format_obstack));               \
+                                                                        \
+  lmin = min;                                                           \
+  lmax = max;                                                           \
+  /* Build `NAME_min' and `NAME_max' in the obstack. */                 \
+  obstack_fgrow1 (&format_obstack, "%s_min", name);                     \
+  obstack_1grow (&format_obstack, 0);                                   \
+  MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack), lmin);      \
+  obstack_fgrow1 (&format_obstack, "%s_max", name);                     \
+  obstack_1grow (&format_obstack, 0);                                   \
+  MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack), lmax);      \
 }
 
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_unsigned_int_table, unsigned int)
@@ -149,9 +149,9 @@ prepare_symbols (void)
   MUSCLE_INSERT_INT ("user_token_number_max", max_user_token_number);
 
   muscle_insert_symbol_number_table ("translate",
-				     token_translations,
-				     token_translations[0],
-				     1, max_user_token_number + 1);
+                                     token_translations,
+                                     token_translations[0],
+                                     1, max_user_token_number + 1);
 
   /* tname -- token names.  */
   {
@@ -163,23 +163,23 @@ prepare_symbols (void)
     set_quoting_flags (qo, QA_SPLIT_TRIGRAPHS);
     for (i = 0; i < nsyms; i++)
       {
-	char *cp = quotearg_alloc (symbols[i]->tag, -1, qo);
-	/* Width of the next token, including the two quotes, the
-	   comma and the space.  */
-	int width = strlen (cp) + 2;
-
-	if (j + width > 75)
-	  {
-	    obstack_sgrow (&format_obstack, "\n ");
-	    j = 1;
-	  }
-
-	if (i)
-	  obstack_1grow (&format_obstack, ' ');
-	MUSCLE_OBSTACK_SGROW (&format_obstack, cp);
+        char *cp = quotearg_alloc (symbols[i]->tag, -1, qo);
+        /* Width of the next token, including the two quotes, the
+           comma and the space.  */
+        int width = strlen (cp) + 2;
+
+        if (j + width > 75)
+          {
+            obstack_sgrow (&format_obstack, "\n ");
+            j = 1;
+          }
+
+        if (i)
+          obstack_1grow (&format_obstack, ' ');
+        MUSCLE_OBSTACK_SGROW (&format_obstack, cp);
         free (cp);
-	obstack_1grow (&format_obstack, ',');
-	j += width;
+        obstack_1grow (&format_obstack, ',');
+        j += width;
       }
     free (qo);
     obstack_sgrow (&format_obstack, " ]b4_null[");
@@ -196,7 +196,7 @@ prepare_symbols (void)
     for (i = 0; i < ntokens; ++i)
       values[i] = symbols[i]->user_token_number;
     muscle_insert_int_table ("toknum", values,
-			     values[0], 1, ntokens);
+                             values[0], 1, ntokens);
     free (values);
   }
 }
@@ -264,7 +264,7 @@ prepare_states (void)
   for (i = 0; i < nstates; ++i)
     values[i] = states[i]->accessing_symbol;
   muscle_insert_symbol_number_table ("stos", values,
-				     0, 1, nstates);
+                                     0, 1, nstates);
   free (values);
 
   MUSCLE_INSERT_INT ("last", high);
@@ -354,11 +354,11 @@ user_actions_output (FILE *out)
   for (r = 0; r < nrules; ++r)
     if (rules[r].action)
       {
-	fprintf (out, "b4_%scase(%d, [b4_syncline(%d, ",
-		 rules[r].is_predicate ? "predicate_" : "",
-		 r + 1, rules[r].action_location.start.line);
-	escaped_output (out, rules[r].action_location.start.file);
-	fprintf (out, ")\n[    %s]])\n\n", rules[r].action);
+        fprintf (out, "b4_%scase(%d, [b4_syncline(%d, ",
+                 rules[r].is_predicate ? "predicate_" : "",
+                 r + 1, rules[r].action_location.start.line);
+        escaped_output (out, rules[r].action_location.start.file);
+        fprintf (out, ")\n[    %s]])\n\n", rules[r].action);
       }
   fputs ("])\n\n", out);
 }
@@ -377,11 +377,11 @@ merger_output (FILE *out)
   for (n = 1, p = merge_functions; p != NULL; n += 1, p = p->next)
     {
       if (p->type[0] == '\0')
-	fprintf (out, "  case %d: *yy0 = %s (*yy0, *yy1); break;\n",
-		 n, p->name);
+        fprintf (out, "  case %d: *yy0 = %s (*yy0, *yy1); break;\n",
+                 n, p->name);
       else
-	fprintf (out, "  case %d: yy0->%s = %s (*yy0, *yy1); break;\n",
-		 n, p->type, p->name);
+        fprintf (out, "  case %d: yy0->%s = %s (*yy0, *yy1); break;\n",
+                 n, p->type, p->name);
     }
   fputs ("]])\n\n", out);
 }
@@ -503,30 +503,30 @@ prepare_actions (void)
      lookahead token type.  */
 
   muscle_insert_rule_number_table ("defact", yydefact,
-				   yydefact[0], 1, nstates);
+                                   yydefact[0], 1, nstates);
 
   /* Figure out what to do after reducing with each rule, depending on
      the saved state from before the beginning of parsing the data
      that matched this rule.  */
   muscle_insert_state_number_table ("defgoto", yydefgoto,
-				    yydefgoto[0], 1, nsyms - ntokens);
+                                    yydefgoto[0], 1, nsyms - ntokens);
 
 
   /* Output PACT. */
   muscle_insert_base_table ("pact", base,
-			     base[0], 1, nstates);
+                             base[0], 1, nstates);
   MUSCLE_INSERT_INT ("pact_ninf", base_ninf);
 
   /* Output PGOTO. */
   muscle_insert_base_table ("pgoto", base,
-			     base[nstates], nstates + 1, nvectors);
+                             base[nstates], nstates + 1, nvectors);
 
   muscle_insert_base_table ("table", table,
-			    table[0], 1, high + 1);
+                            table[0], 1, high + 1);
   MUSCLE_INSERT_INT ("table_ninf", table_ninf);
 
   muscle_insert_base_table ("check", check,
-			    check[0], 1, high + 1);
+                            check[0], 1, high + 1);
 
   /* GLR parsing slightly modifies YYTABLE and YYCHECK (and thus
      YYPACT) so that in states with unresolved conflicts, the default
@@ -538,9 +538,9 @@ prepare_actions (void)
      that case.  Nevertheless, it seems even better to be able to use
      the GLR skeletons even without the non-deterministic tables.  */
   muscle_insert_unsigned_int_table ("conflict_list_heads", conflict_table,
-				    conflict_table[0], 1, high + 1);
+                                    conflict_table[0], 1, high + 1);
   muscle_insert_unsigned_int_table ("conflicting_rules", conflict_list,
-				    0, 1, conflict_list_cnt);
+                                    0, 1, conflict_list_cnt);
 }
 
 
@@ -587,8 +587,8 @@ output_skeleton (void)
   while (pkgdatadirlen && pkgdatadir[pkgdatadirlen - 1] == '/')
     pkgdatadirlen--;
   full_skeleton = xmalloc (pkgdatadirlen + 1
-			   + (skeleton_size < sizeof m4sugar
-			      ? sizeof m4sugar : skeleton_size));
+                           + (skeleton_size < sizeof m4sugar
+                              ? sizeof m4sugar : skeleton_size));
   strncpy (full_skeleton, pkgdatadir, pkgdatadirlen);
   full_skeleton[pkgdatadirlen] = '/';
   strcpy (full_skeleton + pkgdatadirlen + 1, m4sugar);
@@ -669,7 +669,7 @@ output_skeleton (void)
   in = fdopen (filter_fd[0], "r");
   if (! in)
     error (EXIT_FAILURE, get_errno (),
-	   "fdopen");
+           "fdopen");
   scan_skel (in);
   /* scan_skel should have read all of M4's output.  Otherwise, when we
      close the pipe, we risk letting M4 report a broken-pipe to the
