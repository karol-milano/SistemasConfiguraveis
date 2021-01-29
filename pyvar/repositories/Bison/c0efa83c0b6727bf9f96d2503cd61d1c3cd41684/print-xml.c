@@ -45,7 +45,8 @@ struct escape_buf
   char *ptr;
   size_t size;
 };
-static struct escape_buf escape_bufs[3];
+enum { num_escape_bufs = 3 };
+static struct escape_buf escape_bufs[num_escape_bufs];
 
 
 /*--------------------------------.
@@ -496,7 +497,6 @@ xml_escape (char const *str)
 void
 print_xml (void)
 {
-  state_number i;
   int level = 0;
 
   FILE *out = xfopen (spec_xml_file, "w");
@@ -522,8 +522,11 @@ print_xml (void)
   /* print automaton */
   fputc ('\n', out);
   xml_puts (out, level + 1, "<automaton>");
-  for (i = 0; i < nstates; i++)
-    print_state (out, level + 2, states[i]);
+  {
+    state_number i;
+    for (i = 0; i < nstates; i++)
+      print_state (out, level + 2, states[i]);
+  }
   xml_puts (out, level + 1, "</automaton>");
 
   bitset_free (no_reduce_set);
@@ -531,8 +534,11 @@ print_xml (void)
 
   xml_puts (out, 0, "</bison-xml-report>");
 
-  free (escape_bufs[0].ptr);
-  free (escape_bufs[1].ptr);
+  {
+    int i;
+    for (i = 0; i < num_escape_bufs; ++i)
+      free (escape_bufs[i].ptr);
+  }
 
   xfclose (out);
 }
