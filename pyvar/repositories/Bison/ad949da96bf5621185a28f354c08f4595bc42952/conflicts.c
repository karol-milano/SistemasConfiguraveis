@@ -45,7 +45,8 @@ log_resolution (state_t *state, int LAno, int token, char *resolution)
     obstack_fgrow4 (&output_obstack,
 		    _("\
 Conflict in state %d between rule %d and token %s resolved as %s.\n"),
-		    state->number, LAruleno[LAno], tags[token], resolution);
+		    state->number, LAruleno[LAno], symbols[token]->tag,
+		    resolution);
 }
 
 
