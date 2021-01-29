@@ -104,7 +104,7 @@ log_resolution (int lookahead, int token,
 	  break;
 
 	case left_resolution:
-	  obstack_printf (&solved_conflicts_obstack,
+	  obstack_fgrow1 (&solved_conflicts_obstack,
 			  " (%%left %s)",
 			  symbols[token]->tag);
 	  break;
