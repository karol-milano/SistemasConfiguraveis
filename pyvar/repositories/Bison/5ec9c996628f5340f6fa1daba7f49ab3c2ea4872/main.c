@@ -155,31 +155,34 @@ main (int argc, char *argv[])
 
   print_precedence_warnings ();
 
-  /* Output file names. */
-  compute_output_file_names ();
-
-  /* Output the detailed report on the grammar.  */
-  if (report_flag)
+  if (!update_flag)
     {
-      timevar_push (tv_report);
-      print_results ();
-      timevar_pop (tv_report);
-    }
-
-  /* Output the graph.  */
-  if (graph_flag)
-    {
-      timevar_push (tv_graph);
-      print_graph ();
-      timevar_pop (tv_graph);
-    }
-
-  /* Output xml.  */
-  if (xml_flag)
-    {
-      timevar_push (tv_xml);
-      print_xml ();
-      timevar_pop (tv_xml);
+      /* Output file names. */
+      compute_output_file_names ();
+
+      /* Output the detailed report on the grammar.  */
+      if (report_flag)
+        {
+          timevar_push (tv_report);
+          print_results ();
+          timevar_pop (tv_report);
+        }
+
+      /* Output the graph.  */
+      if (graph_flag)
+        {
+          timevar_push (tv_graph);
+          print_graph ();
+          timevar_pop (tv_graph);
+        }
+
+      /* Output xml.  */
+      if (xml_flag)
+        {
+          timevar_push (tv_xml);
+          print_xml ();
+          timevar_pop (tv_xml);
+        }
     }
 
   /* Stop if there were errors, to avoid trashing previous output
@@ -193,9 +196,12 @@ main (int argc, char *argv[])
   timevar_pop (tv_free);
 
   /* Output the tables and the parser to ftable.  In file output.  */
-  timevar_push (tv_parser);
-  output ();
-  timevar_pop (tv_parser);
+  if (!update_flag)
+    {
+      timevar_push (tv_parser);
+      output ();
+      timevar_pop (tv_parser);
+    }
 
   timevar_push (tv_free);
   nullable_free ();
