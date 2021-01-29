@@ -19,9 +19,11 @@
    Boston, MA 02111-1307, USA.  */
 
 #include "system.h"
+
+#include <quotearg.h>
+
 #include "vcg.h"
 #include "vcg_defaults.h"
-#include "quotearg.h"
 
 /* Return an unambiguous printable representated, for NAME, suitable
    for C strings.  Use slot 2 since the user may use slots 0 and 1.
@@ -36,7 +38,7 @@ quote (char const *name)
 
 /* Initialize a graph with the default values. */
 void
-new_graph (graph_t *g)
+new_graph (graph *g)
 {
   g->title = G_TITLE;
   g->label = G_LABEL;
@@ -56,7 +58,7 @@ new_graph (graph_t *g)
   g->y = G_Y;
   g->folding = G_FOLDING;
   g->shrink = G_SHRINK;
-  g->stretch = G_STRETCH;
+  g->expand = G_EXPAND;
 
   g->textmode = G_TEXTMODE;
   g->shape = G_SHAPE;
@@ -93,14 +95,14 @@ new_graph (graph_t *g)
   g->dirty_edge_labels = G_DIRTY_EDGE_LABELS;
   g->finetuning = G_FINETUNING;
   g->ignore_singles = G_IGNORE_SINGLES;
-  g->straight_phase = G_STRAIGHT_PHASE;
+  g->long_straight_phase = G_LONG_STRAIGHT_PHASE;
   g->priority_phase = G_PRIORITY_PHASE;
   g->manhattan_edges = G_MANHATTAN_EDGES;
   g->smanhattan_edges = G_SMANHATTAN_EDGES;
   g->near_edges = G_NEAR_EDGES;
 
   g->orientation = G_ORIENTATION;
-  g->node_alignement = G_NODE_ALIGNEMENT;
+  g->node_alignment = G_NODE_ALIGNMENT;
   g->port_sharing = G_PORT_SHARING;
   g->arrow_mode = G_ARROW_MODE;
   g->treefactor = G_TREEFACTOR;
@@ -126,79 +128,79 @@ new_graph (graph_t *g)
   g->node_list = G_NODE_LIST;
   g->edge_list = G_EDGE_LIST;
 
-  new_edge(&g->edge);
-  new_node(&g->node);
+  new_edge (&g->edge);
+  new_node (&g->node);
 }
 
-/* Initialize a node with the defalut values. */
+/* Initialize a node with the default values. */
 void
-new_node (node_t *node)
+new_node (node *n)
 {
-  node->title = N_TITLE;
-  node->label = N_LABEL;
+  n->title = N_TITLE;
+  n->label = N_LABEL;
 
-  node->locx = N_LOCX; /* Default unspcified. */
-  node->locy = N_LOCY; /* Default unspcified. */
+  n->locx = N_LOCX; /* Default unspcified. */
+  n->locy = N_LOCY; /* Default unspcified. */
 
-  node->vertical_order = N_VERTICAL_ORDER;	/* Default unspcified. */
-  node->horizontal_order = N_HORIZONTAL_ORDER;	/* Default unspcified. */
+  n->vertical_order = N_VERTICAL_ORDER;	/* Default unspcified. */
+  n->horizontal_order = N_HORIZONTAL_ORDER;	/* Default unspcified. */
 
-  node->width = N_WIDTH; /* We assume that we can't define it now. */
-  node->height = N_HEIGHT; /* Also. */
+  n->width = N_WIDTH; /* We assume that we can't define it now. */
+  n->height = N_HEIGHT; /* Also. */
 
-  node->shrink = N_SHRINK;
-  node->stretch = N_STRETCH;
+  n->shrink = N_SHRINK;
+  n->expand = N_EXPAND;
 
-  node->folding = N_FOLDING; /* No explicit default value. */
+  n->folding = N_FOLDING; /* No explicit default value. */
 
-  node->shape = N_SHAPE;
-  node->textmode = N_TEXTMODE;
-  node->borderwidth = N_BORDERWIDTH;
+  n->shape = N_SHAPE;
+  n->textmode = N_TEXTMODE;
+  n->borderwidth = N_BORDERWIDTH;
 
-  node->color = N_COLOR;
-  node->textcolor = N_TEXTCOLOR;
-  node->bordercolor = N_BORDERCOLOR;
+  n->color = N_COLOR;
+  n->textcolor = N_TEXTCOLOR;
+  n->bordercolor = N_BORDERCOLOR;
 
-  node->infos[0] = N_INFOS1;
-  node->infos[1] = N_INFOS2;
-  node->infos[2] = N_INFOS3;
+  n->infos[0] = N_INFOS1;
+  n->infos[1] = N_INFOS2;
+  n->infos[2] = N_INFOS3;
 
-  node->next = N_NEXT;
+  n->next = N_NEXT;
 }
 
-/* Initialize a edge with the defalut values. */
+/* Initialize an edge with the default values. */
 void
-new_edge (edge_t *edge)
+new_edge (edge *e)
 {
-  edge->type = E_EDGE_TYPE;
+  e->type = E_EDGE_TYPE;
 
-  edge->sourcename = E_SOURCENAME;
-  edge->targetname = E_TARGETNAME;
-  edge->label = E_LABEL;
+  e->sourcename = E_SOURCENAME;
+  e->targetname = E_TARGETNAME;
+  e->label = E_LABEL;
 
-  edge->linestyle = E_LINESTYLE;
-  edge->thickness = E_THICKNESS;
+  e->linestyle = E_LINESTYLE;
+  e->thickness = E_THICKNESS;
 
-  edge->class = E_CLASS;
+  e->class = E_CLASS;
 
-  edge->color = E_COLOR;
-  edge->textcolor = E_TEXTCOLOR;
-  edge->arrowcolor = E_ARROWCOLOR;
-  edge->backarrowcolor = E_BACKARROWCOLOR;
+  e->color = E_COLOR;
+  e->textcolor = E_TEXTCOLOR;
+  e->arrowcolor = E_ARROWCOLOR;
+  e->backarrowcolor = E_BACKARROWCOLOR;
 
-  edge->arrowsize = E_ARROWSIZE;
-  edge->backarrowsize = E_BACKARROWSIZE;
-  edge->arrowstyle = E_ARROWSTYLE;
+  e->arrowsize = E_ARROWSIZE;
+  e->backarrowsize = E_BACKARROWSIZE;
+  e->arrowstyle = E_ARROWSTYLE;
 
-  edge->backarrowstyle = E_BACKARROWSTYLE;
+  e->backarrowstyle = E_BACKARROWSTYLE;
 
-  edge->priority = E_PRIORITY;
+  e->priority = E_PRIORITY;
 
-  edge->anchor = E_ANCHOR;
+  e->anchor = E_ANCHOR;
 
-  edge->horizontal_order = E_HORIZONTAL_ORDER;
+  e->horizontal_order = E_HORIZONTAL_ORDER;
 
-  edge->next = E_NEXT;
+  e->next = E_NEXT;
 }
 
 /*----------------------------------------------.
@@ -207,7 +209,7 @@ new_edge (edge_t *edge)
 `----------------------------------------------*/
 
 static const char *
-get_color_str (enum color_e c)
+get_color_str (enum color c)
 {
   switch (c)
     {
@@ -248,7 +250,7 @@ get_color_str (enum color_e c)
 }
 
 static const char *
-get_textmode_str (enum textmode_e t)
+get_textmode_str (enum textmode t)
 {
   switch (t)
     {
@@ -260,7 +262,7 @@ get_textmode_str (enum textmode_e t)
 }
 
 static const char *
-get_shape_str (enum shape_e s)
+get_shape_str (enum shape s)
 {
   switch (s)
     {
@@ -273,7 +275,7 @@ get_shape_str (enum shape_e s)
 }
 
 static const char *
-get_layoutalgorithm_str (enum layoutalgorithm_e l)
+get_layoutalgorithm_str (enum layoutalgorithm l)
 {
   switch (l)
     {
@@ -296,7 +298,7 @@ get_layoutalgorithm_str (enum layoutalgorithm_e l)
 }
 
 static const char *
-get_decision_str (enum decision_e d)
+get_decision_str (enum decision d)
 {
   switch (d)
     {
@@ -307,7 +309,7 @@ get_decision_str (enum decision_e d)
 }
 
 static const char *
-get_orientation_str (enum orientation_e o)
+get_orientation_str (enum orientation o)
 {
   switch (o)
     {
@@ -320,7 +322,7 @@ get_orientation_str (enum orientation_e o)
 }
 
 static const char *
-get_node_alignement_str (enum alignement_e a)
+get_node_alignment_str (enum alignment a)
 {
   switch (a)
     {
@@ -332,7 +334,7 @@ get_node_alignement_str (enum alignement_e a)
 }
 
 static const char *
-get_arrow_mode_str (enum arrow_mode_e a)
+get_arrow_mode_str (enum arrow_mode a)
 {
   switch (a)
     {
@@ -343,7 +345,7 @@ get_arrow_mode_str (enum arrow_mode_e a)
 }
 
 static const char *
-get_crossing_type_str (enum crossing_type_e c)
+get_crossing_type_str (enum crossing_type c)
 {
   switch (c)
     {
@@ -356,7 +358,7 @@ get_crossing_type_str (enum crossing_type_e c)
 }
 
 static const char *
-get_view_str (enum view_e v)
+get_view_str (enum view v)
 {
   switch (v)
     {
@@ -370,7 +372,7 @@ get_view_str (enum view_e v)
 }
 
 static const char *
-get_linestyle_str (enum linestyle_e l)
+get_linestyle_str (enum linestyle l)
 {
   switch (l)
     {
@@ -383,7 +385,7 @@ get_linestyle_str (enum linestyle_e l)
 }
 
 static const char *
-get_arrowstyle_str (enum arrowstyle_e a)
+get_arrowstyle_str (enum arrowstyle a)
 {
   switch (a)
     {
@@ -394,31 +396,31 @@ get_arrowstyle_str (enum arrowstyle_e a)
     }
 }
 
-/*----------------------------.
-| Add functions.       	      |
-| Edge and Nodes int a graph. |
-`----------------------------*/
+/*------------------------------.
+| Add functions.       	        |
+| Edge and nodes into a graph.  |
+`------------------------------*/
 
 void
-add_node (graph_t *graph, node_t *node)
+add_node (graph *g, node *n)
 {
-  node->next = graph->node_list;
-  graph->node_list = node;
+  n->next = g->node_list;
+  g->node_list = n;
 }
 
 void
-add_edge (graph_t *graph, edge_t *edge)
+add_edge (graph *g, edge *e)
 {
-  edge->next = graph->edge_list;
-  graph->edge_list = edge;
+  e->next = g->edge_list;
+  g->edge_list = e;
 }
 
 void
-add_classname (graph_t *g, int val, const char *name)
+add_classname (graph *g, int val, const char *name)
 {
-  struct classname_s *classname;
+  struct classname *classname;
 
-  classname = XMALLOC (struct classname_s, 1);
+  classname = XMALLOC (struct classname, 1);
   classname->no = val;
   classname->name = name;
   classname->next = g->classname;
@@ -426,25 +428,25 @@ add_classname (graph_t *g, int val, const char *name)
 }
 
 void
-add_infoname (graph_t *g, int integer, const char *string)
+add_infoname (graph *g, int integer, const char *str)
 {
-  struct infoname_s *infoname;
+  struct infoname *infoname;
 
-  infoname = XMALLOC (struct infoname_s, 1);
+  infoname = XMALLOC (struct infoname, 1);
   infoname->integer = integer;
-  infoname->string = string;
+  infoname->chars = str;
   infoname->next = g->infoname;
   g->infoname = infoname;
 }
 
 /* Build a colorentry struct and add it to the list.  */
 void
-add_colorentry (graph_t *g, int color_idx, int red_cp,
+add_colorentry (graph *g, int color_idx, int red_cp,
 		int green_cp, int blue_cp)
 {
-  struct colorentry_s *ce;
+  struct colorentry *ce;
 
-  ce = XMALLOC (struct colorentry_s, 1);
+  ce = XMALLOC (struct colorentry, 1);
   ce->color_index = color_idx;
   ce->red_cp = red_cp;
   ce->green_cp = green_cp;
@@ -458,9 +460,9 @@ add_colorentry (graph_t *g, int color_idx, int red_cp,
 `-------------------------------------*/
 
 void
-open_edge(edge_t *edge, FILE *fout)
+open_edge (edge *e, FILE *fout)
 {
-  switch (edge->type)
+  switch (e->type)
     {
     case normal_edge:
       fputs ("\tedge: {\n", fout);
@@ -480,42 +482,42 @@ open_edge(edge_t *edge, FILE *fout)
 }
 
 void
-close_edge(FILE *fout)
+close_edge (FILE *fout)
 {
   fputs ("\t}\n", fout);
 }
 
 void
-open_node(FILE *fout)
+open_node (FILE *fout)
 {
   fputs ("\tnode: {\n", fout);
 }
 
 void
-close_node(FILE *fout)
+close_node (FILE *fout)
 {
   fputs ("\t}\n", fout);
 }
 
 void
-open_graph(FILE *fout)
+open_graph (FILE *fout)
 {
   fputs ("graph: {\n", fout);
 }
 
 void
-close_graph(graph_t *graph, FILE *fout)
+close_graph (graph *g, FILE *fout)
 {
   fputc ('\n', fout);
 
   /* FIXME: Unallocate nodes and edges if required.  */
   {
-    node_t *node;
+    node *n;
 
-    for (node = graph->node_list; node; node = node->next)
+    for (n = g->node_list; n; n = n->next)
       {
 	open_node (fout);
-	output_node (node, fout);
+	output_node (n, fout);
 	close_node (fout);
       }
   }
@@ -523,12 +525,12 @@ close_graph(graph_t *graph, FILE *fout)
   fputc ('\n', fout);
 
   {
-    edge_t *edge;
+    edge *e;
 
-    for (edge = graph->edge_list; edge; edge = edge->next)
+    for (e = g->edge_list; e; e = e->next)
       {
-	open_edge (edge, fout);
-	output_edge (edge, fout);
+	open_edge (e, fout);
+	output_edge (e, fout);
 	close_edge (fout);
       }
   }
@@ -541,221 +543,221 @@ close_graph(graph_t *graph, FILE *fout)
 `-------------------------------------------*/
 
 void
-output_node (node_t *node, FILE *fout)
+output_node (node *n, FILE *fout)
 {
-  if (node->title != N_TITLE)
-    fprintf (fout, "\t\ttitle:\t%s\n", quote (node->title));
-  if (node->label != N_LABEL)
-    fprintf (fout, "\t\tlabel:\t%s\n", quote (node->label));
+  if (n->title != N_TITLE)
+    fprintf (fout, "\t\ttitle:\t%s\n", quote (n->title));
+  if (n->label != N_LABEL)
+    fprintf (fout, "\t\tlabel:\t%s\n", quote (n->label));
 
-  if ((node->locx != N_LOCX) && (node->locy != N_LOCY))
-    fprintf (fout, "\t\tloc { x: %d  y: %d }\t\n", node->locx, node->locy);
+  if ((n->locx != N_LOCX) && (n->locy != N_LOCY))
+    fprintf (fout, "\t\tloc { x: %d  y: %d }\t\n", n->locx, n->locy);
 
-  if (node->vertical_order != N_VERTICAL_ORDER)
-    fprintf (fout, "\t\tvertical_order:\t%d\n", node->vertical_order);
-  if (node->horizontal_order != N_HORIZONTAL_ORDER)
-    fprintf (fout, "\t\thorizontal_order:\t%d\n", node->horizontal_order);
+  if (n->vertical_order != N_VERTICAL_ORDER)
+    fprintf (fout, "\t\tvertical_order:\t%d\n", n->vertical_order);
+  if (n->horizontal_order != N_HORIZONTAL_ORDER)
+    fprintf (fout, "\t\thorizontal_order:\t%d\n", n->horizontal_order);
 
-  if (node->width != N_WIDTH)
-    fprintf (fout, "\t\twidth:\t%d\n", node->width);
-  if (node->height != N_HEIGHT)
-    fprintf (fout, "\t\theight:\t%d\n", node->height);
+  if (n->width != N_WIDTH)
+    fprintf (fout, "\t\twidth:\t%d\n", n->width);
+  if (n->height != N_HEIGHT)
+    fprintf (fout, "\t\theight:\t%d\n", n->height);
 
-  if (node->shrink != N_SHRINK)
-    fprintf (fout, "\t\tshrink:\t%d\n", node->shrink);
-  if (node->stretch != N_STRETCH)
-    fprintf (fout, "\t\tstretch:\t%d\n", node->stretch);
+  if (n->shrink != N_SHRINK)
+    fprintf (fout, "\t\tshrink:\t%d\n", n->shrink);
+  if (n->expand != N_EXPAND)
+    fprintf (fout, "\t\texpand:\t%d\n", n->expand);
 
-  if (node->folding != N_FOLDING)
-    fprintf (fout, "\t\tfolding:\t%d\n", node->folding);
+  if (n->folding != N_FOLDING)
+    fprintf (fout, "\t\tfolding:\t%d\n", n->folding);
 
-  if (node->textmode != N_TEXTMODE)
+  if (n->textmode != N_TEXTMODE)
     fprintf (fout, "\t\ttextmode:\t%s\n",
-	     get_textmode_str (node->textmode));
+	     get_textmode_str (n->textmode));
 
-  if (node->shape != N_SHAPE)
-    fprintf (fout, "\t\tshape:\t%s\n", get_shape_str (node->shape));
+  if (n->shape != N_SHAPE)
+    fprintf (fout, "\t\tshape:\t%s\n", get_shape_str (n->shape));
 
-  if (node->borderwidth != N_BORDERWIDTH)
-    fprintf (fout, "\t\tborderwidth:\t%d\n", node->borderwidth);
+  if (n->borderwidth != N_BORDERWIDTH)
+    fprintf (fout, "\t\tborderwidth:\t%d\n", n->borderwidth);
 
-  if (node->color != N_COLOR)
-    fprintf (fout, "\t\tcolor:\t%s\n", get_color_str (node->color));
-  if (node->textcolor != N_TEXTCOLOR)
+  if (n->color != N_COLOR)
+    fprintf (fout, "\t\tcolor:\t%s\n", get_color_str (n->color));
+  if (n->textcolor != N_TEXTCOLOR)
     fprintf (fout, "\t\ttextcolor:\t%s\n",
-	     get_color_str (node->textcolor));
-  if (node->bordercolor != N_BORDERCOLOR)
+	     get_color_str (n->textcolor));
+  if (n->bordercolor != N_BORDERCOLOR)
     fprintf (fout, "\t\tbordercolor:\t%s\n",
-	     get_color_str (node->bordercolor));
+	     get_color_str (n->bordercolor));
 
   {
     int i;
     for (i = 0; i < 3; ++i)
-      if (node->infos[i])
+      if (n->infos[i])
 	fprintf (fout, "\t\tinfo%d:\t%s\n",
-		 i, quote (node->infos[i]));
+		 i, quote (n->infos[i]));
   }
 }
 
 void
-output_edge (edge_t *edge, FILE *fout)
+output_edge (edge *e, FILE *fout)
 {
   /* FIXME: SOURCENAME and TARGETNAME are mandatory
      so it has to be fatal not to give these informations.  */
-  if (edge->sourcename != E_SOURCENAME)
-    fprintf (fout, "\t\tsourcename:\t%s\n", quote (edge->sourcename));
-  if (edge->targetname != E_TARGETNAME)
-    fprintf (fout, "\t\ttargetname:\t%s\n", quote (edge->targetname));
+  if (e->sourcename != E_SOURCENAME)
+    fprintf (fout, "\t\tsourcename:\t%s\n", quote (e->sourcename));
+  if (e->targetname != E_TARGETNAME)
+    fprintf (fout, "\t\ttargetname:\t%s\n", quote (e->targetname));
 
-  if (edge->label != E_LABEL)
-    fprintf (fout, "\t\tlabel:\t%s\n", quote (edge->label));
+  if (e->label != E_LABEL)
+    fprintf (fout, "\t\tlabel:\t%s\n", quote (e->label));
 
-  if (edge->linestyle != E_LINESTYLE)
+  if (e->linestyle != E_LINESTYLE)
     fprintf (fout, "\t\tlinestyle:\t%s\n",
-	     quote (get_linestyle_str(edge->linestyle)));
+	     quote (get_linestyle_str (e->linestyle)));
 
-  if (edge->thickness != E_THICKNESS)
-    fprintf (fout, "\t\tthickness:\t%d\n", edge->thickness);
-  if (edge->class != E_CLASS)
-    fprintf (fout, "\t\tclass:\t%d\n", edge->class);
+  if (e->thickness != E_THICKNESS)
+    fprintf (fout, "\t\tthickness:\t%d\n", e->thickness);
+  if (e->class != E_CLASS)
+    fprintf (fout, "\t\tclass:\t%d\n", e->class);
 
-  if (edge->color != E_COLOR)
-    fprintf (fout, "\t\tcolor:\t%s\n", get_color_str (edge->color));
-  if (edge->color != E_TEXTCOLOR)
+  if (e->color != E_COLOR)
+    fprintf (fout, "\t\tcolor:\t%s\n", get_color_str (e->color));
+  if (e->color != E_TEXTCOLOR)
     fprintf (fout, "\t\ttextcolor:\t%s\n",
-	     get_color_str (edge->textcolor));
-  if (edge->arrowcolor != E_ARROWCOLOR)
+	     get_color_str (e->textcolor));
+  if (e->arrowcolor != E_ARROWCOLOR)
     fprintf (fout, "\t\tarrowcolor:\t%s\n",
-	     get_color_str (edge->arrowcolor));
-  if (edge->backarrowcolor != E_BACKARROWCOLOR)
+	     get_color_str (e->arrowcolor));
+  if (e->backarrowcolor != E_BACKARROWCOLOR)
     fprintf (fout, "\t\tbackarrowcolor:\t%s\n",
-	     get_color_str (edge->backarrowcolor));
+	     get_color_str (e->backarrowcolor));
 
-  if (edge->arrowsize != E_ARROWSIZE)
-    fprintf (fout, "\t\tarrowsize:\t%d\n", edge->arrowsize);
-  if (edge->backarrowsize != E_BACKARROWSIZE)
-    fprintf (fout, "\t\tbackarrowsize:\t%d\n", edge->backarrowsize);
+  if (e->arrowsize != E_ARROWSIZE)
+    fprintf (fout, "\t\tarrowsize:\t%d\n", e->arrowsize);
+  if (e->backarrowsize != E_BACKARROWSIZE)
+    fprintf (fout, "\t\tbackarrowsize:\t%d\n", e->backarrowsize);
 
-  if (edge->arrowstyle != E_ARROWSTYLE)
+  if (e->arrowstyle != E_ARROWSTYLE)
     fprintf (fout, "\t\tarrowstyle:\t%s\n",
-	     get_arrowstyle_str(edge->arrowstyle));
-  if (edge->backarrowstyle != E_BACKARROWSTYLE)
+	     get_arrowstyle_str (e->arrowstyle));
+  if (e->backarrowstyle != E_BACKARROWSTYLE)
     fprintf (fout, "\t\tbackarrowstyle:\t%s\n",
-	     get_arrowstyle_str(edge->backarrowstyle));
-
-  if (edge->priority != E_PRIORITY)
-    fprintf (fout, "\t\tpriority:\t%d\n", edge->priority);
-  if (edge->anchor != E_ANCHOR)
-    fprintf (fout, "\t\tanchor:\t%d\n", edge->anchor);
-  if (edge->horizontal_order != E_HORIZONTAL_ORDER)
-    fprintf (fout, "\t\thorizontal_order:\t%d\n", edge->horizontal_order);
+	     get_arrowstyle_str (e->backarrowstyle));
+
+  if (e->priority != E_PRIORITY)
+    fprintf (fout, "\t\tpriority:\t%d\n", e->priority);
+  if (e->anchor != E_ANCHOR)
+    fprintf (fout, "\t\tanchor:\t%d\n", e->anchor);
+  if (e->horizontal_order != E_HORIZONTAL_ORDER)
+    fprintf (fout, "\t\thorizontal_order:\t%d\n", e->horizontal_order);
 }
 
 void
-output_graph (graph_t *graph, FILE *fout)
+output_graph (graph *g, FILE *fout)
 {
-  if (graph->title)
-    fprintf (fout, "\ttitle:\t%s\n", quote (graph->title));
-  if (graph->label)
-    fprintf (fout, "\tlabel:\t%s\n", quote (graph->label));
+  if (g->title)
+    fprintf (fout, "\ttitle:\t%s\n", quote (g->title));
+  if (g->label)
+    fprintf (fout, "\tlabel:\t%s\n", quote (g->label));
 
   {
     int i;
     for (i = 0; i < 3; ++i)
-      if (graph->infos[i])
-	fprintf (fout, "\tinfo%d:\t%s\n", i, quote (graph->infos[i]));
+      if (g->infos[i])
+	fprintf (fout, "\tinfo%d:\t%s\n", i, quote (g->infos[i]));
   }
 
-  if (graph->color != G_COLOR)
-    fprintf (fout, "\tcolor:\t%s\n", get_color_str (graph->color));
-  if (graph->textcolor != G_TEXTCOLOR)
-    fprintf (fout, "\ttextcolor:\t%s\n", get_color_str (graph->textcolor));
-  if (graph->bordercolor != G_BORDERCOLOR)
+  if (g->color != G_COLOR)
+    fprintf (fout, "\tcolor:\t%s\n", get_color_str (g->color));
+  if (g->textcolor != G_TEXTCOLOR)
+    fprintf (fout, "\ttextcolor:\t%s\n", get_color_str (g->textcolor));
+  if (g->bordercolor != G_BORDERCOLOR)
     fprintf (fout, "\tbordercolor:\t%s\n",
-	     get_color_str (graph->bordercolor));
+	     get_color_str (g->bordercolor));
 
-  if (graph->width != G_WIDTH)
-    fprintf (fout, "\twidth:\t%d\n", graph->width);
-  if (graph->height != G_HEIGHT)
-    fprintf (fout, "\theight:\t%d\n", graph->height);
-  if (graph->borderwidth != G_BORDERWIDTH)
-    fprintf (fout, "\tborderwidth:\t%d\n", graph->borderwidth);
+  if (g->width != G_WIDTH)
+    fprintf (fout, "\twidth:\t%d\n", g->width);
+  if (g->height != G_HEIGHT)
+    fprintf (fout, "\theight:\t%d\n", g->height);
+  if (g->borderwidth != G_BORDERWIDTH)
+    fprintf (fout, "\tborderwidth:\t%d\n", g->borderwidth);
 
-  if (graph->x != G_X)
-    fprintf (fout, "\tx:\t%d\n", graph->x);
-  if (graph->y != G_Y)
-    fprintf (fout, "\ty:\t%d\n", graph->y);
+  if (g->x != G_X)
+    fprintf (fout, "\tx:\t%d\n", g->x);
+  if (g->y != G_Y)
+    fprintf (fout, "\ty:\t%d\n", g->y);
 
-  if (graph->folding != G_FOLDING)
-    fprintf (fout, "\tfolding:\t%d\n", graph->folding);
+  if (g->folding != G_FOLDING)
+    fprintf (fout, "\tfolding:\t%d\n", g->folding);
 
-  if (graph->shrink != G_SHRINK)
-    fprintf (fout, "\tshrink:\t%d\n", graph->shrink);
-  if (graph->stretch != G_STRETCH)
-    fprintf (fout, "\tstretch:\t%d\n", graph->stretch);
+  if (g->shrink != G_SHRINK)
+    fprintf (fout, "\tshrink:\t%d\n", g->shrink);
+  if (g->expand != G_EXPAND)
+    fprintf (fout, "\texpand:\t%d\n", g->expand);
 
-  if (graph->textmode != G_TEXTMODE)
+  if (g->textmode != G_TEXTMODE)
     fprintf (fout, "\ttextmode:\t%s\n",
-	     get_textmode_str (graph->textmode));
-
-  if (graph->shape != G_SHAPE)
-    fprintf (fout, "\tshape:\t%s\n", get_shape_str (graph->shape));
-
-  if (graph->vertical_order != G_VERTICAL_ORDER)
-    fprintf (fout, "\tvertical_order:\t%d\n", graph->vertical_order);
-  if (graph->horizontal_order != G_HORIZONTAL_ORDER)
-    fprintf (fout, "\thorizontal_order:\t%d\n", graph->horizontal_order);
-
-  if (graph->xmax != G_XMAX)
-    fprintf (fout, "\txmax:\t%d\n", graph->xmax);
-  if (graph->ymax != G_YMAX)
-    fprintf (fout, "\tymax:\t%d\n", graph->ymax);
-
-  if (graph->xbase != G_XBASE)
-    fprintf (fout, "\txbase:\t%d\n", graph->xbase);
-  if (graph->ybase != G_YBASE)
-    fprintf (fout, "\tybase:\t%d\n", graph->ybase);
-
-  if (graph->xspace != G_XSPACE)
-    fprintf (fout, "\txspace:\t%d\n", graph->xspace);
-  if (graph->yspace != G_YSPACE)
-    fprintf (fout, "\tyspace:\t%d\n", graph->yspace);
-  if (graph->xlspace != G_XLSPACE)
-    fprintf (fout, "\txlspace:\t%d\n", graph->xlspace);
-
-  if (graph->xraster != G_XRASTER)
-    fprintf (fout, "\txraster:\t%d\n", graph->xraster);
-  if (graph->yraster != G_YRASTER)
-    fprintf (fout, "\tyraster:\t%d\n", graph->yraster);
-  if (graph->xlraster != G_XLRASTER)
-    fprintf (fout, "\txlraster:\t%d\n", graph->xlraster);
-
-  if (graph->hidden != G_HIDDEN)
-    fprintf (fout, "\thidden:\t%d\n", graph->hidden);
+	     get_textmode_str (g->textmode));
+
+  if (g->shape != G_SHAPE)
+    fprintf (fout, "\tshape:\t%s\n", get_shape_str (g->shape));
+
+  if (g->vertical_order != G_VERTICAL_ORDER)
+    fprintf (fout, "\tvertical_order:\t%d\n", g->vertical_order);
+  if (g->horizontal_order != G_HORIZONTAL_ORDER)
+    fprintf (fout, "\thorizontal_order:\t%d\n", g->horizontal_order);
+
+  if (g->xmax != G_XMAX)
+    fprintf (fout, "\txmax:\t%d\n", g->xmax);
+  if (g->ymax != G_YMAX)
+    fprintf (fout, "\tymax:\t%d\n", g->ymax);
+
+  if (g->xbase != G_XBASE)
+    fprintf (fout, "\txbase:\t%d\n", g->xbase);
+  if (g->ybase != G_YBASE)
+    fprintf (fout, "\tybase:\t%d\n", g->ybase);
+
+  if (g->xspace != G_XSPACE)
+    fprintf (fout, "\txspace:\t%d\n", g->xspace);
+  if (g->yspace != G_YSPACE)
+    fprintf (fout, "\tyspace:\t%d\n", g->yspace);
+  if (g->xlspace != G_XLSPACE)
+    fprintf (fout, "\txlspace:\t%d\n", g->xlspace);
+
+  if (g->xraster != G_XRASTER)
+    fprintf (fout, "\txraster:\t%d\n", g->xraster);
+  if (g->yraster != G_YRASTER)
+    fprintf (fout, "\tyraster:\t%d\n", g->yraster);
+  if (g->xlraster != G_XLRASTER)
+    fprintf (fout, "\txlraster:\t%d\n", g->xlraster);
+
+  if (g->hidden != G_HIDDEN)
+    fprintf (fout, "\thidden:\t%d\n", g->hidden);
 
   /* FIXME: Unallocate struct list if required.
      Maybe with a little function.  */
-  if (graph->classname != G_CLASSNAME)
+  if (g->classname != G_CLASSNAME)
     {
-      struct classname_s *ite;
+      struct classname *ite;
 
-      for (ite = graph->classname; ite; ite = ite->next)
+      for (ite = g->classname; ite; ite = ite->next)
 	fprintf (fout, "\tclassname %d :\t%s\n", ite->no, ite->name);
     }
 
-  if (graph->infoname != G_INFONAME)
+  if (g->infoname != G_INFONAME)
     {
-      struct infoname_s *ite;
+      struct infoname *ite;
 
-      for (ite = graph->infoname; ite; ite = ite->next)
-	fprintf (fout, "\tinfoname %d :\t%s\n", ite->integer, ite->string);
+      for (ite = g->infoname; ite; ite = ite->next)
+	fprintf (fout, "\tinfoname %d :\t%s\n", ite->integer, ite->chars);
     }
 
-  if (graph->colorentry != G_COLORENTRY)
+  if (g->colorentry != G_COLORENTRY)
     {
-      struct colorentry_s *ite;
+      struct colorentry *ite;
 
-      for (ite = graph->colorentry; ite; ite = ite->next)
+      for (ite = g->colorentry; ite; ite = ite->next)
 	{
 	  fprintf (fout, "\tcolorentry %d :\t%d %d %d\n",
 		   ite->color_index,
@@ -765,110 +767,110 @@ output_graph (graph_t *graph, FILE *fout)
 	}
     }
 
-  if (graph->layoutalgorithm != G_LAYOUTALGORITHM)
+  if (g->layoutalgorithm != G_LAYOUTALGORITHM)
     fprintf (fout, "\tlayoutalgorithm:\t%s\n",
-	     get_layoutalgorithm_str(graph->layoutalgorithm));
-
-  if (graph->layout_downfactor != G_LAYOUT_DOWNFACTOR)
-    fprintf (fout, "\tlayout_downfactor:\t%d\n", graph->layout_downfactor);
-  if (graph->layout_upfactor != G_LAYOUT_UPFACTOR)
-    fprintf (fout, "\tlayout_upfactor:\t%d\n", graph->layout_upfactor);
-  if (graph->layout_nearfactor != G_LAYOUT_NEARFACTOR)
-    fprintf (fout, "\tlayout_nearfactor:\t%d\n", graph->layout_nearfactor);
-  if (graph->layout_splinefactor != G_LAYOUT_SPLINEFACTOR)
+	     get_layoutalgorithm_str (g->layoutalgorithm));
+
+  if (g->layout_downfactor != G_LAYOUT_DOWNFACTOR)
+    fprintf (fout, "\tlayout_downfactor:\t%d\n", g->layout_downfactor);
+  if (g->layout_upfactor != G_LAYOUT_UPFACTOR)
+    fprintf (fout, "\tlayout_upfactor:\t%d\n", g->layout_upfactor);
+  if (g->layout_nearfactor != G_LAYOUT_NEARFACTOR)
+    fprintf (fout, "\tlayout_nearfactor:\t%d\n", g->layout_nearfactor);
+  if (g->layout_splinefactor != G_LAYOUT_SPLINEFACTOR)
     fprintf (fout, "\tlayout_splinefactor:\t%d\n",
-	     graph->layout_splinefactor);
+	     g->layout_splinefactor);
 
-  if (graph->late_edge_labels != G_LATE_EDGE_LABELS)
+  if (g->late_edge_labels != G_LATE_EDGE_LABELS)
     fprintf (fout, "\tlate_edge_labels:\t%s\n",
-	     get_decision_str(graph->late_edge_labels));
-  if (graph->display_edge_labels != G_DISPLAY_EDGE_LABELS)
+	     get_decision_str (g->late_edge_labels));
+  if (g->display_edge_labels != G_DISPLAY_EDGE_LABELS)
     fprintf (fout, "\tdisplay_edge_labels:\t%s\n",
-	     get_decision_str(graph->display_edge_labels));
-  if (graph->dirty_edge_labels != G_DIRTY_EDGE_LABELS)
+	     get_decision_str (g->display_edge_labels));
+  if (g->dirty_edge_labels != G_DIRTY_EDGE_LABELS)
     fprintf (fout, "\tdirty_edge_labels:\t%s\n",
-	     get_decision_str(graph->dirty_edge_labels));
-  if (graph->finetuning != G_FINETUNING)
+	     get_decision_str (g->dirty_edge_labels));
+  if (g->finetuning != G_FINETUNING)
     fprintf (fout, "\tfinetuning:\t%s\n",
-	     get_decision_str(graph->finetuning));
-  if (graph->ignore_singles != G_IGNORE_SINGLES)
+	     get_decision_str (g->finetuning));
+  if (g->ignore_singles != G_IGNORE_SINGLES)
     fprintf (fout, "\tignore_singles:\t%s\n",
-	     get_decision_str(graph->ignore_singles));
-  if (graph->straight_phase != G_STRAIGHT_PHASE)
-    fprintf (fout, "\tstraight_phase:\t%s\n",
-	     get_decision_str(graph->straight_phase));
-  if (graph->priority_phase != G_PRIORITY_PHASE)
+	     get_decision_str (g->ignore_singles));
+  if (g->long_straight_phase != G_LONG_STRAIGHT_PHASE)
+    fprintf (fout, "\tlong_straight_phase:\t%s\n",
+	     get_decision_str (g->long_straight_phase));
+  if (g->priority_phase != G_PRIORITY_PHASE)
     fprintf (fout, "\tpriority_phase:\t%s\n",
-	     get_decision_str(graph->priority_phase));
-  if (graph->manhattan_edges != G_MANHATTAN_EDGES)
+	     get_decision_str (g->priority_phase));
+  if (g->manhattan_edges != G_MANHATTAN_EDGES)
     fprintf (fout,
 	     "\tmanhattan_edges:\t%s\n",
-	     get_decision_str(graph->manhattan_edges));
-  if (graph->smanhattan_edges != G_SMANHATTAN_EDGES)
+	     get_decision_str (g->manhattan_edges));
+  if (g->smanhattan_edges != G_SMANHATTAN_EDGES)
     fprintf (fout,
 	     "\tsmanhattan_edges:\t%s\n",
-	     get_decision_str(graph->smanhattan_edges));
-  if (graph->near_edges != G_NEAR_EDGES)
+	     get_decision_str (g->smanhattan_edges));
+  if (g->near_edges != G_NEAR_EDGES)
     fprintf (fout, "\tnear_edges:\t%s\n",
-	     get_decision_str(graph->near_edges));
+	     get_decision_str (g->near_edges));
 
-  if (graph->orientation != G_ORIENTATION)
+  if (g->orientation != G_ORIENTATION)
     fprintf (fout, "\torientation:\t%s\n",
-	     get_orientation_str(graph->orientation));
+	     get_orientation_str (g->orientation));
 
-  if (graph->node_alignement != G_NODE_ALIGNEMENT)
-    fprintf (fout, "\tnode_alignement:\t%s\n",
-	     get_node_alignement_str(graph->node_alignement));
+  if (g->node_alignment != G_NODE_ALIGNMENT)
+    fprintf (fout, "\tnode_alignment:\t%s\n",
+	     get_node_alignment_str (g->node_alignment));
 
-  if (graph->port_sharing != G_PORT_SHARING)
+  if (g->port_sharing != G_PORT_SHARING)
     fprintf (fout, "\tport_sharing:\t%s\n",
-	     get_decision_str(graph->port_sharing));
+	     get_decision_str (g->port_sharing));
 
-  if (graph->arrow_mode != G_ARROW_MODE)
+  if (g->arrow_mode != G_ARROW_MODE)
     fprintf (fout, "\tarrow_mode:\t%s\n",
-	     get_arrow_mode_str(graph->arrow_mode));
+	     get_arrow_mode_str (g->arrow_mode));
 
-  if (graph->treefactor != G_TREEFACTOR)
-    fprintf (fout, "\ttreefactor:\t%f\n", graph->treefactor);
-  if (graph->spreadlevel != G_SPREADLEVEL)
-    fprintf (fout, "\tspreadlevel:\t%d\n", graph->spreadlevel);
+  if (g->treefactor != G_TREEFACTOR)
+    fprintf (fout, "\ttreefactor:\t%f\n", g->treefactor);
+  if (g->spreadlevel != G_SPREADLEVEL)
+    fprintf (fout, "\tspreadlevel:\t%d\n", g->spreadlevel);
 
-  if (graph->crossing_weight != G_CROSSING_WEIGHT)
+  if (g->crossing_weight != G_CROSSING_WEIGHT)
     fprintf (fout, "\tcrossing_weight:\t%s\n",
-	     get_crossing_type_str(graph->crossing_weight));
-  if (graph->crossing_phase2 != G_CROSSING_PHASE2)
+	     get_crossing_type_str (g->crossing_weight));
+  if (g->crossing_phase2 != G_CROSSING_PHASE2)
     fprintf (fout, "\tcrossing_phase2:\t%s\n",
-	     get_decision_str(graph->crossing_phase2));
-  if (graph->crossing_optimization != G_CROSSING_OPTIMIZATION)
+	     get_decision_str (g->crossing_phase2));
+  if (g->crossing_optimization != G_CROSSING_OPTIMIZATION)
     fprintf (fout, "\tcrossing_optimization:\t%s\n",
-	     get_decision_str(graph->crossing_optimization));
-
-  if (graph->view != G_VIEW)
-    fprintf (fout, "\tview:\t%s\n", get_view_str(graph->view));
-
-  if (graph->edges != G_EDGES)
-    fprintf (fout, "\tedges:\t%s\n", get_decision_str(graph->edges));
-
-  if (graph->nodes != G_NODES)
-    fprintf (fout,"\tnodes:\t%s\n", get_decision_str(graph->nodes));
-
-  if (graph->splines != G_SPLINES)
-    fprintf (fout, "\tsplines:\t%s\n", get_decision_str(graph->splines));
-
-  if (graph->bmax != G_BMAX)
-    fprintf (fout, "\tbmax:\t%d\n", graph->bmax);
-  if (graph->cmin != G_CMIN)
-    fprintf (fout, "\tcmin:\t%d\n", graph->cmin);
-  if (graph->cmax != G_CMAX)
-    fprintf (fout, "\tcmax:\t%d\n", graph->cmax);
-  if (graph->pmin != G_PMIN)
-    fprintf (fout, "\tpmin:\t%d\n", graph->pmin);
-  if (graph->pmax != G_PMAX)
-    fprintf (fout, "\tpmax:\t%d\n", graph->pmax);
-  if (graph->rmin != G_RMIN)
-    fprintf (fout, "\trmin:\t%d\n", graph->rmin);
-  if (graph->rmax != G_RMAX)
-    fprintf (fout, "\trmax:\t%d\n", graph->rmax);
-  if (graph->smax != G_SMAX)
-    fprintf (fout, "\tsmax:\t%d\n", graph->smax);
+	     get_decision_str (g->crossing_optimization));
+
+  if (g->view != G_VIEW)
+    fprintf (fout, "\tview:\t%s\n", get_view_str (g->view));
+
+  if (g->edges != G_EDGES)
+    fprintf (fout, "\tedges:\t%s\n", get_decision_str (g->edges));
+
+  if (g->nodes != G_NODES)
+    fprintf (fout,"\tnodes:\t%s\n", get_decision_str (g->nodes));
+
+  if (g->splines != G_SPLINES)
+    fprintf (fout, "\tsplines:\t%s\n", get_decision_str (g->splines));
+
+  if (g->bmax != G_BMAX)
+    fprintf (fout, "\tbmax:\t%d\n", g->bmax);
+  if (g->cmin != G_CMIN)
+    fprintf (fout, "\tcmin:\t%d\n", g->cmin);
+  if (g->cmax != G_CMAX)
+    fprintf (fout, "\tcmax:\t%d\n", g->cmax);
+  if (g->pmin != G_PMIN)
+    fprintf (fout, "\tpmin:\t%d\n", g->pmin);
+  if (g->pmax != G_PMAX)
+    fprintf (fout, "\tpmax:\t%d\n", g->pmax);
+  if (g->rmin != G_RMIN)
+    fprintf (fout, "\trmin:\t%d\n", g->rmin);
+  if (g->rmax != G_RMAX)
+    fprintf (fout, "\trmax:\t%d\n", g->rmax);
+  if (g->smax != G_SMAX)
+    fprintf (fout, "\tsmax:\t%d\n", g->smax);
 }
