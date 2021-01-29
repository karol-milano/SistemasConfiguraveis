@@ -257,7 +257,7 @@ caret_set_file (const char *file)
             caret_free ();
         }
     }
-  return caret_info.file;
+  return !!caret_info.file;
 }
 
 void caret_init (void)
