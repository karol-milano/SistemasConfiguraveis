@@ -1009,6 +1009,8 @@ output_parser (void)
 	      obstack_sgrow (&table_obstack, macro_key);
 	    }
 	}
+      else
+	obstack_1grow (&table_obstack, '%');
     }
 
   /* End. */
