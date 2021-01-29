@@ -1,5 +1,5 @@
 /* Find the length of STRING, but scan at most MAXLEN characters.
-   Copyright (C) 1996, 1997, 1998, 2000 Free Software Foundation, Inc.
+   Copyright (C) 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.
    This file is part of the GNU C Library.
 
    The GNU C Library is free software; you can redistribute it and/or
@@ -51,7 +51,7 @@ size_t
 __strnlen (const char *string, size_t maxlen)
 {
   const char *end = memchr (string, '\0', maxlen);
-  return end ? end - string : maxlen;
+  return end ? (size_t) (end - string) : maxlen;
 }
 #ifdef weak_alias
 weak_alias (__strnlen, strnlen)
