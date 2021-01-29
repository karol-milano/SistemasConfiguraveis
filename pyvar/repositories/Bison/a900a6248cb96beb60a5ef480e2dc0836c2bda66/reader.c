@@ -1740,7 +1740,7 @@ packgram (void)
   int ruleno;
   symbol_list *p;
 
-  ritem = XCALLOC (item_number_t, nritems + 1);
+  ritem = XCALLOC (item_number_t, nritems);
   rules = XCALLOC (rule_t, nrules) - 1;
 
   itemno = 0;
@@ -1787,7 +1787,6 @@ packgram (void)
 	p = p->next;
     }
 
-  ritem[itemno] = 0;
   assert (itemno == nritems);
 
   if (trace_flag)
