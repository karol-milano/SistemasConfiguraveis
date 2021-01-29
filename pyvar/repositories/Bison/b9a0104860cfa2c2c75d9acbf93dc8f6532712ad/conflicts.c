@@ -231,8 +231,7 @@ resolve_sr_conflict (state_t *state, int ruleno,
 	      break;
 
 	    case undef_assoc:
-	      assert (symbols[i]->assoc != undef_assoc);
-	      break;
+	      abort ();
 	    }
       }
 
