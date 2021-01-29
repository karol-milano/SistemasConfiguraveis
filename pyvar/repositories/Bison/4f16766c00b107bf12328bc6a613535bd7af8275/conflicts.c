@@ -1,6 +1,6 @@
 /* Find and resolve or report look-ahead conflicts for bison,
 
-   Copyright (C) 1984, 1989, 1992, 2000, 2001, 2002, 2003
+   Copyright (C) 1984, 1989, 1992, 2000, 2001, 2002, 2003, 2004
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -484,7 +484,7 @@ conflicts_print (void)
 
   if (! glr_parser && rrc_total > 0 && expected_rr_conflicts != -1)
     {
-      warn (_("%expect-rr applies only to GLR parsers"));
+      warn (_("%%expect-rr applies only to GLR parsers"));
       expected_rr_conflicts = -1;
     }
 
