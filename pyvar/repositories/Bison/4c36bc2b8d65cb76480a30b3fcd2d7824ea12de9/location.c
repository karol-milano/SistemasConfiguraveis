@@ -107,7 +107,7 @@ location_print (FILE *out, location loc)
                   quotearg_n_style (3, escape_quoting_style, loc.start.file));
   if (0 <= loc.start.line)
     {
-      res += fprintf(out, ":%d", loc.start.line);
+      res += fprintf (out, ":%d", loc.start.line);
       if (0 <= loc.start.column)
         res += fprintf (out, ".%d", loc.start.column);
     }
@@ -118,7 +118,7 @@ location_print (FILE *out, location loc)
                                         loc.end.file));
       if (0 <= loc.end.line)
         {
-          res += fprintf(out, ":%d", loc.end.line);
+          res += fprintf (out, ":%d", loc.end.line);
           if (0 <= end_col)
             res += fprintf (out, ".%d", end_col);
         }
