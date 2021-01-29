@@ -974,10 +974,11 @@ read_declarations (void)
 	      break;
 
 	    case tok_hdrext:
+	      parse_header_extension_decl ();
 	      break;
 
 	    case tok_srcext:
-	      parse_source_extension_decl();
+	      parse_source_extension_decl ();
 	      break;
 
 	    case tok_noop:
