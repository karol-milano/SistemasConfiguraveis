@@ -66,9 +66,6 @@ set_nullable (void)
      Supposedly NRITEMS - NRULES is enough.  But why take the risk?  */
   rule_list_t *relts = XCALLOC (rule_list_t, nritems + nvars + 1);
 
-  if (trace_flag)
-    fprintf (stderr, "Entering set_nullable\n");
-
   nullable = XCALLOC (char, nvars) - ntokens;
 
   s1 = s2 = squeue;
@@ -128,7 +125,7 @@ set_nullable (void)
   XFREE (rsets + ntokens);
   XFREE (relts);
 
-  if (trace_flag)
+  if (trace_flag & trace_sets)
     nullable_print (stderr);
 }
 
