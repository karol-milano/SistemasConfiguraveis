@@ -1,7 +1,7 @@
 /* Type definitions for nondeterministic finite state machine for Bison.
 
-   Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006, 2007 Free Software
-   Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2009 Free
+   Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -142,6 +142,7 @@ state_new (symbol_number accessing_symbol,
   res->transitions = NULL;
   res->reductions = NULL;
   res->errs = NULL;
+  res->state_list = NULL;
   res->consistent = 0;
   res->solved_conflicts = NULL;
   res->solved_conflicts_xml = NULL;
@@ -154,6 +155,32 @@ state_new (symbol_number accessing_symbol,
   return res;
 }
 
+state *
+state_new_isocore (state const *s)
+{
+  state *res;
+  size_t items_size = s->nitems * sizeof *s->items;
+
+  aver (nstates < STATE_NUMBER_MAXIMUM);
+
+  res = xmalloc (offsetof (state, items) + items_size);
+  res->number = nstates++;
+  res->accessing_symbol = s->accessing_symbol;
+  res->transitions =
+    transitions_new (s->transitions->num, s->transitions->states);
+  res->reductions = reductions_new (s->reductions->num, s->reductions->rules);
+  res->errs = NULL;
+  res->state_list = NULL;
+  res->consistent = s->consistent;
+  res->solved_conflicts = NULL;
+  res->solved_conflicts_xml = NULL;
+
+  res->nitems = s->nitems;
+  memcpy (res->items, s->items, items_size);
+
+  return res;
+}
+
 
 /*---------.
 | Free S.  |
