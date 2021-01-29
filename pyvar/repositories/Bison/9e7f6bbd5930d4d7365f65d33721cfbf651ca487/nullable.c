@@ -57,8 +57,8 @@ set_nullable (void)
      Hence we must allocate room for useless nonterminals too.  */
   shorts **rsets = XCALLOC (shorts *, nvars) - ntokens;
   /* This is said to be more elements than we actually use.
-     Supposedly nitems - nrules is enough.  But why take the risk?  */
-  shorts *relts = XCALLOC (shorts, nitems + nvars + 1);
+     Supposedly NRITEMS - NRULES is enough.  But why take the risk?  */
+  shorts *relts = XCALLOC (shorts, nritems + nvars + 1);
 
   if (trace_flag)
     fprintf (stderr, "Entering set_nullable\n");
