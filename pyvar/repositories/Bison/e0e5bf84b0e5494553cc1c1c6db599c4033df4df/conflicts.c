@@ -432,7 +432,7 @@ conflicts_output (FILE *out)
 int
 conflicts_total_count (void)
 {
-  int i;
+  unsigned i;
   int count;
 
   /* Conflicts by state.  */
@@ -445,7 +445,7 @@ conflicts_total_count (void)
       }
   return count;
 }
- 
+
 
 /*------------------------------------------.
 | Reporting the total number of conflicts.  |
