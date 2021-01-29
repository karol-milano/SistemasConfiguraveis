@@ -69,8 +69,8 @@ fixit_print (fixit const *f, FILE *out)
 {
   fprintf (out, "fix-it:%s:{%d:%d-%d:%d}:%s\n",
            quotearg_n_style (1, c_quoting_style, f->location.start.file),
-           f->location.start.line, f->location.start.column,
-           f->location.end.line, f->location.end.column,
+           f->location.start.line, f->location.start.byte,
+           f->location.end.line, f->location.end.byte,
            quotearg_n_style (2, c_quoting_style, f->fix));
 }
 
@@ -136,19 +136,29 @@ fixits_run (void)
             }
           putc (c, out);
         }
+
       /* Look for the right offset. */
-      while (offset < f->location.start.column)
+      bool need_eol = false;
+      while (offset < f->location.start.byte)
         {
           int c = getc (in);
           if (c == EOF)
             break;
           ++offset;
-          putc (c, out);
+          if (c == '\n')
+            /* The position we are asked for is beyond the actual
+               line: pad with spaces, and remember we need a \n.  */
+            need_eol = true;
+          putc (need_eol ? ' ' : c, out);
         }
 
       /* Paste the fix instead. */
       fputs (f->fix, out);
 
+      /* Maybe install the eol afterwards.  */
+      if (need_eol)
+        putc ('\n', out);
+
       /* Skip the bad input. */
       while (line < f->location.end.line)
         {
@@ -161,16 +171,17 @@ fixits_run (void)
               offset = 1;
             }
         }
-      while (offset < f->location.end.column)
+      while (offset < f->location.end.byte)
         {
           int c = getc (in);
           if (c == EOF)
             break;
           ++offset;
         }
+
       /* If erasing the content of a full line, also remove the
          end-of-line. */
-      if (f->fix[0] == 0 && f->location.start.column == 1)
+      if (f->fix[0] == 0 && f->location.start.byte == 1)
         {
           int c = getc (in);
           if (c == EOF)
