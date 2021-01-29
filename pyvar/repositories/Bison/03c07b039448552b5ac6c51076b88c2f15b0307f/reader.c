@@ -1,7 +1,7 @@
 /* Input parser for Bison
 
    Copyright (C) 1984, 1986, 1989, 1992, 1998, 2000, 2001, 2002, 2003,
-   2005, 2006, 2007 Free Software Foundation, Inc.
+   2005, 2006, 2007, 2009 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -555,6 +555,17 @@ reader (void)
   gram_scanner_initialize ();
   gram_parse ();
 
+  muscle_percent_define_default ("lr.default_rules", "all");
+
+  /* Check front-end %define variable values.  */
+  {
+    static char const * const values[] = {
+      "lr.default_rules", "all", "consistent", "accepting", NULL,
+      NULL
+    };
+    muscle_percent_define_check_values (values);
+  }
+
   if (! complaint_issued)
     check_and_convert_grammar ();
 
