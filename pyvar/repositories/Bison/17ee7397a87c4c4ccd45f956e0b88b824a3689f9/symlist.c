@@ -1,5 +1,6 @@
 /* Lists of symbols for Bison
-   Copyright (C) 2002  Free Software Foundation, Inc.
+
+   Copyright (C) 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -19,21 +20,22 @@
    Boston, MA 02111-1307, USA.  */
 
 #include "system.h"
+
 #include "complain.h"
 #include "symlist.h"
 
 
-/*----------------------------------------------.
-| Create a list containing SYMBOL at LOCATION.  |
-`----------------------------------------------*/
+/*--------------------------------------.
+| Create a list containing SYM at LOC.  |
+`--------------------------------------*/
 
-symbol_list_t *
-symbol_list_new (symbol_t *sym, location_t location)
+symbol_list *
+symbol_list_new (symbol *sym, location loc)
 {
-  symbol_list_t *res = XMALLOC (symbol_list_t, 1);
+  symbol_list *res = XMALLOC (symbol_list, 1);
   res->next = NULL;
   res->sym = sym;
-  res->location = location;
+  res->location = loc;
   res->action = NULL;
   res->ruleprec = NULL;
   res->dprec = 0;
@@ -42,15 +44,14 @@ symbol_list_new (symbol_t *sym, location_t location)
 }
 
 
-/*-----------------------------------------.
-| Prepend SYMBOL at LOCATION to the LIST.  |
-`-----------------------------------------*/
+/*---------------------------------.
+| Prepend SYM at LOC to the LIST.  |
+`---------------------------------*/
 
-symbol_list_t *
-symbol_list_prepend (symbol_list_t *list,
-		     symbol_t *symbol, location_t location)
+symbol_list *
+symbol_list_prepend (symbol_list *list, symbol *sym, location loc)
 {
-  symbol_list_t *res = symbol_list_new (symbol, location);
+  symbol_list *res = symbol_list_new (sym, loc);
   res->next = list;
   return res;
 }
@@ -61,9 +62,9 @@ symbol_list_prepend (symbol_list_t *list,
 `-------------------------------------------------*/
 
 void
-symbol_list_free (symbol_list_t *list)
+symbol_list_free (symbol_list *list)
 {
-  LIST_FREE (symbol_list_t, list);
+  LIST_FREE (symbol_list, list);
 }
 
 
@@ -72,7 +73,7 @@ symbol_list_free (symbol_list_t *list)
 `--------------------*/
 
 unsigned int
-symbol_list_length (symbol_list_t *list)
+symbol_list_length (symbol_list *list)
 {
   int res = 0;
   for (/* Nothing. */; list; list = list->next)
@@ -83,22 +84,20 @@ symbol_list_length (symbol_list_t *list)
 
 /*--------------------------------------------------------------.
 | Get the data type (alternative in the union) of the value for |
-| symbol N in rule RULE.                                        |
+| symbol N in symbol list RP.                                   |
 `--------------------------------------------------------------*/
 
-struniq_t
-symbol_list_n_type_name_get (symbol_list_t *rule, location_t location, int n)
+uniqstr
+symbol_list_n_type_name_get (symbol_list *rp, location loc, int n)
 {
   int i;
-  symbol_list_t *rp;
 
   if (n < 0)
     {
-      complain_at (location, _("invalid $ value"));
+      complain_at (loc, _("invalid $ value"));
       return NULL;
     }
 
-  rp = rule;
   i = 0;
 
   while (i < n)
@@ -106,7 +105,7 @@ symbol_list_n_type_name_get (symbol_list_t *rule, location_t location, int n)
       rp = rp->next;
       if (rp == NULL || rp->sym == NULL)
 	{
-	  complain_at (location, _("invalid $ value"));
+	  complain_at (loc, _("invalid $ value"));
 	  return NULL;
 	}
       ++i;
