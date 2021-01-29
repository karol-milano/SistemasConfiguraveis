@@ -67,7 +67,7 @@ log_resolution (rule_t *rule, symbol_number_t token,
       switch (resolution)
 	{
 	case shift_resolution:
-	case left_resolution:
+	case right_resolution:
 	  obstack_fgrow2 (&solved_conflicts_obstack,
 			  _("\
     Conflict between rule %d and token %s resolved as shift"),
@@ -75,7 +75,7 @@ log_resolution (rule_t *rule, symbol_number_t token,
 			  symbols[token]->tag);
 	  break;
 	case reduce_resolution:
-	case right_resolution:
+	case left_resolution:
 	  obstack_fgrow2 (&solved_conflicts_obstack,
 			  _("\
     Conflict between rule %d and token %s resolved as reduce"),
