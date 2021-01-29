@@ -1,4 +1,4 @@
-/* Copyright (C) 1995, 1996, 1997, 1998 Free Software Foundation, Inc.
+/* Copyright (C) 1995-1998, 2000, 2001 Free Software Foundation, Inc.
    Contributed by Ulrich Drepper <drepper@gnu.ai.mit.edu>, 1995.
 
    This program is free software; you can redistribute it and/or modify
@@ -19,15 +19,8 @@
 # include <config.h>
 #endif
 
-#if defined STDC_HEADERS || defined _LIBC
-# include <stdlib.h>
-#endif
-
-#if defined HAVE_STRING_H || defined _LIBC
-# include <string.h>
-#else
-# include <strings.h>
-#endif
+#include <stdlib.h>
+#include <string.h>
 #include <sys/types.h>
 
 #include "loadinfo.h"
@@ -43,6 +36,18 @@
 
 /* @@ end of prolog @@ */
 
+char *
+_nl_find_language (name)
+     const char *name;
+{
+  while (name[0] != '\0' && name[0] != '_' && name[0] != '@'
+	 && name[0] != '+' && name[0] != ',')
+    ++name;
+
+  return (char *) name;
+}
+
+
 int
 _nl_explode_name (name, language, modifier, territory, codeset,
 		  normalized_codeset, special, sponsor, revision)
@@ -74,9 +79,7 @@ _nl_explode_name (name, language, modifier, territory, codeset,
   mask = 0;
   syntax = undecided;
   *language = cp = name;
-  while (cp[0] != '\0' && cp[0] != '_' && cp[0] != '@'
-	 && cp[0] != '+' && cp[0] != ',')
-    ++cp;
+  cp = _nl_find_language (*language);
 
   if (*language == cp)
     /* This does not make sense: language has to be specified.  Use
