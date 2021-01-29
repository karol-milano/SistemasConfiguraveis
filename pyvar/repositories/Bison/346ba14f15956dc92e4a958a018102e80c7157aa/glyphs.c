@@ -0,0 +1,86 @@
+/* Graphical symbols.
+
+   Copyright (C) 2020 Free Software Foundation, Inc.
+
+   This file is part of Bison, the GNU Compiler Compiler.
+
+   This program is free software: you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation, either version 3 of the License, or
+   (at your option) any later version.
+
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
+
+#include <config.h>
+
+#include "glyphs.h"
+
+#include <assert.h>
+#include <attribute.h>
+#include <stdbool.h>
+#include <string.h>
+#include <mbswidth.h>
+#include <unicodeio.h>
+
+// In gnulib/lib/unicodeio.h unicode_to_mb uses a buffer of 25 bytes.
+typedef char glyph_buffer_t[26];
+
+
+static glyph_buffer_t arrow_buf;
+const char *arrow;
+int arrow_width;
+
+static glyph_buffer_t dot_buf;
+const char *dot;
+int dot_width;
+
+typedef struct
+{
+  const char **glyph;
+  char *buf;
+  const char *fallback;
+} callback_arg_t;
+
+
+static long
+on_success (const char *buf, size_t buflen, void *callback_arg)
+{
+  callback_arg_t *arg = (callback_arg_t *) callback_arg;
+  assert (buflen < sizeof arg->buf);
+  strncpy (arg->buf, buf, buflen);
+  *arg->glyph = arg->buf;
+  return 1;
+}
+
+static long
+on_failure (unsigned code MAYBE_UNUSED, const char *msg MAYBE_UNUSED,
+            void *callback_arg)
+{
+  callback_arg_t *arg = (callback_arg_t *) callback_arg;
+  *arg->glyph = arg->fallback;
+  return 0;
+}
+
+static bool
+glyph_set (const char **glyph,
+           char buf[26], int *width,
+           unsigned code, const char *fallback)
+{
+  callback_arg_t arg = { glyph, buf, fallback };
+  int res = unicode_to_mb (code, on_success, on_failure, &arg);
+  *width = mbswidth (*glyph, 0);
+  return res;
+}
+
+void
+glyphs_init (void)
+{
+  glyph_set (&arrow,      arrow_buf,      &arrow_width,      0x2192, "->");
+  glyph_set (&dot,        dot_buf,        &dot_width,        0x2022, ".");
+}
