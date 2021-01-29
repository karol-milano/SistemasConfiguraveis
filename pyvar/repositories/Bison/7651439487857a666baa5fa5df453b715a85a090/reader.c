@@ -1,5 +1,5 @@
 /* Input parser for bison
-   Copyright 1984, 1986, 1989, 1992, 1998, 2000, 2001
+   Copyright (C) 1984, 1986, 1989, 1992, 1998, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -1821,3 +1821,12 @@ reader (void)
   /* The grammar as a symbol_list is no longer needed. */
   LIST_FREE (symbol_list, grammar);
 }
+
+void
+grammar_free (void)
+{
+  XFREE (ritem);
+  free (rules + 1);
+  /* Free the symbol table data structure.  */
+  free_symtab ();
+}
