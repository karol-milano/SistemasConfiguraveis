@@ -330,8 +330,8 @@ quotearg_buffer_restyled (char *buffer, size_t buffersize,
 		  case '<': case '=': case '>':
 		    /* Escape the second '?' in what would otherwise be
 		       a trigraph.  */
-		    i += 2;
 		    c = arg[i + 2];
+		    i += 2;
 		    STORE ('?');
 		    STORE ('\\');
 		    STORE ('?');
