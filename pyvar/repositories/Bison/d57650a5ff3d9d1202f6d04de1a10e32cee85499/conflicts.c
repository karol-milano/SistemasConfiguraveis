@@ -287,7 +287,7 @@ set_conflicts (state_t *state)
 void
 conflicts_solve (void)
 {
-  size_t i;
+  state_number_t i;
 
   conflicts = XCALLOC (char, nstates);
   shiftset = bitset_create (ntokens, BITSET_FIXED);
@@ -409,7 +409,7 @@ void
 conflicts_output (FILE *out)
 {
   bool printed_sth = FALSE;
-  size_t i;
+  state_number_t i;
   for (i = 0; i < nstates; i++)
     if (conflicts[i])
       {
@@ -432,7 +432,7 @@ conflicts_output (FILE *out)
 int
 conflicts_total_count (void)
 {
-  unsigned i;
+  state_number_t i;
   int count;
 
   /* Conflicts by state.  */
@@ -454,8 +454,6 @@ conflicts_total_count (void)
 void
 conflicts_print (void)
 {
-  size_t i;
-
   /* Is the number of SR conflicts OK?  Either EXPECTED_CONFLICTS is
      not set, and then we want 0 SR, or else it is specified, in which
      case we want equality.  */
@@ -465,12 +463,16 @@ conflicts_print (void)
   int rrc_total = 0;
 
   /* Conflicts by state.  */
-  for (i = 0; i < nstates; i++)
-    if (conflicts[i])
-      {
-	src_total += count_sr_conflicts (states[i]);
-	rrc_total += count_rr_conflicts (states[i], TRUE);
-      }
+  {
+    state_number_t i;
+
+    for (i = 0; i < nstates; i++)
+      if (conflicts[i])
+	{
+	  src_total += count_sr_conflicts (states[i]);
+	  rrc_total += count_rr_conflicts (states[i], TRUE);
+	}
+  }
 
   src_ok = src_total == (expected_conflicts == -1 ? 0 : expected_conflicts);
 
