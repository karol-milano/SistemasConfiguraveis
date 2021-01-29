@@ -322,6 +322,10 @@ location_caret (location loc, const char *style, FILE *out)
   /* If we skip the initial part, we insert "..." before.  */
   if (skip)
     width -= 3;
+  /* If the end of line does not fit, we also need to truncate the
+     end, and leave "..." there.  */
+  if (width < line_len - skip)
+    width -= 3;
 
   /* Go back to the beginning of line.  */
   fseek (caret_info.file, caret_info.offset, SEEK_SET);
@@ -374,7 +378,10 @@ location_caret (location loc, const char *style, FILE *out)
                   opened = false;
                 }
               if (width < caret_info.pos.column - skip)
-                break;
+                {
+                  fprintf (out, "...");
+                  break;
+                }
             }
           putc ('\n', out);
         }
