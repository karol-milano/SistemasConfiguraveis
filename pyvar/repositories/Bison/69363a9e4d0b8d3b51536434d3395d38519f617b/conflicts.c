@@ -1,6 +1,6 @@
 /* Find and resolve or report look-ahead conflicts for bison,
 
-   Copyright (C) 1984, 1989, 1992, 2000, 2001, 2002
+   Copyright (C) 1984, 1989, 1992, 2000, 2001, 2002, 2003
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -495,12 +495,12 @@ conflicts_print (void)
   if (expected_conflicts != -1)
     {
       if (! src_ok)
-	complain (ngettext ("expected %d shift/reduce conflict",
-			    "expected %d shift/reduce conflicts",
-			    expected_conflicts),
-		  expected_conflicts);
+	warn (ngettext ("expected %d shift/reduce conflict",
+			"expected %d shift/reduce conflicts",
+			expected_conflicts),
+	      expected_conflicts);
       if (rrc_total)
-	complain (_("expected 0 reduce/reduce conflicts"));
+	warn (_("expected 0 reduce/reduce conflicts"));
     }
 }
 
