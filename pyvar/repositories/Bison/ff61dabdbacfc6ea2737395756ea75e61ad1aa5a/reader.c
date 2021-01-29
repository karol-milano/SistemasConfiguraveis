@@ -1002,11 +1002,9 @@ read_declarations (void)
 	      break;
 
 	    case SEMANTIC_PARSER:
-	      if (semantic_parser == 0)
-		{
-		  semantic_parser = 1;
-		  open_extra_files ();
-		}
+	      if (!semantic_parser)
+		fguard = xfopen (guardfile, "w");
+	      semantic_parser = 1;
 	      break;
 
 	    case PURE_PARSER:
