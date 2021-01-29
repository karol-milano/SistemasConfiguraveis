@@ -1,7 +1,7 @@
 /* Input parser for Bison
 
    Copyright (C) 1984, 1986, 1989, 1992, 1998, 2000, 2001, 2002, 2003,
-   2005 Free Software Foundation, Inc.
+   2005, 2006 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -307,6 +307,10 @@ grammar_midrule_action (void)
   midrule->action = current_rule->action;
   midrule->action_location = dummy_location;
   current_rule->action = NULL;
+  /* If $$ was used in the action, the LHS of the enclosing rule was
+     incorrectly flagged as used.  */
+  midrule->used = current_rule->used;
+  current_rule->used = false;
 
   if (previous_rule_end)
     previous_rule_end->next = midrule;
