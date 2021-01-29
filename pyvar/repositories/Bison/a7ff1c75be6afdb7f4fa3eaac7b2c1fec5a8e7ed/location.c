@@ -209,7 +209,7 @@ location_caret (location loc, FILE *out)
           /* Print the carets (at least one), with the same indent as above.*/
           fprintf (out, " %*s", loc.start.column - 1, "");
           for (i = loc.start.column; i == loc.start.column || i < len; ++i)
-            putc ('^', out);
+            putc (i == loc.start.column ? '^' : '~', out);
           }
         putc ('\n', out);
       }
