@@ -27,17 +27,21 @@
 #include "relation.h"
 
 void
-relation_print (relation r, relation_node size,
+relation_print (const char *title,
+                relation r, relation_node size,
                 relation_node_print print, FILE *out)
 {
+  if (title)
+    fprintf (out, "%s:\n", title);
   for (size_t i = 0; i < size; ++i)
-    {
-      if (print)
-        print (i, out);
-      else
-        fprintf (out, "%3lu", (unsigned long) i);
-      fputc (':', out);
-      if (r[i])
+    if (r[i])
+      {
+        fputs ("    ", out);
+        if (print)
+          print (i, out);
+        else
+          fprintf (out, "%3lu", (unsigned long) i);
+        fputc (':', out);
         for (relation_node j = 0; r[i][j] != END_NODE; ++j)
           {
             fputc (' ', out);
@@ -46,8 +50,8 @@ relation_print (relation r, relation_node size,
             else
               fprintf (out, "%3lu", (unsigned long) r[i][j]);
           }
-      fputc ('\n', out);
-    }
+        fputc ('\n', out);
+      }
   fputc ('\n', out);
 }
 
@@ -130,10 +134,7 @@ relation_transpose (relation *R_arg, relation_node size)
   relation r = *R_arg;
 
   if (trace_flag & trace_sets)
-    {
-      fputs ("relation_transpose: input\n", stderr);
-      relation_print (r, size, NULL, stderr);
-    }
+    relation_print ("relation_transpose", r, size, NULL, stderr);
 
   /* Count. */
   /* NEDGES[I] -- total size of NEW_R[I]. */
@@ -175,10 +176,7 @@ relation_transpose (relation *R_arg, relation_node size)
   free (r);
 
   if (trace_flag & trace_sets)
-    {
-      fputs ("relation_transpose: output\n", stderr);
-      relation_print (new_R, size, NULL, stderr);
-    }
+    relation_print ("relation_transpose: output", new_R, size, NULL, stderr);
 
   *R_arg = new_R;
 }
