@@ -469,8 +469,7 @@ packgram (void)
 	p = p->next;
     }
 
-  if (itemno != nritems)
-    abort ();
+  assert (itemno == nritems);
 
   if (trace_flag & trace_sets)
     ritem_print (stderr);
@@ -554,8 +553,7 @@ reader (void)
     grammar = p;
   }
 
-  if (! (nsyms <= SYMBOL_NUMBER_MAXIMUM && nsyms == ntokens + nvars))
-    abort ();
+  assert (nsyms <= SYMBOL_NUMBER_MAXIMUM && nsyms == ntokens + nvars);
 
   xfclose (gram_in);
 
