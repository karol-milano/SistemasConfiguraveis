@@ -21,6 +21,7 @@
 
 #include "system.h"
 #include "gram.h"
+#include "symtab.h"
 #include "reader.h"
 
 /* comments for these variables are in gram.h  */
@@ -37,6 +38,8 @@ int nritems;
 rule_t *rule_table = NULL;
 short *rprec = NULL;
 short *rprecsym = NULL;
+
+struct bucket **symbols = NULL;
 short *sprec = NULL;
 short *rassoc = NULL;
 short *sassoc = NULL;
