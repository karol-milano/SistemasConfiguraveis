@@ -1,5 +1,5 @@
 /* argmatch.c -- find a match for a string in an array
-   Copyright (C) 1990, 1998, 1999 Free Software Foundation, Inc.
+   Copyright (C) 1990, 1998, 1999, 2001 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -22,6 +22,7 @@
 
 #include <stdio.h>
 #ifdef STDC_HEADERS
+# include <stdlib.h>
 # include <string.h>
 #endif
 
@@ -38,6 +39,7 @@
 
 #include "error.h"
 #include "quotearg.h"
+#include "quote.h"
 
 /* When reporting an invalid argument, show nonprinting characters
    by using the quoting style ARGMATCH_QUOTING_STYLE.  Do not use
@@ -156,10 +158,11 @@ void
 argmatch_invalid (const char *context, const char *value, int problem)
 {
   char const *format = (problem == -1
-			? _("invalid argument %s for `%s'")
-			: _("ambiguous argument %s for `%s'"));
+			? _("invalid argument %s for %s")
+			: _("ambiguous argument %s for %s"));
 
-  error (0, 0, format, quotearg_style (ARGMATCH_QUOTING_STYLE, value), context);
+  error (0, 0, format, quotearg_n_style (0, ARGMATCH_QUOTING_STYLE, value),
+	 quote_n (1, context));
 }
 
 /* List the valid arguments for argmatch.
