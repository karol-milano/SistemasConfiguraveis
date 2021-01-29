@@ -1,5 +1,5 @@
 /* Find and resolve or report look-ahead conflicts for bison,
-   Copyright 1984, 1989, 1992, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1989, 1992, 2000, 2001 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -418,20 +418,32 @@ conflict_report (int src_num, int rrc_num)
   char *cp = res;
 
   if (src_num == 1)
-    sprintf (cp, _(" 1 shift/reduce conflict"));
+    {
+      sprintf (cp, _(" 1 shift/reduce conflict"));
+      cp += strlen (cp);
+    }
   else if (src_num > 1)
-    sprintf (cp, _(" %d shift/reduce conflicts"), src_num);
-  cp += strlen (cp);
+    {
+      sprintf (cp, _(" %d shift/reduce conflicts"), src_num);
+      cp += strlen (cp);
+    }
 
   if (src_num > 0 && rrc_num > 0)
-    sprintf (cp, _(" and"));
-  cp += strlen (cp);
+    {
+      sprintf (cp, _(" and"));
+      cp += strlen (cp);
+    }
 
   if (rrc_num == 1)
-    sprintf (cp, _(" 1 reduce/reduce conflict"));
+    {
+      sprintf (cp, _(" 1 reduce/reduce conflict"));
+      cp += strlen (cp);
+    }
   else if (rrc_num > 1)
-    sprintf (cp, _(" %d reduce/reduce conflicts"), rrc_num);
-  cp += strlen (cp);
+    {
+      sprintf (cp, _(" %d reduce/reduce conflicts"), rrc_num);
+      cp += strlen (cp);
+    }
 
   *cp++ = '.';
   *cp++ = '\n';
