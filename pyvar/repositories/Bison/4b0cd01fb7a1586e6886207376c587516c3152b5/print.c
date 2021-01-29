@@ -43,6 +43,8 @@
 #include "symtab.h"
 #include "tables.h"
 
+/* For a given state, the symbol numbers of the lookahead tokens for
+   shifts and errors (i.e. not reduce).  */
 static bitset no_reduce_set;
 
 
