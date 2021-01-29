@@ -188,12 +188,20 @@ main (int argc, char *argv[])
         }
 
       /* Output xml.  */
-      if (xml_flag)
+      if (html_flag || xml_flag)
         {
           timevar_push (tv_xml);
           print_xml ();
           timevar_pop (tv_xml);
         }
+
+      /* Output html.  */
+      if (html_flag)
+        {
+          timevar_push (tv_html);
+          print_html ();
+          timevar_pop (tv_html);
+        }
     }
 
   /* Stop if there were errors, to avoid trashing previous output
