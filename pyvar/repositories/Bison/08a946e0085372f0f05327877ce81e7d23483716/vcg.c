@@ -21,6 +21,16 @@
 #include "system.h"
 #include "vcg.h"
 #include "vcg_defaults.h"
+#include "quotearg.h"
+
+/* Return an unambiguous printable representated, allocated in slot 0,
+   for NAME, suitable for C strings.  */
+static char const *
+quote (char const *name)
+{
+  return quotearg_n_style (0, c_quoting_style, name);
+}
+
 
 /* Initialize a graph with the default values. */
 void
@@ -429,7 +439,7 @@ void
 add_classname (graph_t *g, int val, const char *name)
 {
   struct classname_s *classname;
-  
+
   classname = XMALLOC (struct classname_s, 1);
   classname->no = val;
   classname->name = name;
@@ -441,7 +451,7 @@ void
 add_infoname (graph_t *g, int integer, const char *string)
 {
   struct infoname_s *infoname;
-  
+
   infoname = XMALLOC (struct infoname_s, 1);
   infoname->integer = integer;
   infoname->string = string;
@@ -451,11 +461,11 @@ add_infoname (graph_t *g, int integer, const char *string)
 
 /* Build a colorentry struct and add it to the list.  */
 void
-add_colorentry (graph_t *g, int color_idx, int red_cp, 
+add_colorentry (graph_t *g, int color_idx, int red_cp,
 		int green_cp, int blue_cp)
 {
   struct colorentry_s *ce;
-  
+
   ce = XMALLOC (struct colorentry_s, 1);
   ce->color_index = color_idx;
   ce->red_cp = red_cp;
@@ -556,9 +566,9 @@ void
 output_node (node_t *node, FILE *fout)
 {
   if (node->title != N_TITLE)
-    fprintf (fout, "\t\ttitle:\t\"%s\"\n", node->title);
+    fprintf (fout, "\t\ttitle:\t%s\n", quote (node->title));
   if (node->label != N_LABEL)
-    fprintf (fout, "\t\tlabel:\t\"%s\"\n", node->label);
+    fprintf (fout, "\t\tlabel:\t%s\n", quote (node->label));
 
   if ((node->locx != N_LOCX) && (node->locy != N_LOCY))
     fprintf (fout, "\t\tloc { x: %d  y: %d }\t\n", node->locx, node->locy);
@@ -600,12 +610,13 @@ output_node (node_t *node, FILE *fout)
     fprintf (fout, "\t\tbordercolor:\t%s\n",
 	     get_color_str (node->bordercolor));
 
-  if (node->infos[0])
-    fprintf (fout, "\t\tinfo1:\t\"%s\"\n", node->infos[0]);
-  if (node->infos[1])
-    fprintf (fout, "\t\tinfo2:\t\"%s\"\n", node->infos[1]);
-  if (node->infos[2])
-    fprintf (fout, "\t\tinfo3:\t\"%s\"\n", node->infos[2]);
+  {
+    int i;
+    for (i = 0; i < 3; ++i)
+      if (node->infos[i])
+	fprintf (fout, "\t\tinfo%d:\t%s\n",
+		 i, quote (node->infos[i]));
+  }
 }
 
 void
@@ -614,16 +625,16 @@ output_edge (edge_t *edge, FILE *fout)
   /* FIXME: SOURCENAME and TARGETNAME are mandatory
      so it has to be fatal not to give these informations.  */
   if (edge->sourcename != E_SOURCENAME)
-    fprintf (fout, "\t\tsourcename:\t\"%s\"\n", edge->sourcename);
+    fprintf (fout, "\t\tsourcename:\t%s\n", quote (edge->sourcename));
   if (edge->targetname != E_TARGETNAME)
-    fprintf (fout, "\t\ttargetname:\t\"%s\"\n", edge->targetname);
+    fprintf (fout, "\t\ttargetname:\t%s\n", quote (edge->targetname));
 
   if (edge->label != E_LABEL)
-    fprintf (fout, "\t\tlabel:\t\"%s\"\n", edge->label);
+    fprintf (fout, "\t\tlabel:\t%s\n", quote (edge->label));
 
   if (edge->linestyle != E_LINESTYLE)
-    fprintf (fout, "\t\tlinestyle:\t\"%s\"\n", 
-	     get_linestyle_str(edge->linestyle));
+    fprintf (fout, "\t\tlinestyle:\t%s\n",
+	     quote (get_linestyle_str(edge->linestyle)));
 
   if (edge->thickness != E_THICKNESS)
     fprintf (fout, "\t\tthickness:\t%d\n", edge->thickness);
@@ -666,16 +677,16 @@ void
 output_graph (graph_t *graph, FILE *fout)
 {
   if (graph->title)
-    fprintf (fout, "\ttitle:\t\"%s\"\n", graph->title);
+    fprintf (fout, "\ttitle:\t%s\n", quote (graph->title));
   if (graph->label)
-    fprintf (fout, "\tlabel:\t\"%s\"\n", graph->label);
+    fprintf (fout, "\tlabel:\t%s\n", quote (graph->label));
 
-  if (graph->infos[0])
-    fprintf (fout, "\tinfo1:\t\"%s\"\n", graph->infos[0]);
-  if (graph->infos[1])
-    fprintf (fout, "\tinfo2:\t\"%s\"\n", graph->infos[1]);
-  if (graph->infos[2])
-    fprintf (fout, "\tinfo3:\t\"%s\"\n", graph->infos[2]);
+  {
+    int i;
+    for (i = 0; i < 3; ++i)
+      if (graph->infos[i])
+	fprintf (fout, "\tinfo%d:\t%s\n", i, quote (graph->infos[i]));
+  }
 
   if (graph->color != G_COLOR)
     fprintf (fout, "\tcolor:\t%s\n", get_color_str (graph->color));
@@ -711,11 +722,11 @@ output_graph (graph_t *graph, FILE *fout)
 
   if (graph->shape != G_SHAPE)
     fprintf (fout, "\tshape:\t%s\n", get_shape_str (graph->shape));
-  
+
   if (graph->vertical_order != G_VERTICAL_ORDER)
-    fprintf (fout, "\tvertical_order:\t%d\n", graph->vertical_order);  
+    fprintf (fout, "\tvertical_order:\t%d\n", graph->vertical_order);
   if (graph->horizontal_order != G_HORIZONTAL_ORDER)
-    fprintf (fout, "\thorizontal_order:\t%d\n", graph->horizontal_order);  
+    fprintf (fout, "\thorizontal_order:\t%d\n", graph->horizontal_order);
 
   if (graph->xmax != G_XMAX)
     fprintf (fout, "\txmax:\t%d\n", graph->xmax);
@@ -743,8 +754,8 @@ output_graph (graph_t *graph, FILE *fout)
 
   if (graph->hidden != G_HIDDEN)
     fprintf (fout, "\thidden:\t%d\n", graph->hidden);
-  
-  /* FIXME: Unallocate struct list if required.  
+
+  /* FIXME: Unallocate struct list if required.
      Maybe with a little function.  */
   if (graph->classname != G_CLASSNAME)
     {
@@ -765,15 +776,15 @@ output_graph (graph_t *graph, FILE *fout)
   if (graph->colorentry != G_COLORENTRY)
     {
       struct colorentry_s *ite;
-      
+
       for (ite = graph->colorentry; ite; ite = ite->next)
-	{	
-	  fprintf (fout, "\tcolorentry %d :\t%d %d %d\n", 
-		   ite->color_index, 
+	{
+	  fprintf (fout, "\tcolorentry %d :\t%d %d %d\n",
+		   ite->color_index,
 		   ite->red_cp,
 		   ite->green_cp,
 		   ite->blue_cp);
-	}    
+	}
     }
 
   if (graph->layoutalgorithm != G_LAYOUTALGORITHM)
