@@ -59,7 +59,7 @@ new_graph (graph *g)
   g->y = G_Y;
   g->folding = G_FOLDING;
   g->shrink = G_SHRINK;
-  g->expand = G_EXPAND;
+  g->stretch = G_STRETCH;
 
   g->textmode = G_TEXTMODE;
   g->shape = G_SHAPE;
@@ -85,7 +85,6 @@ new_graph (graph *g)
 
   g->classname = G_CLASSNAME; /* No class name association. */
 
-  g->layoutalgorithm = G_LAYOUTALGORITHM;
   g->layout_downfactor = G_LAYOUT_DOWNFACTOR;
   g->layout_upfactor = G_LAYOUT_UPFACTOR;
   g->layout_nearfactor = G_LAYOUT_NEARFACTOR;
@@ -149,7 +148,7 @@ new_node (node *n)
   n->height = N_HEIGHT; /* Also. */
 
   n->shrink = N_SHRINK;
-  n->expand = N_EXPAND;
+  n->stretch = N_STRETCH;
 
   n->folding = N_FOLDING; /* No explicit default value. */
 
@@ -274,29 +273,6 @@ get_shape_str (enum shape shape)
     }
 }
 
-static const char *
-get_layoutalgorithm_str (enum layoutalgorithm layoutalgorithm)
-{
-  switch (layoutalgorithm)
-    {
-    case normal:       	return "normal";
-    case maxdepth:	return "maxdepth";
-    case mindepth:	return "mindepth";
-    case maxdepthslow:	return "maxdepthslow";
-    case mindepthslow:	return "mindepthslow";
-    case maxdegree:	return "maxdegree";
-    case mindegree:	return "mindegree";
-    case maxindegree:	return "maxindegree";
-    case minindegree:	return "minindegree";
-    case maxoutdegree:	return "maxoutdegree";
-    case minoutdegree:	return "minoutdegree";
-    case minbackward:	return "minbackward";
-    case dfs:		return "dfs";
-    case tree:		return "tree";
-    default:		abort (); return NULL;
-    }
-}
-
 static const char *
 get_decision_str (enum decision decision)
 {
@@ -559,8 +535,8 @@ output_node (node *n, FILE *fout)
 
   if (n->shrink != N_SHRINK)
     fprintf (fout, "\t\tshrink:\t%d\n", n->shrink);
-  if (n->expand != N_EXPAND)
-    fprintf (fout, "\t\texpand:\t%d\n", n->expand);
+  if (n->stretch != N_STRETCH)
+    fprintf (fout, "\t\tstretch:\t%d\n", n->stretch);
 
   if (n->folding != N_FOLDING)
     fprintf (fout, "\t\tfolding:\t%d\n", n->folding);
@@ -687,8 +663,8 @@ output_graph (graph *g, FILE *fout)
 
   if (g->shrink != G_SHRINK)
     fprintf (fout, "\tshrink:\t%d\n", g->shrink);
-  if (g->expand != G_EXPAND)
-    fprintf (fout, "\texpand:\t%d\n", g->expand);
+  if (g->stretch != G_STRETCH)
+    fprintf (fout, "\tstretch:\t%d\n", g->stretch);
 
   if (g->textmode != G_TEXTMODE)
     fprintf (fout, "\ttextmode:\t%s\n",
@@ -761,10 +737,6 @@ output_graph (graph *g, FILE *fout)
 	}
     }
 
-  if (g->layoutalgorithm != G_LAYOUTALGORITHM)
-    fprintf (fout, "\tlayoutalgorithm:\t%s\n",
-	     get_layoutalgorithm_str (g->layoutalgorithm));
-
   if (g->layout_downfactor != G_LAYOUT_DOWNFACTOR)
     fprintf (fout, "\tlayout_downfactor:\t%d\n", g->layout_downfactor);
   if (g->layout_upfactor != G_LAYOUT_UPFACTOR)
