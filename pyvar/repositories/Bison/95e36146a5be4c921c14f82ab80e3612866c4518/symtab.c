@@ -1,22 +1,22 @@
 /* Symbol table manager for Bison,
-   Copyright (C) 1984, 1989 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 2000 Free Software Foundation, Inc.
 
-This file is part of Bison, the GNU Compiler Compiler.
+   This file is part of Bison, the GNU Compiler Compiler.
 
-Bison is free software; you can redistribute it and/or modify
-it under the terms of the GNU General Public License as published by
-the Free Software Foundation; either version 2, or (at your option)
-any later version.
+   Bison is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
 
-Bison is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
+   Bison is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
 
-You should have received a copy of the GNU General Public License
-along with Bison; see the file COPYING.  If not, write to
-the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU General Public License
+   along with Bison; see the file COPYING.  If not, write to
+   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
+   Boston, MA 02111-1307, USA.  */
 
 
 #include "system.h"
@@ -32,8 +32,8 @@ static bucket **symtab;
 static int
 hash (const char *key)
 {
-  register const char *cp;
-  register int k;
+  const char *cp;
+  int k;
 
   cp = key;
   k = 0;
@@ -44,29 +44,9 @@ hash (const char *key)
 }
 
 
-
-static char *
-copys (const char *s)
-{
-  register int i;
-  register const char *cp;
-  register char *result;
-
-  i = 1;
-  for (cp = s; *cp; cp++)
-    i++;
-
-  result = XMALLOC(char, i);
-  strcpy(result, s);
-  return result;
-}
-
-
 void
 tabinit (void)
 {
-/*   register int i; JF unused */
-
   symtab = XCALLOC (bucket *, TABSIZE);
 
   firstsymbol = NULL;
@@ -77,17 +57,17 @@ tabinit (void)
 bucket *
 getsym (const char *key)
 {
-  register int hashval;
-  register bucket *bp;
-  register int found;
+  int hashval;
+  bucket *bp;
+  int found;
 
-  hashval = hash(key);
+  hashval = hash (key);
   bp = symtab[hashval];
 
   found = 0;
   while (bp != NULL && found == 0)
     {
-      if (strcmp(key, bp->tag) == 0)
+      if (strcmp (key, bp->tag) == 0)
 	found = 1;
       else
 	bp = bp->link;
@@ -100,7 +80,7 @@ getsym (const char *key)
       bp = XCALLOC (bucket, 1);
       bp->link = symtab[hashval];
       bp->next = NULL;
-      bp->tag = copys(key);
+      bp->tag = xstrdup (key);
       bp->class = unknown_sym;
 
       if (firstsymbol == NULL)
@@ -124,8 +104,8 @@ getsym (const char *key)
 void
 free_symtab (void)
 {
-  register int i;
-  register bucket *bp,*bptmp;/* JF don't use ptr after free */
+  int i;
+  bucket *bp, *bptmp;		/* JF don't use ptr after free */
 
   for (i = 0; i < TABSIZE; i++)
     {
@@ -133,13 +113,15 @@ free_symtab (void)
       while (bp)
 	{
 	  bptmp = bp->link;
-#if 0 /* This causes crashes because one string can appear more than once.  */
+#if 0
+	  /* This causes crashes because one string can appear more
+	     than once.  */
 	  if (bp->type_name)
-	    XFREE(bp->type_name);
+	    XFREE (bp->type_name);
 #endif
-	  XFREE(bp);
+	  XFREE (bp);
 	  bp = bptmp;
 	}
     }
-  XFREE(symtab);
+  XFREE (symtab);
 }
