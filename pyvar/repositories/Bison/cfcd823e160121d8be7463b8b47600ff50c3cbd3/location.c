@@ -175,6 +175,8 @@ location_print (location loc, FILE *out)
     }
   else
     {
+      aver (loc.start.file);
+      aver (loc.end.file);
       int end_col = 0 != loc.end.column ? loc.end.column - 1 : 0;
       res += fprintf (out, "%s",
                       quotearg_n_style (3, escape_quoting_style, loc.start.file));
