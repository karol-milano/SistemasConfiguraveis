@@ -1,7 +1,7 @@
 /* Output the generated parsing program for Bison.
 
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004,
-   2005 Free Software Foundation, Inc.
+   2005, 2006 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -202,14 +202,14 @@ conflict_row (state *s)
 	      && (actrow[j]
 		  != rule_number_as_item_number (reds->rules[i]->number)))
 	    {
-	      assert (0 < conflict_list_free);
+	      aver (0 < conflict_list_free);
 	      conflict_list[conflict_list_cnt] = reds->rules[i]->number + 1;
 	      conflict_list_cnt += 1;
 	      conflict_list_free -= 1;
 	    }
 
 	/* Leave a 0 at the end.  */
-	assert (0 < conflict_list_free);
+	aver (0 < conflict_list_free);
 	conflict_list[conflict_list_cnt] = 0;
 	conflict_list_cnt += 1;
 	conflict_list_free -= 1;
@@ -673,14 +673,14 @@ pack_vector (vector_number vector)
   base_number *to = tos[i];
   unsigned int *conflict_to = conflict_tos[i];
 
-  assert (t);
+  aver (t != 0);
 
   for (j = lowzero - from[0]; ; j++)
     {
       int k;
       bool ok = true;
 
-      assert (j < table_size);
+      aver (j < table_size);
 
       for (k = 0; ok && k < t; k++)
 	{
@@ -713,7 +713,7 @@ pack_vector (vector_number vector)
 	  if (loc > high)
 	    high = loc;
 
-	  assert (BASE_MINIMUM <= j && j <= BASE_MAXIMUM);
+	  aver (BASE_MINIMUM <= j && j <= BASE_MAXIMUM);
 	  return j;
 	}
     }
