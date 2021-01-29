@@ -545,7 +545,7 @@ output_node (node_t *node, struct obstack *os)
   if (node->shrink != N_SHRINK)
     obstack_fgrow1 (os, "\t\tshrink:\t%d\n", node->shrink);
   if (node->stretch != N_STRETCH)
-    obstack_fgrow1 (os, "\t\tshrink:\t%d\n", node->shrink);
+    obstack_fgrow1 (os, "\t\tstretch:\t%d\n", node->stretch);
 
   if (node->folding != N_FOLDING)
     obstack_fgrow1 (os, "\t\tfolding:\t%d\n", node->folding);
@@ -580,7 +580,8 @@ output_node (node_t *node, struct obstack *os)
 void
 output_edge (edge_t *edge, struct obstack *os)
 {
-
+  /* FIXME: SOURCENAME and TARGETNAME are mandatory
+     so it has to be fatal not to give these informations.  */
   if (edge->sourcename != E_SOURCENAME)
     obstack_fgrow1 (os, "\t\tsourcename:\t\"%s\"\n", edge->sourcename);
   if (edge->targetname != E_TARGETNAME)
