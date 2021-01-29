@@ -1,4 +1,4 @@
-/* Input parser for bison
+/* Input parser for Bison
    Copyright (C) 1984, 1986, 1989, 1992, 1998, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
@@ -452,7 +452,8 @@ packgram (void)
 	p = p->next;
     }
 
-  assert (itemno == nritems);
+  if (itemno != nritems)
+    abort ();
 
   if (trace_flag & trace_sets)
     ritem_print (stderr);
@@ -539,8 +540,8 @@ reader (void)
     grammar = p;
   }
 
-  assert (nsyms <= SYMBOL_NUMBER_MAX);
-  assert (nsyms == ntokens + nvars);
+  if (! (nsyms <= SYMBOL_NUMBER_MAX && nsyms == ntokens + nvars))
+    abort ();
 
   xfclose (finput);
 
