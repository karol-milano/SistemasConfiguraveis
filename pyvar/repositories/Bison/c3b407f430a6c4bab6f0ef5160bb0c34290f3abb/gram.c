@@ -1,5 +1,5 @@
 /* Allocate input grammar variables for bison,
-   Copyright 1984, 1986, 1989, 2001 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -51,6 +51,21 @@ int pure_parser;
 int error_token_number;
 
 
+/*--------------------------------------.
+| Return the number of symbols in RHS.  |
+`--------------------------------------*/
+
+int
+rule_rhs_length (rule_t *rule)
+{
+  int res = 0;
+  short *rhsp;
+  for (rhsp = rule->rhs; *rhsp >= 0; ++rhsp)
+    ++res;
+  return res;
+}
+
+
 /*------------------------.
 | Dump RITEM for traces.  |
 `------------------------*/
@@ -76,23 +91,15 @@ ritem_print (FILE *out)
 size_t
 ritem_longest_rhs (void)
 {
-  int length;
-  int max;
+  int max = 0;
   int i;
 
-  length = 0;
-  max = 0;
-  for (i = 0; i < nritems; ++i)
-    if (ritem[i] >= 0)
-      {
-	length++;
-      }
-    else
-      {
-	if (length > max)
-	  max = length;
-	length = 0;
-      }
+  for (i = 1; i < nrules + 1; ++i)
+    {
+      int length = rule_rhs_length (&rules[i]);
+      if (length > max)
+	max = length;
+    }
 
   return max;
 }
