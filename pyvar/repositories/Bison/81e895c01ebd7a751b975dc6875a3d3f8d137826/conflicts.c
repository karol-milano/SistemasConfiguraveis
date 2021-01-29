@@ -477,8 +477,8 @@ conflicts_print (void)
       && src_total != expected_conflicts)
     {
       complain_message_count++;
-      fprintf (stderr, ngettext ("expected %d shift/reduce conflict",
-				 "expected %d shift/reduce conflicts",
+      fprintf (stderr, ngettext ("expected %d shift/reduce conflict\n",
+				 "expected %d shift/reduce conflicts\n",
 				 expected_conflicts),
 	       expected_conflicts);
     }
