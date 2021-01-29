@@ -40,7 +40,7 @@
 int expected_sr_conflicts = -1;
 int expected_rr_conflicts = -1;
 static char *conflicts;
-struct obstack solved_conflicts_obstack;
+static struct obstack solved_conflicts_obstack;
 
 static bitset shift_set;
 static bitset look_ahead_set;
