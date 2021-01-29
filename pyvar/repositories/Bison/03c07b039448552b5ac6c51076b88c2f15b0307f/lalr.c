@@ -1,7 +1,7 @@
 /* Compute lookahead criteria for Bison.
 
    Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003, 2004, 2005,
-   2006, 2007 Free Software Foundation, Inc.
+   2006, 2007, 2008, 2009 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -36,6 +36,7 @@
 #include "getargs.h"
 #include "gram.h"
 #include "lalr.h"
+#include "muscle_tab.h"
 #include "nullable.h"
 #include "reader.h"
 #include "relation.h"
@@ -336,22 +337,30 @@ compute_lookahead_tokens (void)
 `----------------------------------------------------*/
 
 static int
-state_lookahead_tokens_count (state *s)
+state_lookahead_tokens_count (state *s, bool default_rule_only_for_accept)
 {
   int n_lookahead_tokens = 0;
   reductions *rp = s->reductions;
   transitions *sp = s->transitions;
 
-  /* We need a lookahead either to distinguish different
-     reductions (i.e., there are two or more), or to distinguish a
-     reduction from a shift.  Otherwise, it is straightforward,
-     and the state is `consistent'.  There is no need to check that
-     transition 0 hasn't been disabled before checking if it is a
-     shift since transitions are only disabled during conflict
-     resolution, and that hasn't happened yet.  */
+  /* Transitions are only disabled during conflict resolution, and that
+     hasn't happened yet, so there should be no need to check that
+     transition 0 hasn't been disabled before checking if it is a shift.
+     However, this check was performed at one time, so we leave it as an
+     aver.  */
   aver (sp->num == 0 || !TRANSITION_IS_DISABLED (sp, 0));
+
+  /* We need a lookahead either to distinguish different reductions
+     (i.e., there are two or more), or to distinguish a reduction from a
+     shift.  Otherwise, it is straightforward, and the state is
+     `consistent'.  However, for states that have any rules, treat only
+     the accepting state as consistent (since there is never a lookahead
+     token that makes sense there, and so no lookahead token should be
+     read) if the user has otherwise disabled default rules.  */
   if (rp->num > 1
-      || (rp->num == 1 && sp->num && TRANSITION_IS_SHIFT (sp, 0)))
+      || (rp->num == 1 && sp->num && TRANSITION_IS_SHIFT (sp, 0))
+      || (rp->num == 1 && rp->rules[0]->number != 0
+          && default_rule_only_for_accept))
     n_lookahead_tokens += rp->num;
   else
     s->consistent = 1;
@@ -369,11 +378,18 @@ initialize_LA (void)
 {
   state_number i;
   bitsetv pLA;
+  bool default_rule_only_for_accept;
+  {
+    char *default_rules = muscle_percent_define_get ("lr.default_rules");
+    default_rule_only_for_accept = 0 == strcmp (default_rules, "accepting");
+    free (default_rules);
+  }
 
   /* Compute the total number of reductions requiring a lookahead.  */
   nLA = 0;
   for (i = 0; i < nstates; i++)
-    nLA += state_lookahead_tokens_count (states[i]);
+    nLA +=
+      state_lookahead_tokens_count (states[i], default_rule_only_for_accept);
   /* Avoid having to special case 0.  */
   if (!nLA)
     nLA = 1;
@@ -385,7 +401,8 @@ initialize_LA (void)
      require lookahead tokens.  */
   for (i = 0; i < nstates; i++)
     {
-      int count = state_lookahead_tokens_count (states[i]);
+      int count =
+        state_lookahead_tokens_count (states[i], default_rule_only_for_accept);
       if (count)
 	{
 	  states[i]->reductions->lookahead_tokens = pLA;
