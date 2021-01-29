@@ -0,0 +1,613 @@
+/* Print an xml on generated parser, for Bison,
+
+   Copyright (C) 2007 Free Software Foundation, Inc.
+
+   This file is part of Bison, the GNU Compiler Compiler.
+
+   Bison is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
+
+   Bison is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with Bison; see the file COPYING.  If not, write to
+   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
+   Boston, MA 02110-1301, USA.  */
+
+#include <config.h>
+#include "system.h"
+
+#include <stdarg.h>
+
+#include <bitset.h>
+#include <quotearg.h>
+
+#include "LR0.h"
+#include "closure.h"
+#include "conflicts.h"
+#include "files.h"
+#include "getargs.h"
+#include "gram.h"
+#include "lalr.h"
+#include "print.h"
+#include "print-xml.h"
+#include "reader.h"
+#include "reduce.h"
+#include "state.h"
+#include "symtab.h"
+#include "tables.h"
+
+static bitset no_reduce_set;
+
+
+/*----------------------------.
+| Print rules never reduced.  |
+`-----------------------------*/
+
+static void
+print_rules_never_reduced (FILE *out, int level)
+{
+  rule_number r;
+  bool count = false;
+
+  for (r = 0; r < nrules + nuseless_productions; r++)
+    {
+      if (rule_never_reduced_p (&rules[r]))
+	{
+	  count = true;
+	  break;
+	}
+    }
+
+  if (count) {
+    xml_puts (out, level, "<rules-never-reduced>");
+    grammar_rules_partial_print_xml (out, level - 1,
+				     false, rule_never_reduced_p);
+    xml_puts (out, level, "</rules-never-reduced>");
+  }
+  else
+    xml_puts (out, level, "<rules-never-reduced/>");
+}
+
+/*--------------------------------.
+| Report information on a state.  |
+`--------------------------------*/
+
+static void
+print_core (FILE *out, int level, state *s)
+{
+  size_t i;
+  item_number *sitems = s->items;
+  size_t snritems = s->nitems;
+
+  /* Output all the items of a state, not only its kernel.  */
+  if (report_flag & report_itemsets)
+    {
+      closure (sitems, snritems);
+      sitems = itemset;
+      snritems = nitemset;
+    }
+
+  if (!snritems) {
+    xml_puts (out, level, "<itemset/>");
+    return;
+  }
+
+  xml_puts (out, level, "<itemset>");
+
+  for (i = 0; i < snritems; i++)
+    {
+      item_number *sp;
+      item_number *sp1;
+      rule_number r;
+
+      sp1 = sp = ritem + sitems[i];
+
+      while (*sp >= 0)
+	sp++;
+
+      r = item_number_as_rule_number (*sp);
+
+      xml_printf (out, level + 1, "<rule number=\"%d\">",
+		  rules[r].number);
+
+      rule_lhs_print_xml (&rules[r], out, level + 2);
+
+      xml_puts (out, level + 2, "<rhs>");
+      for (sp = rules[r].rhs; sp < sp1; sp++)
+	xml_printf (out, level + 3, "<symbol class=\"%s\">%s</symbol>",
+		    symbol_class_get_string (symbols[*sp]),
+		    xml_escape (symbols[*sp]->tag));
+      xml_puts (out, level + 3, "<point/>");
+      for (/* Nothing */; *sp >= 0; ++sp)
+	xml_printf (out, level + 3, "<symbol class=\"%s\">%s</symbol>",
+		    symbol_class_get_string (symbols[*sp]),
+		    xml_escape (symbols[*sp]->tag));
+
+      xml_puts (out, level + 2, "</rhs>");
+
+      /* Display the lookahead tokens?  */
+      if (report_flag & report_lookahead_tokens)
+	state_rule_lookahead_tokens_print_xml (s, &rules[r], out, level + 2);
+
+      xml_puts (out, level + 1, "</rule>");
+    }
+  xml_puts (out, level, "</itemset>");
+}
+
+
+/*-----------------------------------------------------------.
+| Report the shifts if DISPLAY_SHIFTS_P or the gotos of S on |
+| OUT.                                                       |
+`-----------------------------------------------------------*/
+
+static void
+print_transitions (state *s, FILE *out, int level)
+{
+  transitions *trans = s->transitions;
+  int n = 0;
+  int i;
+
+  for (i = 0; i < trans->num; i++)
+    if (!TRANSITION_IS_DISABLED (trans, i))
+      {
+	n++;
+      }
+
+  /* Nothing to report. */
+  if (!n) {
+    xml_puts (out, level, "<transitions/>");
+    return;
+  }
+
+  /* Report lookahead tokens and shifts.  */
+  xml_puts (out, level, "<transitions>");
+
+  for (i = 0; i < trans->num; i++)
+    if (!TRANSITION_IS_DISABLED (trans, i)
+	&& TRANSITION_IS_SHIFT (trans, i))
+      {
+	symbol *sym = symbols[TRANSITION_SYMBOL (trans, i)];
+	char const *tag = sym->tag;
+	state *s1 = trans->states[i];
+
+	xml_printf (out, level + 1,
+		    "<transition type=\"shift\" symbol=\"%s\" state=\"%d\"/>",
+		    xml_escape (tag), s1->number);
+      }
+
+  for (i = 0; i < trans->num; i++)
+    if (!TRANSITION_IS_DISABLED (trans, i)
+	&& !TRANSITION_IS_SHIFT (trans, i))
+      {
+	symbol *sym = symbols[TRANSITION_SYMBOL (trans, i)];
+	char const *tag = sym->tag;
+	state *s1 = trans->states[i];
+
+	xml_printf (out, level + 1,
+		    "<transition type=\"goto\" symbol=\"%s\" state=\"%d\"/>",
+		    xml_escape (tag), s1->number);
+      }
+
+  xml_puts (out, level, "</transitions>");
+}
+
+
+/*--------------------------------------------------------.
+| Report the explicit errors of S raised from %nonassoc.  |
+`--------------------------------------------------------*/
+
+static void
+print_errs (FILE *out, int level, state *s)
+{
+  errs *errp = s->errs;
+  bool count = false;
+  int i;
+
+  for (i = 0; i < errp->num; ++i)
+    if (errp->symbols[i])
+      count = true;
+
+  /* Nothing to report. */
+  if (!count) {
+    xml_puts (out, level, "<errors/>");
+    return;
+  }
+
+  /* Report lookahead tokens and errors.  */
+  xml_puts (out, level, "<errors>");
+  for (i = 0; i < errp->num; ++i)
+    if (errp->symbols[i])
+      {
+	char const *tag = errp->symbols[i]->tag;
+	xml_printf (out, level + 1,
+		    "<error symbol=\"%s\">nonassociative</error>",
+		    xml_escape (tag));
+      }
+  xml_puts (out, level, "</errors>");
+}
+
+
+/*-------------------------------------------------------------------------.
+| Report a reduction of RULE on LOOKAHEAD_TOKEN (which can be `default').  |
+| If not ENABLED, the rule is masked by a shift or a reduce (S/R and       |
+| R/R conflicts).                                                          |
+`-------------------------------------------------------------------------*/
+
+static void
+print_reduction (FILE *out, int level, char const *lookahead_token,
+		 rule *r, bool enabled)
+{
+  if (r->number)
+    xml_printf (out, level,
+		"<reduction symbol=\"%s\" rule=\"%d\" enabled=\"%s\"/>",
+		xml_escape (lookahead_token),
+		r->number,
+		enabled ? "true" : "false");
+  else
+    xml_printf (out, level,
+		"<reduction symbol=\"%s\" rule=\"accept\" enabled=\"%s\"/>",
+		xml_escape (lookahead_token),
+		enabled ? "true" : "false");
+}
+
+
+/*-------------------------------------------.
+| Report on OUT the reduction actions of S.  |
+`-------------------------------------------*/
+
+static void
+print_reductions (FILE *out, int level, state *s)
+{
+  transitions *trans = s->transitions;
+  reductions *reds = s->reductions;
+  rule *default_rule = NULL;
+  int report = false;
+  int i, j;
+
+  if (reds->num == 0) {
+    xml_puts (out, level, "<reductions/>");
+    return;
+  }
+
+  if (yydefact[s->number] != 0)
+    default_rule = &rules[yydefact[s->number] - 1];
+
+  bitset_zero (no_reduce_set);
+  FOR_EACH_SHIFT (trans, i)
+    bitset_set (no_reduce_set, TRANSITION_SYMBOL (trans, i));
+  for (i = 0; i < s->errs->num; ++i)
+    if (s->errs->symbols[i])
+      bitset_set (no_reduce_set, s->errs->symbols[i]->number);
+
+  if (default_rule)
+    report = true;
+
+  if (reds->lookahead_tokens)
+    for (i = 0; i < ntokens; i++)
+      {
+	bool count = bitset_test (no_reduce_set, i);
+
+	for (j = 0; j < reds->num; ++j)
+	  if (bitset_test (reds->lookahead_tokens[j], i))
+	    {
+	      if (! count)
+		{
+		  if (reds->rules[j] != default_rule)
+		    report = true;
+		  count = true;
+		}
+	      else
+		{
+		  report = true;
+		}
+	    }
+      }
+
+  /* Nothing to report. */
+  if (!report) {
+    xml_puts (out, level, "<reductions/>");
+    return;
+  }
+
+  xml_puts (out, level, "<reductions>");
+
+  /* Report lookahead tokens (or $default) and reductions.  */
+  if (reds->lookahead_tokens)
+    for (i = 0; i < ntokens; i++)
+      {
+	bool defaulted = false;
+	bool count = bitset_test (no_reduce_set, i);
+
+	for (j = 0; j < reds->num; ++j)
+	  if (bitset_test (reds->lookahead_tokens[j], i))
+	    {
+	      if (! count)
+		{
+		  if (reds->rules[j] != default_rule)
+		    print_reduction (out, level + 1, symbols[i]->tag,
+				     reds->rules[j], true);
+		  else
+		    defaulted = true;
+		  count = true;
+		}
+	      else
+		{
+		  if (defaulted)
+		    print_reduction (out, level + 1, symbols[i]->tag,
+				     default_rule, true);
+		  defaulted = false;
+		  print_reduction (out, level + 1, symbols[i]->tag,
+				   reds->rules[j], false);
+		}
+	    }
+      }
+
+  if (default_rule)
+    print_reduction (out, level + 1,
+		     "$default", default_rule, true);
+
+  xml_puts (out, level, "</reductions>");
+}
+
+
+/*--------------------------------------------------------------.
+| Report on OUT all the actions (shifts, gotos, reductions, and |
+| explicit erros from %nonassoc) of S.                          |
+`--------------------------------------------------------------*/
+
+static void
+print_actions (FILE *out, int level, state *s)
+{
+  xml_puts (out, level, "<actions>");
+  print_transitions (s, out, level + 1);
+  print_errs (out, level + 1, s);
+  print_reductions (out, level + 1, s);
+  xml_puts (out, level, "</actions>");
+}
+
+
+/*----------------------------------.
+| Report all the data on S on OUT.  |
+`----------------------------------*/
+
+static void
+print_state (FILE *out, int level, state *s)
+{
+  fputc ('\n', out);
+  xml_printf (out, level, "<state number=\"%d\">", s->number);
+  print_core (out, level + 1, s);
+  print_actions (out, level + 1, s);
+  if ((report_flag & report_solved_conflicts) && s->solved_conflicts_xml)
+    {
+      xml_puts (out, level + 1, "<solved-conflicts>");
+      fputs (s->solved_conflicts_xml, out);
+      xml_puts (out, level + 1, "</solved-conflicts>");
+    }
+  else
+    xml_puts (out, level + 1, "<solved-conflicts/>");
+  xml_puts (out, level, "</state>");
+}
+
+
+/*-----------------------------------------.
+| Print information on the whole grammar.  |
+`-----------------------------------------*/
+
+static void
+print_grammar (FILE *out, int level)
+{
+  symbol_number i;
+
+  fputc ('\n', out);
+  xml_puts (out, level, "<grammar>");
+  grammar_rules_print_xml (out, level);
+
+  /* Terminals */
+  xml_puts (out, level + 1, "<terminals>");
+  for (i = 0; i < max_user_token_number + 1; i++)
+    if (token_translations[i] != undeftoken->number)
+      {
+	char const *tag = symbols[token_translations[i]]->tag;
+	rule_number r;
+	item_number *rhsp;
+
+	xml_printf (out, level + 2,
+		    "<terminal type=\"%d\" symbol=\"%s\">",
+		    i, xml_escape (tag));
+
+	for (r = 0; r < nrules; r++)
+	  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
+	    if (item_number_as_symbol_number (*rhsp) == token_translations[i])
+	      {
+		xml_printf (out, level + 3, "<rule>%d</rule>", r);
+		break;
+	      }
+	xml_puts (out, level + 2, "</terminal>");
+      }
+  xml_puts (out, level + 1, "</terminals>");
+
+  /* Nonterminals */
+  xml_puts (out, level + 1, "<nonterminals>");
+  for (i = ntokens; i < nsyms; i++)
+    {
+      int left_count = 0, right_count = 0;
+      rule_number r;
+      char const *tag = symbols[i]->tag;
+
+      for (r = 0; r < nrules; r++)
+	{
+	  item_number *rhsp;
+	  if (rules[r].lhs->number == i)
+	    left_count++;
+	  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
+	    if (item_number_as_symbol_number (*rhsp) == i)
+	      {
+		right_count++;
+		break;
+	      }
+	}
+
+      xml_printf (out, level + 2,
+		  "<nonterminal type=\"%d\" symbol=\"%s\">",
+		  i, xml_escape (tag));
+
+      if (left_count > 0)
+	{
+	  xml_puts (out, level + 3, "<left>");
+	  for (r = 0; r < nrules; r++)
+	    {
+	      if (rules[r].lhs->number == i)
+		xml_printf (out, level + 4, "<rule>%d</rule>", r);
+	    }
+	  xml_puts (out, level + 3, "</left>");
+	}
+
+      if (right_count > 0)
+	{
+	  xml_puts (out, level + 3, "<right>");
+	  for (r = 0; r < nrules; r++)
+	    {
+	      item_number *rhsp;
+	      for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
+		if (item_number_as_symbol_number (*rhsp) == i)
+		  {
+		    xml_printf (out, level + 4, "<rule>%d</rule>", r);
+		    break;
+		  }
+	    }
+	  xml_puts (out, level + 3, "</right>");
+	}
+
+      xml_puts (out, level + 2, "</nonterminal>");
+    }
+  xml_puts (out, level + 1, "</nonterminals>");
+  xml_puts (out, level, "</grammar>");
+}
+
+void
+xml_puts (FILE *out, int level, char *s)
+{
+  int i;
+  level *= 2;
+  for (i = 0; i < level; i++)
+    fputc (' ', out);
+  fputs (s, out);
+  fputc ('\n', out);
+}
+
+void
+xml_printf (FILE *out, int level, char const *fmt, ...)
+{
+  int i;
+  va_list arglist;
+
+  for (i = 0; i < level; i++)
+    fputc (' ', out);
+
+  va_start (arglist, fmt);
+  vfprintf (out, fmt, arglist);
+  va_end (arglist);
+
+  fputc ('\n', out);
+}
+
+struct escape_buf
+{
+  char *ptr;
+  size_t size;
+};
+
+static char const *
+xml_escape_string (struct escape_buf *buf, char const *str)
+{
+  size_t len = strlen (str);
+  size_t max_expansion = sizeof "&quot;" - 1;
+  char *p;
+
+  if (buf->size <= max_expansion * len)
+    {
+      buf->size = max_expansion * len + 1;
+      buf->ptr = x2realloc (buf->ptr, &buf->size);
+    }
+  p = buf->ptr;
+
+  for (; *str; str++)
+    switch (*str)
+      {
+      default: *p++ = *str; break;
+      case '&': p = stpcpy (p, "&amp;" ); break;
+      case '<': p = stpcpy (p, "&lt;"  ); break;
+      case '>': p = stpcpy (p, "&gt;"  ); break;
+      case '"': p = stpcpy (p, "&quot;"); break;
+      }
+
+  *p = '\0';
+  return buf->ptr;
+}
+
+char const *
+xml_escape_n (int n, char const *str)
+{
+  static struct escape_buf buf[2];
+  return xml_escape_string (buf + n, str);
+}
+
+char const *
+xml_escape (char const *str)
+{
+  return xml_escape_n (0, str);
+}
+
+void
+print_xml (void)
+{
+  state_number i;
+  int level = 0;
+
+  FILE *out = xfopen (spec_xml_file, "w");
+
+  fputs ("<?xml version=\"1.0\"?>\n\n", out);
+  xml_printf (out, level, "<bison-xml-report version=\"%s\">",
+	      xml_escape (VERSION));
+
+  fputc ('\n', out);
+  xml_printf (out, level + 1, "<filename>%s</filename>",
+	      xml_escape (grammar_file));
+
+  /* print reductions */
+  reduce_xml (out, level + 1);
+
+  /* print rules never reduced */
+  print_rules_never_reduced (out, level + 1);
+
+  /* print conflicts */
+  conflicts_output_xml (out, level + 1);
+
+  /* print grammar */
+  print_grammar (out, level + 1);
+
+  if (report_flag & report_itemsets)
+    new_closure (nritems);
+  no_reduce_set =  bitset_create (ntokens, BITSET_FIXED);
+
+  /* print automaton */
+  fputc ('\n', out);
+  xml_puts (out, level + 1, "<automaton>");
+  for (i = 0; i < nstates; i++)
+    print_state (out, level + 2, states[i]);
+  xml_puts (out, level + 1, "</automaton>");
+
+  bitset_free (no_reduce_set);
+  if (report_flag & report_itemsets)
+    free_closure ();
+
+  xml_puts (out, 0, "</bison-xml-report>");
+
+  xfclose (out);
+}
