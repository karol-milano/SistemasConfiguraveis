@@ -178,10 +178,10 @@ location_print (location loc, FILE *out)
       int end_col = 0 != loc.end.column ? loc.end.column - 1 : 0;
       res += fprintf (out, "%s",
                       quotearg_n_style (3, escape_quoting_style, loc.start.file));
-      if (0 <= loc.start.line)
+      if (0 < loc.start.line)
         {
           res += fprintf (out, ":%d", loc.start.line);
-          if (0 <= loc.start.column)
+          if (0 < loc.start.column)
             res += fprintf (out, ".%d", loc.start.column);
         }
       if (loc.start.file != loc.end.file)
@@ -189,14 +189,14 @@ location_print (location loc, FILE *out)
           res += fprintf (out, "-%s",
                           quotearg_n_style (3, escape_quoting_style,
                                             loc.end.file));
-          if (0 <= loc.end.line)
+          if (0 < loc.end.line)
             {
               res += fprintf (out, ":%d", loc.end.line);
               if (0 <= end_col)
                 res += fprintf (out, ".%d", end_col);
             }
         }
-      else if (0 <= loc.end.line)
+      else if (0 < loc.end.line)
         {
           if (loc.start.line < loc.end.line)
             {
@@ -400,7 +400,7 @@ caret_set_column (int col)
 void
 location_caret (location loc, const char *style, FILE *out)
 {
-  if (loc.start.column == -1 || loc.start.line == -1)
+  if (!loc.start.line)
     return;
   if (!caret_set_file (loc.start.file))
     return;
