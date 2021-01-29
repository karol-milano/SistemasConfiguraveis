@@ -78,6 +78,11 @@ columns (void)
 /* Available screen width.  */
 static int screen_width = 80;
 
+/* The ellipsis symbol to use for this locale, and the number of
+   screen-columns it uses.  */
+static const char *ellipsis = "...";
+static int ellipsize = 3;
+
 /* If BUF is null, add BUFSIZE (which in this case must be less than
    INT_MAX) to COLUMN; otherwise, add mbsnwidth (BUF, BUFSIZE, 0) to
    COLUMN.  If an overflow occurs, return INT_MAX.  */
@@ -145,6 +150,7 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
     complain (loc, Wother, _("line number overflow"));
   if (loc->end.column == INT_MAX && loc->start.column != INT_MAX)
     complain (loc, Wother, _("column number overflow"));
+  /* TRANSLATORS: we are counting bytes, and there are too many.  */
   if (loc->end.byte == INT_MAX && loc->start.byte != INT_MAX)
     complain (loc, Wother, _("byte number overflow"));
 }
@@ -236,6 +242,10 @@ static struct
 void caret_init (void)
 {
   screen_width = columns ();
+  /* TRANSLATORS: use the appropriate character (e.g. "…") if
+     available.  */
+  ellipsis = _("...");
+  ellipsize = mbswidth (ellipsis, 0);
 }
 
 void
@@ -376,11 +386,11 @@ caret_set_column (int col)
     }
   /* If we skip the initial part, we insert "..." before.  */
   if (caret_info.skip)
-    caret_info.width -= 3;
+    caret_info.width -= ellipsize;
   /* If the end of line does not fit, we also need to truncate the
      end, and leave "..." there.  */
   if (caret_info.width < caret_info.line_len - caret_info.skip)
-    caret_info.width -= 3;
+    caret_info.width -= ellipsize;
   return true;
 }
 
@@ -418,7 +428,7 @@ location_caret (location loc, const char *style, FILE *out)
         /* Quote the file (at most the first line in the case of
            multiline locations).  */
         {
-          fprintf (out, "%5d | %s", loc.start.line, skip ? "..." : "");
+          fprintf (out, "%5d | %s", loc.start.line, skip ? ellipsis : "");
           /* Whether we opened the style.  If the line is not as
              expected (maybe the file was changed since the scanner
              ran), we might reach the end before we actually saw the
@@ -444,7 +454,7 @@ location_caret (location loc, const char *style, FILE *out)
                 }
               if (width < caret_info.pos.column - skip)
                 {
-                  fprintf (out, "...");
+                  fputs (ellipsis, out);
                   break;
                 }
             }
@@ -454,7 +464,7 @@ location_caret (location loc, const char *style, FILE *out)
         /* Print the carets with the same indentation as above.  */
         {
           fprintf (out, "      | %*s",
-                   loc.start.column - 1 - skip + (skip ? 3 : 0), "");
+                   loc.start.column - 1 - skip + (skip ? ellipsize : 0), "");
           begin_use_class (style, out);
           putc ('^', out);
           /* Underlining a multiline location ends with the first
@@ -475,7 +485,8 @@ location_caret_suggestion (location loc, const char *s, FILE *out)
 {
   const char *style = "fixit-insert";
   fprintf (out, "      | %*s",
-           loc.start.column - 1 - caret_info.skip + (caret_info.skip ? 3 : 0),
+           loc.start.column - 1 - caret_info.skip
+           + (caret_info.skip ? ellipsize : 0),
            "");
   begin_use_class (style, out);
   fputs (s, out);
