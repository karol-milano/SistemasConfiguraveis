@@ -275,8 +275,9 @@ output_rule_data (void)
       obstack_sgrow (&format_obstack, ", ");
       j += strsize;
     }
-  /* add a NULL entry to list of tokens */
-  obstack_sgrow (&format_obstack, "NULL");
+  /* Add a NULL entry to list of tokens (well, 0, as NULL might not be
+     defined).  */
+  obstack_sgrow (&format_obstack, "0");
 
   /* Finish table and store. */
   obstack_1grow (&format_obstack, 0);
