@@ -28,6 +28,7 @@
 #include "state.h"
 #include "complain.h"
 #include "closure.h"
+#include "LR0.h"
 
 extern short *itemset;
 extern short *itemsetend;
@@ -38,8 +39,6 @@ core *first_state;
 shifts *first_shift;
 reductions *first_reduction;
 
-extern void generate_states PARAMS ((void));
-
 static core *this_state;
 static core *last_state;
 static shifts *last_shift;
