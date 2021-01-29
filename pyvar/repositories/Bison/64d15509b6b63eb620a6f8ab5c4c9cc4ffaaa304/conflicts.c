@@ -40,10 +40,11 @@ static unsigned *lookaheadset = NULL;
 static inline void
 log_resolution (int state, int LAno, int token, char *resolution)
 {
-  obstack_fgrow4 (&output_obstack,
-		  _("\
+  if (verbose_flag)
+    obstack_fgrow4 (&output_obstack,
+		    _("\
 Conflict in state %d between rule %d and token %s resolved as %s.\n"),
-		  state, LAruleno[LAno], tags[token], resolution);
+		    state, LAruleno[LAno], tags[token], resolution);
 }
 
 
