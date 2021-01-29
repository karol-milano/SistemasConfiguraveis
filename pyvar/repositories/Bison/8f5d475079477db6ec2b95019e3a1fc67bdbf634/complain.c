@@ -424,12 +424,12 @@ error_message (const location *loc, warnings flags, severity sever,
     if (l < 2 || message[l - 2] != ':' || message[l - 1] != ' ')
       {
         putc ('\n', stderr);
-        fflush (stderr);
+        flush (stderr);
         if (loc && feature_flag & feature_caret && !(flags & no_caret))
           location_caret (*loc, style, stderr);
       }
   }
-  fflush (stderr);
+  flush (stderr);
 }
 
 /** Raise a complaint (fatal error, error or just warning).  */
