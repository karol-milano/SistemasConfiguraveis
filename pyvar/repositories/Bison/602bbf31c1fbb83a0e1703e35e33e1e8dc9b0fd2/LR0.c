@@ -1,5 +1,5 @@
 /* Generate the nondeterministic finite state machine for bison,
-   Copyright 1984, 1986, 1989, 2000, 2001  Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 2000, 2001, 2002  Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -23,6 +23,7 @@
    The entry point is generate_states.  */
 
 #include "system.h"
+#include "bitset.h"
 #include "symtab.h"
 #include "getargs.h"
 #include "reader.h"
@@ -34,7 +35,7 @@
 #include "lalr.h"
 #include "reduce.h"
 
-int nstates;
+unsigned int nstates;
 /* Initialize the final state to -1, otherwise, it might be set to 0
    by default, and since we don't compute the reductions of the final
    state, we end up not computing the reductions of the initial state,
