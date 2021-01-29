@@ -114,7 +114,7 @@ error_message (const location *loc, warnings flags, const char *prefix,
       {
         putc ('\n', stderr);
         fflush (stderr);
-        if (loc && feature_flag & feature_caret)
+        if (loc && feature_flag & feature_caret && !(flags & no_caret))
           location_caret (stderr, *loc);
       }
   }
