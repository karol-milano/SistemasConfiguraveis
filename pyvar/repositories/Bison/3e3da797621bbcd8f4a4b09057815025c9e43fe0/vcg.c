@@ -22,6 +22,7 @@
 #include "vcg.h"
 #include "vcg_defaults.h"
 #include "xalloc.h"
+#include "complain.h"
 
 /* Initialize a graph with the default values. */
 void
@@ -29,15 +30,15 @@ new_graph (graph_t *g)
 {
   g->title = G_TITLE;
   g->label = G_LABEL;
-  
+
   g->infos[0] = G_INFOS1;
   g->infos[1] = G_INFOS2;
   g->infos[2] = G_INFOS3;
-  
+
   g->color = G_COLOR;
   g->textcolor = G_TEXTCOLOR;
   g->bordercolor = G_BORDERCOLOR;
-  
+
   g->width = G_WIDTH;
   g->height = G_HEIGHT;
   g->borderwidth = G_BORDERWIDTH;
@@ -49,17 +50,17 @@ new_graph (graph_t *g)
 
   g->textmode = G_TEXTMODE;
   g->shape = G_SHAPE;
-  
+
   g->xmax = G_XMAX; /* Not output. */
   g->ymax = G_YMAX; /* Not output. */
-  
+
   g->xbase = G_XBASE;
   g->ybase = G_YBASE;
 
   g->xspace = G_XSPACE;
   g->yspace = G_YSPACE;
   g->xlspace = G_XLSPACE; /* Not output. */
-  
+
   g->xraster = G_XRASTER;
   g->yraster = G_YRASTER;
   g->xlraster = G_XLRASTER;
@@ -67,13 +68,13 @@ new_graph (graph_t *g)
   g->hidden = G_HIDDEN; /* No default value. */
 
   g->classname = G_CLASSNAME; /* No class name association. */
-  
+
   g->layoutalgorithm = G_LAYOUTALGORITHM;
   g->layout_downfactor = G_LAYOUT_DOWNFACTOR;
   g->layout_upfactor = G_LAYOUT_UPFACTOR;
   g->layout_nearfactor = G_LAYOUT_NEARFACTOR;
   g->layout_splinefactor = G_LAYOUT_SPLINEFACTOR;
-  
+
   g->late_edge_labels = G_LATE_EDGE_LABELS;
   g->display_edge_labels = G_DISPLAY_EDGE_LABELS;
   g->dirty_edge_labels = G_DIRTY_EDGE_LABELS;
@@ -84,7 +85,7 @@ new_graph (graph_t *g)
   g->manhattan_edges = G_MANHATTAN_EDGES;
   g->smanhattan_edges = G_SMANHATTAN_EDGES;
   g->near_edges = G_NEAR_EDGES;
-  
+
   g->orientation = G_ORIENTATION;
   g->node_alignement = G_NODE_ALIGNEMENT;
   g->port_sharing = G_PORT_SHARING;
@@ -108,10 +109,10 @@ new_graph (graph_t *g)
   g->rmin = G_RMIN;
   g->rmax = G_RMAX;
   g->smax = G_SMAX;
-  
+
   g->node_list = G_NODE_LIST;
   g->edge_list = G_EDGE_LIST;
-  
+
   new_edge(&g->edge);
   new_node(&g->node);
 }
@@ -122,33 +123,33 @@ new_node (node_t *node)
 {
   node->title = N_TITLE;
   node->label = N_LABEL;
-  
+
   node->locx = N_LOCX; /* Default unspcified. */
   node->locy = N_LOCY; /* Default unspcified. */
-  
+
   node->vertical_order = N_VERTICAL_ORDER;	/* Default unspcified. */
   node->horizontal_order = N_HORIZONTAL_ORDER;	/* Default unspcified. */
-  
+
   node->width = N_WIDTH; /* We assume that we can't define it now. */
   node->height = N_HEIGHT; /* Also. */
-  
+
   node->shrink = N_SHRINK;
   node->stretch = N_STRETCH;
-  
+
   node->folding = N_FOLDING; /* No explicit default value. */
-  
+
   node->shape = N_SHAPE;
   node->textmode = N_TEXTMODE;
   node->borderwidth = N_BORDERWIDTH;
-  
+
   node->color = N_COLOR;
   node->textcolor = N_TEXTCOLOR;
   node->bordercolor = N_BORDERCOLOR;
-  
+
   node->infos[0] = N_INFOS1;
   node->infos[1] = N_INFOS2;
   node->infos[2] = N_INFOS3;
-  
+
   node->next = N_NEXT;
 }
 
@@ -197,41 +198,41 @@ get_color_str (enum color_e c)
 {
   switch (c)
     {
-    case white:		return ("white");
-    case blue:		return ("blue");
-    case red:		return ("red");
-    case green:		return ("green");
-    case yellow:	return ("yellow");
-    case magenta:	return ("magenta");
-    case cyan:		return ("cyan");
-    case darkgrey:	return ("darkgrey");
-    case darkblue:	return ("darkblue");
-    case darkred:	return ("darkred");
-    case darkgreen:	return ("darkgreen");
-    case darkyellow:	return ("darkyellow");
-    case darkmagenta:	return ("darkmagenta");
-    case darkcyan:	return ("darkcyan");
-    case gold:		return ("gold");
-    case lightgrey:	return ("lightgrey");
-    case lightblue:	return ("lightblue");
-    case lightred:	return ("lightred");
-    case lightgreen:	return ("lightgreen");
-    case lightyellow:	return ("lightyellow");
-    case lightmagenta:	return ("lightmagenta");
-    case lightcyan:	return ("lightcyan");
-    case lilac:		return ("lilac");
-    case turquoise:	return ("turquoise");
-    case aquamarine:	return ("aquamarine");
-    case khaki:		return ("khaki");
-    case purple:	return ("purple");
-    case yellowgreen:	return ("yellowgreen");
-    case pink:		return ("pink");
-    case orange:	return ("orange");
-    case orchid:	return ("orchid");
-    case black:		return ("black");
+    case white:		return "white";
+    case blue:		return "blue";
+    case red:		return "red";
+    case green:		return "green";
+    case yellow:	return "yellow";
+    case magenta:	return "magenta";
+    case cyan:		return "cyan";
+    case darkgrey:	return "darkgrey";
+    case darkblue:	return "darkblue";
+    case darkred:	return "darkred";
+    case darkgreen:	return "darkgreen";
+    case darkyellow:	return "darkyellow";
+    case darkmagenta:	return "darkmagenta";
+    case darkcyan:	return "darkcyan";
+    case gold:		return "gold";
+    case lightgrey:	return "lightgrey";
+    case lightblue:	return "lightblue";
+    case lightred:	return "lightred";
+    case lightgreen:	return "lightgreen";
+    case lightyellow:	return "lightyellow";
+    case lightmagenta:	return "lightmagenta";
+    case lightcyan:	return "lightcyan";
+    case lilac:		return "lilac";
+    case turquoise:	return "turquoise";
+    case aquamarine:	return "aquamarine";
+    case khaki:		return "khaki";
+    case purple:	return "purple";
+    case yellowgreen:	return "yellowgreen";
+    case pink:		return "pink";
+    case orange:	return "orange";
+    case orchid:	return "orchid";
+    case black:		return "black";
     default:
       complain (_("vcg graph: no such a color."));
-      return (get_color_str(G_COLOR));
+      return get_color_str(G_COLOR);
     }
   return NULL;
 }
@@ -241,12 +242,12 @@ get_textmode_str (enum textmode_e t)
 {
   switch (t)
     {
-    case centered:	return ("center");
-    case left_justify:	return ("left_justify");
-    case right_justify:	return ("right_justify");
+    case centered:	return "center";
+    case left_justify:	return "left_justify";
+    case right_justify:	return "right_justify";
     default:
       complain (_("vcg graph: no such a text mode.."));
-      return (get_textmode_str(G_TEXTMODE));
+      return get_textmode_str(G_TEXTMODE);
     }
   return NULL;
 }
@@ -256,13 +257,13 @@ get_shape_str (enum shape_e s)
 {
   switch (s)
     {
-    case box:		return ("box");
-    case rhomb:		return ("rhomb");
-    case ellipse:	return ("ellipse");
-    case triangle:	return ("triangle");
+    case box:		return "box";
+    case rhomb:		return "rhomb";
+    case ellipse:	return "ellipse";
+    case triangle:	return "triangle";
     default:
       complain (_("vcg graph: no such a shape.."));
-      return (get_shape_str(G_SHAPE));
+      return get_shape_str(G_SHAPE);
     }
   return NULL;
 }
@@ -272,22 +273,22 @@ get_layoutalgorithm_str (enum layoutalgorithm_e l)
 {
   switch (l)
     {
-    case normal:       	return ("normal"); 
-    case maxdepth:	return ("maxdepth");
-    case mindepth:	return ("mindepth");
-    case maxdepthslow:	return ("maxdepthslow");
-    case mindepthslow:	return ("mindepthslow");
-    case maxdegree:	return ("maxdegree");
-    case mindegree:	return ("mindegree");
-    case maxindegree:	return ("maxindegree");
-    case minindegree:	return ("minindegree");
-    case maxoutdegree:	return ("maxoutdegree");
-    case minoutdegree:	return ("minoutdegree");
-    case minbackward:	return ("minbackward");
-    case dfs:		return ("dfs");
-    case tree:		return ("tree");
-    default:		
-      return ("normal");
+    case normal:       	return "normal";
+    case maxdepth:	return "maxdepth";
+    case mindepth:	return "mindepth";
+    case maxdepthslow:	return "maxdepthslow";
+    case mindepthslow:	return "mindepthslow";
+    case maxdegree:	return "maxdegree";
+    case mindegree:	return "mindegree";
+    case maxindegree:	return "maxindegree";
+    case minindegree:	return "minindegree";
+    case maxoutdegree:	return "maxoutdegree";
+    case minoutdegree:	return "minoutdegree";
+    case minbackward:	return "minbackward";
+    case dfs:		return "dfs";
+    case tree:		return "tree";
+    default:
+      return "normal";
     }
   return NULL;
 }
@@ -297,11 +298,11 @@ get_decision_str (enum decision_e d, enum decision_e defaults)
 {
   switch (d)
     {
-    case no:	return ("no");
-    case yes:	return ("yes");
+    case no:	return "no";
+    case yes:	return "yes";
     default:
       complain (_("vcg graph: no such a decision.."));
-      return (get_decision_str(defaults, 0));
+      return get_decision_str(defaults, 0);
     }
   return NULL;
 }
@@ -311,13 +312,13 @@ get_orientation_str (enum orientation_e o)
 {
   switch (o)
     {
-    case top_to_bottom:	return ("top_to_bottom");
-    case bottom_to_top: return ("bottom_to_top");
-    case left_to_right: return ("left_to_right");
-    case right_to_left: return ("right_to_left");
+    case top_to_bottom:	return "top_to_bottom";
+    case bottom_to_top: return "bottom_to_top";
+    case left_to_right: return "left_to_right";
+    case right_to_left: return "right_to_left";
     default:
       complain (_("vcg graph: no such an orientation.."));
-      return (get_orientation_str(G_ORIENTATION));
+      return get_orientation_str(G_ORIENTATION);
     }
   return NULL;
 }
@@ -327,12 +328,12 @@ get_node_alignement_str (enum alignement_e a)
 {
   switch (a)
     {
-    case center:	return ("center");
-    case top:		return ("top");
-    case bottom:	return ("bottom");
+    case center:	return "center";
+    case top:		return "top";
+    case bottom:	return "bottom";
     default:
       complain (_("vcg graph: no such an alignement.."));
-      return (get_node_alignement_str(G_NODE_ALIGNEMENT));
+      return get_node_alignement_str(G_NODE_ALIGNEMENT);
     }
   return NULL;
 }
@@ -342,11 +343,11 @@ get_arrow_mode_str (enum arrow_mode_e a)
 {
   switch (a)
     {
-    case fixed:		return ("fixed");
-    case free_a:	return ("free");
+    case fixed:		return "fixed";
+    case free_a:	return "free";
     default:
       complain (_("vcg graph: no such an arrow mode.."));
-      return (get_arrow_mode_str(G_ARROW_MODE));
+      return get_arrow_mode_str(G_ARROW_MODE);
     }
   return NULL;
 }
@@ -356,14 +357,14 @@ get_crossing_type_str (enum crossing_type_e c)
 {
   switch (c)
     {
-    case bary:		return ("bary");
-    case median:	return ("median");
-    case barymedian:	return ("barymedian");
-    case medianbary:	return ("medianbary");
+    case bary:		return "bary";
+    case median:	return "median";
+    case barymedian:	return "barymedian";
+    case medianbary:	return "medianbary";
     default:
       complain (_("vcg graph: no such a crossing_type.."));
-      return (get_crossing_type_str(G_CROSSING_WEIGHT));  
-    }  
+      return get_crossing_type_str(G_CROSSING_WEIGHT);
+    }
   return NULL;
 }
 
@@ -372,14 +373,14 @@ get_view_str (enum view_e v)
 {
   switch (v)
     {
-    case normal_view:	return ("normal_view");
-    case cfish:		return ("cfish");
-    case pfish:		return ("pfish");
-    case fcfish:	return ("fcfish");
-    case fpfish:	return ("fpfish");
+    case normal_view:	return "normal_view";
+    case cfish:		return "cfish";
+    case pfish:		return "pfish";
+    case fcfish:	return "fcfish";
+    case fpfish:	return "fpfish";
     default:
       complain (_("vcg graph: no such a view.."));
-      return (get_view_str(G_VIEW));  
+      return get_view_str(G_VIEW);
     }
   return NULL;
 }
@@ -389,14 +390,14 @@ get_linestyle_str (enum linestyle_e l)
 {
   switch (l)
     {
-    case continuous:	return ("continuous");
-    case dashed:	return ("dashed");
-    case dotted:	return ("dotted");
-    case invisible:	return ("invisible");
+    case continuous:	return "continuous";
+    case dashed:	return "dashed";
+    case dotted:	return "dotted";
+    case invisible:	return "invisible";
     default:
       complain (_("vcg graph: no such a linestyle.."));
-      return (get_linestyle_str(E_LINESTYLE));  
-    } 
+      return get_linestyle_str(E_LINESTYLE);
+    }
   return NULL;
 }
 
@@ -405,12 +406,12 @@ get_arrowstyle_str (enum arrowstyle_e a)
 {
   switch (a)
     {
-    case solid:	return ("solid");
-    case line:	return ("line");
-    case none:	return ("none");
+    case solid:	return "solid";
+    case line:	return "line";
+    case none:	return "none";
     default:
       complain (_("vcg graph: no such an arrowstyle.."));
-      return (get_arrowstyle_str(E_ARROWSTYLE));  
+      return get_arrowstyle_str(E_ARROWSTYLE);
     }
   return NULL;
 }
@@ -454,16 +455,16 @@ open_edge(edge_t *edge, struct obstack *os)
       break;
     case bent_near_edge:
       obstack_sgrow (os, "\tbentnearedge: {\n");
-      break;  
+      break;
     default:
       obstack_sgrow (os, "\tedge: {\n");
-    }  
+    }
 }
 
 void
 close_edge(struct obstack *os)
 {
-  obstack_sgrow (os, "\t}\n");    
+  obstack_sgrow (os, "\t}\n");
 }
 
 void
@@ -474,7 +475,7 @@ open_node(struct obstack *os)
 
 void
 close_node(struct obstack *os)
-{  
+{
   obstack_sgrow (os, "\t}\n");
 }
 
@@ -491,7 +492,7 @@ close_graph(graph_t *graph, struct obstack *os)
 
   {
     node_t *node;
-    
+
     for (node = graph->node_list; node; node = node->next)
       {
 	open_node (os);
@@ -499,23 +500,23 @@ close_graph(graph_t *graph, struct obstack *os)
 	close_node (os);
       }
   }
-  
+
   obstack_1grow (os, '\n');
-  
+
   {
     edge_t *edge;
-    
+
     for (edge = graph->edge_list; edge; edge = edge->next)
-      {      
+      {
 	open_edge (edge, os);
 	output_edge (edge, os);
 	close_edge (os);
       }
   }
-  
+
   obstack_sgrow (os, "}\n");
-}    
-  
+}
+
 /*-------------------------------------------.
 | Output functions (formatted) in obstack os |
 `-------------------------------------------*/
@@ -530,44 +531,44 @@ output_node (node_t *node, struct obstack *os)
 
   if ((node->locx != N_LOCX) && (node->locy != N_LOCY))
     obstack_fgrow2 (os, "\t\tloc { x: %d  y: %d }\t\n", node->locx, node->locy);
-  
+
   if (node->vertical_order != N_VERTICAL_ORDER)
     obstack_fgrow1 (os, "\t\tvertical_order:\t%d\n", node->vertical_order);
   if (node->horizontal_order != N_HORIZONTAL_ORDER)
     obstack_fgrow1 (os, "\t\thorizontal_order:\t%d\n", node->horizontal_order);
-  
+
   if (node->width != N_WIDTH)
     obstack_fgrow1 (os, "\t\twidth:\t%d\n", node->width);
   if (node->height != N_HEIGHT)
     obstack_fgrow1 (os, "\t\theight:\t%d\n", node->height);
-  
+
   if (node->shrink != N_SHRINK)
     obstack_fgrow1 (os, "\t\tshrink:\t%d\n", node->shrink);
   if (node->stretch != N_STRETCH)
     obstack_fgrow1 (os, "\t\tshrink:\t%d\n", node->shrink);
-  
+
   if (node->folding != N_FOLDING)
-    obstack_fgrow1 (os, "\t\tfolding:\t%d\n", node->folding);  
-  
+    obstack_fgrow1 (os, "\t\tfolding:\t%d\n", node->folding);
+
   if (node->textmode != N_TEXTMODE)
-    obstack_fgrow1 (os, "\t\ttextmode:\t%s\n", 
+    obstack_fgrow1 (os, "\t\ttextmode:\t%s\n",
 		    get_textmode_str (node->textmode));
-  
+
   if (node->shape != N_SHAPE)
     obstack_fgrow1 (os, "\t\tshape:\t%s\n", get_shape_str (node->shape));
-  
+
   if (node->borderwidth != N_BORDERWIDTH)
     obstack_fgrow1 (os, "\t\tborderwidth:\t%d\n", node->borderwidth);
-  
+
   if (node->color != N_COLOR)
     obstack_fgrow1 (os, "\t\tcolor:\t%s\n", get_color_str (node->color));
   if (node->textcolor != N_TEXTCOLOR)
-    obstack_fgrow1 (os, "\t\ttextcolor:\t%s\n", 
+    obstack_fgrow1 (os, "\t\ttextcolor:\t%s\n",
 		    get_color_str (node->textcolor));
   if (node->bordercolor != N_BORDERCOLOR)
-    obstack_fgrow1 (os, "\t\tbordercolor:\t%s\n", 
+    obstack_fgrow1 (os, "\t\tbordercolor:\t%s\n",
 		    get_color_str (node->bordercolor));
-  
+
   if (node->infos[0])
     obstack_fgrow1 (os, "\t\tinfo1:\t\"%s\"\n", node->infos[0]);
   if (node->infos[1])
@@ -584,14 +585,14 @@ output_edge (edge_t *edge, struct obstack *os)
     obstack_fgrow1 (os, "\t\tsourcename:\t\"%s\"\n", edge->sourcename);
   if (edge->targetname != E_TARGETNAME)
     obstack_fgrow1 (os, "\t\ttargetname:\t\"%s\"\n", edge->targetname);
-  
+
   if (edge->label != E_LABEL)
     obstack_fgrow1 (os, "\t\tlabel:\t\"%s\"\n", edge->label);
 
   if (edge->linestyle != E_LINESTYLE)
-    obstack_fgrow1 (os, "\t\tlinestyle:\t\"%s\"\n", 
+    obstack_fgrow1 (os, "\t\tlinestyle:\t\"%s\"\n",
 		    get_linestyle_str(edge->linestyle));
-  
+
   if (edge->thickness != E_THICKNESS)
     obstack_fgrow1 (os, "\t\tthickness:\t%d\n", edge->thickness);
   if (edge->class != E_CLASS)
@@ -600,27 +601,27 @@ output_edge (edge_t *edge, struct obstack *os)
   if (edge->color != E_COLOR)
     obstack_fgrow1 (os, "\t\tcolor:\t%s\n", get_color_str (edge->color));
   if (edge->color != E_TEXTCOLOR)
-    obstack_fgrow1 (os, "\t\ttextcolor:\t%s\n", 
+    obstack_fgrow1 (os, "\t\ttextcolor:\t%s\n",
 		    get_color_str (edge->textcolor));
   if (edge->arrowcolor != E_ARROWCOLOR)
-    obstack_fgrow1 (os, "\t\tarrowcolor:\t%s\n", 
+    obstack_fgrow1 (os, "\t\tarrowcolor:\t%s\n",
 		    get_color_str (edge->arrowcolor));
   if (edge->backarrowcolor != E_BACKARROWCOLOR)
-    obstack_fgrow1 (os, "\t\tbackarrowcolor:\t%s\n", 
+    obstack_fgrow1 (os, "\t\tbackarrowcolor:\t%s\n",
 		    get_color_str (edge->backarrowcolor));
 
   if (edge->arrowsize != E_ARROWSIZE)
     obstack_fgrow1 (os, "\t\tarrowsize:\t%d\n", edge->arrowsize);
   if (edge->backarrowsize != E_BACKARROWSIZE)
     obstack_fgrow1 (os, "\t\tbackarrowsize:\t%d\n", edge->backarrowsize);
-  
+
   if (edge->arrowstyle != E_ARROWSTYLE)
-    obstack_fgrow1 (os, "\t\tarrowstyle:\t%s\n", 
+    obstack_fgrow1 (os, "\t\tarrowstyle:\t%s\n",
 		    get_arrowstyle_str(edge->arrowstyle));
   if (edge->backarrowstyle != E_BACKARROWSTYLE)
-    obstack_fgrow1 (os, "\t\tbackarrowstyle:\t%s\n", 
+    obstack_fgrow1 (os, "\t\tbackarrowstyle:\t%s\n",
 		    get_arrowstyle_str(edge->backarrowstyle));
-  
+
   if (edge->priority != E_PRIORITY)
     obstack_fgrow1 (os, "\t\tpriority:\t%d\n", edge->priority);
   if (edge->anchor != E_ANCHOR)
@@ -636,29 +637,29 @@ output_graph (graph_t *graph, struct obstack *os)
     obstack_fgrow1 (os, "\ttitle:\t\"%s\"\n", graph->title);
   if (graph->label)
     obstack_fgrow1 (os, "\tlabel:\t\"%s\"\n", graph->label);
-  
+
   if (graph->infos[0])
     obstack_fgrow1 (os, "\tinfo1:\t\"%s\"\n", graph->infos[0]);
   if (graph->infos[1])
     obstack_fgrow1 (os, "\tinfo2:\t\"%s\"\n", graph->infos[1]);
   if (graph->infos[2])
     obstack_fgrow1 (os, "\tinfo3:\t\"%s\"\n", graph->infos[2]);
-  
+
   if (graph->color != G_COLOR)
     obstack_fgrow1 (os, "\tcolor:\t%s\n", get_color_str (graph->color));
   if (graph->textcolor != G_TEXTCOLOR)
     obstack_fgrow1 (os, "\ttextcolor:\t%s\n", get_color_str (graph->textcolor));
   if (graph->bordercolor != G_BORDERCOLOR)
-    obstack_fgrow1 (os, "\tbordercolor:\t%s\n", 
+    obstack_fgrow1 (os, "\tbordercolor:\t%s\n",
 		    get_color_str (graph->bordercolor));
-    
+
   if (graph->width != G_WIDTH)
     obstack_fgrow1 (os, "\twidth:\t%d\n", graph->width);
   if (graph->height != G_HEIGHT)
     obstack_fgrow1 (os, "\theight:\t%d\n", graph->height);
   if (graph->borderwidth != G_BORDERWIDTH)
     obstack_fgrow1 (os, "\tborderwidth:\t%d\n", graph->borderwidth);
-  
+
   if (graph->x != G_X)
     obstack_fgrow1 (os, "\tx:\t%d\n", graph->x);
   if (graph->y != G_Y)
@@ -671,19 +672,19 @@ output_graph (graph_t *graph, struct obstack *os)
     obstack_fgrow1 (os, "\tshrink:\t%d\n", graph->shrink);
   if (graph->stretch != G_STRETCH)
     obstack_fgrow1 (os, "\tstretch:\t%d\n", graph->stretch);
- 
+
   if (graph->textmode != G_TEXTMODE)
-    obstack_fgrow1 (os, "\ttextmode:\t%s\n", 
+    obstack_fgrow1 (os, "\ttextmode:\t%s\n",
 		    get_textmode_str (graph->textmode));
- 
+
   if (graph->shape != G_SHAPE)
     obstack_fgrow1 (os, "\tshape:\t%s\n", get_shape_str (graph->shape));
-  
+
   if (graph->xmax != G_XMAX)
     obstack_fgrow1 (os, "\txmax:\t%d\n", graph->xmax);
   if (graph->ymax != G_YMAX)
     obstack_fgrow1 (os, "\tymax:\t%d\n", graph->ymax);
-  
+
   if (graph->xbase != G_XBASE)
     obstack_fgrow1 (os, "\txbase:\t%d\n", graph->xbase);
   if (graph->ybase != G_YBASE)
@@ -695,7 +696,7 @@ output_graph (graph_t *graph, struct obstack *os)
     obstack_fgrow1 (os, "\tyspace:\t%d\n", graph->yspace);
   if (graph->xlspace != G_XLSPACE)
     obstack_fgrow1 (os, "\txlspace:\t%d\n", graph->xlspace);
-  
+
   if (graph->xraster != G_XRASTER)
     obstack_fgrow1 (os, "\txraster:\t%d\n", graph->xraster);
   if (graph->yraster != G_YRASTER)
@@ -705,182 +706,130 @@ output_graph (graph_t *graph, struct obstack *os)
 
   if (graph->hidden != G_HIDDEN)
     obstack_fgrow1 (os, "\thidden:\t%d\n", graph->hidden);
-  
+
   if (graph->classname != G_CLASSNAME)
     {
       struct classname_s *ite;
-      
+
       for (ite = graph->classname; ite; ite = ite->next)
 	obstack_fgrow2 (os, "\tclassname %d :\t%s\n", ite->no, ite->name);
     }
-  
+
   if (graph->layoutalgorithm != G_LAYOUTALGORITHM)
-    obstack_fgrow1 (os, "\tlayoutalgorithm:\t%s\n", 
+    obstack_fgrow1 (os, "\tlayoutalgorithm:\t%s\n",
 		    get_layoutalgorithm_str(graph->layoutalgorithm));
-  
+
   if (graph->layout_downfactor != G_LAYOUT_DOWNFACTOR)
     obstack_fgrow1 (os, "\tlayout_downfactor:\t%d\n", graph->layout_downfactor);
   if (graph->layout_upfactor != G_LAYOUT_UPFACTOR)
-    obstack_fgrow1 (os, "\tlayout_upfactor:\t%d\n", graph->layout_upfactor);  
+    obstack_fgrow1 (os, "\tlayout_upfactor:\t%d\n", graph->layout_upfactor);
   if (graph->layout_nearfactor != G_LAYOUT_NEARFACTOR)
     obstack_fgrow1 (os, "\tlayout_nearfactor:\t%d\n", graph->layout_nearfactor);
   if (graph->layout_splinefactor != G_LAYOUT_SPLINEFACTOR)
-    obstack_fgrow1 (os, "\tlayout_splinefactor:\t%d\n", 
+    obstack_fgrow1 (os, "\tlayout_splinefactor:\t%d\n",
 		    graph->layout_splinefactor);
-  
+
   if (graph->late_edge_labels != G_LATE_EDGE_LABELS)
-    obstack_fgrow1 (os, "\tlate_edge_labels:\t%s\n", 
-		    get_decision_str(graph->late_edge_labels, 
+    obstack_fgrow1 (os, "\tlate_edge_labels:\t%s\n",
+		    get_decision_str(graph->late_edge_labels,
 				     G_LATE_EDGE_LABELS));
   if (graph->display_edge_labels != G_DISPLAY_EDGE_LABELS)
-    obstack_fgrow1 (os, "\tdisplay_edge_labels:\t%s\n", 
-		    get_decision_str(graph->display_edge_labels, 
+    obstack_fgrow1 (os, "\tdisplay_edge_labels:\t%s\n",
+		    get_decision_str(graph->display_edge_labels,
 				     G_DISPLAY_EDGE_LABELS));
   if (graph->dirty_edge_labels != G_DIRTY_EDGE_LABELS)
-    obstack_fgrow1 (os, "\tdirty_edge_labels:\t%s\n", 
-		    get_decision_str(graph->dirty_edge_labels, 
+    obstack_fgrow1 (os, "\tdirty_edge_labels:\t%s\n",
+		    get_decision_str(graph->dirty_edge_labels,
 				     G_DIRTY_EDGE_LABELS));
   if (graph->finetuning != G_FINETUNING)
-    obstack_fgrow1 (os, "\tfinetuning:\t%s\n", 
+    obstack_fgrow1 (os, "\tfinetuning:\t%s\n",
 		    get_decision_str(graph->finetuning, G_FINETUNING));
   if (graph->ignore_singles != G_IGNORE_SINGLES)
-    obstack_fgrow1 (os, "\tignore_singles:\t%s\n", 
+    obstack_fgrow1 (os, "\tignore_singles:\t%s\n",
 		    get_decision_str(graph->ignore_singles, G_IGNORE_SINGLES));
   if (graph->straight_phase != G_STRAIGHT_PHASE)
-    obstack_fgrow1 (os, "\tstraight_phase:\t%s\n", 
+    obstack_fgrow1 (os, "\tstraight_phase:\t%s\n",
 		    get_decision_str(graph->straight_phase, G_STRAIGHT_PHASE));
   if (graph->priority_phase != G_PRIORITY_PHASE)
-    obstack_fgrow1 (os, "\tpriority_phase:\t%s\n", 
+    obstack_fgrow1 (os, "\tpriority_phase:\t%s\n",
 		    get_decision_str(graph->priority_phase, G_PRIORITY_PHASE));
   if (graph->manhattan_edges != G_MANHATTAN_EDGES)
-    obstack_fgrow1 (os, 
-		    "\tmanhattan_edges:\t%s\n", 
-		    get_decision_str(graph->manhattan_edges, 
+    obstack_fgrow1 (os,
+		    "\tmanhattan_edges:\t%s\n",
+		    get_decision_str(graph->manhattan_edges,
 				     G_MANHATTAN_EDGES));
   if (graph->smanhattan_edges != G_SMANHATTAN_EDGES)
-    obstack_fgrow1 (os, 
-		    "\tsmanhattan_edges:\t%s\n", 
-		    get_decision_str(graph->smanhattan_edges, 
+    obstack_fgrow1 (os,
+		    "\tsmanhattan_edges:\t%s\n",
+		    get_decision_str(graph->smanhattan_edges,
 				     G_SMANHATTAN_EDGES));
   if (graph->near_edges != G_NEAR_EDGES)
-    obstack_fgrow1 (os, "\tnear_edges:\t%s\n", 
+    obstack_fgrow1 (os, "\tnear_edges:\t%s\n",
 		    get_decision_str(graph->near_edges, G_NEAR_EDGES));
-  
+
   if (graph->orientation != G_ORIENTATION)
-    obstack_fgrow1 (os, "\torientation:\t%s\n", 
+    obstack_fgrow1 (os, "\torientation:\t%s\n",
 		    get_decision_str(graph->orientation, G_ORIENTATION));
-  
+
   if (graph->node_alignement != G_NODE_ALIGNEMENT)
-    obstack_fgrow1 (os, "\tnode_alignement:\t%s\n", 
-		    get_decision_str(graph->node_alignement, 
+    obstack_fgrow1 (os, "\tnode_alignement:\t%s\n",
+		    get_decision_str(graph->node_alignement,
 				     G_NODE_ALIGNEMENT));
-  
+
   if (graph->port_sharing != G_PORT_SHARING)
-    obstack_fgrow1 (os, "\tport_sharing:\t%s\n", 
+    obstack_fgrow1 (os, "\tport_sharing:\t%s\n",
 		    get_decision_str(graph->port_sharing, G_PORT_SHARING));
-  
+
   if (graph->arrow_mode != G_ARROW_MODE)
-    obstack_fgrow1 (os, "\tarrow_mode:\t%s\n", 
+    obstack_fgrow1 (os, "\tarrow_mode:\t%s\n",
 		    get_arrow_mode_str(graph->arrow_mode));
-  
+
   if (graph->treefactor != G_TREEFACTOR)
     obstack_fgrow1 (os, "\ttreefactor:\t%f\n", graph->treefactor);
   if (graph->spreadlevel != G_SPREADLEVEL)
     obstack_fgrow1 (os, "\tspreadlevel:\t%d\n", graph->spreadlevel);
-  
+
   if (graph->crossing_weight != G_CROSSING_WEIGHT)
-    obstack_fgrow1 (os, "\tcrossing_weight:\t%s\n", 
+    obstack_fgrow1 (os, "\tcrossing_weight:\t%s\n",
 		    get_crossing_type_str(graph->crossing_weight));
   if (graph->crossing_phase2 != G_CROSSING_PHASE2)
-    obstack_fgrow1 (os, "\tcrossing_phase2:\t%s\n", 
-		    get_decision_str(graph->crossing_phase2, 
+    obstack_fgrow1 (os, "\tcrossing_phase2:\t%s\n",
+		    get_decision_str(graph->crossing_phase2,
 				     G_CROSSING_PHASE2));
   if (graph->crossing_optimization != G_CROSSING_OPTIMIZATION)
-    obstack_fgrow1 (os, "\tcrossing_optimization:\t%s\n", 
-		    get_decision_str(graph->crossing_optimization, 
+    obstack_fgrow1 (os, "\tcrossing_optimization:\t%s\n",
+		    get_decision_str(graph->crossing_optimization,
 				     G_CROSSING_OPTIMIZATION));
-  
+
   if (graph->view != G_VIEW)
     obstack_fgrow1 (os, "\tview:\t%s\n", get_view_str(graph->view));
-  
+
   if (graph->edges != G_EDGES)
-    obstack_fgrow1 (os, "\tedges:\t%s\n", get_decision_str(graph->edges, 
-							   G_EDGES));  
-  
+    obstack_fgrow1 (os, "\tedges:\t%s\n", get_decision_str(graph->edges,
+							   G_EDGES));
+
   if (graph->nodes != G_NODES)
-    obstack_fgrow1 (os,"\tnodes:\t%s\n", 
-		    get_decision_str(graph->nodes, G_NODES));  
-  
+    obstack_fgrow1 (os,"\tnodes:\t%s\n",
+		    get_decision_str(graph->nodes, G_NODES));
+
   if (graph->splines != G_SPLINES)
-    obstack_fgrow1 (os, "\tsplines:\t%s\n", 
+    obstack_fgrow1 (os, "\tsplines:\t%s\n",
 		    get_decision_str(graph->splines, G_SPLINES));
-  
+
   if (graph->bmax != G_BMAX)
-    obstack_fgrow1 (os, "\tbmax:\t%d\n", graph->bmax);    
+    obstack_fgrow1 (os, "\tbmax:\t%d\n", graph->bmax);
   if (graph->cmin != G_CMIN)
-    obstack_fgrow1 (os, "\tcmin:\t%d\n", graph->cmin);    
+    obstack_fgrow1 (os, "\tcmin:\t%d\n", graph->cmin);
   if (graph->cmax != G_CMAX)
-    obstack_fgrow1 (os, "\tcmax:\t%d\n", graph->cmax);    
+    obstack_fgrow1 (os, "\tcmax:\t%d\n", graph->cmax);
   if (graph->pmin != G_PMIN)
-    obstack_fgrow1 (os, "\tpmin:\t%d\n", graph->pmin);    
+    obstack_fgrow1 (os, "\tpmin:\t%d\n", graph->pmin);
   if (graph->pmax != G_PMAX)
-    obstack_fgrow1 (os, "\tpmax:\t%d\n", graph->pmax);    
+    obstack_fgrow1 (os, "\tpmax:\t%d\n", graph->pmax);
   if (graph->rmin != G_RMIN)
-    obstack_fgrow1 (os, "\trmin:\t%d\n", graph->rmin);    
+    obstack_fgrow1 (os, "\trmin:\t%d\n", graph->rmin);
   if (graph->rmax != G_RMAX)
-    obstack_fgrow1 (os, "\trmax:\t%d\n", graph->rmax);    
+    obstack_fgrow1 (os, "\trmax:\t%d\n", graph->rmax);
   if (graph->smax != G_SMAX)
-    obstack_fgrow1 (os, "\tsmax:\t%d\n", graph->smax);    
+    obstack_fgrow1 (os, "\tsmax:\t%d\n", graph->smax);
 }
-
-#ifdef NDEBUG
-
-int main ()
-{
-  graph_t graph;
-  node_t *node;
-  edge_t *edge;
-  struct obstack graph_obstack;
-  
-  obstack_init (&graph_obstack);
-
-  new_graph(&graph);
-    
-  graph.title = "graph_title";
-  graph.label = "graph_label";
-  graph.color = yellow;
-  graph.textcolor = green;
-  graph.width = 5;
-  graph.x = 12;
-  graph.y = 17;
-  graph.textmode = right_justify;
-  
-  open_graph (&graph, stdout);
-  
-  node = XMALLOC (node_t, 1);
-  new_node (node);
-  node->title = "A";
-  node->locx = 12;
-  node->locy = 71;
-  add_node (&graph, node);
-
-  node = XMALLOC (node_t, 1);
-  new_node (node);
-  node->title = "B";
-  add_node (&graph, node);
-
-  edge = XMALLOC (edge_t, 1);
-  new_edge (edge);
-  edge->sourcename = "B";
-  edge->targetname = "A";
-  add_edge (&graph, edge);
-
-  output_graph(&graph, stdout);
-  close_graph (&graph, stdout);
-  
-  obstack_save (&graph_obstack, "essai.vcg");
-  
-  return (0);
-}
-
-#endif /* not DEBUG */
