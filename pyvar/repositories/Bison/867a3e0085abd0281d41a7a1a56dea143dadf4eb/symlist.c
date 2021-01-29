@@ -1,6 +1,6 @@
 /* Lists of symbols for Bison
 
-   Copyright (C) 2002 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2005 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -44,6 +44,18 @@ symbol_list_new (symbol *sym, location loc)
 }
 
 
+/*------------------.
+| Print this list.  |
+`------------------*/
+
+void
+symbol_list_print (FILE *f, symbol_list *l)
+{
+  for (/* Nothing. */; l; l = l->next)
+    symbol_print (f, l->sym);
+}
+
+
 /*---------------------------------.
 | Prepend SYM at LOC to the LIST.  |
 `---------------------------------*/
@@ -94,7 +106,7 @@ symbol_list_n_type_name_get (symbol_list *rp, location loc, int n)
 
   if (n < 0)
     {
-      complain_at (loc, _("invalid $ value"));
+      complain_at (loc, _("invalid $ value: $%d"), n);
       return NULL;
     }
 
@@ -105,7 +117,8 @@ symbol_list_n_type_name_get (symbol_list *rp, location loc, int n)
       rp = rp->next;
       if (rp == NULL || rp->sym == NULL)
 	{
-	  complain_at (loc, _("invalid $ value"));
+	  complain_at (loc, _("invalid $ value: $%d"), n);
+	  fprintf (stderr, "\n");
 	  return NULL;
 	}
       ++i;
