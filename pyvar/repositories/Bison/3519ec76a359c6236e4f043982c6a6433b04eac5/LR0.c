@@ -1,5 +1,5 @@
 /* Generate the nondeterministic finite state machine for bison,
-   Copyright (C) 1984, 1986, 1989 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 2000 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -29,11 +29,9 @@
 #include "complain.h"
 #include "closure.h"
 
-extern char *nullable;
 extern short *itemset;
 extern short *itemsetend;
 
-
 int nstates;
 int final_state;
 core *first_state;
