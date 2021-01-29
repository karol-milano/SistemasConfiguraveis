@@ -161,6 +161,21 @@ fixits_run (void)
             break;
           ++offset;
         }
+      /* If erasing the content of a full line, also remove the
+         end-of-line. */
+      if (f->fix[0] == 0 && f->location.start.column == 1)
+        {
+          int c = getc (in);
+          if (c == EOF)
+            break;
+          else if (c == '\n')
+            {
+              ++line;
+              offset = 1;
+            }
+          else
+            ungetc (c, in);
+        }
     }
   /* Paste the rest of the file.  */
   {
