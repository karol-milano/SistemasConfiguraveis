@@ -1,6 +1,6 @@
 /* Allocate input grammar variables for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 2001, 2002, 2003, 2005 Free
+   Copyright (C) 1984, 1986, 1989, 2001, 2002, 2003, 2005, 2006 Free
    Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -325,7 +325,8 @@ grammar_rules_never_reduced_report (const char *message)
 void
 grammar_free (void)
 {
-  free (ritem);
+  if (ritem)
+    free (ritem - 1);
   free (rules);
   free (token_translations);
   /* Free the symbol table data structure.  */
