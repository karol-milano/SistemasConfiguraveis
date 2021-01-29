@@ -30,7 +30,7 @@
 #include "getargs.h"
 #include "location.h"
 
-location const empty_location = EMPTY_LOCATION_INIT;
+location const empty_loc = EMPTY_LOCATION_INIT;
 
 /* If BUF is null, add BUFSIZE (which in this case must be less than
    INT_MAX) to COLUMN; otherwise, add mbsnwidth (BUF, BUFSIZE, 0) to
