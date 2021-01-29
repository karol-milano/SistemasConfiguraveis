@@ -76,12 +76,12 @@ void derivation_list_free (derivation_list dl)
 derivation *
 derivation_new (symbol_number sym, derivation_list children)
 {
-  derivation *deriv = xmalloc (sizeof (derivation));
-  deriv->sym = sym;
-  deriv->children = children;
-  deriv->reference_count = 0;
-  deriv->color = -1;
-  return deriv;
+  derivation *res = xmalloc (sizeof *res);
+  res->sym = sym;
+  res->children = children;
+  res->reference_count = 0;
+  res->color = -1;
+  return res;
 }
 
 void
