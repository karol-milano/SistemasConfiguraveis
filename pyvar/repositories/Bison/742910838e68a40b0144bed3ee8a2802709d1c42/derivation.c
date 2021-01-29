@@ -55,9 +55,10 @@ derivation_list_prepend (derivation_list dl, derivation *d)
 
 void derivation_list_free (derivation_list dl)
 {
-  gl_list_iterator_t it = gl_list_iterator (dl);
-  derivation *d;
-  while (gl_list_iterator_next (&it, (const void **) &d, NULL))
+  derivation *d = NULL;
+  for (gl_list_iterator_t it = gl_list_iterator (dl);
+       derivation_list_next (&it, &d);
+       )
     if (d != &d_dot)
       derivation_free (d);
   gl_list_free (dl);
@@ -94,9 +95,10 @@ derivation_free (derivation *d)
         {
           if (deriv->children)
             {
-              gl_list_iterator_t it = gl_list_iterator (deriv->children);
-              derivation *child;
-              while (gl_list_iterator_next (&it, (const void **) &child, NULL))
+              derivation *child = NULL;
+              for (gl_list_iterator_t it = gl_list_iterator (deriv->children);
+                   derivation_list_next (&it, &child);
+                   )
                 if (child != &d_dot)
                   gl_list_add_last (free_queue, child);
               gl_list_free (deriv->children);
@@ -114,9 +116,10 @@ derivation_size (const derivation *deriv)
   if (!deriv->children)
     return 1;
   int size = 1;
-  gl_list_iterator_t it = gl_list_iterator (deriv->children);
-  derivation *child;
-  while (gl_list_iterator_next (&it, (const void **) &child, NULL))
+  derivation *child = NULL;
+  for (gl_list_iterator_t it = gl_list_iterator (deriv->children);
+       derivation_list_next (&it, &child);
+       )
     size += derivation_size (child);
   return size;
 }
@@ -136,10 +139,12 @@ derivation_print (const derivation *deriv, FILE *f)
       fprintf (f, " %s", sym->tag);
       return;
     }
-  gl_list_iterator_t it = gl_list_iterator (deriv->children);
-  derivation *child;
+
   fprintf (f, " %s ::=[", sym->tag);
-  while (gl_list_iterator_next (&it, (const void **) &child, NULL))
+  derivation *child;
+  for (gl_list_iterator_t it = gl_list_iterator (deriv->children);
+       derivation_list_next (&it, &child);
+       )
     {
       derivation_print (child, f);
       fputs (" ", f);
@@ -162,10 +167,11 @@ derivation_print_leaves (const derivation *deriv, FILE *f)
       return;
     }
 
-  gl_list_iterator_t it = gl_list_iterator (deriv->children);
   const char *sep = "";
   derivation *child;
-  while (gl_list_iterator_next (&it, (const void **) &child, NULL))
+  for (gl_list_iterator_t it = gl_list_iterator (deriv->children);
+       derivation_list_next (&it, &child);
+       )
     {
       fputs (sep, f);
       sep = "  ";
