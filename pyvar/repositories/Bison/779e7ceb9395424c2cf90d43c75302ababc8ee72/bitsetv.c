@@ -1,5 +1,5 @@
 /* Bitset vectors.
-   Copyright (C) 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2004 Free Software Foundation, Inc.
 
 This file is part of GCC.
 
@@ -149,7 +149,7 @@ bitsetv_dump (FILE *file, char const *title, char const *subtitle,
   fprintf (file, "%s\n", title);
   for (i = 0; bsetv[i]; i++)
     {
-      fprintf (file, "%s %lu\n", subtitle, (unsigned long) i);
+      fprintf (file, "%s %lu\n", subtitle, (unsigned long int) i);
       bitset_dump (file, bsetv[i]);
     }
 
@@ -164,7 +164,7 @@ debug_bitsetv (bitsetv bsetv)
 
   for (i = 0; bsetv[i]; i++)
     {
-      fprintf (stderr, "%lu: ", (unsigned long) i);
+      fprintf (stderr, "%lu: ", (unsigned long int) i);
       debug_bitset (bsetv[i]);
     }
 
