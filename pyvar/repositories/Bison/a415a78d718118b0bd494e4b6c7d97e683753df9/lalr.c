@@ -68,7 +68,7 @@ static goto_number **includes;
 static goto_list **lookback;
 
 static void
-goto_print (goto_number i, FILE* out)
+goto_print (goto_number i, FILE *out)
 {
   const state_number src = from_state[i];
   const state_number dst = to_state[i];
@@ -193,6 +193,8 @@ initialize_goto_follows (void)
         }
     }
 
+  if (trace_flag & trace_automaton)
+    relation_print ("reads", reads, ngotos, goto_print, stderr);
   relation_digraph (reads, ngotos, goto_follows);
 
   for (goto_number i = 0; i < ngotos; ++i)
@@ -282,15 +284,12 @@ build_relations (void)
 
   relation_transpose (&includes, ngotos);
   if (trace_flag & trace_automaton)
-    {
-      fprintf (stderr, "includes:\n");
-      relation_print (includes, ngotos, goto_print, stderr);
-    }
+    relation_print ("includes", includes, ngotos, goto_print, stderr);
 }
 
 /* Print FOLLOWS for debugging.  */
 static void
-follows_print (FILE* out)
+follows_print (FILE *out)
 {
   for (goto_number i = 0; i < ngotos; ++i)
     {
