@@ -1,4 +1,5 @@
 /* VCG description handler for Bison.
+
    Copyright (C) 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -420,7 +421,7 @@ add_classname (graph *g, int val, const char *name)
 {
   struct classname *classname;
 
-  classname = XMALLOC (struct classname, 1);
+  MALLOC (classname, 1);
   classname->no = val;
   classname->name = name;
   classname->next = g->classname;
@@ -432,7 +433,7 @@ add_infoname (graph *g, int integer, const char *str)
 {
   struct infoname *infoname;
 
-  infoname = XMALLOC (struct infoname, 1);
+  MALLOC (infoname, 1);
   infoname->integer = integer;
   infoname->chars = str;
   infoname->next = g->infoname;
@@ -446,7 +447,7 @@ add_colorentry (graph *g, int color_idx, int red_cp,
 {
   struct colorentry *ce;
 
-  ce = XMALLOC (struct colorentry, 1);
+  MALLOC (ce, 1);
   ce->color_index = color_idx;
   ce->red_cp = red_cp;
   ce->green_cp = green_cp;
