@@ -1,5 +1,5 @@
 /* Locations for Bison
-   Copyright (C) 2002, 2005, 2006 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2005, 2006, 2007 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -27,7 +27,7 @@
 #include "complain.h"
 #include "location.h"
 
-location const empty_location;
+location const empty_location = EMPTY_LOCATION_INIT;
 
 /* If BUF is null, add BUFSIZE (which in this case must be less than
    INT_MAX) to COLUMN; otherwise, add mbsnwidth (BUF, BUFSIZE, 0) to
