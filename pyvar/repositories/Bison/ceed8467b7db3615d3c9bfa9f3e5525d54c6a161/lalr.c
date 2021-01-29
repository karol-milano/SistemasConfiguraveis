@@ -48,9 +48,7 @@ LA[l, i] is 1 if the rule LAruleno[l] is applicable in the appropriate state
 If LA[l, i] and LA[l, j] are both 1 for i != j, it is a conflict.
 */
 
-#include <stdio.h>
 #include "system.h"
-#include "machine.h"
 #include "types.h"
 #include "state.h"
 #include "alloc.h"
