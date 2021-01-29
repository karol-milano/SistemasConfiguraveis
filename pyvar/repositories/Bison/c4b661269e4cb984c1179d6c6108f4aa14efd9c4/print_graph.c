@@ -32,6 +32,7 @@
 #include "obstack.h"
 #include "print_graph.h"
 #include "vcg.h"
+#include "quote.h"
 
 static graph_t graph;
 
@@ -56,6 +57,9 @@ print_core (int state)
 
   for (i = 0; i < k; i++)
     {
+      if (i)
+	obstack_sgrow (&graph_obstack, "\\n");
+
       sp1 = sp = ritem + statep->items[i];
 
       while (*sp > 0)
@@ -64,17 +68,16 @@ print_core (int state)
       rule = -(*sp);
 
       obstack_fgrow1 (&graph_obstack, _("%d: "), rule);
-      obstack_fgrow1 (&graph_obstack, " %s  ->  ", tags[rlhs[rule]]);
+      obstack_fgrow1 (&graph_obstack, " %s  ->  ", quote (tags[rlhs[rule]]));
 
       for (sp = ritem + rrhs[rule]; sp < sp1; sp++)
-	obstack_fgrow1 (&graph_obstack, "%s ", tags[*sp]);
+	obstack_fgrow1 (&graph_obstack, "%s ", quote (tags[*sp]));
 
       obstack_1grow (&graph_obstack, '.');
 
       while (*sp > 0)
-	obstack_fgrow1 (&graph_obstack, " %s", tags[*sp++]);
+	obstack_fgrow1 (&graph_obstack, " %s", quote (tags[*sp++]));
 
-      obstack_sgrow (&graph_obstack, "\\n");
     }
   obstack_sgrow (&graph_obstack, "\"\n");
 }
@@ -129,10 +132,12 @@ print_actions (int state, node_t *node)
 	      edge.type = back_edge;
 	    open_edge (&edge, &graph_obstack);
 	    edge.sourcename = node->title;
+	    sprintf (buff, "%d", state1);
 	    edge.targetname = buff;
-	    sprintf (edge.targetname, "%d", state1);
 	    edge.color = (symbol == 0) ? blue : red;
-	    edge.label = tags[symbol];
+	    /* FIXME: Be aware that quote uses static memory.  The string
+	       must be output immediately (which is the case here). */
+	    edge.label = tags[symbol] ? quote (tags[symbol]) : NULL;
 	    output_edge (&edge, &graph_obstack);
 	    close_edge (&graph_obstack);
 	  }
@@ -176,10 +181,10 @@ print_actions (int state, node_t *node)
 	  new_edge (&edge);
 	  open_edge (&edge, &graph_obstack);
 	  edge.sourcename = node->title;
+	  sprintf (buff, "%d", state1);
 	  edge.targetname = buff;
 	  edge.color = red;
-	  sprintf (edge.targetname, "%d", state1);
-	  edge.label = tags[symbol];
+	  edge.label = tags[symbol] ? quote (tags[symbol]) : NULL;
 	  output_edge (&edge, &graph_obstack);
 	  close_edge (&graph_obstack);
 	}
