@@ -1054,10 +1054,10 @@ read_declarations (void)
 	    case tok_stropt:
 	    case tok_intopt:
 	    case tok_obsolete:
-	    case tok_illegal:
 	      abort ();
 	      break;
 
+	    case tok_illegal:
 	    default:
 	      complain (_("unrecognized: %s"), token_buffer);
 	      skip_to_char ('%');
