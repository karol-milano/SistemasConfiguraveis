@@ -1,6 +1,6 @@
 /* Type definitions for nondeterministic finite state machine for Bison.
 
-   Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -174,8 +174,7 @@ state_free (state *s)
 void
 state_transitions_set (state *s, int num, state **trans)
 {
-  if (s->transitions)
-    abort ();
+  assert (!s->transitions);
   s->transitions = transitions_new (num, trans);
 }
 
@@ -187,8 +186,7 @@ state_transitions_set (state *s, int num, state **trans)
 void
 state_reductions_set (state *s, int num, rule **reds)
 {
-  if (s->reductions)
-    abort ();
+  assert (!s->reductions);
   s->reductions = reductions_new (num, reds);
 }
 
@@ -248,9 +246,9 @@ state_rule_look_ahead_tokens_print (state *s, rule *r, FILE *out)
 }
 
 
-/*----------------------.
+/*---------------------.
 | A state hash table.  |
-`----------------------*/
+`---------------------*/
 
 /* Initial capacity of states hash table.  */
 #define HT_INITIAL_CAPACITY 257
