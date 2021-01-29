@@ -382,7 +382,7 @@ reduce_grammar (void)
       reduce_print ();
 
       if (!bitset_test (N, accept->content->number - ntokens))
-        complain (&startsymbol_location, fatal,
+        complain (&startsymbol_loc, fatal,
                   _("start symbol %s does not derive any sentence"),
                   startsymbol->tag);
 
