@@ -1,5 +1,5 @@
 /* Determine the number of screen columns needed for a string.
-   Copyright (C) 2000-2001 Free Software Foundation, Inc.
+   Copyright (C) 2000-2002 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -87,9 +87,7 @@ int wcwidth ();
    With flags = MBSW_REJECT_INVALID | MBSW_REJECT_UNPRINTABLE, this is
    the multibyte analogon of the wcswidth function.  */
 int
-mbswidth (string, flags)
-     const char *string;
-     int flags;
+mbswidth (const char *string, int flags)
 {
   return mbsnwidth (string, strlen (string), flags);
 }
@@ -99,10 +97,7 @@ mbswidth (string, flags)
    non-printable character occurs, and MBSW_REJECT_UNPRINTABLE is
    specified, -1 is returned.  */
 int
-mbsnwidth (string, nbytes, flags)
-     const char *string;
-     size_t nbytes;
-     int flags;
+mbsnwidth (const char *string, size_t nbytes, int flags)
 {
   const char *p = string;
   const char *plimit = p + nbytes;
