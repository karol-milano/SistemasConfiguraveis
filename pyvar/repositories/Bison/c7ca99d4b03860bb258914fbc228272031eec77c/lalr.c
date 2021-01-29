@@ -39,9 +39,6 @@
 #include "derives.h"
 #include "getargs.h"
 
-/* All the decorated states, indexed by the state number.  */
-state_t **states = NULL;
-
 rule_t **LArule = NULL;
 bitsetv LA = NULL;
 size_t nLA;
