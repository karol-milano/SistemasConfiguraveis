@@ -40,7 +40,7 @@ static bitset lookaheadset;
 
 
 static inline void
-log_resolution (state_t *state, int LAno, int token, char *resolution)
+log_resolution (state_t *state, int LAno, int token, const char *resolution)
 {
   if (verbose_flag)
     obstack_fgrow4 (&output_obstack,
