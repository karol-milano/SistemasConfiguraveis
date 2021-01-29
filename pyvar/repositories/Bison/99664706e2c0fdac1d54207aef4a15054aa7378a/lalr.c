@@ -398,10 +398,7 @@ build_relations (void)
 
   relation_transpose (&includes, ngotos);
   if (trace_flag & trace_automaton)
-    {
-      lookback_print (stderr);
-      relation_print ("includes", includes, ngotos, goto_print, stderr);
-    }
+    relation_print ("includes", includes, ngotos, goto_print, stderr);
 }
 
 /* Compute FOLLOWS from INCLUDES, and free INCLUDES.  */
@@ -420,6 +417,9 @@ compute_follows (void)
 static void
 compute_lookahead_tokens (void)
 {
+  if (trace_flag & trace_automaton)
+      lookback_print (stderr);
+
   for (size_t i = 0; i < nLA; ++i)
     for (goto_list *sp = lookback[i]; sp; sp = sp->next)
       bitset_or (LA[i], LA[i], goto_follows[sp->value]);
