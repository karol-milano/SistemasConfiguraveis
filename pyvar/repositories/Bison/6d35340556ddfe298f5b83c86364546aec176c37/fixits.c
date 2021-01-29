@@ -91,7 +91,7 @@ fixits_register (location const *loc, char const* fix)
                                    true);
   fixit *f = fixit_new (loc, fix);
   gl_sortedlist_add (fixits, (gl_listelement_compar_fn) fixit_cmp, f);
-  if (feature_flag & feature_fixit_parsable)
+  if (feature_flag & feature_fixit)
     fixit_print (f, stderr);
 }
 
