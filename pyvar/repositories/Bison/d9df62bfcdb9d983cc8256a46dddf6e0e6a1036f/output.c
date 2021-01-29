@@ -132,6 +132,56 @@ string_output (FILE *out, char const *string)
 }
 
 
+/* Store in BUFFER a copy of SRC where trigraphs are escaped, return
+   the size of the result (including the final NUL).  If called with
+   BUFFERSIZE = 0, returns the needed size for BUFFER.  */
+static ptrdiff_t
+escape_trigraphs (char *buffer, ptrdiff_t buffersize, const char *src)
+{
+#define STORE(c)                                \
+  do                                            \
+    {                                           \
+      if (res < buffersize)                     \
+        buffer[res] = (c);                      \
+      ++res;                                    \
+    }                                           \
+  while (0)
+  ptrdiff_t res = 0;
+  for (ptrdiff_t i = 0, len = strlen (src); i < len; ++i)
+    {
+      if (i + 2 < len
+          && src[i] == '?' && src[i+1] == '?')
+        {
+          switch (src[i+2])
+            {
+            case '!': case '\'':
+            case '(': case ')': case '-': case '/':
+            case '<': case '=': case '>':
+              i += 1;
+              STORE ('?');
+              STORE ('"');
+              STORE ('"');
+              STORE ('?');
+              continue;
+            }
+        }
+      STORE (src[i]);
+    }
+  STORE ('\0');
+#undef STORE
+  return res;
+}
+
+/* Same as xstrdup, except that trigraphs are escaped.  */
+static char *
+xescape_trigraphs (const char *src)
+{
+  ptrdiff_t bufsize = escape_trigraphs (NULL, 0, src);
+  char *buf = xcharalloc (bufsize);
+  escape_trigraphs (buf, bufsize, src);
+  return buf;
+}
+
 /* Generate the b4_<MUSCLE_NAME> (e.g., b4_tname) table with the
    symbol names (aka tags). */
 
@@ -148,7 +198,7 @@ prepare_symbol_names (char const *muscle_name)
     {
       char *cp =
         symbols[i]->tag[0] == '"' && !quote
-        ? xstrdup (symbols[i]->tag)
+        ? xescape_trigraphs (symbols[i]->tag)
         : quotearg_alloc (symbols[i]->tag, -1, qo);
       /* Width of the next token, including the two quotes, the
          comma and the space.  */
