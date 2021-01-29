@@ -82,36 +82,36 @@ print_core (FILE *out, int level, state *s)
       sp1 = sp = ritem + sitems[i];
 
       while (*sp >= 0)
-	sp++;
+        sp++;
 
       r = item_number_as_rule_number (*sp);
       sp = rules[r].rhs;
 
       /* Display the lookahead tokens?  */
       if (item_number_is_rule_number (*sp1))
-	{
-	  reductions *reds = s->reductions;
-	  int red = state_reduction_find (s, &rules[r]);
-	  /* Print item with lookaheads if there are. */
-	  if (reds->lookahead_tokens && red != -1)
-	    {
-	      xml_printf (out, level + 1,
-			  "<item rule-number=\"%d\" point=\"%d\">",
-			  rules[r].number, sp1 - sp);
-	      state_rule_lookahead_tokens_print_xml (s, &rules[r],
-						     out, level + 2);
-	      xml_puts (out, level + 1, "</item>");
-	      printed = true;
-	    }
-	}
+        {
+          reductions *reds = s->reductions;
+          int red = state_reduction_find (s, &rules[r]);
+          /* Print item with lookaheads if there are. */
+          if (reds->lookahead_tokens && red != -1)
+            {
+              xml_printf (out, level + 1,
+                          "<item rule-number=\"%d\" point=\"%d\">",
+                          rules[r].number, sp1 - sp);
+              state_rule_lookahead_tokens_print_xml (s, &rules[r],
+                                                     out, level + 2);
+              xml_puts (out, level + 1, "</item>");
+              printed = true;
+            }
+        }
 
       if (!printed)
-	{
-	  xml_printf (out, level + 1,
-		      "<item rule-number=\"%d\" point=\"%d\"/>",
-		      rules[r].number,
-		      sp1 - sp);
-	}
+        {
+          xml_printf (out, level + 1,
+                      "<item rule-number=\"%d\" point=\"%d\"/>",
+                      rules[r].number,
+                      sp1 - sp);
+        }
     }
   xml_puts (out, level, "</itemset>");
 }
@@ -132,7 +132,7 @@ print_transitions (state *s, FILE *out, int level)
   for (i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i))
       {
-	n++;
+        n++;
       }
 
   /* Nothing to report. */
@@ -146,28 +146,28 @@ print_transitions (state *s, FILE *out, int level)
 
   for (i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i)
-	&& TRANSITION_IS_SHIFT (trans, i))
+        && TRANSITION_IS_SHIFT (trans, i))
       {
-	symbol *sym = symbols[TRANSITION_SYMBOL (trans, i)];
-	char const *tag = sym->tag;
-	state *s1 = trans->states[i];
+        symbol *sym = symbols[TRANSITION_SYMBOL (trans, i)];
+        char const *tag = sym->tag;
+        state *s1 = trans->states[i];
 
-	xml_printf (out, level + 1,
-		    "<transition type=\"shift\" symbol=\"%s\" state=\"%d\"/>",
-		    xml_escape (tag), s1->number);
+        xml_printf (out, level + 1,
+                    "<transition type=\"shift\" symbol=\"%s\" state=\"%d\"/>",
+                    xml_escape (tag), s1->number);
       }
 
   for (i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i)
-	&& !TRANSITION_IS_SHIFT (trans, i))
+        && !TRANSITION_IS_SHIFT (trans, i))
       {
-	symbol *sym = symbols[TRANSITION_SYMBOL (trans, i)];
-	char const *tag = sym->tag;
-	state *s1 = trans->states[i];
+        symbol *sym = symbols[TRANSITION_SYMBOL (trans, i)];
+        char const *tag = sym->tag;
+        state *s1 = trans->states[i];
 
-	xml_printf (out, level + 1,
-		    "<transition type=\"goto\" symbol=\"%s\" state=\"%d\"/>",
-		    xml_escape (tag), s1->number);
+        xml_printf (out, level + 1,
+                    "<transition type=\"goto\" symbol=\"%s\" state=\"%d\"/>",
+                    xml_escape (tag), s1->number);
       }
 
   xml_puts (out, level, "</transitions>");
@@ -200,10 +200,10 @@ print_errs (FILE *out, int level, state *s)
   for (i = 0; i < errp->num; ++i)
     if (errp->symbols[i])
       {
-	char const *tag = errp->symbols[i]->tag;
-	xml_printf (out, level + 1,
-		    "<error symbol=\"%s\">nonassociative</error>",
-		    xml_escape (tag));
+        char const *tag = errp->symbols[i]->tag;
+        xml_printf (out, level + 1,
+                    "<error symbol=\"%s\">nonassociative</error>",
+                    xml_escape (tag));
       }
   xml_puts (out, level, "</errors>");
 }
@@ -217,19 +217,19 @@ print_errs (FILE *out, int level, state *s)
 
 static void
 print_reduction (FILE *out, int level, char const *lookahead_token,
-		 rule *r, bool enabled)
+                 rule *r, bool enabled)
 {
   if (r->number)
     xml_printf (out, level,
-		"<reduction symbol=\"%s\" rule=\"%d\" enabled=\"%s\"/>",
-		xml_escape (lookahead_token),
-		r->number,
-		enabled ? "true" : "false");
+                "<reduction symbol=\"%s\" rule=\"%d\" enabled=\"%s\"/>",
+                xml_escape (lookahead_token),
+                r->number,
+                enabled ? "true" : "false");
   else
     xml_printf (out, level,
-		"<reduction symbol=\"%s\" rule=\"accept\" enabled=\"%s\"/>",
-		xml_escape (lookahead_token),
-		enabled ? "true" : "false");
+                "<reduction symbol=\"%s\" rule=\"accept\" enabled=\"%s\"/>",
+                xml_escape (lookahead_token),
+                enabled ? "true" : "false");
 }
 
 
@@ -268,22 +268,22 @@ print_reductions (FILE *out, int level, state *s)
   if (reds->lookahead_tokens)
     for (i = 0; i < ntokens; i++)
       {
-	bool count = bitset_test (no_reduce_set, i);
-
-	for (j = 0; j < reds->num; ++j)
-	  if (bitset_test (reds->lookahead_tokens[j], i))
-	    {
-	      if (! count)
-		{
-		  if (reds->rules[j] != default_reduction)
-		    report = true;
-		  count = true;
-		}
-	      else
-		{
-		  report = true;
-		}
-	    }
+        bool count = bitset_test (no_reduce_set, i);
+
+        for (j = 0; j < reds->num; ++j)
+          if (bitset_test (reds->lookahead_tokens[j], i))
+            {
+              if (! count)
+                {
+                  if (reds->rules[j] != default_reduction)
+                    report = true;
+                  count = true;
+                }
+              else
+                {
+                  report = true;
+                }
+            }
       }
 
   /* Nothing to report. */
@@ -298,36 +298,36 @@ print_reductions (FILE *out, int level, state *s)
   if (reds->lookahead_tokens)
     for (i = 0; i < ntokens; i++)
       {
-	bool defaulted = false;
-	bool count = bitset_test (no_reduce_set, i);
-
-	for (j = 0; j < reds->num; ++j)
-	  if (bitset_test (reds->lookahead_tokens[j], i))
-	    {
-	      if (! count)
-		{
-		  if (reds->rules[j] != default_reduction)
-		    print_reduction (out, level + 1, symbols[i]->tag,
-				     reds->rules[j], true);
-		  else
-		    defaulted = true;
-		  count = true;
-		}
-	      else
-		{
-		  if (defaulted)
-		    print_reduction (out, level + 1, symbols[i]->tag,
-				     default_reduction, true);
-		  defaulted = false;
-		  print_reduction (out, level + 1, symbols[i]->tag,
-				   reds->rules[j], false);
-		}
-	    }
+        bool defaulted = false;
+        bool count = bitset_test (no_reduce_set, i);
+
+        for (j = 0; j < reds->num; ++j)
+          if (bitset_test (reds->lookahead_tokens[j], i))
+            {
+              if (! count)
+                {
+                  if (reds->rules[j] != default_reduction)
+                    print_reduction (out, level + 1, symbols[i]->tag,
+                                     reds->rules[j], true);
+                  else
+                    defaulted = true;
+                  count = true;
+                }
+              else
+                {
+                  if (defaulted)
+                    print_reduction (out, level + 1, symbols[i]->tag,
+                                     default_reduction, true);
+                  defaulted = false;
+                  print_reduction (out, level + 1, symbols[i]->tag,
+                                   reds->rules[j], false);
+                }
+            }
       }
 
   if (default_reduction)
     print_reduction (out, level + 1,
-		     "$default", default_reduction, true);
+                     "$default", default_reduction, true);
 
   xml_puts (out, level, "</reductions>");
 }
@@ -390,7 +390,7 @@ print_grammar (FILE *out, int level)
   for (i = 0; i < max_user_token_number + 1; i++)
     if (token_translations[i] != undeftoken->number)
       {
-	char const *tag = symbols[token_translations[i]]->tag;
+        char const *tag = symbols[token_translations[i]]->tag;
         int precedence = symbols[token_translations[i]]->prec;
         assoc associativity = symbols[token_translations[i]]->assoc;
         xml_indent (out, level + 2);
@@ -414,9 +414,9 @@ print_grammar (FILE *out, int level)
     {
       char const *tag = symbols[i]->tag;
       xml_printf (out, level + 2,
-		  "<nonterminal symbol-number=\"%d\" name=\"%s\""
+                  "<nonterminal symbol-number=\"%d\" name=\"%s\""
                   " usefulness=\"%s\"/>",
-		  i, xml_escape (tag),
+                  i, xml_escape (tag),
                   reduce_nonterminal_useless_in_grammar (i)
                     ? "useless-in-grammar" : "useful");
     }
@@ -512,7 +512,7 @@ print_xml (void)
 
   fputc ('\n', out);
   xml_printf (out, level + 1, "<filename>%s</filename>",
-	      xml_escape (grammar_file));
+              xml_escape (grammar_file));
 
   /* print grammar */
   print_grammar (out, level + 1);
