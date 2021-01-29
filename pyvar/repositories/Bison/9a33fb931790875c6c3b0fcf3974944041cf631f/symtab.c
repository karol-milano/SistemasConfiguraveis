@@ -1189,10 +1189,10 @@ init_prec_nodes (void)
 static symgraphlink *
 symgraphlink_new (graphid id, symgraphlink *next)
 {
-  symgraphlink *l = xmalloc (sizeof *l);
-  l->id = id;
-  l->next = next;
-  return l;
+  symgraphlink *res = xmalloc (sizeof *res);
+  res->id = id;
+  res->next = next;
+  return res;
 }
 
 
