@@ -46,6 +46,11 @@ symbol *accept = NULL;
 symbol *startsymbol = NULL;
 location startsymbol_location;
 
+/*---------------------------.
+| Precedence relation graph. |
+`---------------------------*/
+
+static symgraph **prec_nodes;
 
 /*---------------------------------.
 | Create a new symbol, named TAG.  |
@@ -971,3 +976,100 @@ symbols_pack (void)
               _("the start symbol %s is a token"),
               startsymbol->tag);
 }
+
+/*---------------------------------.
+| Initialize relation graph nodes. |
+`---------------------------------*/
+
+static void
+init_prec_nodes (void)
+{
+  int i;
+  prec_nodes = xcalloc (nsyms, sizeof *prec_nodes);
+  for (i = 0; i < nsyms; ++i)
+    {
+      prec_nodes[i] = xmalloc (sizeof *prec_nodes[i]);
+      symgraph *s = prec_nodes[i];
+      s->id = i;
+      s->succ = 0;
+      s->pred = 0;
+    }
+}
+
+/*----------------.
+| Create a link.  |
+`----------------*/
+
+static symgraphlink *
+symgraphlink_new (graphid id, symgraphlink *next)
+{
+  symgraphlink *l = xmalloc (sizeof *l);
+  l->id = id;
+  l->next = next;
+  return l;
+}
+
+
+/*------------------------------------------------------------------.
+| Register the second symbol of the precedence relation, and return |
+| whether this relation is new.  Use only in register_precedence.   |
+`------------------------------------------------------------------*/
+
+static bool
+register_precedence_second_symbol (symgraphlink **first, graphid sym)
+{
+  if (!*first || sym < (*first)->id)
+    *first = symgraphlink_new (sym, *first);
+  else
+    {
+      symgraphlink *slist = *first;
+
+      while (slist->next && slist->next->id <= sym)
+        slist = slist->next;
+
+      if (slist->id == sym)
+        /* Relation already present. */
+        return false;
+
+      slist->next = symgraphlink_new (sym, slist->next);
+    }
+  return true;
+}
+
+/*------------------------------------------------------------------.
+| Register a new relation between symbols as used. The first symbol |
+| has a greater precedence than the second one.                     |
+`------------------------------------------------------------------*/
+
+void
+register_precedence (graphid first, graphid snd)
+{
+  if (!prec_nodes)
+    init_prec_nodes ();
+  register_precedence_second_symbol (&(prec_nodes[first]->succ), snd);
+  register_precedence_second_symbol (&(prec_nodes[snd]->pred), first);
+}
+
+
+/*--------------------------------------------------.
+| Print a warning for unused precedence relations.  |
+`--------------------------------------------------*/
+
+void
+print_precedence_warnings (void)
+{
+  int i;
+  if (!prec_nodes)
+    init_prec_nodes ();
+  for (i = 0; i < nsyms; ++i)
+    {
+      symbol *s = symbols[i];
+      if (s
+          && s->prec != 0
+          && !prec_nodes[i]->pred
+          && !prec_nodes[i]->succ
+          && s->assoc == precedence_assoc)
+        complain (&s->location, Wother,
+                  _("useless precedence for %s"), s->tag);
+    }
+}
