@@ -38,7 +38,10 @@
 /* -1 stands for not specified. */
 int expected_sr_conflicts = -1;
 int expected_rr_conflicts = -1;
-static char *conflicts;
+
+/* CONFLICTS[STATE-NUM] -- Whether that state has unresolved conflicts.  */
+static bool *conflicts;
+
 static struct obstack solved_conflicts_obstack;
 static struct obstack solved_conflicts_xml_obstack;
 
@@ -376,7 +379,7 @@ set_conflicts (state *s, symbol **errors)
     for (int i = 0; i < reds->num; ++i)
       {
         if (!bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
-          conflicts[s->number] = 1;
+          conflicts[s->number] = true;
         bitset_or (lookahead_set, lookahead_set, reds->lookahead_tokens[i]);
       }
 }
