@@ -21,7 +21,6 @@
 #include <config.h>
 #include "system.h"
 
-#include "complain.h"
 #include "symlist.h"
 
 /*--------------------------------------.
@@ -174,22 +173,17 @@ symbol_list *
 symbol_list_n_get (symbol_list *l, int n)
 {
   int i;
-
-  if (n < 0)
-    return NULL;
-
+  aver (0 <= n);
   for (i = 0; i < n; ++i)
     {
       l = l->next;
-      if (l == NULL
-          || (l->content_type == SYMLIST_SYMBOL && l->content.sym == NULL))
-        return NULL;
+      aver (l);
     }
-
+  aver (l->content_type == SYMLIST_SYMBOL);
+  aver (l->content.sym);
   return l;
 }
 
-
 /*--------------------------------------------------------------.
 | Get the data type (alternative in the union) of the value for |
 | symbol N in symbol list L.                                    |
@@ -198,21 +192,14 @@ symbol_list_n_get (symbol_list *l, int n)
 uniqstr
 symbol_list_n_type_name_get (symbol_list *l, location loc, int n)
 {
-  l = symbol_list_n_get (l, n);
-  if (!l)
-    {
-      complain (&loc, complaint, _("invalid $ value: $%d"), n);
-      return NULL;
-    }
-  aver (l->content_type == SYMLIST_SYMBOL);
-  return l->content.sym->type_name;
+  return symbol_list_n_get (l, n)->content.sym->type_name;
 }
 
 bool
 symbol_list_null (symbol_list *node)
 {
-  return !node ||
-    (node->content_type == SYMLIST_SYMBOL && !(node->content.sym));
+  return (!node
+          || (node->content_type == SYMLIST_SYMBOL && !node->content.sym));
 }
 
 void
