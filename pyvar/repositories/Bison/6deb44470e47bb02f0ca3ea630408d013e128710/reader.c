@@ -931,6 +931,7 @@ read_declarations (void)
 	    case EXPECT:
 	      parse_expect_decl ();
 	      break;
+
 	    case THONG:
 	      parse_thong_decl ();
 	      break;
@@ -947,14 +948,6 @@ read_declarations (void)
 	      parse_assoc_decl (non_assoc);
 	      break;
 
-	    case SEMANTIC_PARSER:
-	      semantic_parser = 1;
-	      break;
-
-	    case PURE_PARSER:
-	      pure_parser = 1;
-	      break;
-
 	    case NOOP:
 	      break;
 
