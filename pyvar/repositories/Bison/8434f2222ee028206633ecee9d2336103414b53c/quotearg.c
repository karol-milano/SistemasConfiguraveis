@@ -1,5 +1,5 @@
 /* quotearg.c - quote arguments for output
-   Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.
+   Copyright (C) 1998, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -305,6 +305,16 @@ quotearg_buffer_restyled (char *buffer, size_t buffersize,
       c = arg[i];
       switch (c)
 	{
+	case '\0':
+	  if (backslash_escapes)
+	    {
+	      STORE ('\\');
+	      STORE ('0');
+	      STORE ('0');
+	      c = '0';
+	    }
+	  break;
+
 	case '?':
 	  switch (quoting_style)
 	    {
@@ -531,14 +541,15 @@ quotearg_buffer (char *buffer, size_t buffersize,
 				   p->style, p);
 }
 
-/* Use storage slot N to return a quoted version of the string ARG.
+/* Use storage slot N to return a quoted version of argument ARG.
+   ARG is of size ARGSIZE, but if that is -1, ARG is a null-terminated string.
    OPTIONS specifies the quoting options.
    The returned value points to static storage that can be
    reused by the next call to this function with the same value of N.
    N must be nonnegative.  N is deliberately declared with type "int"
    to allow for future extensions (using negative values).  */
 static char *
-quotearg_n_options (int n, char const *arg,
+quotearg_n_options (int n, char const *arg, size_t argsize,
 		    struct quoting_options const *options)
 {
   /* Preallocate a slot 0 buffer, so that the caller can always quote
@@ -579,13 +590,13 @@ quotearg_n_options (int n, char const *arg,
   {
     size_t size = slotvec[n].size;
     char *val = slotvec[n].val;
-    size_t qsize = quotearg_buffer (val, size, arg, (size_t) -1, options);
+    size_t qsize = quotearg_buffer (val, size, arg, argsize, options);
 
     if (size <= qsize)
       {
 	slotvec[n].size = size = qsize + 1;
 	slotvec[n].val = val = xrealloc (val == slot0 ? 0 : val, size);
-	quotearg_buffer (val, size, arg, (size_t) -1, options);
+	quotearg_buffer (val, size, arg, argsize, options);
       }
 
     return val;
@@ -595,7 +606,7 @@ quotearg_n_options (int n, char const *arg,
 char *
 quotearg_n (int n, char const *arg)
 {
-  return quotearg_n_options (n, arg, &default_quoting_options);
+  return quotearg_n_options (n, arg, (size_t) -1, &default_quoting_options);
 }
 
 char *
@@ -604,13 +615,29 @@ quotearg (char const *arg)
   return quotearg_n (0, arg);
 }
 
-char *
-quotearg_n_style (int n, enum quoting_style s, char const *arg)
+/* Return quoting options for STYLE, with no extra quoting.  */
+static struct quoting_options
+quoting_options_from_style (enum quoting_style style)
 {
   struct quoting_options o;
-  o.style = s;
+  o.style = style;
   memset (o.quote_these_too, 0, sizeof o.quote_these_too);
-  return quotearg_n_options (n, arg, &o);
+  return o;
+}
+
+char *
+quotearg_n_style (int n, enum quoting_style s, char const *arg)
+{
+  struct quoting_options const o = quoting_options_from_style (s);
+  return quotearg_n_options (n, arg, (size_t) -1, &o);
+}
+
+char *
+quotearg_n_style_mem (int n, enum quoting_style s,
+		      char const *arg, size_t argsize)
+{
+  struct quoting_options const o = quoting_options_from_style (s);
+  return quotearg_n_options (n, arg, argsize, &o);
 }
 
 char *
@@ -625,7 +652,7 @@ quotearg_char (char const *arg, char ch)
   struct quoting_options options;
   options = default_quoting_options;
   set_char_quoting (&options, ch, 1);
-  return quotearg_n_options (0, arg, &options);
+  return quotearg_n_options (0, arg, (size_t) -1, &options);
 }
 
 char *
