@@ -1,6 +1,6 @@
 /* Print information on generated parser, for bison,
 
-   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003, 2004, 2005, 2007
+   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003, 2004, 2005, 2007, 2009
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -370,15 +370,15 @@ print_state (FILE *out, state *s)
 | Print information on the whole grammar.  |
 `-----------------------------------------*/
 
-#define END_TEST(End)				\
-do {						\
-  if (column + strlen(buffer) > (End))		\
-    {						\
-      fprintf (out, "%s\n   ", buffer);		\
-      column = 3;				\
-      buffer[0] = 0;				\
-    }						\
-} while (0)
+#define END_TEST(End)                           \
+  do {                                          \
+    if (column + strlen (buffer) > (End))       \
+      {                                         \
+        fprintf (out, "%s\n   ", buffer);       \
+        column = 3;                             \
+        buffer[0] = 0;                          \
+      }                                         \
+  } while (0)
 
 
 static void
