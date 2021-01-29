@@ -156,6 +156,25 @@ map_goto (state_number src, symbol_number sym)
     }
 }
 
+/* Print FOLLOWS for debugging.  */
+static void
+follows_print (const char* title, FILE *out)
+{
+  fprintf (out, "%s:\n", title);
+  for (goto_number i = 0; i < ngotos; ++i)
+    {
+      fputs ("    FOLLOWS[", out);
+      goto_print (i, out);
+      fputs ("] =", out);
+      bitset_iterator iter;
+      symbol_number sym;
+      BITSET_FOR_EACH (iter, goto_follows[i], sym, 0)
+        fprintf (out, " %s", symbols[sym]->tag);
+      fputc ('\n', out);
+    }
+  fputc ('\n', out);
+}
+
 /* Build goto_follows. */
 static void
 initialize_goto_follows (void)
@@ -192,10 +211,15 @@ initialize_goto_follows (void)
           nedges = 0;
         }
     }
-
   if (trace_flag & trace_automaton)
-    relation_print ("reads", reads, ngotos, goto_print, stderr);
+    {
+      follows_print ("follows after shifts", stderr);
+      relation_print ("reads", reads, ngotos, goto_print, stderr);
+    }
+
   relation_digraph (reads, ngotos, goto_follows);
+  if (trace_flag & trace_automaton)
+    follows_print ("follows after read", stderr);
 
   for (goto_number i = 0; i < ngotos; ++i)
     free (reads[i]);
@@ -287,33 +311,13 @@ build_relations (void)
     relation_print ("includes", includes, ngotos, goto_print, stderr);
 }
 
-/* Print FOLLOWS for debugging.  */
-static void
-follows_print (FILE *out)
-{
-  for (goto_number i = 0; i < ngotos; ++i)
-    {
-      fputs ("FOLLOWS[", out);
-      goto_print (i, out);
-      fputs ("] =", out);
-      bitset_iterator iter;
-      symbol_number sym;
-      BITSET_FOR_EACH (iter, goto_follows[i], sym, 0)
-        {
-          fputc (' ', out);
-          symbol_print (symbols[sym], out);
-        }
-      fputc ('\n', out);
-    }
-}
-
 /* Compute FOLLOWS from INCLUDES, and free INCLUDES.  */
 static void
 compute_follows (void)
 {
   relation_digraph (includes, ngotos, goto_follows);
   if (trace_flag & trace_sets)
-    follows_print (stderr);
+    follows_print ("follows after includes", stderr);
   for (goto_number i = 0; i < ngotos; ++i)
     free (includes[i]);
   free (includes);
@@ -423,32 +427,28 @@ initialize_LA (void)
 static void
 lookahead_tokens_print (FILE *out)
 {
-  fprintf (out, "Lookahead tokens: BEGIN\n");
+  fputs ("Lookaheads:\n", out);
   for (state_number i = 0; i < nstates; ++i)
     {
       const reductions *reds = states[i]->reductions;
-      int n_lookahead_tokens = 0;
-
-      if (reds->lookahead_tokens)
-        for (int j = 0; j < reds->num; ++j)
-          if (reds->lookahead_tokens[j])
-            ++n_lookahead_tokens;
-
-      fprintf (out, "State %d: %d lookahead tokens\n",
-               i, n_lookahead_tokens);
-
-      if (reds->lookahead_tokens)
-        for (int j = 0; j < reds->num; ++j)
-          {
-            bitset_iterator iter;
-            int k;
-            BITSET_FOR_EACH (iter, reds->lookahead_tokens[j], k, 0)
-              fprintf (out, "   on %d (%s) -> rule %d\n",
-                       k, symbols[k]->tag,
-                       reds->rules[j]->number);
-          }
+      if (reds->num)
+        {
+          fprintf (out, "  State %d:\n", i);
+          for (int j = 0; j < reds->num; ++j)
+            {
+              fprintf (out, "    rule %d:", reds->rules[j]->number);
+              if (reds->lookahead_tokens)
+              {
+                bitset_iterator iter;
+                int k;
+                BITSET_FOR_EACH (iter, reds->lookahead_tokens[j], k, 0)
+                  fprintf (out, " %s", symbols[k]->tag);
+              }
+              fputc ('\n', out);
+            }
+        }
     }
-  fprintf (out, "Lookahead tokens: END\n");
+  fputc ('\n', out);
 }
 
 void
