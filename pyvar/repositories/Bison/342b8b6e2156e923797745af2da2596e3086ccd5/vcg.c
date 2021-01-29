@@ -21,8 +21,6 @@
 #include "system.h"
 #include "vcg.h"
 #include "vcg_defaults.h"
-#include "xalloc.h"
-#include "complain.h"
 
 /* Initialize a graph with the default values. */
 void
@@ -51,6 +49,9 @@ new_graph (graph_t *g)
   g->textmode = G_TEXTMODE;
   g->shape = G_SHAPE;
 
+  g->vertical_order = G_VERTICAL_ORDER;
+  g->horizontal_order = G_HORIZONTAL_ORDER;
+
   g->xmax = G_XMAX; /* Not output. */
   g->ymax = G_YMAX; /* Not output. */
 
@@ -231,8 +232,7 @@ get_color_str (enum color_e c)
     case orchid:	return "orchid";
     case black:		return "black";
     default:
-      complain (_("vcg graph: no such color."));
-      return get_color_str(G_COLOR);
+      assert (!"Not a default color.");
     }
   return NULL;
 }
@@ -246,8 +246,7 @@ get_textmode_str (enum textmode_e t)
     case left_justify:	return "left_justify";
     case right_justify:	return "right_justify";
     default:
-      complain (_("vcg graph: no such text mode"));
-      return get_textmode_str(G_TEXTMODE);
+      assert (!"Not a text mode.");
     }
   return NULL;
 }
@@ -262,8 +261,7 @@ get_shape_str (enum shape_e s)
     case ellipse:	return "ellipse";
     case triangle:	return "triangle";
     default:
-      complain (_("vcg graph: no such shape"));
-      return get_shape_str(G_SHAPE);
+      assert (!"Not a shape.");
     }
   return NULL;
 }
@@ -288,21 +286,20 @@ get_layoutalgorithm_str (enum layoutalgorithm_e l)
     case dfs:		return "dfs";
     case tree:		return "tree";
     default:
-      return "normal";
+      assert (!"Not a layout algorithm.");
     }
   return NULL;
 }
 
 static const char *
-get_decision_str (enum decision_e d, enum decision_e defaults)
+get_decision_str (enum decision_e d)
 {
   switch (d)
     {
     case no:	return "no";
     case yes:	return "yes";
     default:
-      complain (_("vcg graph: no such decision"));
-      return get_decision_str(defaults, 0);
+      assert (!"Either yes nor no.");
     }
   return NULL;
 }
@@ -317,8 +314,7 @@ get_orientation_str (enum orientation_e o)
     case left_to_right: return "left_to_right";
     case right_to_left: return "right_to_left";
     default:
-      complain (_("vcg graph: no such an orientation"));
-      return get_orientation_str(G_ORIENTATION);
+      assert (!"Not an orientation.");
     }
   return NULL;
 }
@@ -332,8 +328,7 @@ get_node_alignement_str (enum alignement_e a)
     case top:		return "top";
     case bottom:	return "bottom";
     default:
-      complain (_("vcg graph: no such an alignement"));
-      return get_node_alignement_str(G_NODE_ALIGNEMENT);
+      assert (!"Not an alignement.");
     }
   return NULL;
 }
@@ -346,8 +341,7 @@ get_arrow_mode_str (enum arrow_mode_e a)
     case fixed:		return "fixed";
     case free_a:	return "free";
     default:
-      complain (_("vcg graph: no such an arrow mode"));
-      return get_arrow_mode_str(G_ARROW_MODE);
+      assert (!"Not an arrow mode.");
     }
   return NULL;
 }
@@ -362,8 +356,7 @@ get_crossing_type_str (enum crossing_type_e c)
     case barymedian:	return "barymedian";
     case medianbary:	return "medianbary";
     default:
-      complain (_("vcg graph: no such crossing_type"));
-      return get_crossing_type_str(G_CROSSING_WEIGHT);
+      assert (!"Not a crossing type.");
     }
   return NULL;
 }
@@ -379,8 +372,7 @@ get_view_str (enum view_e v)
     case fcfish:	return "fcfish";
     case fpfish:	return "fpfish";
     default:
-      complain (_("vcg graph: no such view"));
-      return get_view_str(G_VIEW);
+      assert (!"Not a view.");
     }
   return NULL;
 }
@@ -395,8 +387,7 @@ get_linestyle_str (enum linestyle_e l)
     case dotted:	return "dotted";
     case invisible:	return "invisible";
     default:
-      complain (_("vcg graph: no such linestyle"));
-      return get_linestyle_str(E_LINESTYLE);
+      assert (!"Not a line style.");
     }
   return NULL;
 }
@@ -410,8 +401,7 @@ get_arrowstyle_str (enum arrowstyle_e a)
     case line:	return "line";
     case none:	return "none";
     default:
-      complain (_("vcg graph: no such an arrowstyle"));
-      return get_arrowstyle_str(E_ARROWSTYLE);
+      assert (!"Not an arrow style.");
     }
   return NULL;
 }
@@ -435,402 +425,461 @@ add_edge (graph_t *graph, edge_t *edge)
   graph->edge_list = edge;
 }
 
+void
+add_classname (graph_t *g, int val, const char *name)
+{
+  struct classname_s *classname;
+  
+  classname = XMALLOC (struct classname_s, 1);
+  classname->no = val;
+  classname->name = name;
+  classname->next = g->classname;
+  g->classname = classname;
+}
+
+void
+add_infoname (graph_t *g, int integer, const char *string)
+{
+  struct infoname_s *infoname;
+  
+  infoname = XMALLOC (struct infoname_s, 1);
+  infoname->integer = integer;
+  infoname->string = string;
+  infoname->next = g->infoname;
+  g->infoname = infoname;
+}
+
+/* Build a colorentry struct and add it to the list.  */
+void
+add_colorentry (graph_t *g, int color_idx, int red_cp, 
+		int green_cp, int blue_cp)
+{
+  struct colorentry_s *ce;
+  
+  ce = XMALLOC (struct colorentry_s, 1);
+  ce->color_index = color_idx;
+  ce->red_cp = red_cp;
+  ce->green_cp = green_cp;
+  ce->blue_cp = blue_cp;
+  ce->next = g->colorentry;
+  g->colorentry = ce;
+}
+
 /*-------------------------------------.
 | Open and close functions (formatted) |
 `-------------------------------------*/
 
 void
-open_edge(edge_t *edge, struct obstack *os)
+open_edge(edge_t *edge, FILE *fout)
 {
   switch (edge->type)
     {
     case normal_edge:
-      obstack_sgrow (os, "\tedge: {\n");
+      fputs ("\tedge: {\n", fout);
       break;
     case back_edge:
-      obstack_sgrow (os, "\tbackedge: {\n");
+      fputs ("\tbackedge: {\n", fout);
       break;
     case near_edge:
-      obstack_sgrow (os, "\tnearedge: {\n");
+      fputs ("\tnearedge: {\n", fout);
       break;
     case bent_near_edge:
-      obstack_sgrow (os, "\tbentnearedge: {\n");
+      fputs ("\tbentnearedge: {\n", fout);
       break;
     default:
-      obstack_sgrow (os, "\tedge: {\n");
+      fputs ("\tedge: {\n", fout);
     }
 }
 
 void
-close_edge(struct obstack *os)
+close_edge(FILE *fout)
 {
-  obstack_sgrow (os, "\t}\n");
+  fputs ("\t}\n", fout);
 }
 
 void
-open_node(struct obstack *os)
+open_node(FILE *fout)
 {
-  obstack_sgrow (os, "\tnode: {\n");
+  fputs ("\tnode: {\n", fout);
 }
 
 void
-close_node(struct obstack *os)
+close_node(FILE *fout)
 {
-  obstack_sgrow (os, "\t}\n");
+  fputs ("\t}\n", fout);
 }
 
 void
-open_graph(struct obstack *os)
+open_graph(FILE *fout)
 {
-  obstack_sgrow (os, "graph: {\n");
+  fputs ("graph: {\n", fout);
 }
 
 void
-close_graph(graph_t *graph, struct obstack *os)
+close_graph(graph_t *graph, FILE *fout)
 {
-  obstack_1grow (os, '\n');
+  fputc ('\n', fout);
 
+  /* FIXME: Unallocate nodes and edges if required.  */
   {
     node_t *node;
 
     for (node = graph->node_list; node; node = node->next)
       {
-	open_node (os);
-	output_node (node, os);
-	close_node (os);
+	open_node (fout);
+	output_node (node, fout);
+	close_node (fout);
       }
   }
 
-  obstack_1grow (os, '\n');
+  fputc ('\n', fout);
 
   {
     edge_t *edge;
 
     for (edge = graph->edge_list; edge; edge = edge->next)
       {
-	open_edge (edge, os);
-	output_edge (edge, os);
-	close_edge (os);
+	open_edge (edge, fout);
+	output_edge (edge, fout);
+	close_edge (fout);
       }
   }
 
-  obstack_sgrow (os, "}\n");
+  fputs ("}\n", fout);
 }
 
 /*-------------------------------------------.
-| Output functions (formatted) in obstack os |
+| Output functions (formatted) in file FOUT  |
 `-------------------------------------------*/
 
 void
-output_node (node_t *node, struct obstack *os)
+output_node (node_t *node, FILE *fout)
 {
   if (node->title != N_TITLE)
-    obstack_fgrow1 (os, "\t\ttitle:\t\"%s\"\n", node->title);
+    fprintf (fout, "\t\ttitle:\t\"%s\"\n", node->title);
   if (node->label != N_LABEL)
-    obstack_fgrow1 (os, "\t\tlabel:\t\"%s\"\n", node->label);
+    fprintf (fout, "\t\tlabel:\t\"%s\"\n", node->label);
 
   if ((node->locx != N_LOCX) && (node->locy != N_LOCY))
-    obstack_fgrow2 (os, "\t\tloc { x: %d  y: %d }\t\n", node->locx, node->locy);
+    fprintf (fout, "\t\tloc { x: %d  y: %d }\t\n", node->locx, node->locy);
 
   if (node->vertical_order != N_VERTICAL_ORDER)
-    obstack_fgrow1 (os, "\t\tvertical_order:\t%d\n", node->vertical_order);
+    fprintf (fout, "\t\tvertical_order:\t%d\n", node->vertical_order);
   if (node->horizontal_order != N_HORIZONTAL_ORDER)
-    obstack_fgrow1 (os, "\t\thorizontal_order:\t%d\n", node->horizontal_order);
+    fprintf (fout, "\t\thorizontal_order:\t%d\n", node->horizontal_order);
 
   if (node->width != N_WIDTH)
-    obstack_fgrow1 (os, "\t\twidth:\t%d\n", node->width);
+    fprintf (fout, "\t\twidth:\t%d\n", node->width);
   if (node->height != N_HEIGHT)
-    obstack_fgrow1 (os, "\t\theight:\t%d\n", node->height);
+    fprintf (fout, "\t\theight:\t%d\n", node->height);
 
   if (node->shrink != N_SHRINK)
-    obstack_fgrow1 (os, "\t\tshrink:\t%d\n", node->shrink);
+    fprintf (fout, "\t\tshrink:\t%d\n", node->shrink);
   if (node->stretch != N_STRETCH)
-    obstack_fgrow1 (os, "\t\tstretch:\t%d\n", node->stretch);
+    fprintf (fout, "\t\tstretch:\t%d\n", node->stretch);
 
   if (node->folding != N_FOLDING)
-    obstack_fgrow1 (os, "\t\tfolding:\t%d\n", node->folding);
+    fprintf (fout, "\t\tfolding:\t%d\n", node->folding);
 
   if (node->textmode != N_TEXTMODE)
-    obstack_fgrow1 (os, "\t\ttextmode:\t%s\n",
-		    get_textmode_str (node->textmode));
+    fprintf (fout, "\t\ttextmode:\t%s\n",
+	     get_textmode_str (node->textmode));
 
   if (node->shape != N_SHAPE)
-    obstack_fgrow1 (os, "\t\tshape:\t%s\n", get_shape_str (node->shape));
+    fprintf (fout, "\t\tshape:\t%s\n", get_shape_str (node->shape));
 
   if (node->borderwidth != N_BORDERWIDTH)
-    obstack_fgrow1 (os, "\t\tborderwidth:\t%d\n", node->borderwidth);
+    fprintf (fout, "\t\tborderwidth:\t%d\n", node->borderwidth);
 
   if (node->color != N_COLOR)
-    obstack_fgrow1 (os, "\t\tcolor:\t%s\n", get_color_str (node->color));
+    fprintf (fout, "\t\tcolor:\t%s\n", get_color_str (node->color));
   if (node->textcolor != N_TEXTCOLOR)
-    obstack_fgrow1 (os, "\t\ttextcolor:\t%s\n",
-		    get_color_str (node->textcolor));
+    fprintf (fout, "\t\ttextcolor:\t%s\n",
+	     get_color_str (node->textcolor));
   if (node->bordercolor != N_BORDERCOLOR)
-    obstack_fgrow1 (os, "\t\tbordercolor:\t%s\n",
-		    get_color_str (node->bordercolor));
+    fprintf (fout, "\t\tbordercolor:\t%s\n",
+	     get_color_str (node->bordercolor));
 
   if (node->infos[0])
-    obstack_fgrow1 (os, "\t\tinfo1:\t\"%s\"\n", node->infos[0]);
+    fprintf (fout, "\t\tinfo1:\t\"%s\"\n", node->infos[0]);
   if (node->infos[1])
-    obstack_fgrow1 (os, "\t\tinfo2:\t\"%s\"\n", node->infos[1]);
+    fprintf (fout, "\t\tinfo2:\t\"%s\"\n", node->infos[1]);
   if (node->infos[2])
-    obstack_fgrow1 (os, "\t\tinfo3:\t\"%s\"\n", node->infos[2]);
+    fprintf (fout, "\t\tinfo3:\t\"%s\"\n", node->infos[2]);
 }
 
 void
-output_edge (edge_t *edge, struct obstack *os)
+output_edge (edge_t *edge, FILE *fout)
 {
   /* FIXME: SOURCENAME and TARGETNAME are mandatory
      so it has to be fatal not to give these informations.  */
   if (edge->sourcename != E_SOURCENAME)
-    obstack_fgrow1 (os, "\t\tsourcename:\t\"%s\"\n", edge->sourcename);
+    fprintf (fout, "\t\tsourcename:\t\"%s\"\n", edge->sourcename);
   if (edge->targetname != E_TARGETNAME)
-    obstack_fgrow1 (os, "\t\ttargetname:\t\"%s\"\n", edge->targetname);
+    fprintf (fout, "\t\ttargetname:\t\"%s\"\n", edge->targetname);
 
   if (edge->label != E_LABEL)
-    obstack_fgrow1 (os, "\t\tlabel:\t\"%s\"\n", edge->label);
+    fprintf (fout, "\t\tlabel:\t\"%s\"\n", edge->label);
 
   if (edge->linestyle != E_LINESTYLE)
-    obstack_fgrow1 (os, "\t\tlinestyle:\t\"%s\"\n",
-		    get_linestyle_str(edge->linestyle));
+    fprintf (fout, "\t\tlinestyle:\t\"%s\"\n", 
+	     get_linestyle_str(edge->linestyle));
 
   if (edge->thickness != E_THICKNESS)
-    obstack_fgrow1 (os, "\t\tthickness:\t%d\n", edge->thickness);
+    fprintf (fout, "\t\tthickness:\t%d\n", edge->thickness);
   if (edge->class != E_CLASS)
-    obstack_fgrow1 (os, "\t\tclass:\t%d\n", edge->class);
+    fprintf (fout, "\t\tclass:\t%d\n", edge->class);
 
   if (edge->color != E_COLOR)
-    obstack_fgrow1 (os, "\t\tcolor:\t%s\n", get_color_str (edge->color));
+    fprintf (fout, "\t\tcolor:\t%s\n", get_color_str (edge->color));
   if (edge->color != E_TEXTCOLOR)
-    obstack_fgrow1 (os, "\t\ttextcolor:\t%s\n",
-		    get_color_str (edge->textcolor));
+    fprintf (fout, "\t\ttextcolor:\t%s\n",
+	     get_color_str (edge->textcolor));
   if (edge->arrowcolor != E_ARROWCOLOR)
-    obstack_fgrow1 (os, "\t\tarrowcolor:\t%s\n",
-		    get_color_str (edge->arrowcolor));
+    fprintf (fout, "\t\tarrowcolor:\t%s\n",
+	     get_color_str (edge->arrowcolor));
   if (edge->backarrowcolor != E_BACKARROWCOLOR)
-    obstack_fgrow1 (os, "\t\tbackarrowcolor:\t%s\n",
-		    get_color_str (edge->backarrowcolor));
+    fprintf (fout, "\t\tbackarrowcolor:\t%s\n",
+	     get_color_str (edge->backarrowcolor));
 
   if (edge->arrowsize != E_ARROWSIZE)
-    obstack_fgrow1 (os, "\t\tarrowsize:\t%d\n", edge->arrowsize);
+    fprintf (fout, "\t\tarrowsize:\t%d\n", edge->arrowsize);
   if (edge->backarrowsize != E_BACKARROWSIZE)
-    obstack_fgrow1 (os, "\t\tbackarrowsize:\t%d\n", edge->backarrowsize);
+    fprintf (fout, "\t\tbackarrowsize:\t%d\n", edge->backarrowsize);
 
   if (edge->arrowstyle != E_ARROWSTYLE)
-    obstack_fgrow1 (os, "\t\tarrowstyle:\t%s\n",
-		    get_arrowstyle_str(edge->arrowstyle));
+    fprintf (fout, "\t\tarrowstyle:\t%s\n",
+	     get_arrowstyle_str(edge->arrowstyle));
   if (edge->backarrowstyle != E_BACKARROWSTYLE)
-    obstack_fgrow1 (os, "\t\tbackarrowstyle:\t%s\n",
-		    get_arrowstyle_str(edge->backarrowstyle));
+    fprintf (fout, "\t\tbackarrowstyle:\t%s\n",
+	     get_arrowstyle_str(edge->backarrowstyle));
 
   if (edge->priority != E_PRIORITY)
-    obstack_fgrow1 (os, "\t\tpriority:\t%d\n", edge->priority);
+    fprintf (fout, "\t\tpriority:\t%d\n", edge->priority);
   if (edge->anchor != E_ANCHOR)
-    obstack_fgrow1 (os, "\t\tanchor:\t%d\n", edge->anchor);
+    fprintf (fout, "\t\tanchor:\t%d\n", edge->anchor);
   if (edge->horizontal_order != E_HORIZONTAL_ORDER)
-    obstack_fgrow1 (os, "\t\thorizontal_order:\t%d\n", edge->horizontal_order);
+    fprintf (fout, "\t\thorizontal_order:\t%d\n", edge->horizontal_order);
 }
 
 void
-output_graph (graph_t *graph, struct obstack *os)
+output_graph (graph_t *graph, FILE *fout)
 {
   if (graph->title)
-    obstack_fgrow1 (os, "\ttitle:\t\"%s\"\n", graph->title);
+    fprintf (fout, "\ttitle:\t\"%s\"\n", graph->title);
   if (graph->label)
-    obstack_fgrow1 (os, "\tlabel:\t\"%s\"\n", graph->label);
+    fprintf (fout, "\tlabel:\t\"%s\"\n", graph->label);
 
   if (graph->infos[0])
-    obstack_fgrow1 (os, "\tinfo1:\t\"%s\"\n", graph->infos[0]);
+    fprintf (fout, "\tinfo1:\t\"%s\"\n", graph->infos[0]);
   if (graph->infos[1])
-    obstack_fgrow1 (os, "\tinfo2:\t\"%s\"\n", graph->infos[1]);
+    fprintf (fout, "\tinfo2:\t\"%s\"\n", graph->infos[1]);
   if (graph->infos[2])
-    obstack_fgrow1 (os, "\tinfo3:\t\"%s\"\n", graph->infos[2]);
+    fprintf (fout, "\tinfo3:\t\"%s\"\n", graph->infos[2]);
 
   if (graph->color != G_COLOR)
-    obstack_fgrow1 (os, "\tcolor:\t%s\n", get_color_str (graph->color));
+    fprintf (fout, "\tcolor:\t%s\n", get_color_str (graph->color));
   if (graph->textcolor != G_TEXTCOLOR)
-    obstack_fgrow1 (os, "\ttextcolor:\t%s\n", get_color_str (graph->textcolor));
+    fprintf (fout, "\ttextcolor:\t%s\n", get_color_str (graph->textcolor));
   if (graph->bordercolor != G_BORDERCOLOR)
-    obstack_fgrow1 (os, "\tbordercolor:\t%s\n",
-		    get_color_str (graph->bordercolor));
+    fprintf (fout, "\tbordercolor:\t%s\n",
+	     get_color_str (graph->bordercolor));
 
   if (graph->width != G_WIDTH)
-    obstack_fgrow1 (os, "\twidth:\t%d\n", graph->width);
+    fprintf (fout, "\twidth:\t%d\n", graph->width);
   if (graph->height != G_HEIGHT)
-    obstack_fgrow1 (os, "\theight:\t%d\n", graph->height);
+    fprintf (fout, "\theight:\t%d\n", graph->height);
   if (graph->borderwidth != G_BORDERWIDTH)
-    obstack_fgrow1 (os, "\tborderwidth:\t%d\n", graph->borderwidth);
+    fprintf (fout, "\tborderwidth:\t%d\n", graph->borderwidth);
 
   if (graph->x != G_X)
-    obstack_fgrow1 (os, "\tx:\t%d\n", graph->x);
+    fprintf (fout, "\tx:\t%d\n", graph->x);
   if (graph->y != G_Y)
-    obstack_fgrow1 (os, "\ty:\t%d\n", graph->y);
+    fprintf (fout, "\ty:\t%d\n", graph->y);
 
   if (graph->folding != G_FOLDING)
-    obstack_fgrow1 (os, "\tfolding:\t%d\n", graph->folding);
+    fprintf (fout, "\tfolding:\t%d\n", graph->folding);
 
   if (graph->shrink != G_SHRINK)
-    obstack_fgrow1 (os, "\tshrink:\t%d\n", graph->shrink);
+    fprintf (fout, "\tshrink:\t%d\n", graph->shrink);
   if (graph->stretch != G_STRETCH)
-    obstack_fgrow1 (os, "\tstretch:\t%d\n", graph->stretch);
+    fprintf (fout, "\tstretch:\t%d\n", graph->stretch);
 
   if (graph->textmode != G_TEXTMODE)
-    obstack_fgrow1 (os, "\ttextmode:\t%s\n",
-		    get_textmode_str (graph->textmode));
+    fprintf (fout, "\ttextmode:\t%s\n",
+	     get_textmode_str (graph->textmode));
 
   if (graph->shape != G_SHAPE)
-    obstack_fgrow1 (os, "\tshape:\t%s\n", get_shape_str (graph->shape));
+    fprintf (fout, "\tshape:\t%s\n", get_shape_str (graph->shape));
+  
+  if (graph->vertical_order != G_VERTICAL_ORDER)
+    fprintf (fout, "\tvertical_order:\t%d\n", graph->vertical_order);  
+  if (graph->horizontal_order != G_HORIZONTAL_ORDER)
+    fprintf (fout, "\thorizontal_order:\t%d\n", graph->horizontal_order);  
 
   if (graph->xmax != G_XMAX)
-    obstack_fgrow1 (os, "\txmax:\t%d\n", graph->xmax);
+    fprintf (fout, "\txmax:\t%d\n", graph->xmax);
   if (graph->ymax != G_YMAX)
-    obstack_fgrow1 (os, "\tymax:\t%d\n", graph->ymax);
+    fprintf (fout, "\tymax:\t%d\n", graph->ymax);
 
   if (graph->xbase != G_XBASE)
-    obstack_fgrow1 (os, "\txbase:\t%d\n", graph->xbase);
+    fprintf (fout, "\txbase:\t%d\n", graph->xbase);
   if (graph->ybase != G_YBASE)
-    obstack_fgrow1 (os, "\tybase:\t%d\n", graph->ybase);
+    fprintf (fout, "\tybase:\t%d\n", graph->ybase);
 
   if (graph->xspace != G_XSPACE)
-    obstack_fgrow1 (os, "\txspace:\t%d\n", graph->xspace);
+    fprintf (fout, "\txspace:\t%d\n", graph->xspace);
   if (graph->yspace != G_YSPACE)
-    obstack_fgrow1 (os, "\tyspace:\t%d\n", graph->yspace);
+    fprintf (fout, "\tyspace:\t%d\n", graph->yspace);
   if (graph->xlspace != G_XLSPACE)
-    obstack_fgrow1 (os, "\txlspace:\t%d\n", graph->xlspace);
+    fprintf (fout, "\txlspace:\t%d\n", graph->xlspace);
 
   if (graph->xraster != G_XRASTER)
-    obstack_fgrow1 (os, "\txraster:\t%d\n", graph->xraster);
+    fprintf (fout, "\txraster:\t%d\n", graph->xraster);
   if (graph->yraster != G_YRASTER)
-    obstack_fgrow1 (os, "\tyraster:\t%d\n", graph->yraster);
+    fprintf (fout, "\tyraster:\t%d\n", graph->yraster);
   if (graph->xlraster != G_XLRASTER)
-    obstack_fgrow1 (os, "\txlraster:\t%d\n", graph->xlraster);
+    fprintf (fout, "\txlraster:\t%d\n", graph->xlraster);
 
   if (graph->hidden != G_HIDDEN)
-    obstack_fgrow1 (os, "\thidden:\t%d\n", graph->hidden);
-
+    fprintf (fout, "\thidden:\t%d\n", graph->hidden);
+  
+  /* FIXME: Unallocate struct list if required.  
+     Maybe with a little function.  */
   if (graph->classname != G_CLASSNAME)
     {
       struct classname_s *ite;
 
       for (ite = graph->classname; ite; ite = ite->next)
-	obstack_fgrow2 (os, "\tclassname %d :\t%s\n", ite->no, ite->name);
+	fprintf (fout, "\tclassname %d :\t%s\n", ite->no, ite->name);
+    }
+
+  if (graph->infoname != G_INFONAME)
+    {
+      struct infoname_s *ite;
+
+      for (ite = graph->infoname; ite; ite = ite->next)
+	fprintf (fout, "\tinfoname %d :\t%s\n", ite->integer, ite->string);
+    }
+
+  if (graph->colorentry != G_COLORENTRY)
+    {
+      struct colorentry_s *ite;
+      
+      for (ite = graph->colorentry; ite; ite = ite->next)
+	{	
+	  fprintf (fout, "\tcolorentry %d :\t%d %d %d\n", 
+		   ite->color_index, 
+		   ite->red_cp,
+		   ite->green_cp,
+		   ite->blue_cp);
+	}    
     }
 
   if (graph->layoutalgorithm != G_LAYOUTALGORITHM)
-    obstack_fgrow1 (os, "\tlayoutalgorithm:\t%s\n",
-		    get_layoutalgorithm_str(graph->layoutalgorithm));
+    fprintf (fout, "\tlayoutalgorithm:\t%s\n",
+	     get_layoutalgorithm_str(graph->layoutalgorithm));
 
   if (graph->layout_downfactor != G_LAYOUT_DOWNFACTOR)
-    obstack_fgrow1 (os, "\tlayout_downfactor:\t%d\n", graph->layout_downfactor);
+    fprintf (fout, "\tlayout_downfactor:\t%d\n", graph->layout_downfactor);
   if (graph->layout_upfactor != G_LAYOUT_UPFACTOR)
-    obstack_fgrow1 (os, "\tlayout_upfactor:\t%d\n", graph->layout_upfactor);
+    fprintf (fout, "\tlayout_upfactor:\t%d\n", graph->layout_upfactor);
   if (graph->layout_nearfactor != G_LAYOUT_NEARFACTOR)
-    obstack_fgrow1 (os, "\tlayout_nearfactor:\t%d\n", graph->layout_nearfactor);
+    fprintf (fout, "\tlayout_nearfactor:\t%d\n", graph->layout_nearfactor);
   if (graph->layout_splinefactor != G_LAYOUT_SPLINEFACTOR)
-    obstack_fgrow1 (os, "\tlayout_splinefactor:\t%d\n",
-		    graph->layout_splinefactor);
+    fprintf (fout, "\tlayout_splinefactor:\t%d\n",
+	     graph->layout_splinefactor);
 
   if (graph->late_edge_labels != G_LATE_EDGE_LABELS)
-    obstack_fgrow1 (os, "\tlate_edge_labels:\t%s\n",
-		    get_decision_str(graph->late_edge_labels,
-				     G_LATE_EDGE_LABELS));
+    fprintf (fout, "\tlate_edge_labels:\t%s\n",
+	     get_decision_str(graph->late_edge_labels));
   if (graph->display_edge_labels != G_DISPLAY_EDGE_LABELS)
-    obstack_fgrow1 (os, "\tdisplay_edge_labels:\t%s\n",
-		    get_decision_str(graph->display_edge_labels,
-				     G_DISPLAY_EDGE_LABELS));
+    fprintf (fout, "\tdisplay_edge_labels:\t%s\n",
+	     get_decision_str(graph->display_edge_labels));
   if (graph->dirty_edge_labels != G_DIRTY_EDGE_LABELS)
-    obstack_fgrow1 (os, "\tdirty_edge_labels:\t%s\n",
-		    get_decision_str(graph->dirty_edge_labels,
-				     G_DIRTY_EDGE_LABELS));
+    fprintf (fout, "\tdirty_edge_labels:\t%s\n",
+	     get_decision_str(graph->dirty_edge_labels));
   if (graph->finetuning != G_FINETUNING)
-    obstack_fgrow1 (os, "\tfinetuning:\t%s\n",
-		    get_decision_str(graph->finetuning, G_FINETUNING));
+    fprintf (fout, "\tfinetuning:\t%s\n",
+	     get_decision_str(graph->finetuning));
   if (graph->ignore_singles != G_IGNORE_SINGLES)
-    obstack_fgrow1 (os, "\tignore_singles:\t%s\n",
-		    get_decision_str(graph->ignore_singles, G_IGNORE_SINGLES));
+    fprintf (fout, "\tignore_singles:\t%s\n",
+	     get_decision_str(graph->ignore_singles));
   if (graph->straight_phase != G_STRAIGHT_PHASE)
-    obstack_fgrow1 (os, "\tstraight_phase:\t%s\n",
-		    get_decision_str(graph->straight_phase, G_STRAIGHT_PHASE));
+    fprintf (fout, "\tstraight_phase:\t%s\n",
+	     get_decision_str(graph->straight_phase));
   if (graph->priority_phase != G_PRIORITY_PHASE)
-    obstack_fgrow1 (os, "\tpriority_phase:\t%s\n",
-		    get_decision_str(graph->priority_phase, G_PRIORITY_PHASE));
+    fprintf (fout, "\tpriority_phase:\t%s\n",
+	     get_decision_str(graph->priority_phase));
   if (graph->manhattan_edges != G_MANHATTAN_EDGES)
-    obstack_fgrow1 (os,
-		    "\tmanhattan_edges:\t%s\n",
-		    get_decision_str(graph->manhattan_edges,
-				     G_MANHATTAN_EDGES));
+    fprintf (fout,
+	     "\tmanhattan_edges:\t%s\n",
+	     get_decision_str(graph->manhattan_edges));
   if (graph->smanhattan_edges != G_SMANHATTAN_EDGES)
-    obstack_fgrow1 (os,
-		    "\tsmanhattan_edges:\t%s\n",
-		    get_decision_str(graph->smanhattan_edges,
-				     G_SMANHATTAN_EDGES));
+    fprintf (fout,
+	     "\tsmanhattan_edges:\t%s\n",
+	     get_decision_str(graph->smanhattan_edges));
   if (graph->near_edges != G_NEAR_EDGES)
-    obstack_fgrow1 (os, "\tnear_edges:\t%s\n",
-		    get_decision_str(graph->near_edges, G_NEAR_EDGES));
+    fprintf (fout, "\tnear_edges:\t%s\n",
+	     get_decision_str(graph->near_edges));
 
   if (graph->orientation != G_ORIENTATION)
-    obstack_fgrow1 (os, "\torientation:\t%s\n",
-		    get_decision_str(graph->orientation, G_ORIENTATION));
+    fprintf (fout, "\torientation:\t%s\n",
+	     get_orientation_str(graph->orientation));
 
   if (graph->node_alignement != G_NODE_ALIGNEMENT)
-    obstack_fgrow1 (os, "\tnode_alignement:\t%s\n",
-		    get_decision_str(graph->node_alignement,
-				     G_NODE_ALIGNEMENT));
+    fprintf (fout, "\tnode_alignement:\t%s\n",
+	     get_node_alignement_str(graph->node_alignement));
 
   if (graph->port_sharing != G_PORT_SHARING)
-    obstack_fgrow1 (os, "\tport_sharing:\t%s\n",
-		    get_decision_str(graph->port_sharing, G_PORT_SHARING));
+    fprintf (fout, "\tport_sharing:\t%s\n",
+	     get_decision_str(graph->port_sharing));
 
   if (graph->arrow_mode != G_ARROW_MODE)
-    obstack_fgrow1 (os, "\tarrow_mode:\t%s\n",
-		    get_arrow_mode_str(graph->arrow_mode));
+    fprintf (fout, "\tarrow_mode:\t%s\n",
+	     get_arrow_mode_str(graph->arrow_mode));
 
   if (graph->treefactor != G_TREEFACTOR)
-    obstack_fgrow1 (os, "\ttreefactor:\t%f\n", graph->treefactor);
+    fprintf (fout, "\ttreefactor:\t%f\n", graph->treefactor);
   if (graph->spreadlevel != G_SPREADLEVEL)
-    obstack_fgrow1 (os, "\tspreadlevel:\t%d\n", graph->spreadlevel);
+    fprintf (fout, "\tspreadlevel:\t%d\n", graph->spreadlevel);
 
   if (graph->crossing_weight != G_CROSSING_WEIGHT)
-    obstack_fgrow1 (os, "\tcrossing_weight:\t%s\n",
-		    get_crossing_type_str(graph->crossing_weight));
+    fprintf (fout, "\tcrossing_weight:\t%s\n",
+	     get_crossing_type_str(graph->crossing_weight));
   if (graph->crossing_phase2 != G_CROSSING_PHASE2)
-    obstack_fgrow1 (os, "\tcrossing_phase2:\t%s\n",
-		    get_decision_str(graph->crossing_phase2,
-				     G_CROSSING_PHASE2));
+    fprintf (fout, "\tcrossing_phase2:\t%s\n",
+	     get_decision_str(graph->crossing_phase2));
   if (graph->crossing_optimization != G_CROSSING_OPTIMIZATION)
-    obstack_fgrow1 (os, "\tcrossing_optimization:\t%s\n",
-		    get_decision_str(graph->crossing_optimization,
-				     G_CROSSING_OPTIMIZATION));
+    fprintf (fout, "\tcrossing_optimization:\t%s\n",
+	     get_decision_str(graph->crossing_optimization));
 
   if (graph->view != G_VIEW)
-    obstack_fgrow1 (os, "\tview:\t%s\n", get_view_str(graph->view));
+    fprintf (fout, "\tview:\t%s\n", get_view_str(graph->view));
 
   if (graph->edges != G_EDGES)
-    obstack_fgrow1 (os, "\tedges:\t%s\n", get_decision_str(graph->edges,
-							   G_EDGES));
+    fprintf (fout, "\tedges:\t%s\n", get_decision_str(graph->edges));
 
   if (graph->nodes != G_NODES)
-    obstack_fgrow1 (os,"\tnodes:\t%s\n",
-		    get_decision_str(graph->nodes, G_NODES));
+    fprintf (fout,"\tnodes:\t%s\n", get_decision_str(graph->nodes));
 
   if (graph->splines != G_SPLINES)
-    obstack_fgrow1 (os, "\tsplines:\t%s\n",
-		    get_decision_str(graph->splines, G_SPLINES));
+    fprintf (fout, "\tsplines:\t%s\n", get_decision_str(graph->splines));
 
   if (graph->bmax != G_BMAX)
-    obstack_fgrow1 (os, "\tbmax:\t%d\n", graph->bmax);
+    fprintf (fout, "\tbmax:\t%d\n", graph->bmax);
   if (graph->cmin != G_CMIN)
-    obstack_fgrow1 (os, "\tcmin:\t%d\n", graph->cmin);
+    fprintf (fout, "\tcmin:\t%d\n", graph->cmin);
   if (graph->cmax != G_CMAX)
-    obstack_fgrow1 (os, "\tcmax:\t%d\n", graph->cmax);
+    fprintf (fout, "\tcmax:\t%d\n", graph->cmax);
   if (graph->pmin != G_PMIN)
-    obstack_fgrow1 (os, "\tpmin:\t%d\n", graph->pmin);
+    fprintf (fout, "\tpmin:\t%d\n", graph->pmin);
   if (graph->pmax != G_PMAX)
-    obstack_fgrow1 (os, "\tpmax:\t%d\n", graph->pmax);
+    fprintf (fout, "\tpmax:\t%d\n", graph->pmax);
   if (graph->rmin != G_RMIN)
-    obstack_fgrow1 (os, "\trmin:\t%d\n", graph->rmin);
+    fprintf (fout, "\trmin:\t%d\n", graph->rmin);
   if (graph->rmax != G_RMAX)
-    obstack_fgrow1 (os, "\trmax:\t%d\n", graph->rmax);
+    fprintf (fout, "\trmax:\t%d\n", graph->rmax);
   if (graph->smax != G_SMAX)
-    obstack_fgrow1 (os, "\tsmax:\t%d\n", graph->smax);
+    fprintf (fout, "\tsmax:\t%d\n", graph->smax);
 }
