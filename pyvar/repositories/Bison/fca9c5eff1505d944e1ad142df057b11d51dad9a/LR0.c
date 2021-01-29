@@ -1,4 +1,4 @@
-/* Generate the nondeterministic finite state machine for Bison.
+/* Generate the LR(0) parser states for Bison.
 
    Copyright (C) 1984, 1986, 1989, 2000-2002, 2004-2010 Free Software
    Foundation, Inc.
@@ -328,8 +328,8 @@ set_states (void)
 
 
 /*-------------------------------------------------------------------.
-| Compute the nondeterministic finite state machine (see state.h for |
-| details) from the grammar.                                         |
+| Compute the LR(0) parser states (see state.h for details) from the |
+| grammar.                                                           |
 `-------------------------------------------------------------------*/
 
 void
