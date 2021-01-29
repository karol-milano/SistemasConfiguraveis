@@ -150,7 +150,7 @@ struct caret_info
 static struct caret_info caret_info = { NULL, 1, 0 };
 
 void
-cleanup_caret ()
+caret_free ()
 {
   if (caret_info.source)
     fclose (caret_info.source);
