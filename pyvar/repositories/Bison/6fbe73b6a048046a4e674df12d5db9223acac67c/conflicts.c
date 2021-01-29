@@ -360,15 +360,9 @@ set_conflicts (state *s, symbol **errors)
       state_errs_set (s, nerrs, errors);
     }
   if (obstack_object_size (&solved_conflicts_obstack))
-    {
-      obstack_1grow (&solved_conflicts_obstack, '\0');
-      s->solved_conflicts = obstack_finish (&solved_conflicts_obstack);
-    }
+    s->solved_conflicts = obstack_finish0 (&solved_conflicts_obstack);
   if (obstack_object_size (&solved_conflicts_xml_obstack))
-    {
-      obstack_1grow (&solved_conflicts_xml_obstack, '\0');
-      s->solved_conflicts_xml = obstack_finish (&solved_conflicts_xml_obstack);
-    }
+    s->solved_conflicts_xml = obstack_finish0 (&solved_conflicts_xml_obstack);
 
   /* Loop over all rules which require lookahead in this state.  Check
      for conflicts not resolved above.  */
