@@ -1,5 +1,5 @@
 /* Match rules with nonterminals for bison,
-   Copyright 1984, 1989, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1989, 2000, 2001  Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -26,12 +26,13 @@
 
 #include "system.h"
 #include "types.h"
+#include "reader.h"
 #include "gram.h"
 #include "derives.h"
 
 short **derives;
 
-#if DEBUG
+#if TRACE
 
 static void
 print_derives (void)
@@ -39,21 +40,17 @@ print_derives (void)
   int i;
   short *sp;
 
-  fputs ("\n\n\n", stdout);
-  printf (_("DERIVES"));
-  fputs ("\n\n", stdout);
+  fputs ("\n\n\nDERIVES\n\n", stderr);
 
   for (i = ntokens; i < nsyms; i++)
     {
-      printf (_("%s derives"), tags[i]);
+      fprintf (stderr, "%s derives", tags[i]);
       for (sp = derives[i]; *sp > 0; sp++)
-	{
-	  printf ("  %d", *sp);
-	}
-      putchar ('\n');
+	fprintf (stderr, "  %d", *sp);
+      putc ('\n', stderr);
     }
 
-  putchar ('\n');
+  putc ('\n', stderr);
 }
 
 #endif
@@ -99,7 +96,7 @@ set_derives (void)
       *q++ = -1;
     }
 
-#if DEBUG
+#if TRACE
   print_derives ();
 #endif
 
