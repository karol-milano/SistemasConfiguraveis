@@ -52,6 +52,11 @@ fixit_new (location const *loc, char const* fix)
   return res;
 }
 
+static int
+fixit_cmp (const  fixit *a, const fixit *b)
+{
+  return location_cmp (a->location, b->location);
+}
 
 static void
 fixit_free (fixit *f)
@@ -85,7 +90,7 @@ fixits_register (location const *loc, char const* fix)
                                    (gl_listelement_dispose_fn) fixit_free,
                                    true);
   fixit *f = fixit_new (loc, fix);
-  gl_list_add_last (fixits, f);
+  gl_sortedlist_add (fixits, (gl_listelement_compar_fn) fixit_cmp, f);
   if (feature_flag & feature_fixit_parsable)
     fixit_print (f, stderr);
 }
