@@ -1,4 +1,4 @@
-/* Output the generated parsing program for bison,
+/* Output the generated parsing program for Bison.
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
@@ -235,7 +235,8 @@ prepare_rules (void)
       /* Merger-function index (GLR).  */
       merger[r] = rules[r].merger;
     }
-  assert (i == nritems);
+  if (i != nritems)
+    abort ();
 
   muscle_insert_item_number_table ("rhs", rhs, ritem[0], 1, nritems);
   muscle_insert_unsigned_int_table ("prhs", prhs, 0, 0, nrules);
@@ -345,7 +346,8 @@ token_definitions_output (FILE *out)
       /* At this stage, if there are literal aliases, they are part of
 	 SYMBOLS, so we should not find symbols which are the aliases
 	 here.  */
-      assert (number != USER_NUMBER_ALIAS);
+      if (number == USER_NUMBER_ALIAS)
+	abort ();
 
       /* Skip error token.  */
       if (symbol == errtoken)
