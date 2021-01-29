@@ -242,8 +242,11 @@ static struct
 void caret_init (void)
 {
   screen_width = columns ();
-  /* TRANSLATORS: use the appropriate character (e.g. "…") if
-     available.  */
+  /* TRANSLATORS: This is used when a line is too long, and is
+     displayed truncated.  Use an ellipsis appropriate for your
+     language, remembering that "…" (U+2026 HORIZONTAL ELLIPSIS)
+     sometimes misdisplays and that "..." (three ASCII periods) is a
+     safer choice in some locales.  */
   ellipsis = _("...");
   ellipsize = mbswidth (ellipsis, 0);
 }
