@@ -43,7 +43,7 @@ static bitset lookaheadset;
 static inline void
 log_resolution (state_t *state, int LAno, int token, const char *resolution)
 {
-  if (verbose_flag)
+  if (report_flag & report_states)
     obstack_fgrow4 (&output_obstack,
 		    _("\
 Conflict in state %d between rule %d and token %s resolved as %s.\n"),
