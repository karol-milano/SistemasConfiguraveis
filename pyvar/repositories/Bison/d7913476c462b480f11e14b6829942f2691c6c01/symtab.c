@@ -20,7 +20,7 @@ Boston, MA 02111-1307, USA.  */
 
 
 #include "system.h"
-#include "alloc.h"
+#include "xalloc.h"
 #include "symtab.h"
 #include "gram.h"
 
@@ -56,7 +56,7 @@ copys (const char *s)
   for (cp = s; *cp; cp++)
     i++;
 
-  result = xmalloc((unsigned int)i);
+  result = XMALLOC(char, i);
   strcpy(result, s);
   return result;
 }
@@ -67,7 +67,7 @@ tabinit (void)
 {
 /*   register int i; JF unused */
 
-  symtab = NEW2(TABSIZE, bucket *);
+  symtab = XCALLOC (bucket *, TABSIZE);
 
   firstsymbol = NULL;
   lastsymbol = NULL;
@@ -97,7 +97,7 @@ getsym (const char *key)
     {
       nsyms++;
 
-      bp = NEW(bucket);
+      bp = XCALLOC (bucket, 1);
       bp->link = symtab[hashval];
       bp->next = NULL;
       bp->tag = copys(key);
@@ -135,11 +135,11 @@ free_symtab (void)
 	  bptmp = bp->link;
 #if 0 /* This causes crashes because one string can appear more than once.  */
 	  if (bp->type_name)
-	    FREE(bp->type_name);
+	    XFREE(bp->type_name);
 #endif
-	  FREE(bp);
+	  XFREE(bp);
 	  bp = bptmp;
 	}
     }
-  FREE(symtab);
+  XFREE(symtab);
 }
