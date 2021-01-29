@@ -1,4 +1,5 @@
-/* Allocate input grammar variables for bison,
+/* Allocate input grammar variables for Bison.
+
    Copyright (C) 1984, 1986, 1989, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -328,9 +329,9 @@ grammar_rules_never_reduced_report (const char *message)
 void
 grammar_free (void)
 {
-  XFREE (ritem);
+  free (ritem);
   free (rules);
-  XFREE (token_translations);
+  free (token_translations);
   /* Free the symbol table data structure.  */
   symbols_free ();
   free_merger_functions ();
