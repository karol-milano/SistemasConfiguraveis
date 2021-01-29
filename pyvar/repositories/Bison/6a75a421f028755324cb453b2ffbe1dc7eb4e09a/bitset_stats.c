@@ -1,5 +1,5 @@
 /* Bitset statistics.
-   Copyright (C) 2002 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -39,12 +39,8 @@
 #include <string.h>
 #include <stdio.h>
 
-#ifdef HAVE_GETTEXT_H
 #include "gettext.h"
 #define _(Msgid)  gettext (Msgid)
-#else
-#define _(Msgid)  Msgid
-#endif
 
 /* Configuration macros.  */
 #define BITSET_STATS_FILE "bitset.dat"
