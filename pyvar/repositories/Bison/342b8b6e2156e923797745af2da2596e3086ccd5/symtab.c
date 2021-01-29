@@ -20,7 +20,6 @@
 
 
 #include "system.h"
-#include "xalloc.h"
 #include "symtab.h"
 #include "gram.h"
 
@@ -143,6 +142,7 @@ free_symtab (void)
 	  if (bp->type_name)
 	    XFREE (bp->type_name);
 #endif
+	  XFREE (bp->tag);
 	  XFREE (bp);
 	  bp = bptmp;
 	}
