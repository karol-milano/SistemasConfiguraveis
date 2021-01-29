@@ -461,6 +461,12 @@ location_caret (location loc, const char *style, FILE *out)
                   break;
                 }
             }
+          // The line is shorter than expected.
+          if (opened)
+            {
+              end_use_class (style, out);
+              opened = false;
+            }
           putc ('\n', out);
         }
 
