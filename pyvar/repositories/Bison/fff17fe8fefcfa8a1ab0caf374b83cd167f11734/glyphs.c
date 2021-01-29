@@ -36,10 +36,21 @@ static glyph_buffer_t arrow_buf;
 const char *arrow;
 int arrow_width;
 
+static glyph_buffer_t down_arrow_buf;
+const char *down_arrow;
+int down_arrow_width;
+
 static glyph_buffer_t dot_buf;
 const char *dot;
 int dot_width;
 
+static glyph_buffer_t empty_buf;
+const char *empty;
+int empty_width;
+
+const char *derivation_separator = " ";
+int derivation_separator_width = 1;
+
 typedef struct
 {
   const char **glyph;
@@ -54,7 +65,6 @@ on_success (const char *buf, size_t buflen, void *callback_arg)
   callback_arg_t *arg = (callback_arg_t *) callback_arg;
   assert (buflen < sizeof arg->buf);
   strncpy (arg->buf, buf, buflen);
-  *arg->glyph = arg->buf;
   return 1;
 }
 
@@ -63,7 +73,8 @@ on_failure (unsigned code MAYBE_UNUSED, const char *msg MAYBE_UNUSED,
             void *callback_arg)
 {
   callback_arg_t *arg = (callback_arg_t *) callback_arg;
-  *arg->glyph = arg->fallback;
+  assert (strlen (arg->fallback) < sizeof arg->buf);
+  strcpy (arg->buf, arg->fallback);
   return 0;
 }
 
@@ -74,6 +85,7 @@ glyph_set (const char **glyph,
 {
   callback_arg_t arg = { glyph, buf, fallback };
   int res = unicode_to_mb (code, on_success, on_failure, &arg);
+  *glyph = buf;
   *width = mbswidth (*glyph, 0);
   return res;
 }
@@ -83,4 +95,9 @@ glyphs_init (void)
 {
   glyph_set (&arrow,      arrow_buf,      &arrow_width,      0x2192, "->");
   glyph_set (&dot,        dot_buf,        &dot_width,        0x2022, ".");
+  glyph_set (&down_arrow, down_arrow_buf, &down_arrow_width, 0x21b3, "`->");
+  glyph_set (&empty,      empty_buf,      &empty_width,      0x03b5, "%empty");
+
+  strncat (down_arrow_buf, " ", sizeof down_arrow_buf - strlen (down_arrow_buf) - 1);
+  down_arrow_width += 1;
 }
