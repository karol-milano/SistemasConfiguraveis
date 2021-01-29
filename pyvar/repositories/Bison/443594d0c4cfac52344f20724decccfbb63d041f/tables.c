@@ -1,4 +1,4 @@
-/* Output the generated parsing program for bison,
+/* Output the generated parsing program for Bison.
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
@@ -33,9 +33,9 @@
 #include "conflicts.h"
 #include "tables.h"
 
-/* Several tables will be indexed both by state and nonterminal
-   numbers.  We call `vector' such a thing (= either a state or a
-   symbol number.
+/* Several tables are indexed both by state and nonterminal numbers.
+   We call such an index a `vector'; i.e., a vector is either a state
+   or a nonterminal number.
 
    Of course vector_number_t ought to be wide enough to contain
    state_number_t and symbol_number_t.  */
@@ -190,14 +190,16 @@ conflict_row (state_t *state)
 	      && (actrow[j]
 		  != rule_number_as_item_number (reds->rules[i]->number)))
 	    {
-	      assert (conflict_list_free > 0);
+	      if (conflict_list_free <= 0)
+		abort ();
 	      conflict_list[conflict_list_cnt] = reds->rules[i]->number + 1;
 	      conflict_list_cnt += 1;
 	      conflict_list_free -= 1;
 	    }
 
 	/* Leave a 0 at the end.  */
-	assert (conflict_list_free > 0);
+	if (conflict_list_free <= 0)
+	  abort ();
 	conflict_list_cnt += 1;
 	conflict_list_free -= 1;
       }
@@ -654,13 +656,17 @@ pack_vector (vector_number_t vector)
   base_t *to = tos[i];
   unsigned int *conflict_to = conflict_tos[i];
 
-  assert (t);
+  if (! t)
+    abort ();
 
-  for (j = lowzero - from[0]; j < (int) table_size; j++)
+  for (j = lowzero - from[0]; ; j++)
     {
       int k;
       int ok = 1;
 
+      if ((int) table_size <= j)
+	abort ();
+
       for (k = 0; ok && k < t; k++)
 	{
 	  loc = j + state_number_as_int (from[k]);
@@ -692,13 +698,11 @@ pack_vector (vector_number_t vector)
 	  if (loc > high)
 	    high = loc;
 
-	  assert (BASE_MIN <= j && j <= BASE_MAX);
+	  if (! (BASE_MIN <= j && j <= BASE_MAX))
+	    abort ();
 	  return j;
 	}
     }
-#define pack_vector_succeeded 0
-  assert (pack_vector_succeeded);
-  return 0;
 }
 
 
@@ -784,11 +788,12 @@ tables_generate (void)
 {
   int i;
 
-  /* That's a poor way to make sure the sizes are properly corelated,
-     in particular the signedness is not taking into account, but it's
-     not useless.  */
-  assert (sizeof (nvectors) >= sizeof (nstates));
-  assert (sizeof (nvectors) >= sizeof (nvars));
+  /* This is a poor way to make sure the sizes are properly
+     correlated.  In particular the signedness is not taken into
+     account.  But it's not useless.  */
+  verify (sizes_are_properly_correlated,
+	  (sizeof nstates <= sizeof nvectors
+	   && sizeof nvars <= sizeof nvectors));
 
   nvectors = state_number_as_int (nstates) + nvars;
 
