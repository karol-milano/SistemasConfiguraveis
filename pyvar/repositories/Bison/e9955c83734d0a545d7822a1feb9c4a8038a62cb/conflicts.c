@@ -216,6 +216,10 @@ resolve_sr_conflict (state_t *state, int lookahead)
 	      /* Record an explicit error for this token.  */
 	      errp->errs[errp->nerrs++] = i;
 	      break;
+
+	    case undef_assoc:
+	      assert (symbols[i]->assoc != undef_assoc);
+	      break;
 	    }
       }
 
