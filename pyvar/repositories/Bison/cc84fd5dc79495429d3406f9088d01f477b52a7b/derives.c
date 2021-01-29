@@ -1,40 +1,59 @@
 /* Match rules with nonterminals for bison,
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
 
 
-/* set_derives finds, for each variable (nonterminal), which rules can derive it.
-   It sets up the value of derives so that
-   derives[i - ntokens] points to a vector of rule numbers,
-   terminated with -1.  */
+/* set_derives finds, for each variable (nonterminal), which rules can
+   derive it.  It sets up the value of derives so that derives[i -
+   ntokens] points to a vector of rule numbers, terminated with -1.
+   */
 
 #include "system.h"
 #include "alloc.h"
 #include "types.h"
 #include "gram.h"
-
-extern void set_derives PARAMS((void));
-extern void free_derives PARAMS((void));
+#include "derives.h"
 
 #if DEBUG
-static void print_derives PARAMS((void));
 extern char **tags;
+
+static void
+print_derives (void)
+{
+  register int i;
+  register short *sp;
+
+  printf (_("\n\n\nDERIVES\n\n"));
+
+  for (i = ntokens; i < nsyms; i++)
+    {
+      printf (_("%s derives"), tags[i]);
+      for (sp = derives[i]; *sp > 0; sp++)
+	{
+	  printf ("  %d", *sp);
+	}
+      putchar ('\n');
+    }
+
+  putchar ('\n');
+}
+
 #endif
 
 short **derives;
@@ -49,8 +68,8 @@ set_derives (void)
   register shorts **dset;
   register shorts *delts;
 
-  dset = NEW2(nvars, shorts *) - ntokens;
-  delts = NEW2(nrules + 1, shorts);
+  dset = NEW2 (nvars, shorts *) - ntokens;
+  delts = NEW2 (nrules + 1, shorts);
 
   p = delts;
   for (i = nrules; i > 0; i--)
@@ -65,8 +84,8 @@ set_derives (void)
 	}
     }
 
-  derives = NEW2(nvars, short *) - ntokens;
-  q = NEW2(nvars + nrules, short);
+  derives = NEW2 (nvars, short *) - ntokens;
+  q = NEW2 (nvars + nrules, short);
 
   for (i = ntokens; i < nsyms; i++)
     {
@@ -80,44 +99,17 @@ set_derives (void)
       *q++ = -1;
     }
 
-#ifdef	DEBUG
-  print_derives();
+#if DEBUG
+  print_derives ();
 #endif
 
-  FREE(dset + ntokens);
-  FREE(delts);
+  FREE (dset + ntokens);
+  FREE (delts);
 }
 
 void
 free_derives (void)
 {
-  FREE(derives[ntokens]);
-  FREE(derives + ntokens);
-}
-
-
-
-#ifdef	DEBUG
-
-static void
-print_derives (void)
-{
-  register int i;
-  register short *sp;
-
-  printf(_("\n\n\nDERIVES\n\n"));
-
-  for (i = ntokens; i < nsyms; i++)
-    {
-      printf(_("%s derives"), tags[i]);
-      for (sp = derives[i]; *sp > 0; sp++)
-	{
-	  printf("  %d", *sp);
-	}
-      putchar('\n');
-    }
-
-  putchar('\n');
+  FREE (derives[ntokens]);
+  FREE (derives + ntokens);
 }
-
-#endif
