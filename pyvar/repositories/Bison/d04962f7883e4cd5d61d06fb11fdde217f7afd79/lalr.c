@@ -193,7 +193,7 @@ initialize_goto_follows (void)
         }
     }
 
-  relation_digraph (reads, ngotos, &goto_follows);
+  relation_digraph (reads, ngotos, goto_follows);
 
   for (goto_number i = 0; i < ngotos; ++i)
     free (reads[i]);
@@ -312,7 +312,7 @@ follows_print (FILE* out)
 static void
 compute_follows (void)
 {
-  relation_digraph (includes, ngotos, &goto_follows);
+  relation_digraph (includes, ngotos, goto_follows);
   if (trace_flag & trace_sets)
     follows_print (stderr);
   for (goto_number i = 0; i < ngotos; ++i)
