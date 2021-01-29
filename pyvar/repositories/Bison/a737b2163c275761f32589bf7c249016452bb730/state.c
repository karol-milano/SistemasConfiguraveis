@@ -1,6 +1,6 @@
 /* Type definitions for nondeterministic finite state machine for Bison.
 
-   Copyright (C) 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -49,17 +49,17 @@ transitions_new (int num, state **the_states)
 }
 
 
-/*-------------------------------------------------------------------.
-| Return the state such these TRANSITIONS contain a shift/goto to it |
-| on S.  Abort if none found.                                        |
-`-------------------------------------------------------------------*/
+/*-------------------------------------------------------.
+| Return the state such that SHIFTS contain a shift/goto |
+| to it on SYM.  Abort if none found.                    |
+`-------------------------------------------------------*/
 
 state *
-transitions_to (transitions *shifts, symbol_number s)
+transitions_to (transitions *shifts, symbol_number sym)
 {
   int j;
   for (j = 0; j < shifts->num; j++)
-    if (TRANSITION_SYMBOL (shifts, j) == s)
+    if (TRANSITION_SYMBOL (shifts, j) == sym)
       return shifts->states[j];
   abort ();
 }
