@@ -28,24 +28,17 @@
 #include <mbswidth.h>
 #include <unicodeio.h>
 
-// In gnulib/lib/unicodeio.h unicode_to_mb uses a buffer of 25 bytes.
-typedef char glyph_buffer_t[26];
 
-
-static glyph_buffer_t arrow_buf;
-const char *arrow;
+glyph_buffer_t arrow;
 int arrow_width;
 
-static glyph_buffer_t down_arrow_buf;
-const char *down_arrow;
+glyph_buffer_t down_arrow;
 int down_arrow_width;
 
-static glyph_buffer_t dot_buf;
-const char *dot;
+glyph_buffer_t dot;
 int dot_width;
 
-static glyph_buffer_t empty_buf;
-const char *empty;
+glyph_buffer_t empty;
 int empty_width;
 
 const char *derivation_separator = " ";
@@ -53,8 +46,7 @@ int derivation_separator_width = 1;
 
 typedef struct
 {
-  const char **glyph;
-  char *buf;
+  glyph_buffer_t *pbuf;
   const char *fallback;
 } callback_arg_t;
 
@@ -63,8 +55,8 @@ static long
 on_success (const char *buf, size_t buflen, void *callback_arg)
 {
   callback_arg_t *arg = (callback_arg_t *) callback_arg;
-  assert (buflen + 1 < sizeof arg->buf);
-  *stpncpy (arg->buf, buf, buflen) = '\0';
+  assert (buflen + 1 < sizeof *arg->pbuf);
+  *stpncpy (*arg->pbuf, buf, buflen) = '\0';
   return 1;
 }
 
@@ -73,19 +65,17 @@ on_failure (unsigned code MAYBE_UNUSED, const char *msg MAYBE_UNUSED,
             void *callback_arg)
 {
   callback_arg_t *arg = (callback_arg_t *) callback_arg;
-  assert (strlen (arg->fallback) + 1 < sizeof arg->buf);
-  strcpy (arg->buf, arg->fallback);
+  assert (strlen (arg->fallback) + 1 < sizeof *arg->pbuf);
+  strcpy (*arg->pbuf, arg->fallback);
   return 0;
 }
 
 static bool
-glyph_set (const char **glyph,
-           char buf[26], int *width,
+glyph_set (glyph_buffer_t *glyph, int *width,
            unsigned code, const char *fallback)
 {
-  callback_arg_t arg = { glyph, buf, fallback };
+  callback_arg_t arg = { glyph, fallback };
   int res = unicode_to_mb (code, on_success, on_failure, &arg);
-  *glyph = buf;
   *width = mbswidth (*glyph, 0);
   return res;
 }
@@ -93,11 +83,11 @@ glyph_set (const char **glyph,
 void
 glyphs_init (void)
 {
-  glyph_set (&arrow,      arrow_buf,      &arrow_width,      0x2192, "->");
-  glyph_set (&dot,        dot_buf,        &dot_width,        0x2022, ".");
-  glyph_set (&down_arrow, down_arrow_buf, &down_arrow_width, 0x21b3, "`->");
-  glyph_set (&empty,      empty_buf,      &empty_width,      0x03b5, "%empty");
+  glyph_set (&arrow,      &arrow_width,      0x2192, "->");
+  glyph_set (&dot,        &dot_width,        0x2022, ".");
+  glyph_set (&down_arrow, &down_arrow_width, 0x21b3, "`->");
+  glyph_set (&empty,      &empty_width,      0x03b5, "%empty");
 
-  strncat (down_arrow_buf, " ", sizeof down_arrow_buf - strlen (down_arrow_buf) - 1);
+  strncat (down_arrow, " ", sizeof down_arrow - strlen (down_arrow) - 1);
   down_arrow_width += 1;
 }
