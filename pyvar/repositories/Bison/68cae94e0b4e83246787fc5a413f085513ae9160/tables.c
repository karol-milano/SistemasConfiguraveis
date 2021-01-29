@@ -202,16 +202,14 @@ conflict_row (state *s)
 	      && (actrow[j]
 		  != rule_number_as_item_number (reds->rules[i]->number)))
 	    {
-	      if (conflict_list_free <= 0)
-		abort ();
+	      assert (0 < conflict_list_free);
 	      conflict_list[conflict_list_cnt] = reds->rules[i]->number + 1;
 	      conflict_list_cnt += 1;
 	      conflict_list_free -= 1;
 	    }
 
 	/* Leave a 0 at the end.  */
-	if (conflict_list_free <= 0)
-	  abort ();
+	assert (0 < conflict_list_free);
 	conflict_list[conflict_list_cnt] = 0;
 	conflict_list_cnt += 1;
 	conflict_list_free -= 1;
@@ -675,16 +673,14 @@ pack_vector (vector_number vector)
   base_number *to = tos[i];
   unsigned int *conflict_to = conflict_tos[i];
 
-  if (!t)
-    abort ();
+  assert (t);
 
   for (j = lowzero - from[0]; ; j++)
     {
       int k;
       bool ok = true;
 
-      if (table_size <= j)
-	abort ();
+      assert (j < table_size);
 
       for (k = 0; ok && k < t; k++)
 	{
@@ -717,8 +713,7 @@ pack_vector (vector_number vector)
 	  if (loc > high)
 	    high = loc;
 
-	  if (! (BASE_MINIMUM <= j && j <= BASE_MAXIMUM))
-	    abort ();
+	  assert (BASE_MINIMUM <= j && j <= BASE_MAXIMUM);
 	  return j;
 	}
     }
