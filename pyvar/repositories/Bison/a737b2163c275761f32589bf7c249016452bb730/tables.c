@@ -1,6 +1,6 @@
 /* Output the generated parsing program for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002
+   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -51,9 +51,9 @@ state_number_to_vector_number (state_number s)
 }
 
 static inline vector_number
-symbol_number_to_vector_number (symbol_number s)
+symbol_number_to_vector_number (symbol_number sym)
 {
-  return state_number_as_int (nstates) + s - ntokens;
+  return state_number_as_int (nstates) + sym - ntokens;
 }
 
 int nvectors;
