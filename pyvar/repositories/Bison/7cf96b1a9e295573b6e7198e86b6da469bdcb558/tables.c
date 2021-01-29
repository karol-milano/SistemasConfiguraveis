@@ -1,7 +1,7 @@
 /* Output the generated parsing program for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004
-   Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004,
+   2005 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -44,11 +44,13 @@
    state_number and symbol_number.  */
 typedef int vector_number;
 
+#if 0 /* Not currently used.  */
 static inline vector_number
 state_number_to_vector_number (state_number s)
 {
   return s;
 }
+#endif
 
 static inline vector_number
 symbol_number_to_vector_number (symbol_number sym)
