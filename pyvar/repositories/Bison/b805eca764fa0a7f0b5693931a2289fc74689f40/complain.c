@@ -89,7 +89,7 @@ error_message (const location *loc, warnings flags, const char *prefix,
   unsigned pos = 0;
 
   if (loc)
-    pos += location_print (stderr, *loc);
+    pos += location_print (*loc, stderr);
   else
     pos += fprintf (stderr, "%s", current_file ? current_file : program_name);
   pos += fprintf (stderr, ": ");
@@ -117,7 +117,7 @@ error_message (const location *loc, warnings flags, const char *prefix,
         putc ('\n', stderr);
         fflush (stderr);
         if (loc && feature_flag & feature_caret && !(flags & no_caret))
-          location_caret (stderr, *loc);
+          location_caret (*loc, stderr);
       }
   }
   fflush (stderr);
