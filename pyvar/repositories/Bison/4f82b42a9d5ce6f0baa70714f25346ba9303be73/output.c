@@ -235,7 +235,7 @@ prepare_rules (void)
       /* Merger-function index (GLR).  */
       merger[r] = rules[r].merger;
     }
-  assert (i == nritems);
+  aver (i == nritems);
 
   muscle_insert_item_number_table ("rhs", rhs, ritem[0], 1, nritems);
   muscle_insert_unsigned_int_table ("prhs", prhs, 0, 0, nrules);
@@ -342,7 +342,7 @@ token_definitions_output (FILE *out)
       /* At this stage, if there are literal aliases, they are part of
 	 SYMBOLS, so we should not find symbols which are the aliases
 	 here.  */
-      assert (number != USER_NUMBER_ALIAS);
+      aver (number != USER_NUMBER_ALIAS);
 
       /* Skip error token.  */
       if (sym == errtoken)
