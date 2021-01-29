@@ -418,9 +418,7 @@ add_edge (graph *g, edge *e)
 void
 add_classname (graph *g, int val, const char *name)
 {
-  struct classname *classname;
-
-  MALLOC (classname, 1);
+  struct classname *classname = xmalloc (sizeof *classname);
   classname->no = val;
   classname->name = name;
   classname->next = g->classname;
@@ -430,9 +428,7 @@ add_classname (graph *g, int val, const char *name)
 void
 add_infoname (graph *g, int integer, const char *str)
 {
-  struct infoname *infoname;
-
-  MALLOC (infoname, 1);
+  struct infoname *infoname = xmalloc (sizeof *infoname);
   infoname->integer = integer;
   infoname->chars = str;
   infoname->next = g->infoname;
@@ -444,9 +440,7 @@ void
 add_colorentry (graph *g, int color_idx, int red_cp,
 		int green_cp, int blue_cp)
 {
-  struct colorentry *ce;
-
-  MALLOC (ce, 1);
+  struct colorentry *ce = xmalloc (sizeof *ce);
   ce->color_index = color_idx;
   ce->red_cp = red_cp;
   ce->green_cp = green_cp;
